#import "AppDelegate.h"

#import <AWSDK/AWBeacon.h>
#import <AWSDK/AWProxy.h>
#import <AWSDK/AWServer.h>
#import <AWSDK/AWAgentAuthenticatorController.h>
#import <AWSDK/AWSDKCore.h>
#import <AWSDK/AWSDKErrors.h>


#import "MainViewController.h"

static NSString * const APP_SCHEME = @"webtest";

@interface AppDelegate ()

@property (nonatomic, retain) AWBeacon *beacon;

@end

@implementation AppDelegate

@synthesize datasamplerConfiguration = _datasamplerConfiguration;

- (id)init {
    if ((self = [super init])){
    }
    return self;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    
    __block BOOL GetUDID = NO;
    int UdidFlag;

    NSError *errorr;
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *path = [documentsDirectory stringByAppendingPathComponent:@"AppConfig.plist"];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    if (![fileManager fileExistsAtPath: path])
    {
        NSString *bundle = [[NSBundle mainBundle] pathForResource:@"AppConfig" ofType:@"plist"];
        
        [fileManager copyItemAtPath:bundle toPath: path error:&errorr];
    }
    NSMutableDictionary *appconfig = [[NSMutableDictionary alloc] initWithContentsOfFile: path];
    
    
    int Interval = [appconfig[@"Sampling Interval(minutes)"]intValue]*60;
    int Sensitivity = [appconfig[@"Location Sensitivity(meters)"]intValue];
    
    //App Config override, grants ability to use the new iOS7 MDM app config feature to override the hardcoded settings
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSMutableDictionary *configDictionary = [defaults dictionaryForKey:@"com.apple.configuration.managed"];
    
    NSString *intervalOverride = configDictionary[@"interval"];
    NSString *sensitivityOverride = configDictionary[@"sensitivity"];

    if([intervalOverride isEqualToString:@""] || intervalOverride == nil || [intervalOverride isEqualToString:@"0"]){
        NSLog(@"No override for interval detected or value is invalid, pull from plist settings");
    }else{
        Interval = [intervalOverride integerValue]*60;
        NSLog(@"MDM APP CONFIG DETECTED for Interval");
    }

    if([sensitivityOverride isEqualToString:@""] || sensitivityOverride == nil || [sensitivityOverride isEqualToString:@"0"]){
        NSLog(@"No override for sensitivity app config detected or value is invalid, pull from plist settings");
    }else{
        Sensitivity = [sensitivityOverride integerValue];
        NSLog(@"MDM APP CONFIG DETECTED for sensitivity");
    }
    
    NSLog(@"%@",[NSString stringWithFormat:@"Interval is %d", Interval]);
    NSLog(@"%@",[NSString stringWithFormat:@"Sensitivity is %d", Sensitivity]);
    
    UdidFlag = [appconfig[@"DO NOT TOUCH - SET TO YES"]intValue];
    
    if(UdidFlag==1){    //Has the app ever been initiated with the UDID? If so then follow this workflow.
        GetUDID = YES;
        NSLog(@"App is launching for the first time...Begin Registration");
        
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Authenticate" message:@"Please allow the Agent to authenticate. If the Agent does not trigger and this message persists, please terminate this app and restart it." delegate:self cancelButtonTitle:nil otherButtonTitles:nil];
        [alert show];   //This alert prevents the app from moving forward unless it has been sucessfully initialized
        if([[AWAgentAuthenticatorController sharedInstance] canUseAgent]){
            NSLog(@"Agent detected on device");
            [NSThread sleepForTimeInterval:3];  //Pause for 3 seconds and give the app time to initialize
            
            [[AWAgentAuthenticatorController sharedInstance] renewWithScheme:APP_SCHEME callback:^(BOOL authenticated){
                if(authenticated){
                    NSLog(@"App has successfully authenticated");
                    [self performSelector:@selector(dismissAlertView:) withObject:alert afterDelay:2];
                    [appconfig setObject:[NSNumber numberWithInt:0] forKey:@"DO NOT TOUCH - SET TO YES"];
                    [appconfig writeToFile: path atomically:YES];
                    GetUDID = NO;
                    
                    NSString *url = [[AWAgentAuthenticatorController sharedInstance] serverURL];
                    NSLog(@"Server URL obtained is %@", url);
                    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];

                    
                    [[AWServer sharedInstance] setDeviceServicesURL:[NSURL URLWithString:url]];
                    [defaults setObject:[NSString stringWithFormat:@"%@", url] forKey:@"DSURL"];
                    [defaults synchronize];
                    
                    //Create location manager instance for GPS
                    CLLocationManager * manager = [CLLocationManager new];
                    __block UIBackgroundTaskIdentifier background_task;
                    
                    background_task = [application beginBackgroundTaskWithExpirationHandler:^ {
                        //Usually you would end the background task here, but we'll continue to let it run
                        //iOS will force the app to eventually crash, but since we declared the VOIP key in the plist
                        //the app will restart itself and continue on in the background
                        NSLog(@"Background task has expired. Completion handler called.");
                    }];
                    
                    // Start Beacon for jailbreak detection
                    self.beacon = [[AWBeacon alloc] initWithAPNSToken:@"" transmitInterval:Interval locationGroup:@"" locationMode:AWLocationModeStandard distance:Sensitivity];
                    [self.beacon start];
                    [self.beacon send];
                    
                    // The time in seconds between dataSampler samples
                    NSInteger dataSamplerSampleInterval = Interval;
                    // The time in seconds between dataSampler transmissions
                    NSInteger dataSamplerTransmitInterval = Interval;
                    //The error and information logging level the dataSampler module is run at
                    AWTraceLevel dataSamplerTraceLevel = Verbose;
                    
                    AWDataSamplerModuleBitmask moduleBitMask = AWDataSamplerModuleGPS;  //Only bitmask GPS module since we only want to sample GPS
                    
                    _datasamplerConfiguration = [[AWDataSamplerConfiguration alloc]
                                                 initWithSampleModules:moduleBitMask
                                                 defaultSampleInterval:dataSamplerSampleInterval
                                                 defaultTransmitInterval:dataSamplerTransmitInterval
                                                 traceLevel:dataSamplerTraceLevel];
                    
                    // Instantiate an dataSampler with these configurations
                    [[AWDataSampler mDataSamplerModule] setConfig:self.datasamplerConfiguration];
                    
                    // If set yes, GPS information will also be send in, no otherwise
                    [[AWDataSampler mDataSamplerModule] setSendGPSImmediate:YES];
                    
                    NSError *error;
                    
                    if([[AWDataSampler mDataSamplerModule] g_AWDataSamplerIsStarted]){  //Is data sampler started already?
                        NSLog(@"Datasampler is ACTIVE");
                        //[[AWDataSampler mDataSamplerModule] shutDown:&error];   //If so, shut it down because you can only have one started at a time
                    }else{
                        NSLog(@"Datasampler is INACTIVE");
                    }
                    
                    [[AWDataSampler mDataSamplerModule] startUp:&error];    //Start data sampler for sending GPS data
                    
                    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
                        
                        manager.desiredAccuracy = kCLLocationAccuracyBest;
                        [manager startUpdatingLocation];
                        
                        while(TRUE)
                        {
                            //Loop to keep backgroundTimeRemaining from decreasing.
                            //NSLog(@"Background time remaining: %.0f seconds (%d mins)", [UIApplication sharedApplication].backgroundTimeRemaining, (int)[UIApplication sharedApplication].backgroundTimeRemaining / 60);
                            [NSThread sleepForTimeInterval:1]; //wait for 1 sec
                        }
                        
                        [application endBackgroundTask: background_task];
                        background_task = UIBackgroundTaskInvalid;
                        
                    });

                }
            }];
        }else{
            UIAlertView *agentAlert = [[UIAlertView alloc] initWithTitle:@"Agent not found" message:@"The AirWatch Agent must be installed on this device in order to continue. Please download the agent, then terminate and restart this application." delegate:self cancelButtonTitle:nil otherButtonTitles:nil];
            [agentAlert show];
        }
        
        
    }else{
        NSLog(@"App has already registered.");
        NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
        
        NSString *url = [defaults stringForKey:@"DSURL"];
        NSLog(@"%@",url);
        [[AWServer sharedInstance] setDeviceServicesURL:[NSURL URLWithString:url]];
        
        //Create location manager instance for GPS
        CLLocationManager * manager = [CLLocationManager new];
        __block UIBackgroundTaskIdentifier background_task;
        
        background_task = [application beginBackgroundTaskWithExpirationHandler:^ {
            //Usually you would end the background task here, but we'll continue to let it run
            //iOS will force the app to eventually crash, but since we declared the VOIP key in the plist
            //the app will restart itself and continue on in the background
            NSLog(@"Background task has expired. Completion handler called.");
        }];
        
        // Start Beacon for jailbreak detection
        self.beacon = [[AWBeacon alloc] initWithAPNSToken:@"" transmitInterval:Interval locationGroup:@"" locationMode:AWLocationModeStandard distance:Sensitivity];
        [self.beacon start];
        [self.beacon send];
        
        // The time in seconds between dataSampler samples
        NSInteger dataSamplerSampleInterval = Interval;
        // The time in seconds between dataSampler transmissions
        NSInteger dataSamplerTransmitInterval = Interval;
        //The error and information logging level the dataSampler module is run at
        AWTraceLevel dataSamplerTraceLevel = Verbose;
        
        AWDataSamplerModuleBitmask moduleBitMask = AWDataSamplerModuleGPS;  //Only bitmask GPS module since we only want to sample GPS
        
        _datasamplerConfiguration = [[AWDataSamplerConfiguration alloc]
                                     initWithSampleModules:moduleBitMask
                                     defaultSampleInterval:dataSamplerSampleInterval
                                     defaultTransmitInterval:dataSamplerTransmitInterval
                                     traceLevel:dataSamplerTraceLevel];
        
        // Instantiate an dataSampler with these configurations
        [[AWDataSampler mDataSamplerModule] setConfig:self.datasamplerConfiguration];
        
        // If set yes, GPS information will also be send in, no otherwise
        [[AWDataSampler mDataSamplerModule] setSendGPSImmediate:YES];
        
        NSError *error;
        
        if([[AWDataSampler mDataSamplerModule] g_AWDataSamplerIsStarted]){  //Is data sampler started already?
            NSLog(@"Datasampler is ACTIVE");
            //[[AWDataSampler mDataSamplerModule] shutDown:&error];   //If so, shut it down because you can only have one started at a time
        }else{
            NSLog(@"Datasampler is INACTIVE");
        }
         
        [[AWDataSampler mDataSamplerModule] startUp:&error];    //Start data sampler for sending GPS data
        
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            
            manager.desiredAccuracy = kCLLocationAccuracyBest;
            [manager startUpdatingLocation];
            
            while(TRUE)
            {
                //Loop to keep backgroundTimeRemaining from decreasing.
                //NSLog(@"Background time remaining: %.0f seconds (%d mins)", [UIApplication sharedApplication].backgroundTimeRemaining, (int)[UIApplication sharedApplication].backgroundTimeRemaining / 60);
                [NSThread sleepForTimeInterval:1]; //wait for 1 sec
            }
            
            [application endBackgroundTask: background_task];
            background_task = UIBackgroundTaskInvalid;
            
        });

    }
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.rootViewController = [MainViewController new];
    [self.window makeKeyAndVisible];
    
    return YES;
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Send Beacon
    [self.beacon send];
    if([[AWDataSampler mDataSamplerModule] g_AWDataSamplerIsStarted]){
        NSLog(@"Application is active. Data sampler is active.");
    }else{
        NSLog(@"Application is active. Data sampler is not started.");
    }
    
}

-(void)dismissAlertView:(UIAlertView *)alertView{
    [alertView dismissWithClickedButtonIndex:0 animated:YES];
}

-(void)applicationWillTerminate:(UIApplication *)application{
    //TODO: Send off distress call when application is about to be killed
    
}


- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation
{
    if ([url.scheme isEqualToString:APP_SCHEME]) {
        return [[AWAgentAuthenticatorController sharedInstance] processURL:url];
    } else {
        return NO;
    }
}

@end

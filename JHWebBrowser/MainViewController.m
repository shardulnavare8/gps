#import "MainViewController.h"
#import "JHWebBrowser.h"

@interface MainViewController ()

@property (nonatomic, strong) JHWebBrowser *browser;

@end

@implementation MainViewController
@synthesize browser;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    browser = [JHWebBrowser new];
    
    NSString *plistCatPath = [[NSBundle mainBundle] pathForResource:@"AppConfig" ofType:@"plist"];  //Get interval setting from plist
    NSMutableDictionary *appconfig = [NSMutableDictionary dictionaryWithContentsOfFile:plistCatPath];
    
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSDictionary *configdictionary = [defaults dictionaryForKey:@"com.apple.configuration.managed"];
    NSString *urlOverride = configdictionary[@"url"];
    
    if([urlOverride isEqualToString:@""] || urlOverride == nil){
        NSLog(@"No url override detected");
        browser.url = [NSURL URLWithString:appconfig[@"Landing Page"]];
    }else{
        NSLog(@"url override detected.");
        browser.url = [NSURL URLWithString:urlOverride];
    }
    
    
    
    
    CGRect frame = self.view.bounds;
    //frame.size.height -= 50;
    browser.view.frame = frame;
    [self.view addSubview:browser.view];
    
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return YES;
}

@end

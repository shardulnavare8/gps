#import <UIKit/UIKit.h>
#import <AWSDK/AWDataSampler.h>
#import <AWSDK/AWDataSamplerConfiguration.h>

@class ViewController;

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) ViewController *viewController;


/*
 *  An Air-Watch DataSampler configuration object, used to configure the neccessary
 *  information to send to the Air-Watch console
 *
 */
@property (nonatomic, retain) AWDataSamplerConfiguration *datasamplerConfiguration;

@end

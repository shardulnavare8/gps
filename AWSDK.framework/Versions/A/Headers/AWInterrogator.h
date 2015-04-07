
/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWInterrogator.h */ 

#import <Foundation/Foundation.h>
#import <AWSDK/AWMacro.h>
/**
 @enum  An enum holding the possible Interrogator transmission types
 */

typedef enum
{
	kInterrogatorTransmitterUnknown = 0,	/**< Transmit method unknown. */
	kInterrogatoransmitterHttp,		/**< Transmit Interrogator samples through HTTP */
	kInterrogatorTransmitterTcp,		/**< Transmit Interrogator samples through TCP */	
}
AWInterrogatorTransmitterType;

@class AWInterrogatorTransmitter;
@class AWInterrogatorConfiguration;

/**
 @deprecated
 @brief		AWInterrogator is utility kind of interface, by using this user can send dynamic data of device, like system info, analytics info, GPS info, callLog info, usage info, usageData info etc.
 \n
     AWInterrogator declares the programmatic interface for an object that manages the SDK‚Äôs Interrogator module. AWInterrogator declares methods for starting and stopping the Interrogator service on a device. Settings for the Interrogator is passed through a configuration object of type AWInterrogatorConfiguration. Using the configuration object, the user can stop and start various Interrogator modules. To set up Interrogator module, user has to initialize the interrogator module instance with a configuration object and then start the module by calling the method startUp:outError on Interrogator module instance. Calling shutDown:outError on the Interrogator module instance will stop sampling and transmission.
 
 
 
 @details    DEPRECATED: Please use AWDataSampler instead.
 @version 3.7.1
 */
AW_DEPRECATED_ATTRIBUTE_MESSAGE("Please use AWDataSampler instead.")
@interface AWInterrogator : NSObject
{
	BOOL g_AWInterrogatorIsInitialized;
	BOOL g_AWInterrogatorIsStarted;
	AWInterrogatorTransmitterType _transmitType;
	BOOL sendGPSImmediate;
}

/** Property to indicate whether or not the Interrogator is initialized with an InterrogatorConfig. **/
@property (nonatomic, assign) BOOL g_AWInterrogatorIsInitialized;

/** Property to indicate whether or not the Interrogator is currently started and transmitting. **/
@property (nonatomic) BOOL g_AWInterrogatorIsStarted;

/** Property to indicate whether Interrogator should transmit GPS updates imediately. **/
@property (nonatomic) BOOL sendGPSImmediate;

///-------------------------------------
/// @name Interrogator Module Management
///-------------------------------------

/**  Gets the instance of the Interrogator module so that multiple instances cannot be started.
 
 Method should be called when other classes need to access the interrogator instance.
 
 @return a pointer to the AWInterrogator object. 
 */
+ (AWInterrogator*)mInterrogatorModule;

/** Initializes the Interrogator module for use. This does not start transmitting, you must use startUp: to begin transmission.
 
 @return The object id of the created Interrogator object.
 @param config An AWInterrogatorConfiguration that defines the proper Interrogator settings. 
 */
- (id)initWithConfig:(AWInterrogatorConfiguration *)config;

/** Starts up the interrogator module and begins the timer on the configured modules.
 
 Method should be called when the host application is ready to start transmitting interrogator data.
 
 @return A BOOL value indicating method success. 
 @param outError Out parameter used if an error occurs while starting the Interrogator module.  May be NULL.
 */
- (BOOL)startUp:(NSError **)outError;

/** Closes all network connections, stops all Interrogator transmissions. The Interrogator can be restarted, given it has a valid configuration.
 
 Method should be called when the host application no longer needs the capabilities of the Interrogator module.
 
 @return A BOOL value indicating method success. 
 @param modules An array of module objects to be started. These modules should be initialized with a timer value.
 @param outError Out parameter used if an error occurs while shutting down the Interrogator module.  May be NULL.
 */
- (BOOL)shutDown:(NSError **)outError;

/** Forces a transmit of all Interrogator data on the device.
 
 Method should be called only when there is a critical need to get Interrogator data to the console.
 
 @return A BOOL value indicating method success. 
 @param outError Out parameter used if an error occurs while transmitting. May be NULL.
 @param delegate The id of the object to call delegate methods on. This needs to implement <AWInterrogatorTransmitterDelegate>.
 */
- (BOOL)Transmit:(NSError **)outError delegate:(id)delegate;

/** Forces a sample of all Interrogator data on the device.
 
 Method should be called only when there is a critical need to get Interrogator data to the console, and used in conjunction with Transmit.
 */
- (void)SampleModules;

@end

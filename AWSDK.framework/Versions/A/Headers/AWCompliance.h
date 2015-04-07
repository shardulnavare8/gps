/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWCompliance.h */


#import <Foundation/Foundation.h>
#import "AWCompliancePayload.h"


/** The notification name for when the device is compromised and user access is restricted. */
extern NSString * const AWComplianceUserAccessRestrictedNotification;

/** The notification name for when the device is compromised and application wipe needed. */
extern NSString * const AWComplianceUserApplicationWipeNotification;

/** The notification name for when the device is compromised and application wipe needed. */
extern NSString * const AWComplianceCustomActionNotification;

/** The notification name for when the AWCompliance Settings are updated */
extern NSString * const AWComplianceSettingsUpdated;

/** The notification name for when the device is compromised and a message needs to be displayed. */
extern NSString *const AWComplianceDisplayMessageNotification;

/** The key used to access the AWAction object stored in the userInfo dictionary of Notifications. */
extern NSString *const AWComplianceUserInfoObjectKey;

typedef enum AWJailBrokenStatus
{
    AWJailBrokenStatusNotAvailable =0,
    AWDeviceNotJailBroken,
	AWDeviceJailBroken
} AWJailBrokenStatus;

/**
 @brief		Compliance service to enforce compromised device restrictions.
 @details	A service that is used to monitor device for compromisation. When device is compromised, notifications are posted.
 @version 3.7.1
 */
@interface AWCompliance : NSObject {
    
}


/** AWCompliance Intializer.
 
 @brief AWCompliance object made by this function.
 @return A newly initialized AWCompliance.
 */
+ (AWCompliance *)sharedInstance;

/**
 * @brief Starts the AWCompliance service with settings defined in the cached SDK Profile
 *        AWCompliance will automatically up be updated with new profiles as they are received.
 * @return A BOOL indicating if the AWCompliance service was started successfully.
 */
+ (BOOL)startService:(NSError**)outError;

/**
 * @brief Stop monitoring the device for compliance
 * @return A BOOL indicating if the AWCompliance service was stop successfully.
 */
+ (BOOL)stopService:(NSError**)outError;

/** Check Device compromisedStatus
 @brief This method will return the JailBroken Status.
 @return AWJailBrokenStatus \nAWDeviceJailBroken if a Jailbreak is detected.
 \nAWDeviceNotJailBroken if a Jailbreak isn't detected.
 */
#if	TARGET_OS_IPHONE
- (AWJailBrokenStatus)jailBrokenStatus;
#endif
@end

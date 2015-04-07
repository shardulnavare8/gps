/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWRestrictions.h */


#import <Foundation/Foundation.h>
#import "AWRestrictionsPayload.h"

/** The key to use when accessing an AWAction passed in the UserInfo object of a AWRestrictions Notification */
extern NSString * const AWRestrictionsActionObjectKey;

/** The notification name for when the device was offline more than allowed and a message is displayed. */
extern NSString * const AWMaxOfflineUsageDisplayMessageNotification;

/** The notification name for when the device was offline more than allowed and user access is restricted. */
extern NSString * const AWMaxOfflineUsageUserAccessRestrictedNotification;

/** The notification name for when the device was offline more than allowed and application wipe needed. */
extern NSString * const AWMaxOfflineUsageApplicationWipeNotification;

/** The notification name for when the device was offline more than allowed and custom action needed. */
extern NSString * const AWMaxOfflineUsageCustomActionNotification;

/** The notification name for when the user has 1 more successful offline login */
extern NSString * const AWMaxOfflineSuccessfulLoginWarningNotification;

/** The notification name for when the maximum number of successful Offline login has been reached */
extern NSString * const AWMaxOfflineSuccessfulLoginReachedNotification;

/** The notification name for when the device is not MDM-Enrolled and and a message is displayed. */
extern NSString * const AWDeviceNotMDMEnrolledDisplayMessageNotification;

/** The notification name for when the device is not MDM-Enrolled and user access is restricted. */
extern NSString * const AWDeviceNotMDMEnrolledUserAccessRestrictedNotification;

/** The notification name for when the device is not MDM-Enrolled and application wipe needed. */
extern NSString * const AWDeviceNotMDMEnrolledApplicationWipeNotification;

/** The notification name for when the device is not MDM-Enrolled and custom action needed. */
extern NSString * const AWDeviceNotMDMEnrolledCustomActionNotification;

/** The notification name for when AWRestrictions settings have been updated */
extern NSString * const AWRestrictionsSettingsUpdatedNotification;

/** The AWRestriction Modes. */
typedef enum {
    
    AWRestrictionModeUnknown = - 1,       /**< The restriction mode has not been determined or is unknown. */
    AWRestrictionModeAllowOffline,        /**< Offline use is allowed. */
    AWRestrictionModeRequireMDMEnrollment /**< The Device MDM-Enrollment is required. */
}
AWRestrictionMode;


/**
 @brief		Restrictions service to enforce accesss restrictions.
 @details	A service that is used to monitor device for various access parameters. When access restrictions are met, notifications are posted.
 @version 3.7.1
 */
@interface AWRestrictions : NSObject {
    
}


/** Indicates if offline mode is allowed. */
@property (nonatomic, readonly) BOOL isOfflineModeCurrentlyEnabled;

/** Indicates if MDM-Enrollment is required. */
@property (nonatomic, readonly) BOOL requiresMDMEnrollment;

/** A boolean indicating if Copy and Cut actions are allowed. */
@property (nonatomic, readonly) BOOL preventCopyAndCut;


/** Restrictions Intializer.
 
 @brief Restrictions object made by this function.
 @param RestrictionsPayload The dictionary representation of settings to create Restrictions.
 @return Newly initialized Restrictions.
 */
+ (AWRestrictions *)sharedInstance;

/**
 * @brief Starts the AWRestrictions service with settings defined in the cached SDK Profile
 *        AWRestrictions will automatically be updated with new profiles as they are received.
 * @return A BOOL indicating if the AWRestrictions service was started successfully.
 */
+ (BOOL)startService:(NSError**)outError;

/**
 * @brief Stop monitoring the device for restrictions
 * @return A BOOL indicating if the AWRestrictions service was stop successfully.
 */
+ (BOOL)stopService:(NSError**)outError;

/**
 @brief Increase the number of successful Offline login count by 1
 
 */
- (void)increaseSuccessfulOfflineLoginCount;

/**
 @brief Decrease the number of successful Offline login count by 1
        The minimum count will be set to 0 if it's decreased to a negative value.
 */
- (void)decreaseSuccessfulOfflineLoginCount;

/**
 @brief The current value of successful Offline login attempt
 @return An integer indicating the number of successful Offline login
 */
- (NSInteger)currentSuccessfulOfflineLoginCount;

/**
 @brief Set the current successful Offline login back to 0
 */
- (void)resetCurrentSuccessfulOfflineLoginCount;

@end

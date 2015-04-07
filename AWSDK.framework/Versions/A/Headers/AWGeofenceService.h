/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWGeofenceService.h */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AWSDK/AWGeofence.h>

/** The notification name for when the device enters a specific geofence section. */
extern NSString *const AWGeofenceServiceDeviceDidEnterGeofenceNotification;

/** The ntoification name for when the device exits a specific geofence section. */
extern NSString *const AWGeofenceServiceDeviceDidExitGeofenceNotification;

/** The userInfo key used to retrieve the array of actions to be executed. */
extern NSString *const AWGeofenceServiceActionsKey;

/** The geofencing error domain. */
extern NSString *const AWErrorDomainGeofence;

/** The geofence section of a device. */
typedef enum
{
	AWGeofenceSectionUnknown = -1,	/**< The geofence section has not been determined or is unknown. */
	AWGeofenceSectionNone,		/**< The device is outside of every geofence section. */
	AWGeofenceSectionInner,		/**< The device is inside the inner geofence section. */
	AWGeofenceSectionMiddle,	/**< The device is inside the middle geofence section. */
	AWGeofenceSectionOuter		/**< The device is inside the outer geofence section. */
}
AWGeofenceSection;

/**
 @brief		Geofencing service to enforce restrictions.
 @details	A service that is used to monitor device location in the sense of a geofence. When location conditions are met, notifications are posted.
 @version 3.7.1
 */
@interface AWGeofenceService : NSObject <CLLocationManagerDelegate>
{
	
}
/** GeofenceService Intializer.
 
 @brief GeofenceService object made by this function.
 @param AWGeofence A model that is used to represent a geofence.
 @return Newly initialized GeofenceService.
 */
@property (nonatomic, retain) AWGeofence *geofence;

/** The device's current section within the geofence. */
@property (nonatomic, readonly) AWGeofenceSection deviceGeofenceSection;

+ (AWGeofenceService *)sharedInstance;

/**
 Starts the geofence service.
 
 @param error An out error to be used if the error fails to start.
 @return A boolean indicating if the service was able to successfully start.
 */
- (BOOL)start:(NSError **)error;

/** Stops the geofence service. */
- (void)stop;

/** Sets the purpose text that will be displayed when location services prompt is presented. 
 
 @param text String to be displayed to user.
 */
- (void)setLocationManagerPurposeText:(NSString *)text;

@end

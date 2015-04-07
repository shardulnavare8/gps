/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWGeofence.h */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AWSDK/AWGeofencePayload.h>

/** The notification posted when AWGeofence settings have been updated */
extern NSString *const AWGeofenceSettingsUpdated;


/**
 @brief		Describes a geofence to be used with `AWGeofenceService`.
 @details	A model that is used to represent a geofence.
 @version 3.7.1
 */
@interface AWGeofence : NSObject
{

}

/** The name of the geofence. */
@property (nonatomic, copy) NSString *name;

/** The center point of the geofence. */
@property (nonatomic, assign) CLLocationCoordinate2D centerCoordinate;

/** The distance (in meters) from the fence's centerpoint to the inner boundary. */
@property (nonatomic, assign) CLLocationDistance innerRadius;

/** The distance (in meters) from the fence's centerpoint to the middle boundary. */
@property (nonatomic, assign) CLLocationDistance middleRadius;

/** The distance (in meters) from the fence's centerpoint to the outer boundary. */
@property (nonatomic, assign) CLLocationDistance outerRadius;

/** Actions to be performed once the device enters the inner fence. */
@property (nonatomic, retain) NSArray *innerFenceEnterActions;

/** Actions to be performed once the device exits the inner fence. */
@property (nonatomic, retain) NSArray *innerFenceExitActions;

/** Actions to be performed once the device enters the middle fence. */
@property (nonatomic, retain) NSArray *middleFenceEnterActions;

/** Actions to be performed once the device exits the middle fence. */
@property (nonatomic, retain) NSArray *middleFenceExitActions;

/** Actions to be performed once the device enters the outer fence. */
@property (nonatomic, retain) NSArray *outerFenceEnterActions;

/** Actions to be performed once the device exits the outer fence. */
@property (nonatomic, retain) NSArray *outerFenceExitActions;

/**
 Helper initializer to create and configure a geo-fence according to a profile payload.
 
 @param payload Geo-fence payload containg properties to be applied.
 @return Newly intialized and configured geo-fence.
 */
- (id)initWithGeofencePayload:(AWGeofencePayload *)payload;

/**
 @return A `CLLocation` object representing the geofence's center. 
 */
- (CLLocation *)centerLocation;

@end

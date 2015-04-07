/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWGeofencePayload.h */

#import <AWSDK/AWProfilePayload.h>
#import <CoreLocation/CoreLocation.h>

@interface AWGeofenceArea : NSObject

@property (nonatomic, readonly) CLLocationCoordinate2D center;
@property (nonatomic, readonly) CLLocationDistance radius;
@property (nonatomic, readonly) NSString *uniqueID;
@property (nonatomic, readonly) NSString *name;

- (id)initWithInfo:(NSDictionary *)info;

@end

/**
 @brief		Geofence payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the geofence group of an SDK profile.
 @version 3.7.1
 */
@interface AWGeofencePayload : AWProfilePayload
{
	
}

/** The name of the geofence. */
@property (nonatomic, readonly) NSString *name;

/** The centerpoint of the geofence. */
@property (nonatomic, readonly) CLLocationCoordinate2D centerCoordinate;

/** The raidus of the inner fence. */
@property (nonatomic, readonly) CLLocationDistance innerFenceRadius;

/** The radius of the middle fence. */
@property (nonatomic, readonly) CLLocationDistance middleFenceRadius;

/** The radius of the outer fence. */
@property (nonatomic, readonly) CLLocationDistance outerFenceRadius;

/** An array of actions to be performed once the device enters the inner fence. */
@property (nonatomic, readonly) NSArray *innerFenceEnterActions;

/** An array of actions to be performed once the device exits the inner fence. */
@property (nonatomic, readonly) NSArray *innerFenceExitActions;

/** An array of actions to be performed once the device enters the middle fence. */
@property (nonatomic, readonly) NSArray *middleFenceEnterActions;

/** An array of actions to be performed once the device exits the middle fence. */
@property (nonatomic, readonly) NSArray *middleFenceExitActions;

/** An array of actions to be performed once the device enters the outer fence. */
@property (nonatomic, readonly) NSArray *outerFenceEnterActions;

/** An array of actions to be performed once the device exits the outer fence. */
@property (nonatomic, readonly) NSArray *outerFenceExitActions;

/** A boolean indicating if geofencing should be enabled. */
@property (nonatomic, readonly) BOOL isEnabled;

@property (nonatomic, readonly) NSArray *geofenceAreas;

@end

/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWDeviceStatusController.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWMacro.h>

@class AWDeviceStatusConfiguration;

/** 
 @brief		Provides an interface to query device enrollment information from the server. Server information can be set by passing an instance of type `AWDeviceStatusConfiguration`.
 @version 3.7.1
 */

@interface AWDeviceStatusController : NSObject
{
    
}

/** @name Configuring a Device Status Controller */
//@{

/** The device status configuration to be used with the device status controller. */
@property (nonatomic, retain) AWDeviceStatusConfiguration *configuration;

//@}

/** @name Creating a Device Status Controller */
//@{

/** The designated initializer to 
 AWDeviceStatusController object is manage to get status of device enrollment with Airwatch console. AWDeviceStatusController is configured through AWDeviceStatusConfiguration object. 
 @return An initlialized device status controller.
 @param configuration a container that holds server details to retrieve device information.
 */
- (id)initWithConfiguration:(AWDeviceStatusConfiguration *)configuration;

//@}

/** @name Obtaining Device Status */
//@{
/** Queries the AirWatch console to determine if the current device is enrolled.
 
 @param callBackBlock The callback block to be executed when a response is received from the AirWatch console, and also get response of enrollment status in boolean object.
 */
- (void)queryDeviceEnrollmentStatus:(void(^)(BOOL enrolled, NSError *error))callBackBlock;

//@}

/** @name Obtaining Device Status */
//@{
/** Queries the AirWatch console to determine if the current device is enrolled.
 
 @param callBackBlock The callback block to be executed when a response is received from the AirWatch console, and also get response of enrollment status in boolean object.
 */
+ (void)queryDeviceEnrollmentStatus:(void(^)(BOOL enrolled, NSError *error))callbackBlock;

//@}

@end

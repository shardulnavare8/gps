/*
 AirWatch iOS Software Development Kit
 Copyright © 2013 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWBeacon.h */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <AWSDK/AWLocationModeTypes.h>
#import <AWSDK/AWMacro.h>

@class AWBeaconConfiguration;

// NSString keys for AWBeacon Notifications
extern NSString *const AWBeaconDidFailToSendNotification;
extern NSString *const AWBeaconDidSendNotification;
extern NSString *const AWBeaconErrorUserInfoKey;

/**
 @brief		The Beacon service is used to send a heartbeat message to AirWatch.
 @details	AWBeacon represent an AirWatch beacon object. Beacon represent static kind of device data like IP Address,MAC Address etc. AWBeacon manage Beacon operation. By using AWBeacon we can start communicating to server and send Beacon to server.
 @version 3.7.1
 */
@interface AWBeacon : NSObject

/**
 NSString object which represent APNS (Apple Push Notification Server) Token.
 */
@property (nonatomic, copy) NSString *APNSToken;

/**
 NSString object which represent bundleIdentifier.
 */
@property (nonatomic, copy) NSString *bundleIdentifier;

/**
 Optional NSString object which contains user emailAddress.
 */
@property (nonatomic, copy) NSString *emailAddress;

/**
 Optional NSString object which contains location groupCode.
 */
@property (nonatomic, copy) NSString *groupCode;

/**
 Optional NSString object which contains user phoneNumber.
 */
@property (nonatomic, copy) NSString *phoneNumber;

/**
 transmitInterval specifies the time Interval in seconds for sending Beacon to server, Means after every specified transmitInterval device send Beacon to server.
 */
@property (nonatomic, assign) NSTimeInterval transmitInterval;

/**
 locationMode is enum object specifies  communication is kicked start or not.
 */
@property (nonatomic, assign) AWLocationMode locationMode;

/**
 The distance in meters for the distance between traveling points, means after specified distance change, device will send Beacon to server.
 */
@property (nonatomic, assign) CLLocationDistance locationDistanceFilter;

/**
 Specifies the distance in meter for location accuracy.
 */
@property (nonatomic, assign) CLLocationAccuracy locationDesiredAccuracy;

/** @name Beacon Initialization */
//@{

/** 
 This method will initialize the Beacon with basic values to begin with. All other values can be manually set.
 
 @param token This is a required APNS (Apple Push Notification Service) token that will be used for communication between the app and the server.
 @param interval This is a required time interval (in seconds) that specify how often a beacon should be send to the server
 @param locationGroup An optional value that can be used to send user's location group to the server
 @param locationMode An optional value, if enabled, will allow the beacon to be sent to the server even when the app is in background.
 @param distanceFilter Ano optional value to specify how often to update the user's location. For best result, the distance should not be less then 25 meters. The default value is 50 meters.
 */
- (id)initWithAPNSToken:(NSString *)token
       transmitInterval:(NSTimeInterval)interval
          locationGroup:(NSString *)lg
           locationMode:(AWLocationMode)locationModeIn
               distance:(CLLocationDistance)distanceFilter;

/**
 Start the beacon and set it ready to send information.
 */
- (void)start;

/**
 Stop the beacon
 */
- (void)stop;

/**
 Send the beacon to the server
 */
- (void)send;

/**
 A class method to allow the app to access the time that the last successful beacon was sent
 */
+ (NSDate *)lastSuccessfulBeaconTimeStamp;


/**
 The class method based implementation has been deprecated and will be removed in the next major release of the SDK.
 Please create a Beacon instance and use the corresponding methods to start/stop the beacon service and to send the
 beacon.
 */


/** By using startUpWithConfiguration, user can Starts the Beacon module. This method is configured by AWBeaconConfiguration object.This method returns Boolean value that indicate wheather beacon is started or not.
 
 @param configuration AWBeaconConfiguration object is passed for configuration, which contains the server,device, user and location configuration data. The configuration to be used with the Beacon.
 @param outError  It contains error description in case of Beacon module can not be started, otherwise it is NIL.
 //The error that occurred in the case that the Beacon module cannot be started.
 @return Returns YES if the Beacon module was started, otherwise NO.
 
 */
+ (BOOL)startUpWithConfiguration:(AWBeaconConfiguration *)configuration
						   error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("Create an instance of AWBeacon and configure the object directly. Use -start to start the Beacon Service.");

/** Shuts down an active Beacon module and return the boolean value which indicate the status of Beacon shutdown.
 
 @param outError It contains error description in case of Beacon module can not be shutsown, otherwise it is NIL.
 //The error that occurred in the case that the Beacon module cannot be shutdown.
 @return Returns YES if the Beacon module was shutdown, otherwise NO.
 */
+ (BOOL)shutDown:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use instance method -stop.");



/** Forces a Beacon to send.
 
 @attention It can not send Beacon, if Beacon module is already started. So if user want to forcefuly send this, first of all user has to shutDown the module.
 @param outError The error that occurred in the case that the Beacon message failed to send.
 @return Returns YES if the Beacon was sent successfully, otherwise NO.
 */
+ (BOOL)send:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use instance method -send.");

@end

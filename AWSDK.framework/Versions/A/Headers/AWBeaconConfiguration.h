/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWBeaconConfiguration.h */

#import <AWSDK/AWLocationModeTypes.h>

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <AWSDK/AWMacro.h>

extern NSInteger const kAWBeaconIntervalDisabled;

/** 
 @brief		Configuration model used to configure an `AWBeacon`. 
 @details	AWConfiguration contains all the settings needed to create and configure an AWBeacon Module. AWConfiguration contains the server,device, user and location setting data.AWConfiguration is module, which user need to ready before connecting to Beacon module."Thread Background" feature available only for ios 4.0 or letter. 
 @version 3.7.1
 */
AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use AWBeacon -initWithAPNSToken:transmitInterval:locationGroup:locationMode:distance:")
@interface AWBeaconConfiguration : NSObject <NSCopying>
{
    
}

/**
 NSString object which represent server name, by which Beacon module will communicate.
 @details **DEPRECATED**: Configure the Device Services host in AWServer.
 */
@property (nonatomic, copy) NSString *host AW_DEPRECATED_ATTRIBUTE_MESSAGE("Configure the Device Services host in AWServer.");

/**
 NSString object represent the applicationPath.
 @details **DEPRECATED**: Configure the Beacon path in AWServer.
 */
@property (nonatomic, copy) NSString *applicationPath AW_DEPRECATED_ATTRIBUTE_MESSAGE("Configure the Beacon path in AWServer.");

/** 
 NSString object which represent APNS (Apple Push Notification Server) Token.
 */
@property (nonatomic, copy) NSString *APNSToken;

/**
 NSString object which represent bundleIdentifier.
 */
@property (nonatomic, copy) NSString *bundleIdentifier;

/**
 NSString object represent checkInAction.
 */
@property (nonatomic, copy) NSString *checkInAction;

/**
 NSString object which contains user emailAddress.
 */
@property (nonatomic, copy) NSString *emailAddress;

/**
 NSString object which contains location groupCode.
 */
@property (nonatomic, copy) NSString *groupCode;

/**
 NSString object which contains user phoneNuumber.
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

@property (nonatomic, assign)AWTraceLevel traceLevel;

/**
 Boolean object indicate that whether backgroundingEnabled or not.
 @attention backgroundingEnabled feature provide only ios 4.0 or letter version device.
 */
@property (nonatomic, assign) BOOL backgroundingEnabled __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_4_0);

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
/**
 *  @attention This is for iOS 4.0 earlier version. Create a beacon with these configuration.
 *  @details   **DEPRECATED**: Use AWServer to configure the host and application path.
 *
 *  @param host The server for the beacon to communicate with
 *  @param applicationPath The path to the application
 *  @param checkInAction Check in action
 *  @param bundleIdentifier The app bundle identifier
 *  @param APNSToken The Apple Push Notification server token
 *  @param groupCode Location Group code
 *  @param emailAddres Email address of user
 *  @param phoneNumber Phone number of user
 *  @param transmitInterval The time interval, in seconds, to transmit information between beacon and server
 *  @param locationMode The mode at which communication is kicked start or not
 *  @param locationDistanceFilter The distance between traveling points
 *  @param backgroundingEnabled Allow the app to run in the background or not
 *  @return Returns the beaconConfiguration object, by using we can start communicating beacon to server.
 */
- (id)initWithHost:(NSString *)host 
   applicationPath:(NSString *)applicationPath 
     checkInAction:(NSString *)checkInAction
  bundleIdentifier:(NSString *)bundleIdentifier
         APNSToken:(NSString *)APNSToken
         groupCode:(NSString *)groupCode
      emailAddress:(NSString *)emailAddress   
       phoneNumber:(NSString *)phoneNumber
  transmitInterval:(NSTimeInterval)transmitInterval
      locationMode:(AWLocationMode)locationMode
locationDistanceFilter:(CLLocationDistance)locationDistanceFilter
backgroundingEnabled:(BOOL)backgroundingEnabled AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use AWServer to configure the host and application path.");

#else

/** 
 *  @attention Create a beacon with these configurations for ios device 4.0 or letter version.
 *  @details   **DEPRECATED**: Use AWServer to configure the host and application path.
 *
 *  @param host The server for the beacon to communicate with
 *  @param applicationPath The path to the application
 *  @param checkInAction Check in action
 *  @param bundleIdentifier The app bundle identifier
 *  @param APNSToken The Apple Push Notification server token
 *  @param groupCode Location Group code
 *  @param emailAddres Email address of user
 *  @param phoneNumber Phone number of user
 *  @param transmitInterval The time interval, in seconds, to transmit information between beacon and server
 *  @param locationMode The mode at which communication is kicked start or not
 *  @param locationDistanceFilter The distance between traveling points
 *  @return Returns the beaconConfiguration object, by using we can start communicating beacon to server.
 */
- (id)initWithHost:(NSString *)host 
   applicationPath:(NSString *)applicationPath 
     checkInAction:(NSString *)checkInAction
  bundleIdentifier:(NSString *)bundleIdentifier
         APNSToken:(NSString *)APNSToken
         groupCode:(NSString *)groupCode
      emailAddress:(NSString *)emailAddress   
       phoneNumber:(NSString *)phoneNumber
  transmitInterval:(NSTimeInterval)transmitInterval
      locationMode:(AWLocationMode)locationMode
locationDistanceFilter:(CLLocationDistance)locationDistanceFilter AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use AWServer to configure the host and application path.");

#endif

#if __IPHONE_4_0 <= __IPHONE_OS_VERSION_MAX_ALLOWED
/**
 *  @attention This is for iOS 4.0 earlier version. Create a beacon with these configuration.
 *
 *  @param checkInAction Check in action
 *  @param bundleIdentifier The app bundle identifier
 *  @param APNSToken The Apple Push Notification server token
 *  @param groupCode Location Group code
 *  @param emailAddres Email address of user
 *  @param phoneNumber Phone number of user
 *  @param transmitInterval The time interval, in seconds, to transmit information between beacon and server
 *  @param locationMode The mode at which communication is kicked start or not
 *  @param locationDistanceFilter The distance between traveling points
 *  @param backgroundingEnabled Allow the app to run in the background or not
 *  @return Returns the beaconConfiguration object, by using we can start communicating beacon to server.
 */
- (id)initWithCheckInAction:(NSString *)checkInAction
  bundleIdentifier:(NSString *)bundleIdentifier
         APNSToken:(NSString *)APNSToken
         groupCode:(NSString *)groupCode
      emailAddress:(NSString *)emailAddress   
       phoneNumber:(NSString *)phoneNumber
  transmitInterval:(NSTimeInterval)transmitInterval
      locationMode:(AWLocationMode)locationMode
locationDistanceFilter:(CLLocationDistance)locationDistanceFilter
backgroundingEnabled:(BOOL)backgroundingEnabled;

#else

/** 
 *  @attention Create a beacon with these configurations for ios device 4.0 or letter version.
 *
 *  @param checkInAction Check in action.
 *  @param bundleIdentifier The app bundle identifier.
 *  @param APNSToken The Apple Push Notification server token.
 *  @param groupCode Location Group code.
 *  @param emailAddres Email address of user.
 *  @param phoneNumber Phone number of user.
 *  @param transmitInterval The time interval, in seconds, to transmit information between beacon and server.
 *  @param locationMode The mode at which communication is kicked start or not.
 *  @param locationDistanceFilter The distance between traveling points.
 *  @return Returns the beaconConfiguration object, by using we can start communicating beacon to server.
 */
- (id)initWithCheckInAction:(NSString *)checkInAction
  bundleIdentifier:(NSString *)bundleIdentifier
         APNSToken:(NSString *)APNSToken
         groupCode:(NSString *)groupCode
      emailAddress:(NSString *)emailAddress   
       phoneNumber:(NSString *)phoneNumber
  transmitInterval:(NSTimeInterval)transmitInterval
      locationMode:(AWLocationMode)locationMode
locationDistanceFilter:(CLLocationDistance)locationDistanceFilter;

#endif

@end

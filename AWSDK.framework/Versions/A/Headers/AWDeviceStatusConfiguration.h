/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWDeviceStatusConfiguration.h */

/**
 @brief		Configuration used to setup a `AWDeviceStatusController`.
 @details	`AWDeviceStatusConfiguration` is a container that holds server details to retrieve device information.
 @version 3.7.1
 */
@interface AWDeviceStatusConfiguration : NSObject
{
    
}

/** The URL of the AirWatch device services.
 
 This value must conform to RFC 1808. Please see http://www.ietf.org/rfc/rfc1808.txt for more information.
 
 */
@property (nonatomic, copy) NSURL *deviceServicesURL AW_DEPRECATED_ATTRIBUTE;

/** The path of the device info endpoint. 
 
 The default value is DeviceInfo.svc. 
 */
@property (nonatomic, copy) NSString *endpointPath AW_DEPRECATED_ATTRIBUTE;

/** The device status service action to perform.
 
 The default is GetDeviceStatus.
 */
@property (nonatomic, copy) NSString *deviceStatusAction;

/** 
 
 The designated intializer to create device management configurations.
 
 @brief AWDeviceStatusController can be configured by getting AWDeviceStatusConfiguration object.
 Creates a device management configuration with the specified parameters.
 
 @return A new device management configuration object.
 @param hostName The host name of the AirWatch console conforming to RFC 1808.
 @param endpointPath The endpoint path of the device info service.
 @param deviceStatusAction The device status service action to perform.
 
 */
- (id)initWithHostName:(NSString *)hostName endpointPath:(NSString *)endpointPath deviceStatusAction:(NSString *)deviceStatusAction;

@end

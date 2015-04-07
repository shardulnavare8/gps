/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 Unless required by applicable law, this Software Development Kit and sample code is distributed 
 on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
 AirWatch expressly disclaims any and all liability resulting from User’s use of this Software 
 Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWServer.h */

#import <AWSDK/AWMacro.h>

/*! 
 @constant
 @brief Notification that is posted when the server's reachability status changes.
 */
extern NSString *const AWServerReachabilityChangedNotification;

/*!
 @constant
 @brief Key used to access the version of the AirWatch Console sent in all response headers.
 */
extern NSString *const kAWConsoleVersionKey;

extern NSString *const kAWSDKVersionKey;

typedef struct
{
    uint major;
    uint minor;
    uint release;
    uint hotfix;
}AWConsoleVersion;

/*!
 @brief		Central point of configuration for the AirWatch instance.
 @details	Configuration class used to set the AirWatch Device Services URL and endpoint locations.
 @version 3.7.1
 */
@interface AWServer : NSObject <NSCoding>
{
	
}

/*!
 Returns the shared server seeded with default values.
 */
+ (AWServer *)sharedInstance;

/*!
 The URL of Device Services.
 */
@property (nonatomic, copy) NSURL *deviceServicesURL;

/*! An additional URL path componenet pointing to a web service.  */
@property (nonatomic, copy) NSString *servicePath;
//@}

/*!
 The relative path to the asset management endpoint.
 
 Defaults to "/AssetManagement.aws".
 */
@property (nonatomic, copy) NSString *assetManagementPath;

/*!
 The relative path to the old asset management endpoint.
 
 Defaults to "/AssetManagement.svc".
 */
@property (nonatomic, copy) NSString *oldAssetManagementPath;

/*!
 The relative path to the beacon endpoint.
 
 Defaults to "/AirWatchBeacon.svc".
 */
@property (nonatomic, copy) NSString *beaconPath;

/*!
 The relative path to the command processor endpoint.
 
 Defaults to "/AppleMDM/Processor.aspx".
 */
@property (nonatomic, copy) NSString *commandProcessorPath;


/*!
 The relative path to the 'new' command processor endpoint.
 
 Defaults to "/awmdmsdk/v3/processor".
 */
@property (nonatomic, copy) NSString *commandProcessorNewPath;


/*!
 The relative path to the content handler endpoint.
 
 Defaults to "/Content/ContentHandler.ashx".
 */
@property (nonatomic, copy) NSString *contentHandlerPath;

/*!
 The relative path to the repository handler endpoint.
 
 Defaults to "/ContentRepository.aws".
 */
@property (nonatomic, copy) NSString *contentRepositoryPath;

/*!
 The relative path to the device info endpoint.
 
 Defaults to "/DeviceInfo.svc";
 */
@property (nonatomic, copy) NSString *deviceInfoPath;

/*!
 @deprecated
 @brief The relative path to the HTTP Interogator endpoint.
 
 This is optional and only is used when using the HTTP Interogator endpoint.
 
 @details DEPRECATED: Please use dataSamplerHTTPPath instead.
 */
@property (nonatomic, copy) NSString *interrogatorHTTPPath AW_DEPRECATED_ATTRIBUTE_MESSAGE("Please use dataSamplerHTTPPath instead.");

/*!
 The relative path to the HTTP datasampler endpoint.
 
 This is optional and only is used when using the HTTP datasampler endpoint.
 */
@property (nonatomic, copy) NSString *dataSamplerHTTPPath;

/*!
 The port of of the interrogator service.
 
 Defaults to "8087".
 */
@property (nonatomic, assign) NSUInteger interrogatorPort;

/*!
 The relative path to the keystore endpoint.
 
 Defaults to "/keystore.svc".
 */
@property (nonatomic, copy) NSString *keystorePath;

/*!
 The relative path to the logging endpoint.
 
 Defaults to "/Logging.aspx".
 */
@property (nonatomic, copy) NSString *loggingPath;

/**
 The relative path to the open enrollment endpoint.
 
 Defaults to "/iOS/OpenEnrollment.aspx".
 */
@property (nonatomic, copy) NSString *openEnrollmentPath;

/** 
 The relative path to the screen capture endpoint.
 
 Defaults to "/ScreenCapture.ashx".	
 */
@property (nonatomic, copy) NSString *screenCapturePath;

/**
 The relative path to the settings endpoint.
 
 Defaults to "/iOS/SettingsEndpoint.aspx".
 */
@property (nonatomic, copy) NSString *settingsPath;

/**
 The relative path to the secure channel connection endpoint.
 
 Defaults to "/ConnectionEndpoint.aws".
 */
@property (nonatomic, copy) NSString *secureChannelConnectionPath;

/**
 The relative path to the authentication endpoint.
 
 Defaults to "AuthenticationEndpoint.aws".
 */
@property (nonatomic, copy) NSString *authenticationPath;

/**
 The relative path to the server health endpoing.
 
 Defaults to "/awhealth".
 */
@property (nonatomic, copy) NSString *healthPath;

/**
 Determines if the device can reach AirWatch Device Services.
 */
@property (nonatomic, readonly) BOOL canReachDeviceServices;

/*!
 @brief Represents the the version of the AirWatch Console.
 @return AWConsoleVersion struct
 @discussion
    This property will return an AWConsoleVersion struct with all values set to 0 if no responses 
    have been received from the Console. Otherwise, a version string in the following format will 
    be returned. 
    <strong>When communicating with a console not running AirWatch 6.4 or greater, the struct will
    always be returned with 0 values.</strong>
 @availability AirWatch 6.4+
 */
- (AWConsoleVersion)consoleVersion;

/*!
 @brief whether or not console support hmac authentication
 @return true if we can authenticate with hmac, false if we have to use auth-token
 @discussion
 Even though hmac has been supported for a while, not until 6.4 do we implement hmac authentication
 for retrieve content, this let us check the compatibility of the feature based on the console version
 @availability AirWatch 6.4+
 */
+ (BOOL)doesConsoleSupportHmacAuthentication;

/*!
 @brief whether or not console support v2 profile
 @return true if console can send down sdk v2 profile, false otherwise
 @availability AirWatch 6.5+
 */
+ (BOOL)doesConsoleSupportV2Profile;

/*!
 @brief Sets the device services url property.
 @param deviceServicesURL the url to be used
 @param block a block that will be called once the console version has been determined. 
        This value is safe to be nil.
 @discussion This method sets the value of this receiver's deviceServicesURL property. It will
 also determine the version of the console located at the specified URL. The compeletion block should
 be used to if there is any code execution that is dependent on the console version. If you don't 
 care what version of the console you are connecting to pass nil for the block value, or simply use
 the default property mutator.
 */
- (void)setDeviceServicesURL:(NSURL *)deviceServicesURL completion:(void(^)(void))block;

@end

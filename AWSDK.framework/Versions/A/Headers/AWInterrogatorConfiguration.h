/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWInterrogatorConfiguration.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWCommon.h>
#import <AWSDK/AWDataSamplerTypes.h>
#import <AWSDK/AWMacro.h>

#define DEFAULT_HTTP_SCHEME  @"http"

@class AWInterrogatorConnection;

/**
 @deprecated
 @brief AWInterrogatorConfiguration is the property container for configurable Interrogator settings.
		\n
		User can specify the sampling modules to be started, destination server, sampling intervals , transmission intervals.
 
 @details DEPRECATED: Please use AWDataSamplerConfiguration instead.
 @version 3.7.1
 */
AW_DEPRECATED_ATTRIBUTE_MESSAGE("Please use AWDataSamplerConfiguration instead.")
@interface AWInterrogatorConfiguration : NSObject
{
	AWInterrogatorConnection *interrogatorConnection;
	AWDataSamplerModuleBitmask sampleModules;
	NSTimeInterval defaultSampleInterval;
	NSTimeInterval transmitInterval;
	enum AWTraceLevel traceLevel;
	NSString* urlScheme;
}

/** @name Configuration an Interrogator Configuration */
//@{

/** The server connection information used to send the Interrogator transmission. */
@property (nonatomic, retain) AWInterrogatorConnection *interrogatorConnection AW_DEPRECATED_ATTRIBUTE;

/** A bitmask whose flags specify which modules to use. See `Sample Modules` for bitmask constants. */
@property (nonatomic, assign) AWDataSamplerModuleBitmask sampleModules;

/** The time (in seconds) between Interrogator samples. */
@property (nonatomic, assign) NSTimeInterval defaultSampleInterval;

/** The time (in seconds) between Interrogator transmissions. */
@property (nonatomic, assign) NSTimeInterval transmitInterval;

/** The error and information logging level the Interrogator module is run at. */
@property enum AWTraceLevel traceLevel;

/** The URL scheme to be used for http Interrogator transmitter. */
@property (nonatomic, retain) NSString *urlScheme;

//@}

/** @name Creating an Interrogator Configuration */
//@{

/**
 @details DEPRECATED:
 @return Returns an AWInterrogatorConfiguration initialized with the specified values.
 @param theHost The host name (IP or DNS) of the end point.
 @param thePort The port number of the end point.
 @param sampleModules A bitmask whose flags specify which modules to use. See `Sample Modules` for bitmask constants.
 @param defaultSampleInterval The time in seconds between Interrogator samples for all modules by default.
 @param defaultTransmitInterval The time in seconds between Interrogator transmissions for all modules by default.
 @param theTraceLevel The error and information logging level the Interrogator module is run at.
 */

- (id)initWithHost:(NSString *)theHost
port:(NSInteger)thePort
sampleModules:(AWDataSamplerModuleBitmask)module
defaultSampleInterval:(NSTimeInterval)sampleInterval
defaultTransmitInterval:(NSTimeInterval)theTransmitInterval
traceLevel:(enum AWTraceLevel)theTraceLevel AW_DEPRECATED_ATTRIBUTE;

/**
 @return Returns an AWInterrogatorConfiguration initialized with the specified values.
 
 @param sampleModules A bitmask whose flags specify which modules to use. See `Sample Modules` for bitmask constants.
 @param defaultSampleInterval The time in seconds between Interrogator samples for all modules by default.
 @param defaultTransmitInterval The time in seconds between Interrogator transmissions for all modules by default.
 @param theTraceLevel The error and information logging level the Interrogator module is run at.
 */
- (id)initWithSampleModules:(AWDataSamplerModuleBitmask)module
      defaultSampleInterval:(NSTimeInterval)sampleInterval
    defaultTransmitInterval:(NSTimeInterval)theTransmitInterval
                 traceLevel:(enum AWTraceLevel)theTraceLevel;

//@}

@end

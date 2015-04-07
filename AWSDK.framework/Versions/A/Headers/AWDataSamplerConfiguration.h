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

@class AWDataSamplerConnection;

/**
 @brief AWDataSamplerConfiguration is the property container for configurable DataSampler settings.
 User can specify the sampling modules to be started, destination server, sampling intervals , transmission intervals.
 @version 3.7.1
 */
@interface AWDataSamplerConfiguration : NSObject
{
	AWDataSamplerConnection *dataSamplerConnection;
	AWDataSamplerModuleBitmask sampleModules;
	NSTimeInterval defaultSampleInterval;
	NSTimeInterval transmitInterval;
	enum AWTraceLevel traceLevel;
	NSString* urlScheme;
}

/** @name Configuration an DataSampler Configuration */
//@{

/** The server connection information used to send the DataSampler transmission. */
@property (nonatomic, retain) AWDataSamplerConnection *dataSamplerConnection AW_DEPRECATED_ATTRIBUTE;

/** A bitmask whose flags specify which modules to use. See `Sample Modules` for bitmask constants. */
@property (nonatomic, assign) AWDataSamplerModuleBitmask sampleModules;

/** The time (in seconds) between DataSampler samples. */
@property (nonatomic, assign) NSTimeInterval defaultSampleInterval;

/** The time (in seconds) between DataSampler transmissions. */
@property (nonatomic, assign) NSTimeInterval transmitInterval;

/** The error and information logging level the DataSampler module is run at. */
@property enum AWTraceLevel traceLevel;

/** The URL scheme to be used for http DataSampler transmitter. */
@property (nonatomic, retain) NSString *urlScheme;

//@}

/** @name Creating an DataSampler Configuration */
//@{

/**
 @details DEPRECATED:
 @return Returns an AWDataSamplerConfiguration initialized with the specified values.
 @param theHost The host name (IP or DNS) of the end point.
 @param thePort The port number of the end point.
 @param sampleModules A bitmask whose flags specify which modules to use. See `Sample Modules` for bitmask constants.
 @param defaultSampleInterval The time in seconds between DataSampler samples for all modules by default.
 @param defaultTransmitInterval The time in seconds between DataSampler transmissions for all modules by default.
 @param theTraceLevel The error and information logging level the DataSampler module is run at.
 */

- (id)initWithHost:(NSString *)theHost
port:(NSInteger)thePort
sampleModules:(AWDataSamplerModuleBitmask)module
defaultSampleInterval:(NSTimeInterval)sampleInterval
defaultTransmitInterval:(NSTimeInterval)theTransmitInterval
traceLevel:(enum AWTraceLevel)theTraceLevel AW_DEPRECATED_ATTRIBUTE;

/**
 @return Returns an AWDataSamplerConfiguration initialized with the specified values.
 
 @param sampleModules A bitmask whose flags specify which modules to use. See `Sample Modules` for bitmask constants.
 @param defaultSampleInterval The time in seconds between DataSampler samples for all modules by default.
 @param defaultTransmitInterval The time in seconds between DataSampler transmissions for all modules by default.
 @param theTraceLevel The error and information logging level the DataSampler module is run at.
 */
- (id)initWithSampleModules:(AWDataSamplerModuleBitmask)module
      defaultSampleInterval:(NSTimeInterval)sampleInterval
    defaultTransmitInterval:(NSTimeInterval)theTransmitInterval
                 traceLevel:(enum AWTraceLevel)theTraceLevel;

//@}

@end

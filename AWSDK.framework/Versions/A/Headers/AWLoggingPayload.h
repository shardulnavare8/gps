/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWLoggingPayload.h */

#import <AWSDK/AWProfilePayload.h>
#import <AWSDK/AWLog.h>

/**
 @brief		Logging payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the Logging group of an SDK profile.
 @version 3.7.1
 */

@interface AWLoggingPayload : AWProfilePayload

/** An AWLogTraceLevel that defines the logging module's trace level. */
@property (nonatomic, readonly) AWLogLevel loggingLevel;

/** A boolean that defines if logs should only be sent while connected to wifi. */
@property (nonatomic, readonly) BOOL sendLogsOverWifiOnly;

@end

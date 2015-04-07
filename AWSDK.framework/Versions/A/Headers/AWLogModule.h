/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWLogModule.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWLog.h>

/**
 @brief		Log module.
 @details	Model representing a logging module.
 @version 3.7.1
 */
@interface AWLogModule : NSObject
{
    
}

/** Numeric identifier of the logging module. */
@property (nonatomic, assign) NSInteger identifier;

/** Name of the logging module. */
@property (nonatomic, copy) NSString *name;

/** Trace level of the logging module. */
@property (nonatomic, assign) AWLogLevel traceLevel;

@end

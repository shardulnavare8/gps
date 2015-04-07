/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWCrashLogReporter.h */


#import <Foundation/Foundation.h>


/**
 * @version 3.7.1
 */
@interface AWCrashLogReporter : NSObject


/** Enables the crash reporter and registers for crash tracking.
 
 Method should be called when the host application is ready to start crash tracking.
 
 @return A BOOL value indicating registration was a success or failure.
 @param outError Out parameter used if an error occurs while registering for crash tracking. May be NULL.
 */
- (BOOL)startUp:(NSError **)outError;


//- (BOOL)shutDown:(NSError **)outError;

/**
 
 @brief Returns YES if the application has previously crashed and an pending crash report is available.
 */
- (BOOL)hasPendingCrashReport;

/**
 
 @brief If an application has a pending crash report, this method crash reporting and cleanup.
 */
- (void)reportCrashLogToConsole;


@end

/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on 
 an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
 AirWatch expressly disclaims any and all liability resulting from User’s use of this Software 
 Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 
 */

/*! \file AWLog.h */ 

#import <Foundation/Foundation.h>
#import <AWSDK/AWMacro.h>

/**
 @constant  console notification of airwatch log sent
 */
extern NSString *const AWLogDidSendToAirWatchConsoleNotification;

/**
 @constant  console notification of airwatch log sent fail
 */
extern NSString *const AWLogDidFailToSendToAirWatchConsoleNotification;

/**
 @constant console notification of device log sent successfully
 */
extern NSString *const AWDeviceLogDidSendToAirWatchConsoleNotification;

/**
 @constant console notification of device log sent fail
 */
extern NSString *const AWDeviceLogDidFailToSendToAirWatchConsoleNotification;

/**
 @enum AWLogTraceLevel              Enumeration that defines the logging module's trace level.
 */
AW_DEPRECATED_ATTRIBUTE
typedef enum AWLogTraceLevel
{
	AWLogTraceLevelOff = 0, /** Output no tracing and debugging messages. */
	AWLogTraceLevelError,   /** Output error-handling messages. */
	AWLogTraceLevelWarning, /** Output warnings and error-handling messages.*/
	AWLogTraceLevelInfo,    /** Output informational messages, warnings, and error-handling messages.*/
	AWLogTraceLevelVerbose  /** Output all debugging and tracing messages.*/
}
AWLogTraceLevel;

/**
 @enum AWLogLevel Enumeration that defines the logging levels.
 */
typedef enum
{
    AWLogLevelOff       = 0,
    AWLogLevelError = 1,    /** Used for logging error messages */
    AWLogLevelWarning = 2,  /** Used for logging warning messages */
    AWLogLevelInfo = 3,     /** Used for logging informational messages */
    AWLogLevelVerbose = 4   /** Used for logging verbose messages */
    
} AWLogLevel;


typedef enum
{
    AWLogOutputDestinationNone              = 1 << 0, /* Logs won't be displayed anywhere. */
    AWLogOutputDestinationDeviceConsole     = 1 << 1, /* Logs will be written to stdout */
    AWLogOutputDestinationLogFile           = 1 << 2, /* Logs with be written to disk */

} AWLoggingOutputDestination;

#ifdef __OBJC__
#define AWLogVerbose(fmt,...) [[AWLog sharedInstance] logWithLogLevel:AWLogLevelVerbose \
                                methodName:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
                                line:__LINE__ message:[NSString stringWithFormat:(fmt), ##__VA_ARGS__]]

#define AWLogInfo(fmt,...) [[AWLog sharedInstance] logWithLogLevel:AWLogLevelInfo \
                            methodName:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
                            line:__LINE__ message:[NSString stringWithFormat:(fmt), ##__VA_ARGS__]]

#define AWLogWarning(fmt,...) [[AWLog sharedInstance] logWithLogLevel:AWLogLevelWarning \
                                methodName:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
                                line:__LINE__ message:[NSString stringWithFormat:(fmt), ##__VA_ARGS__]]

#define AWLogError(fmt,...) [[AWLog sharedInstance] logWithLogLevel:AWLogLevelError \
                                methodName:[NSString stringWithFormat:@"%s",__PRETTY_FUNCTION__] \
                                line:__LINE__ message:[NSString stringWithFormat:(fmt), ##__VA_ARGS__]]
#endif



/**
 @attention	Please note that AWLog is not thread-safe. Any calls to AWLog should be made on the main thread.
 @brief		AWLog is an utility class, through which we can get specific log of SDK's functionality. Log is very handy way to trace any system's status and through which we can get the senario of any functionalities.
 @discussion In order for the Logging module to function properly, Logging must be enabled in AirWatch console for your 
 location group.
 @version 3.7.1
 */
@interface AWLog : NSObject

/**
 @property outputDestinationMask
 @brief used to specify where your log statements will be written. The value is a bitmask therefore multiple options
 may exist together.
 @discussion If AWLogOutputDestinationNone is included at all, there will NOT BE ANY OUTPUT.
 */
@property (nonatomic, assign) AWLoggingOutputDestination outputDestinationMask;

/**
 Initializes the Logging module for use.
 @return AWLog singleton.
 */
+ (AWLog *)sharedInstance;

/**
 Writes a log statement to the output idicated by outputDesitinationMask.
 
 @param logLevel - The severity of the statement.
 @param methodName - The name of the method where this method is being called from.
 @param lineNumber - The line number of this statement.
 @message - The statement to be written.
 
 @discussion Four macros have been defined for your convience which match up to the four valid log levels.
 AWLogVerbose AWLogInfo AWLogWarning and AWLogError. These macros can be used exactly as NSLog is used.
 */
- (void)logWithLogLevel:(NSInteger)logLevel
             methodName:(NSString *)methodName
                   line:(NSUInteger)lineNumber
                message:(NSString *)message;

/**
 Sends a device log to the AirWatch console.
 
 @param completion - The completion block called once the operation has finished. Two parameters are provided to the
 block.
 BOOL success indicates if the logs were uploaded successfully.
 NSError error will be provided if an error occured. nil otherwise.
 */

- (void)sendDeviceLogsWithCompletion:(void(^)(BOOL success, NSError *error))completion;

/**
 Sends application level logs to the AirWatch console. Use this to upload log statements created with 
 -logWithLogLevel:methodName:line:message:
 
 @param completion - The completion block called once the operation has finished. Two parameters are provided to the
 block.
 BOOL success indicates if the logs were uploaded successfully.
 NSError error will be provided if an error occured. nil otherwise.
 
 @params completion
 */

- (void)sendApplicationLogsWithCompletion:(void(^)(BOOL success, NSError *error))completion;



/*
 
 *******************
 *   DEPRECATED    *
 *******************
 
 All of the methods below are DEPRECATED. Please use the singleton object by calling
 sharedInstance and use the instance methods above.
 */

/** @name Logging Module Management */
//@{

/** Initializes the Logging module for use.
 
 @return Boolean variable indicating the method success status.
 @param outError Out parameter used if an error occurs while processing the message. May be NULL.
 */

+ (BOOL)startUp:(NSError **)outError AW_DEPRECATED_ATTRIBUTE;

/** Closes all network and database connections and frees any allocated memory.
 
 Method should be called when the host application no longer needs the capabilities of the Logging module.
 
 @return Boolean variable indicating the method success status.
 @param outError Out parameter used if an error occurs while processing the message. May be NULL.
 */

+ (BOOL)shutDown:(NSError **)outError AW_DEPRECATED_ATTRIBUTE;

/**
 Creates, and adds, a logging module to the list of registered modules.
 
 @return Boolean variable indicating the method success status.
 @param moduleName The name of the module to be registered.
 @param traceLevel The requested Trace Level for the requesting module.
 @param outError Out parameter used if an error occurs while processing the message. May be NULL.
 */

+ (BOOL)registerModule:(NSString *)moduleName traceLevel:(AWLogTraceLevel)traceLevel error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE;

/** @name Logging Messages */
//@{

/**
 Writes the requested message to the log if the requesting module's trace level is set to Verbose or higher.
 
 In the event a message is sent to this method without the Logging module being first initialized, the message will be written to the device console through the NSLog facility.
 
 @return Boolean variable indicating the method success status.
 @param theRequestingModule	The name of the module requesting the logging operation.
 @param theMethodName The name of the method within the module requesting the logging operation.
 @param theMessage The data logged.
 @param outError Out parameter used if an error occurs while processing the message.  May be NULL.
 */

+ (BOOL)logVerbose:(NSString *)moduleName methodName:(NSString *)methodName message:(NSString *)message error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("logWithLogLevel:methodName:line:message:");

/**
 Writes the requested message to the log if the requesting module's trace level is set to Info or higher.
 
 In the event a message is sent to this method without the Logging module being first initialized, the message will be written to the device console through the NSLog facility.
 
 @return Boolean variable indicating the method success status.
 @param theRequestingModule	The name of the module requesting the logging operation.
 @param theMethodName The name of the method within the module requesting the logging operation.
 @param theMessage The data logged.
 @param outError Out parameter used if an error occurs while processing the message.  May be NULL.
 */

+ (BOOL)logInfo:(NSString *)moduleName methodName:(NSString *)methodName message:(NSString *)message error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("logWithLogLevel:methodName:line:message:");

/**
 Writes the requested message to the log if the requesting module's trace level is set to Warning or higher.
 
 In the event a message is sent to this method without the Logging module being first initialized, the message will be written to the device console through the NSLog facility.
 
 @return Boolean variable indicating the method success status.
 @param theRequestingModule	The name of the module requesting the logging operation.
 @param theMethodName The name of the method within the module requesting the logging operation.
 @param theMessage The data logged.
 @param outError Out parameter used if an error occurs while processing the message.  May be NULL.
 */

+ (BOOL)logWarning:(NSString *)moduleName methodName:(NSString *)methodName message:(NSString *)message error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("logWithLogLevel:methodName:line:message:");

/**
 Writes the requested message to the log if the requesting module's trace level is set to Error or higher.
 
 In the event a message is sent to this method without the Logging module being first initialized, the message will be written to the device console through the NSLog facility.
 
 @return Boolean variable indicating the method success status.
 @param theRequestingModule	The name of the module requesting the logging operation.
 @param theMethodName The name of the method within the module requesting the logging operation.
 @param theMessage The data logged.
 @param outError Out parameter used if an error occurs while processing the message.  May be NULL.
 */

+ (BOOL)logError:(NSString *)moduleName methodName:(NSString *)methodName message:(NSString *)message error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE_MESSAGE("logWithLogLevel:methodName:line:message:");

/** @name Log Management */
//@{

/** Removes all persisted log entries for the requesting module name.
 
 @return Boolean variable indicating the method success status.
 @param targetModule The name of the module requesting the log purge.
 @param outError Out parameter used if an error occurs while processing the message. May be NULL.
 */

+ (BOOL)purgeLogForModule:(NSString *)moduleName error:(NSError **)outError AW_DEPRECATED_ATTRIBUTE;

/**
 Sends a specified log to the AirWatch console.
 
 @param moduleName The module name of the log to transmit.
 */
+ (void)sendLogModuleToAirWatchConsole:(NSString *)moduleName AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use -sendApplicationLogsWithCompletion:");

/**
 Sends a device log to the AirWatch console.
 
 @param console The airwatch console url
 @param applicationBundle The applicationBundle name of the application for log.If we pass nil, it will take all application log and send to console.
 @param numberOfEntries numberOfEntries indicate the number of entries of log we want.
 @param outError Out parameter used if an error occurs while processing the message. May be NULL.
 */
+ (void)sendLogToAirWatchWithApplicationBundle:(NSString *)bundle numberOfEntries:(NSUInteger)entries AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use -sendDeviceLogsWithCompletion:");

//@}


@end

/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWAnalytics.h */

#import <Foundation/Foundation.h>
#if	TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif
#import <AWSDK/AWMacro.h>

/**
 @enum  AWAnalyticsEvent
 @brief Valid event type.
 */
typedef enum
{
	AWAnalyticsCustomEvent = 0,     /**< Signals a custom event has occured */
	AWAnalyticsSessionStarted,      /**< Signals the start of an AWAnalytics Session */
	AWAnalyticsSessionEnded,        /**< Signals the end of an AWAnalytics Session */
	AWAnalyticsViewDidAppear,       /**< Signals that a view appeared */
	AWAnalyticsViewDidDisappear     /**< Signals that a view has disappeared */
}
AWAnalyticsEvent;

/**
 @enum  valueTypeEnum
 @brief Valid event values.
 */
typedef enum
{
    AWAnalyticsValueNone = 0,   /**< Use when there is no value associated with an event */
    AWAnalyticsValueInteger,    /**< Use when the value associated with an event is an integer */
    AWAnalyticsValueLong,       /**< Use when the value associated with an event is a long */
    AWAnalyticsValueString      /**< Use when the value associated with an event is a long */
}
AWAnaltyicsEventValueType;

/**
 @brief		Analytics for an application.
 @details	Track useful statistical data concerning your application.
 @version 3.7.1
 */
@interface AWAnalytics : NSObject

@property (nonatomic, assign) BOOL enabled;     /**< Boolean used to represent the state of the AWAnalytics module */


/** 
 The bundleVersion object will contain the value from "CFBundleShortVersionString" out of the Info.plist by default and can be overridden
 if desired.
 */
@property (nonatomic, retain) NSString *bundleVersion;


/** 
 The bundleName object will contain the value from "CFBundleName" out of the Info.plist by default and can be overridden
 if desired.
 */
@property (nonatomic, retain) NSString *bundleName;


/** 
 Returns the singleton Instance of the Analytics class.
 Method should be called when you need to access an instantiated analytics singleton.
 @return A shared AWAnalytics singleton object.
 */
+ (AWAnalytics*)mAnalytics;


/**
 Records an analytics event.
 
 @param event The type of event.
 @param name The name of the event.
 @param eventValue The value associated with the event.
 @param valueType The type of value being recorded.
 */
- (void)recordEvent:(AWAnalyticsEvent)event
          eventName:(NSString *)name
         eventValue:(NSString *)eventValue
          valueType:(AWAnaltyicsEventValueType)value;

@end

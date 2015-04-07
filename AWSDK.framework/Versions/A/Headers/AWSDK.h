/*!
 AirWatch iOS Software Development Kit
 Copyright © 2013 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on
 an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 AirWatch expressly disclaims any and all liability resulting from User’s use of this Software
 Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWSDK.h */

#import <Foundation/Foundation.h>

/*! AWSDKSettingsChangedNotification
 @brief Name of the NSNotification that is posted when SDK settings have changed due to the SDK handling
 a URL with -handleOpenURL:error:
 
 @detail The Notification object's user info with contain all of the updated values. The values can
 be obtained with the following keys: AWSDKSettingsGroupIDKey, AWSDKSettingsServerURLKey,
 AWSDKSettingsAWUIDKey.
 */
extern NSString *const AWSDKSettingsChangedNotification;

/*! The key used to obtain the new Group ID. */
extern NSString *const AWSDKSettingsGroupIDKey;

/*! The key used to obtain the new DeviceServices URL. */
extern NSString *const AWSDKSettingsServerURLKey;

/*! The key used to obtain the new AWUID. */
extern NSString *const AWSDKSettingsAWUIDKey;

typedef void (^AWSDKInitCompletionHandler)(BOOL success, NSError *outError);

/*!
 @brief Handles initialization of internal SDK components so that communication with the AirWatch
 console can occur
 @version 3.7
 */
@interface AWSDK : NSObject

/*!
 This property will be used to determine if the SDK should handle a particular URL.
 */
@property (nonatomic, retain) NSString *sdkURLScheme;

/*!
 * INTERNAL
 * This property is used to lookup device ID for AW Apps when upgrading from iOS 6 to iOS 7.
 */
@property (nonatomic, retain) NSString *APNSToken;


/*!
 This method will initialize internal SDK components so that communication with the AirWatch
 console can occur.
 @param handler - The completion block takes two parameters BOOL success and NSError outError.
 @discussion success will be YES if initialization was successful, NO on failure. If an error occurs
 outError will contain an NSError object with the domain AWSDKErrorDomain, and one of the following 
 errors:
 
 AWSDKErrorServerNotSet - Thrown when the AWServer deviceServicesURL is nil.
 AWSDKErrorInitializationFailed - Thrown when an initialization step has failed.
 */
- (void)initializeWithCompletion:(AWSDKInitCompletionHandler)handler;

/*!
 Indicates if all initialization steps have been completed.
 @return YES if initialization has already occured, NO if any initialization steps are required.
 */
- (BOOL)isInitialized;

/*!
 Used to handle the SDK URL scheme. Before the SDK will handle the URL, the scheme MUST match the 
 value stored in the sdkURLScheme property.
 
 @param url url to handle. Should be in the following format:
	<scheme>://sdkcommand/changeUID;uid=<uid>;groupid=<groupid>;serverurl=<serverurl>
	where <scheme> matches the self.sdkURLScheme and one placed in the Info.plist for your app.
 @param outError If an error occurs, upon return contains an NSError object that describes the 
 problem. Pass NULL if you do not want error information.
 
 @return BOOL indicating if the SDK handled the url.
 
 @discussion Please note that a return value of NO does NOT indicate an error. If an error occurs 
 outError will contain an error with the AWSDKErrorDomain and one of the following error codes:
 
 AWSDKErrorSDKSchemeNotSet - Thrown when self.sdkURLScheme is nil.
 AWSDKErrorMissingParameterInURL - Thrown when the URL passed in doesn't contain the required 
 parameters.
 */
- (BOOL)handleOpenURL:(NSURL *)url error:(NSError **)outError;

@end

/*
 * AirWatch iOS Software Development Kit
 * Copyright © 2013 AirWatch. All rights reserved.
 *
 * Unless required by applicable law, this Software Development Kit and sample
 * code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF
 * ANYKIND, either express or implied. AirWatch expressly disclaims any and all
 * liability resulting from User’s use of this Software Development Kit. Any
 * modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWProfileStore.h */


#import <Foundation/Foundation.h>
#import <AWSDK/AWProfile.h>

extern NSString *const kAWStoredSDKProfileInfoKey;
extern NSString *const kAWStoredAppProfileInfoKey;


@interface AWProfileStore:NSObject

/**
 Stores the AWProfile object in local storage.
 @return BOOL indicating whether the profile was stored successfully
*/
- (BOOL)storeProfile:(AWProfile*)profile;

/**
 Provides an array of all AWProfiles currently stored on the device.
 @return NSArray of AWProfile objects.
 */
- (NSArray*)allProfiles;

/**
 Provides an array of all SDK AWProfiles currently stored on the device.
 @return NSArray of AWProfile objects.
 */
- (NSArray*)allSDKProfiles;

/**
 Provides an array of all App AWProfiles currently stored on the device.
 @return NSArray of AWProfile objects.
 */
- (NSArray*)allAppProfiles;

/**
 Provides an array of all AWProfiles currently stored on the device.
 @return NSArray of AWProfile objects.
 */
- (NSArray*)allProfileDictionaries;

/**
 Provides an array of all SDK AWProfiles currently stored on the device.
 @return NSArray of AWProfile objects.
 */
- (NSArray*)allSDKProfileDictionaries;

/**
 Provides an array of all App AWProfiles currently stored on the device.
 @return NSArray of AWProfile objects.
 */
- (NSArray*)allAppProfileDictionaries;

@end

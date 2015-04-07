/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWProfilePayload.h */

#import <Foundation/Foundation.h>

/**
 @brief		An abstract class that is used to represent profile payloads.
 @details	Abstract class used for subclasses to inherit from. Subclasses must implement all methods.
 @version 3.7.1
 */
@interface AWProfilePayload : NSObject
{
	
}

/**
 The designated intializer to create a profile payload.
 
 @param dictionary A dictionary representation of a profile payload.
 @return A newly initialized profile payload.
 */
- (id)initWithDictionary:(NSDictionary *)dictionary;

/**
 The profile type in the format of a string.
 
 @return Profile type text.
 */
+ (NSString *)payloadType;

/**
 The version 2 profile type in the format of a string.
 
 @return Profile type text.
 */
+ (NSString *)payloadTypeV2;

- (NSDictionary *)toDictionary;

@end

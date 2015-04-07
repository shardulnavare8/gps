/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

#import <Foundation/Foundation.h>

/*!
 @enum AWCommandStatus
 @brief A type definition for commands
 
 Details.
 */
typedef enum {
	UNKNOWN = 0,
	ACKNOWLEDGED,
	ERROR,
	COMMANDFORMATERROR,
	IDLE,
	NOTNOW
} AWCommandStatus;

/** 
 *   AWCommandTypes a Singleton class used to hold command types and get their string representations
 * @version 3.7.1
 */
@interface AWCommandTypes : NSObject {
	
}

/** 
 *   Return a singleton of AWCommandTypes
 */
+ (AWCommandTypes *)sharedInstance;

/** 
 *  Return a command's status in NSString format
 * 
 *  @param type An AWCommandStatus type to be convert to NSString type name
 */
- (NSString *)commandStatusTypeName:(AWCommandStatus)type;

@end

/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWAction.h */

#import <Foundation/Foundation.h>

/** @enum AWActionType
    @brief     The specific type of action.
 */
typedef enum
{
	AWActionDisplayAlert = 1,   /**< Display alert message. */
	AWActionLockUser,           /**< Lock the user out of the application. */
	AWActionWipeApplication,    /**< Wipe the application data. */
	AWActionRestrictAccess,     /**< Restrict access to the application. */
	AWActionCustom,             /**< Custom action. */
	AWActionReportBackToServer  /**< The application should report back to AirWatch via a Beacon message. */
}
AWActionType;

/**
 @brief		Executable actions. 
 @details	Action that should be executed when a defined condition is met.
 @version 3.7.1
 */
@interface AWAction : NSObject <NSCoding>
{
	
}

/** 
 @brief A type describing the action. 
 */
@property (nonatomic, assign) AWActionType type;

/** 
 @brief The value of the action.
 @detail This will only be non-nil when the `type` is `AWActionDisplayAlert` or `AWActionCustom`.
 */
@property (nonatomic, copy) NSString *value;

@end

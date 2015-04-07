/*
 * AirWatch iOS Software Development Kit
 * Copyright © 2012 AirWatch. All rights reserved.
 *
 * Unless required by applicable law, this Software Development Kit and sample
 * code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. AirWatch expressly disclaims any and all
 * liability resulting from User’s use of this Software Development Kit. Any
 * modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWCommand.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWMacro.h>

/**
 @enum AWCommandType
 Indicates the type of command
 */
typedef enum
{
	AWUnknownCommand = -1,                  /**< Unknown command. */
	AWInstallProfileCommandType,            /**< Install profile command. */
	AWInstallContentCommandType,            /**< Install content command. */
	AWRemoveContentCommandType,             /**< Remove content command. */
	AWScreenCaptureCommandType,             /**< Screen capture command. */
	AWEraseDeviceCommandType,               /**< Erase device command. */
    AWRequestProfilesCommandType,           /**< Request Profiles command. */
    AWRemoveApplicationProfilesCommandType, /**< Remove Application Profiles Command. */
    AWRequestCertificatesCommandType,        /**< Request Certificates Command. */
    AWUploadLogsCommandType,
    AWResetAppPasscodeType,                     /**< Reset the app passcode */
    AWDeviceLockCommandType,
    AWClearPasscodeCommandType
}
AWCommandType;

/**
 @brief		Represents a command received from AirWatch.
 @details	An abstract class that represents commands created on the AirWatch console.
 @version 3.7.1
 */
@interface AWCommand : NSObject
{
    
}

/** 
 *  @name Information About the Command
 */
//@{

/** The UUID of the command. */
@property (nonatomic, readonly) NSString *UUID;

/** The contents of the 'Command' element */
@property (nonatomic, readonly) NSDictionary *commandInfo;

/** The old payload. */
@property (nonatomic, readonly) NSDictionary *payload AW_DEPRECATED_ATTRIBUTE_MESSAGE("Please retreive the profile through AWInstallProfileCommand.");

/** A type describing the command. */
@property (nonatomic, assign) AWCommandType type;

//@}

/** @name Initialization */
//@{

/** 
 *  Returns a command built from a dictionary.
 *
 *  @param info The dictionary to be used to build the command.
 *  @return Returns initialized object.
 */
- (id)initWithDictionary:(NSDictionary *)info;

//@}

@end

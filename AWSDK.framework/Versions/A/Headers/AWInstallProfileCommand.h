/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWInstallProfileCommand.h */

#import <AWSDK/AWCommand.h>
#import <AWSDK/AWProfile.h>


/**
 @brief		Install profile command.
 @details	Command used to signal the request of installing a profile.
 @version 3.7.1
 */
@interface AWInstallProfileCommand : AWCommand
{
	
}

/** Profile to be installed. */
@property (nonatomic, readonly) AWProfile *profile;

@end

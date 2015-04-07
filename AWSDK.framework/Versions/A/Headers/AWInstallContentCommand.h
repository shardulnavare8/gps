/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWInstallContentCommand.h */

#import <AWSDK/AWCommand.h>

/**
 @brief		Install content command.
 @details	Command used to signal a request to install content.
 @version 3.7.1
 */
@interface AWInstallContentCommand : AWCommand
{
	
}

/** 
 The unique identifier of a content entity. This is the identity of the content
 entity that should be installed.
 */
@property (nonatomic, readonly) NSInteger contentIdentifier;

@end

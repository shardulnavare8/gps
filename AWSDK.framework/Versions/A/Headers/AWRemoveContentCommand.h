/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWRemoveContentCommand.h */

#import <AWSDK/AWCommand.h>

/**
 @brief		Remove content command.
 @details	Command used to signal a request to remove content.
 @version 3.7.1
 */
@interface AWRemoveContentCommand : AWCommand
{

}

/** Identifier of the content to be removed */
@property (nonatomic, assign) NSInteger contentIdentifier;

@end

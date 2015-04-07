/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWEraseDeviceCommand.h */

#import <AWSDK/AWCommand.h>

/**
 @brief		Erase device (Enterprise wipe) command.
 @details	Command used to signal a request to erase the device (Though it is techically impossible to wipe device from within an app in iOS, the command will be executed in appropriate manner by the application which is using the SDK ).
 @version 3.7.1
 */
@interface AWEraseDeviceCommand : AWCommand
{

}
	
@end

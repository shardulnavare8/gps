/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWCompliancePayload.h */

#import <AWSDK/AWProfilePayload.h>

/**
 @brief		Compliance payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the compliance group of an SDK profile.
 @version 3.7.1
 */
@interface AWCompliancePayload : AWProfilePayload
{
	
}

/** A boolean indicating if compromised (jailbroken) devices should be prevented. */
@property (nonatomic, readonly) BOOL preventCompromisedDevices;

/** A boolean indicating if device restorations should be prevented. */
@property (nonatomic, readonly) BOOL preventRestoringBackupDevices;

/** An array of actions to be performed if the device is compromised. */
@property (nonatomic, readonly) NSArray *preventCompromisedDevicesActions;

/** A boolean indicating if compromised (jailbroken) devices should be prevented. */
@property (nonatomic, readonly) BOOL enableCompromisedProtection;

/** A string for the id of the compromised policy. */
@property (nonatomic, readonly) NSString *compromisedPolicyID;

@end
	
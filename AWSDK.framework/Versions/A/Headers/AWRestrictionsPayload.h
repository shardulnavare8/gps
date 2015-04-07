/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWRestrictionsPayload.h */

#import <AWSDK/AWMacro.h>
#import <AWSDK/AWProfilePayload.h>

/**
 @brief		Access control payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the access control group of an SDK profile.
 @version 3.7.1
 */
@interface AWRestrictionsPayload : AWProfilePayload
{
	
}

/** A boolean indicating if the application can be used while the device is offline. */
@property (nonatomic, readonly) BOOL isOfflineModeAllowed;

/** The amount of time an application can be run while the device is offline. */
@property (nonatomic, readonly) long long maximumAllowedOfflineDuration;

/** The amount of times an application can be used before the device goes online. */
@property (nonatomic, readonly) NSInteger maximumOfflineUses;

/** The actions to be taken when maximum offline login is exceeded */
@property (nonatomic, readonly) NSArray *offlineOverLimitActions;

/** A boolean indicating if MDM enrollment is required. */
@property (nonatomic, readonly) BOOL isMDMEnrollmentRequired;

/** An array of actions to be performed if the device is not enrolled. */
@property (nonatomic, readonly) NSArray *deviceNotEnrolledActions;

/** A boolean indicating if Copy and Cut actions are allowed. */
@property (nonatomic, readonly) BOOL preventCopyAndCut;

/** A boolean indicating whether to only allow open document in allowed list of app */
@property (nonatomic, readonly) BOOL restrictDocumentToApps;

/** A list of Apps that're allowed to open documents */
@property (nonatomic, readonly) NSArray *restrictedApplications AW_DEPRECATED_ATTRIBUTE_MESSAGE("Changed to allowdApplications");
@property (nonatomic, readonly) NSArray *allowedApplications;

/** A boolean indicating if printing is allowed. */
@property (nonatomic, readonly) BOOL printingEnabled;

/** A boolean indicating if data loss prevention is enabled. */
@property (nonatomic, readonly) BOOL enableDataLossPrevention;

@end

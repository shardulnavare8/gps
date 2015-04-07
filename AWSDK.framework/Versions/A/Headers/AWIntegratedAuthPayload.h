/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWIntegratedAuthPayload.h */
#import <AWSDK/AWProfilePayload.h>

/**
 @brief		AWIntegratedAuthPayload payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the Integrated Authentication group of an SDK profile (V2).
 @version 3.7.1
 */
@interface AWIntegratedAuthPayload : AWProfilePayload

@property (nonatomic, readonly) BOOL enableIntegratedAuthentication;   /**< A boolean indicating if Integrated Authentication is enabled. */

@property (nonatomic, readonly) NSArray *allowedSites;

@end

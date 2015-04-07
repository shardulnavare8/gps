/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWBrandingPayload.h */

#import <AWSDK/AWProfilePayload.h>

/**
 @brief     Custom payload that is contained within a 'AWProfile'.
 @version 3.7.1
 */
@interface AWCustomPayload : AWProfilePayload
{
	
}

/** The custom settings represented as a string. */
@property (nonatomic, readonly) NSString *settings;

@end

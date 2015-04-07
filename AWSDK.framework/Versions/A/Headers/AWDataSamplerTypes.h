/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWDataSamplerTypes.h */

/**
 @enum AWDataSamplerModuleBitmask       Enumeration that defines the DataSampler module type.
 @version 3.7.1
 */

enum {
    AWDataSamplerModuleNone            = 0,
    AWDataSamplerModuleSystem          = 1 << 0,	/** System module of DataSampler   */
    AWDataSamplerModuleAnalytics       = 1 << 1,	/** Analytics   module of DataSampler*/
    AWDataSamplerModuleGPS             = 1 << 2,	/** GPS module of DataSampler   */
    AWDataSamplerModuleNetworkData     = 1 << 3,	/** NetworkData module of DataSampler   */
    AWDataSamplerModuleCallLog         = 1 << 4,	/** Call log module of DataSampler   */
    AWDataSamplerModuleNetworkAdapter  = 1 << 5,	/** Network adapter module of DataSampler   */
    AWDataSamplerModuleWLAN2Sample     = 1 << 6,     /** WLAN2 sample module of DataSampler   */
    AWDataSamplerModuleAppSample       = 1 << 7     /** Application sample module of DataSampler   */
};

typedef NSUInteger AWDataSamplerModuleBitmask;
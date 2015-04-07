/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWInterrogatorTypes.h */ 

/** 
 @deprecated
 @details                 DEPRECATED: Please use AWDataSamplerModuleBitmask instead. 
 @enum AWInterrogatorModuleBitmask       Enumeration that defines the Interrogator module type.
 @version 3.7.1
 */

enum {
    AWInterrogatorModuleNone            = 0,
    AWInterrogatorModuleSystem          = 1 << 0,	/** System module of Interrogator   */
    AWInterrogatorModuleAnalytics       = 1 << 1,	/** Analytics   module of Interrogator*/
    AWInterrogatorModuleGPS             = 1 << 2,	/** GPS module of Interrogator   */
    AWInterrogatorModuleNetworkData     = 1 << 3,	/** NetworkData module of Interrogator   */
    AWInterrogatorModuleCallLog         = 1 << 4,	/** Call log module of Interrogator   */
    AWInterrogatorModuleNetworkAdapter  = 1 << 5,	/** Network adapter module of Interrogator   */
    AWInterrogatorModuleWLAN2Sample     = 1 << 6	/** WLAN2 sample module of Interrogator   */
};

typedef NSUInteger AWInterrogatorModuleBitmask AW_DEPRECATED_ATTRIBUTE_MESSAGE("Please use AWDataSamplerModuleBitmask instead.");
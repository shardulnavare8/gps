/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWLocationModeTypes.h */ 

/**
 @enum  An enum to specify location service type.
 @version 3.7.1
 */
typedef enum 
{    
    AWLocationModeDisabled = -1,
    AWLocationModeStandard,     ///< use standard location service
    AWLocationModeSignificant,   ///< use sugnificant location service
    AWLocationModeRegionMonitoring       ///< use region monitoring service
}
AWLocationMode;
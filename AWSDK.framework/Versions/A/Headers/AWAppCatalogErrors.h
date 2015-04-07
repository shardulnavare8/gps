/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWAppCatalogErrors.h */

#import <Foundation/Foundation.h>

extern NSString *const AWSDKAppCatalogErrorDomain;


/**
 @enum      Enum provides status of AppCatalog errors.
 @version   1.1
*/
enum {
    
    AWAppCatalogIconDownloadMalformedURL = 1,    ///< The request could not be fulfilled because of a malformed Application Icon URL.
    AWAppCatalogIconDownloadUnableFetchData      ///< Unable to download application icon data.
};
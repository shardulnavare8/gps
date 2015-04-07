/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval from AirWatch. 
 */

/*! \file AWCertificateTrust.h */

#import <Foundation/Foundation.h>

/**
 @brief		Evalutes the trust of a certificate chain.
 @details	This utility class evaluates certificates against the root CA certificates on the device.
 @version 3.7.1
 */
@interface AWCertificateTrust : NSObject {
    
}

/** 
 @brief  Performs a trust evaluation with a certifcate.
 
 Certificates will evaluate as trusted if their certificate chains can be traced back to a trusted root certificate
 present on the device. The root certificate may be provided by a well-known Certificate Authority (CA), such as Symantec, or by your
 own internal CA. If you provide your own CA, then your root certificate must be installed on your devices, after which certificates
 issued by your CA will evaluate as trusted.
 
 Certificates are not issued by AirWatch.
 
 *  @param path A filesystem path to a certificate.
 *  @return A boolean value indicating whether the certifcate at the supplied path is trusted.
 */

+ (BOOL)isCertificateTrustedAtPath:(NSString *)path;

@end

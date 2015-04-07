/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWCertificatePayload.h */

#import <AWSDK/AWProfilePayload.h>

/**
 @brief		Analytics payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the certificate group of an application profile.
 @version 3.7.1
 */
@interface AWCertificatePayload : AWProfilePayload
{
	
}

/** The certificate's data. */
@property (nonatomic, readonly) NSData *certificateData;

/** The name of the certificate. */
@property (nonatomic, readonly) NSString *certificateName;

/** The password of the certificate. */
@property (nonatomic, readonly) NSString *certificatePassword;

/** The thumbprint of the certificate. */
@property (nonatomic, readonly) NSString *certificateThumbprint;

/** The type of the certificate. */
@property (nonatomic, readonly) NSString *certificateType;

@end

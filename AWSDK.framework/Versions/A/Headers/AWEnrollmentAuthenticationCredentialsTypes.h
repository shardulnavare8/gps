/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWEnrollmentAuthenticationCredentialsTypes.h */

#import <Foundation/Foundation.h>

// TODO: This enum should be a bitmask
/** The possible types of authentication credentials. */
typedef enum
{    
	AWEnrollmentAuthenticationCredentialsNone = 0,			/**< No credentials */
	AWEnrollmentAuthenticationCredentialsPin,			/**< PIN only credentials. */
	AWEnrollmentAuthenticationCredentialsUsernamePassword,		/**< Username and password credentials. */
	AWEnrollmentAuthenticationCredentialsCertificate,		/**< Certificate based credentials. */
	AWEnrollmentAuthenticationCredentialsCertificateWithPin,		/**< Credentials with both a certicate and PIN. */
	AWEnrollmentAuthenticationCredentialsAuthorizationToken,		/**< Credentials with one time authorization token from SSP*/
    AWEnrollmentAuthenticationCredentialsSSO
}
AWEnrollmentAuthenticationCredentialsType;

/** The default authentication credential type. */
extern AWEnrollmentAuthenticationCredentialsType const AWDefaultAuthenticationCredentialsType;
extern AWEnrollmentAuthenticationCredentialsType const AWTokenAuthenticationCredentialsType;

/**
 @brief		Constants for authentication.
 @details	Defines numerous constants used for authenticating a user.
 @version 3.7.1
 */
@interface AWEnrollmentAuthenticationCredentialsTypes : NSObject

@end

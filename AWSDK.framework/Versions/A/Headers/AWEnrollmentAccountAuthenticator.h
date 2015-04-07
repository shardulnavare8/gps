/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWEnrollmentAccountAuthenticator.h */ 

#import <Foundation/Foundation.h>
#import <AWSDK/AWEnrollmentAuthenticationCredentialsTypes.h>

@class AWEnrollmentAccount;

/**
 * An enum holding the possible authentication failure reasons.
 */

typedef enum
{    
    AWEnrollmentAuthenticationUserDeviceMismatch    = -5,	///< The authenticated user was not used to enroll the target device. 
    AWEnrollmentAuthenticationNotEnrolled           = -4,	///< The device is not enrolled.
    AWEnrollmentAuthenticationDeviceNotFound        = -3,	///< The device has not checked in to the console.
    AWEnrollmentAuthenticationInternalServerError   = -2,	///< An internal server error occurred.
    AWEnrollmentAuthenticationInvalidCredentials    = -1,	///< Invalid credentials were supplied.
    AWEnrollmentAuthenticationInvalidActivationCode = 0		///< An invalid activation code was supplied.    
}
AWEnrollmentAuthenticationResult; ///< Enumeration describing the cause of failure.

/**
 * Call back block given authentication status of account after authentication attempt
 */

typedef void(^AWEnrollmentAuthenticatorCompletionStatusBlock)(BOOL authenticated, AWEnrollmentAccount *account, NSError *error);

/** 
 The AWEnrollmentAccountAuthenticator provides an interface to authenticate an enrollment account at a specified server location. The details of server is passed to the AWEnrollmentAccountAuthenticator through an AWServer object.
 @brief AWEnrollmentAccountAuthenticator manage to check authenticate AWEnrollmentAccount object.
 
 */

/**
 @brief		Enrollment account authenticator.
 @details	Controller used to authenticate an enrollment account against AirWatch.
 @version 3.7.1
 */
@interface AWEnrollmentAccountAuthenticator : NSObject
{
    
}

/** @name Authenticating an Account */
//@{

/** Authenticates an AirWatch enrollment account.
 
 @param account The account to be authenticated.
 @param block A callback block used to retrieve the status of the authentication. Boolean object indicate whether the AWEnrollmentAccount is authenticated or not, and error will be get if any error occur regarding authentication.
 */
- (void)authenticateAccount:(AWEnrollmentAccount *)account callBackBlock:(AWEnrollmentAuthenticatorCompletionStatusBlock)block;

//@}

@end


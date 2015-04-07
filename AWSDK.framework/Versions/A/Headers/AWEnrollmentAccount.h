/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWEnrollmentAccount.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWEnrollmentAuthenticationCredentialsTypes.h>

/**
 @brief		Model representing an AirWatch enrollment account.
 @version 3.7.1
 */
@interface AWEnrollmentAccount : NSObject {
    
}

/** @name Configuring an Account */
//@{
/** The numeric identifier associated with the account. This will be -1 until 
 the account has been authenticated against AirWatch. Upon authentication, 
 contains a valid user identifier.
 
 Default value of -1. 
 */
@property (nonatomic, assign) NSInteger identifier;

/** The activation code (group identifier) of the account. */
@property (nonatomic, copy) NSString *activationCode;

/** The username of the account. */
@property (nonatomic, copy) NSString *username;

/** The password of the account. */
@property (nonatomic, copy) NSString *password;

/** From 6.4 console, we support one time authorization token interchangable with username/password */
@property (nonatomic, copy) NSString *authorizationToken;

/** The type of the authentication credentails used by the web service. Defaults 
 to AWEnrollmentAuthenticationCredentialsUsernamePassword if not explicitly 
 set. */
@property (nonatomic, assign) AWEnrollmentAuthenticationCredentialsType authenticationCredentialsType;

//@}

/** @name Creating an Account */
//@{

/** Optional helper intializer. 
 
 @brief AWEnrollmentAccount object made by this function. and it is modal class of enrollment account. 
 @param activationCode The activation code (group identifier) of the account.
 @param username The username of the account.
 @param password The password of the account.
 @return A newly initialized enrollment account. 
 */
- (id)initWithActivationCode:(NSString *)activationCode username:(NSString *)username password:(NSString *)password;

/*
 @brief AWEnrollmentAccount object made by this function. and it is modal class of enrollment account.
 @param authorizationToken Token used to authorize a user.
 @return A newly initialized enrollment account.
 @discussion The authorizationToken can be obtained from the Self Service Portal.
 */
- (id)initWithActivationCode:(NSString *)activationCode authorizationToken:(NSString *)authorizationToken;

//@}

@end

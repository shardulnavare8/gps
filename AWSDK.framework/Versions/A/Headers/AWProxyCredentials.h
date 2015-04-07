/*
 AirWatch iOS Software Development Kit
 Copyright © 2013 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWProxyCredentials.h */

#import <Foundation/Foundation.h>

@class AWEnrollmentAccount;

/**
 @brief Encapsulates the necessary information to authenticate against a proxy.
 @discussion If you're authenticating against a standard proxy you can provide a username and password.
 If you're authenticating against a MAG proxy the provided enrollment account will be used to fetch a new MAG 
 certificate.
 */
@interface AWProxyCredentials : NSObject

/**
 The username used to authenticate against a standard/F5 proxy.
 @discussion This value will only be used for Standard/F5 Proxy.
 */
@property (nonatomic, retain)NSString *username;

/**
 The password used to authenticate against a standard/F5 proxy.
 @discussion This value will only be used for Standard/F5 Proxy.
 */
@property (nonatomic, retain)NSString *password;

/**
 The AWEnrollmentAccount used to authenticate against a MAG proxy.
 @discussion This value will only be used for MAG/F5 Proxy.
 */
@property (nonatomic, retain)AWEnrollmentAccount *account;

/**
 Used to indicate that the account property should be used for F5 authentication.
 @discussion defaults to NO
 */
@property (nonatomic, assign)BOOL f5ShouldUseEnrollmentAccount;

/**
 Creates and returns an AWProxyCredential object initialized with a username and password for use with a Standard
 Proxy.
 
 */
+ (id)credentialsWithUsername:(NSString *)username password:(NSString *)password;

/**
 Creates and returns an AWProxyCredential object initialized with an AWEnrollment account for use with MAG/F5 Proxy.
 */
+ (id)credentialsWithEnrollmentAccount:(AWEnrollmentAccount *)account;


@end

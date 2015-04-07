/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWURLCredentialStorage.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWEnrollmentAccount.h>

/**
 @brief		Object used for setting and retrieving cahced NSURLCredential objects for use against NSURLProtectionSpace objects.
 @version 3.7.1
 */
@interface AWURLCredentialStorage : NSObject

/** The currently authenticated enrollment account used for handling authentication challenges. */
@property (nonatomic, retain, readonly) AWEnrollmentAccount *enrollmentAccount;

/**
 Creates an AWURLCedentialStorage object corresponding to the passed in AWEnrollmentAccount 
	for storing and retrieving saved URL credentials.
 
 @param enrollmentAccount An AWEnrollmentAccount used to store/retrieve credentials with.
 @return A newly initialized AWURLCedentialStorage object.
 */
- (id)initWithEnrollmentAccount:(AWEnrollmentAccount *)enrollmentAccount AW_DEPRECATED_ATTRIBUTE_MESSAGE("Use initWithEnrollmentAccount:encryptionKey:");

/**
 Creates an AWURLCedentialStorage object corresponding to the passed in AWEnrollmentAccount
 for storing and retrieving saved URL credentials.
 
 @param enrollmentAccount An AWEnrollmentAccount used to store/retrieve credentials with.
 @param encryptionKey A cryptographic key used for encrypting/decrypting stored passcodes in the keychain.
 @return A newly initialized AWURLCedentialStorage object.
 */
- (id)initWithEnrollmentAccount:(AWEnrollmentAccount *)enrollmentAccount encryptionKey:(NSData *)encryptionKey;

/**
 Stores a set of passed in credentials for a specific protection space.
 
 @param credentials The set of credentials to be saved.
 @param protectionSpace The protection space to associate the credentials with.
 */
- (void)setCredentials:(NSURLCredential *)credentials forProtectionSpace:(NSURLProtectionSpace *)protectionSpace;

/**
 Removes the stored credentials corresponding wiht the supplied protection space.
 
 @param protectionSpace The protection space corresponding with the credentials to be removed.
 */
- (void)removeCredentialsForProtectionSpace:(NSURLProtectionSpace *)protectionSpace;

/**
 Removes all the stored credentials for the user.
 */
- (void)removeAllCredentials;

/**
 Fetches the credentials corresponding with the supplied protection space
 
 @param protectionSpace The protection space for which you would like stored credentials for.
 @return The credentials corresponding with the supplied protection space.
 */
- (NSURLCredential *)credentialsForProtectionSpace:(NSURLProtectionSpace *)protectionSpace;

/**
 Fetches all credentials that correspond with a protection space containing an authentication realm matching the supplied realm.
	This can be used to fetch additional credentials that may successfully authenticate against your protection space, 
		if you do not have a set of credentials matching your specific protection space.
 
 @param realm The authentication realm for which you would like potential credentials for.
 @return A set of NSURLCredential objects matched with protection spaces containing the same realm as supplied.
 */
- (NSSet *)supplementaryCredentialsMatchingAuthenticationRealm:(NSString *)realm;

/**
 Removes all persisted credentials within the keychain for all users.
 @param error A pointer to an NSError in the event the operation is unsuccessful.
 @return A BOOL reflecting the success or failure of the operation.
 */
+ (BOOL)removeAllCredentialStorageAccounts:(NSError **)error;

@end

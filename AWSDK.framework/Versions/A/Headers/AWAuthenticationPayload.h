/* Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWAuthenticationPayload.h */

/**
 @enum AWAuthenticationMethod
 Indicates the Authentication Method to be used
 */
typedef enum AWAuthenticationMethod
{
    AWAuthenticationMethodNone = 0,
	AWAuthenticationMethodPasscode = 1,         /**< Use the Passcode Authentication method. */
	AWAuthenticationMethodUsernamePassword = 2  /**< Use the Username and Password Authentication method. */
}
AWAuthenticationMethod;

/**
 @enum AWAuthenticationPasscodeComplexity
 Specfies how complex a passcode should be.
 */
typedef enum AWAuthenticationPasscodeComplexity
{
	AWAuthenticationPasscodeSimpleComplexity = 1,       /**< Use simple passcodes */
	AWAuthenticationPasscodeAlphanumericComplexity = 2  /**< Require Passcodes to contain both letters and numbers */
}
AWAuthenticationPasscodeComplexity;

typedef NS_ENUM(NSInteger, AWPasscodeMode) {
    AWPasscodeModeOff = 0,
    AWPasscodeModeNumeric = 1,
    AWPasscodeModeAlphanumeric = 2
};

#import <AWSDK/AWProfilePayload.h>

/**
 @brief		Authentication payload that is contained in an `AWProfile`.
 @details	A profile payload that represents the authentication group of an SDK profile.
 @version 3.7.1
 */
@interface AWAuthenticationPayload : AWProfilePayload
{
	
}

/** The authentication type being used. */
@property (nonatomic, readonly) AWAuthenticationMethod authenticationMethod;

/** 
 The passcode complexity.
 **This only applies to passcodes.**
 */
@property (nonatomic, readonly) AWAuthenticationPasscodeComplexity passcodeComplexity;

/** The minimum length of a passcode. 

 **This only applies to passcodes.**
 */
@property (nonatomic, readonly) NSInteger minimumPasscodeLength;

/** The minimum complex characters a passcode must contain. 

 **This only applies to passcodes.**
 */
@property (nonatomic, readonly) NSInteger minimumComplexCharacters;

/** The maximum amount of days before a passcode expires and a new one must be set. 

 **This only applies to passcodes.**
 */
@property (nonatomic, readonly) NSTimeInterval maximumPasscodeAge;

/** The amount of passcodes that must be unique before reusing one is allowed. 

 **This only applies to passcodes.**
 */
@property (nonatomic, readonly) NSInteger passcodeHistory;

/** Amount of time the application can be unlocked without prompting for the passcode. 

 **This applies to username / password & passcodes.**
 */
@property (nonatomic, readonly) NSTimeInterval gracePeriod;

/** Whether or not single sign-on should be allowed. 
 
 **This only applies to username / password.**
 */
@property (nonatomic, readonly) BOOL allowSingleSignOn;

/** Number of failed authentication attempts allowed before actions should be executed.

 **This applies to username / password & passcode.**
 */
@property (nonatomic, readonly) NSInteger maximumFailedAttempts;

/** The sequence of action taken after max number of failed passcode / password attempts occured
 
 **This applies to username / password & passcode.**
 */
@property (nonatomic, readonly) NSArray *actionsTakenOnMaxFailedAttempt;

/** The idle time (in minute) before application will auto lock
 
 **This is currently being passed down but have no way to manipulate the value from console**
 */
@property (nonatomic, readonly) NSInteger autoLockMinute;

/** Don't know the intention of this one yet
 
 **This is currently being passed down but have no way to manipulate the value from console**
 */
@property (nonatomic, readonly) BOOL allowSamePasscodeAllApp;

/** Determine if device passcode level should be required
 
 **This start being implemented in 6.4 to replace authenticationMethod = 1 (passcode)**
 */
@property (nonatomic, readonly) BOOL requirePasscode;

@property (nonatomic, readonly) BOOL enableSingleSignOn;   /**< A boolean indicating if Single Sign-On is enabled. */

@property (nonatomic, readonly) AWPasscodeMode passcodeMode;
@property (nonatomic, readonly) BOOL allowSimple;
@property (nonatomic, readonly) NSInteger passcodeTimeout;
@property (nonatomic, readonly) NSInteger actionOnMaxFailedAttempts;
@property (nonatomic, readonly) NSString *policyId;

@property (nonatomic, readonly) BOOL enableIntegratedAuthentication;   /**< A boolean indicating if Integrated Authentication is enabled. */

@property (nonatomic, readonly) NSArray *allowedSites;


/** To access back the dictionary used to create this payload
 
 **
 */
@property (nonatomic, readonly) NSDictionary *payloadDictionary;

@end

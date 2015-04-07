/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWAgentAuthenticatorController.h */

#import <Foundation/Foundation.h>


typedef void (^agentAuthCallback)(BOOL authenticated);

@interface AWAgentAuthenticatorController : NSObject

+ (AWAgentAuthenticatorController*)sharedInstance;

/*!
 @method Authenticate
 @abstract Authenticate application through airwatch Agent
 */
- (void)authenticateWithScheme:(NSString*)scheme callback:(agentAuthCallback)callback;

/*!
 @method Process launch URL
 */
- (BOOL)processURL:(NSURL*)url;

/*!
 @method Renew
 @abstract Renew credentials through airwatch Agent
 */
- (void)renewWithScheme:(NSString*)scheme callback:(agentAuthCallback)callback;

/*!
 @method Server URL
 @abstract Airwatch Device Services URL
 */
- (NSString*)serverURL;

/*!
 @method canUseAgent
 @abstract Checks to see if airwatch agent can be used
 */
- (BOOL)canUseAgent;
@end

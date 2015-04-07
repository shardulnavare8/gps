/*
 * AirWatch iOS Software Development Kit
 * Copyright © 2012 AirWatch. All rights reserved.
 *
 * Unless required by applicable law, this Software Development Kit and sample
 * code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF
 * ANY
 * KIND, either express or implied. AirWatch expressly disclaims any and all
 * liability resulting from User’s use of this Software Development Kit. Any
 * modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWSession.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWMacro.h>

typedef enum {
    AWAuthenticationTypeToken = 1,
    AWAuthenticationTypeHMAC = 2
}AWAuthenticationType;

@protocol AWSessionDelegate;

@class AWEnrollmentAccount;

extern NSString *const AWSessionTokenUnsupported;
extern NSString *const AWSessionHeaderToken;

/**
 * @brief   AWSession manages the session of enrollmented account with endpoint.
 * @details	Represents a unique temporary, session used to authenticate against AirWatch API
            endpoints.
 * @version 3.7.1
 */
@interface AWSession:NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate,
NSXMLParserDelegate>
{
}

/*!
    @param account The AWEnrollmentAccount used to obtain a session token.
    @return Returns an instance of AWSession
 */
- (id)initWithAccount:(AWEnrollmentAccount *)account;

/*!
    Request a token for the receiver. This token will be used for subsequent requests to the 
    AirWatch Console.
    @return YES if the connection was created, NO if the connection was not created.
    @discussion The return value does not indicate a token was received. You must implement the
                @link AWSessionDelegate @\link protocol.
 */
- (BOOL)requestToken;

/*!
    Request that the receiver's token be invalidated. This will a prevent any subsequent
    requests to the AirWatch Console using the invalidated token.
    @return YES if the connection was created, NO if the connection was not created.
    @discussion The return value does not indicate a token was invalidated. You must implement
                the @link AWSessionDelegate @\link protocol.
 */
- (BOOL)invalidateToken;

/*!
    Returning a Boolean value that indicates whether the receiver's token is valid.
    @return YES if the token is valid otherwise NO if the token is not valid.
 */
- (BOOL)tokenIsValid;

/*!
    The token of the receiver.
    @property
    @discussion If a request for a token has not been made, or the token has been invalidated token
                will be nil.
 */
@property (nonatomic, copy) NSString *token;

/*!
    The delegate of the receiver.
    @property
    @discussion The AWSessionDelegate will be notified when a token is received or invalidated, and
                if an error occured while requesting a token or invalidating a token.
 */
@property (nonatomic, assign) id<AWSessionDelegate> delegate;

/*!
    Boolean value indicating if  the receiver is requesting a token.
    @property
 */
@property (nonatomic, readonly) BOOL isRequestingToken;

/*!
    Boolean value indicating if the receiver is invalidating a token
    @property
 */
@property (nonatomic, readonly) BOOL isInvalidatingToken;

/*!
    The enrollmenteAccount object that the receiver uses to get a session token.
    @property
 */
@property (nonatomic, retain) AWEnrollmentAccount *account;

/*!
    The AWAuthenticationType that the receiver will use.
    @property
 */
@property (nonatomic, assign) AWAuthenticationType authenticationType;

/*!
    NSString representing the authenticationGroup, which is simply the BundleIdentifier.
    @property
 */
@property (nonatomic, retain) NSString *authenticationGroup;

/*!
    NSString representing the temperory token, used for retriving HMAC token post
    successful enrollment through native enrollment process
 */
@property (nonatomic, retain) NSString *authorizationCode;

@end


/*!
    The AWSessionDelegate will be notified when a token is received or invalidated, and
    if an error occured while requesting a token or invalidating a token.
    @protocol
 */
@protocol AWSessionDelegate <NSObject>

@required
/*!
    This method notifies the receiver when the AWSession object receives a token.
 */
- (void)AWSession:(AWSession *)session didRecieveToken:(NSString *)token;

/*!
    This method notifies the receiver when the AWSession failed to connect.
 */
- (void)AWSession:(AWSession *)session didFailWithError:(NSError *)error;

/*!
    This method notifies the receiver when the AWSession invalidated the token successfully.
 */
- (void)AWSessionDidInvalidate:(AWSession *)session;

/*!
    This method notifies the receiver when the AWSession failed to invalidate the token.
 */
- (void)AWSession:(AWSession *)session failedToInvalidateTokenWithError:(NSError *)error;
@end
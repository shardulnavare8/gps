/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWTermsOfUse.h */

#import <Foundation/Foundation.h>

/** @name Check TermsOfUse  Completion Handler Block*/
//@{
/* A callback block used to check TermsOfUse acceptanceRequired status of a device
 //@return status : success or failure of the operation
 //@return touAcceptanceRequired : a bool value indicates need of acceptance of  terms of use
 //@return outError: details of error in case of failure of operation
 **/

typedef void (^ CheckTOUCompletionHandler) (BOOL status,BOOL touAcceptanceRequired,NSError *error);

//@}

/** @name Fetch/Accepted TermsOfUse  Completion Handler Block*/
//@{
/* A callback block used to give terms of use content Id, content and application list
 //@return status : success or failure of the operation
 //@return touContentId : Terms of Use content Id
 //@return touContent : Terms of Use content string.
 //@return appsList : Array of applications.
 //@return outError: details of error in case of failure of operation
 **/

typedef void (^ FetchTOUCompletionHandler) (BOOL status,NSUInteger touContentId,NSString *touContent,NSArray *appsList,NSError *error);

//@}

/** @name Accept/Reject TermsOfUse  Completion Handler Block*/
//@{
/* A callback block used to accept/reject terms of use
 //@return status : success or failure of the operation
 //@return outError: details of error in case of failure of operation
 **/

typedef void (^ UserActionTOUCompletionHandler)(BOOL status,NSError *error);

//@}


/**
 @brief		Provides an interface to expose methods for internal apps and SDK-enabled apps to consume Terms of Use.
 @version 3.7.1
 */

@interface AWTermsOfUse : NSObject

/** @name Check Status of TermsOfUse */
//@{

/** This method uses a block to check TermsOfUse status.
 
 @param CheckTOUCompletionHandler: The callback block to be executed when a check TermsOfUse status operation is complete,
 and also get response of TermsOfUse acceptanceRequired status in boolean object.
 */

+ (void) checkTermsOfUse:(CheckTOUCompletionHandler) handler;

//@}


/** @name Fetch TermsOfUse */
//@{

/** This method uses a block to fetch TermsOfUse that should be accepted.
 
 @param FetchTOUCompletionHandler: The callback block to be executed when a fetch TermsOfUse  operation is complete,
 and also get response of TermsOfUse conetnt Id and content.
 */

+ (void) fetchTermsOfUse:(FetchTOUCompletionHandler) handler;

//@}


/** @name Accept TermsOfUse */
//@{

/** This method uses a block to accept TermsOfUse.
 
 @param contentId of Accepted TermsOfUse.
 @param UserActionTOUCompletionHandler: The callback block to be executed when accept TermsOfUse  operation is complete,
 and also get response of status of operation.
 */
+ (void) acceptTermsOfUseForContentId:(NSInteger)contentId andHandler:(UserActionTOUCompletionHandler) handler;

//@}


/** @name Reject TermsOfUse */
//@{

/** This method uses a block to reject TermsOfUse.
 
 @param contentId of rejected TermsOfUse.
 @param UserActionTOUCompletionHandler: The callback block to be executed when reject TermsOfUse operation is complete,
 and also get response of status of operation.
 */
+ (void) rejectTermsOfUseForContentId:(NSInteger)contentId andHandler:(UserActionTOUCompletionHandler) handler;

//@}



/** @name Fetch Accepted TermsOfUse for Content Id */
//@{

/** This method uses a block to fetch accepted TermsOfUse.
 
 @param contentId of  TermsOfUse.
 @param FetchTOUCompletionHandler: The callback block to be executed when accept TermsOfUse  operation is complete,
 and also get response of status of operation.
 */
+ (void) fetchAcceptedTermsOfUseWithContentId:(NSInteger)contentId andHandler:(FetchTOUCompletionHandler) handler;

//@}


/** @name Fetch Accepted TermsOfUse */
//@{

/** This method uses a block to fetch accepted TermsOfUse.
 
 @param FetchTOUCompletionHandler: The callback block to be executed when accept TermsOfUse  operation is complete,
 and also get response of status of operation.
 */
+ (void) fetchAcceptedTermsOfUse:(FetchTOUCompletionHandler) handler;
//@}


@end

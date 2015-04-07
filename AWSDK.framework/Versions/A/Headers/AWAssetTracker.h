/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWAssetTracker.h */


#import <AWSDK/AWSession.h>
#import <Foundation/Foundation.h>
#import <Foundation/Foundation.h>


/** @name Completion Handler Block*/
//@{
/* A callback block used to checkin or checkout a device
//@return success : success or failure of the operation
//@return outError: details of error in case of failure of operation
 **/

typedef void ( ^CompletionHandler)(BOOL success, NSError **outError);

//@}


/** @name Status Handler Block */
//@{
/* A callback block used to find the checkin or checkout status of the device
@param success: success or failure of the operation
@param checkedout: bool giving if device is checkedout
@param lastChangeDate: The date time of the last check-out or check-in operation
@param userName : contains the checkedout/checkedin username of the device
@param group: contains the checkedout / checkedin Location Group of the device
@param outError: details of error in case of failure of operation 
 **/

typedef void ( ^StatusHandler)(BOOL success, BOOL checkedOut, NSDate * lastChangeDate, NSString * userName, NSString * group, NSError **outError);

//@}


static NSString *const kAssetTrackerErrorTitleKey = @"LocalizedTitle";
static NSString *const kAssetTrackerErrorMessageKey = @"LocalizedMessage";

/**
 * An enum holding all the possible Asset Tracker Status.
 */

typedef enum {
    AWAssetTrackerStatusOK = 0,                /** AssetTracker Status - OK */
    AWAssetTrackerStatusInvalidCredentials,    /** AssetTracker Status - Invalid Credentials */
    AWAssetTrackerStatusDeviceNotEnrolled,     /** AssetTracker Status - Device is not enrolled */
    AWAssetTrackerStatusDeviceNonCompliant,    /** AssetTracker Status - Device is non compliant */
    AWAssetTrackerStatusInvalidLocationGroup,  /** AssetTracker Status - Location group is invalid */
    AWAssetTrackerStatusDeviceCheckedOut,      /** AssetTracker Status - Device is Checked Out */
    AWAssetTrackerStatusDeviceCheckedIn,       /** AssetTracker Status - Device is Checked In */
    AWAssetTrackerStatusInvalidCheckOutRequest,/** AssetTracker Status - Checkout request is Invalid */
    AWAssetTrackerStatusServerError,           /** AssetTracker Status - Server Error */
    AWAssetTrackerStatusSharedDeviceDisabled   /** AssetTracker Status - Shared Device Disabled */
} AWAssetTrackerStatus;


/**
 @brief: The AWAssetTracker provides an interface for AssetManagement of a corporate asset/device.
 It can be used to provide services to checkout or checkin a device and get a checkout/checkedin
 status of the device
 
 */

@interface AWAssetTracker:NSObject <AWSessionDelegate, NSURLConnectionDelegate,
                                    NSURLConnectionDataDelegate>


/** @name Checking Out a Device */
//@{

/** This method uses a block to checkout a device.
 
 @param AWsession object containing username, activation group and password.
 @param CompletionHandler: The callback block to be executed when a check-in operation is complete,
 and also get response of check-in success or failure in boolean object.
 */

- (void)checkoutWithSession:(AWSession *)session
   withCompletionHandler:(CompletionHandler)handler;

//@}


/** @name Checking In a Device */
//@{

/** This method uses a block to Checkin a device.
 
 @param AWsession object containing username, activation group and password.
 @param CompletionHandler: The callback block to be executed when a check-in operation is complete, 
 and also get response of check-in success or failure in boolean object.
 */

- (void)checkinWithSession:(AWSession *)session
   withCompletionHandler:(CompletionHandler)handler;

//@}



/** @name Getting the Status */
//@{

/** This method is used for getting the checked out status of a device. 
 
 @param StatusHandler:  The callback block to be executed when a response about check-in/checkout 
 status is recive from airwatch console. The parameter returned includes succees/failure of operation,
 device checkedin or checkedout, date of the last checkin/checkout operation, username and group 
 under which device was checkin/checkedout
*/

- (void)statusWithCompletionHandler:(StatusHandler)handler;

//@}


@end

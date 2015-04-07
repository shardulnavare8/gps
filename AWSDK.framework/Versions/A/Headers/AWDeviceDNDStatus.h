/*
 AirWatch iOS Software Development Kit
 Copyright © 2013 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWDeviceDNDStatus.h */


#import <Foundation/Foundation.h>

/**
 @brief		Provides an interface to query/set device DND status from/on the server.
 */

@interface AWDeviceDNDStatus : NSObject


/** @name Fetch Device DND Status */
//@{
/** Queries the AirWatch server to get the current DND status for the device, if DND is enabled.
 
 @param block   The callback block to be executed when a response is received
    from the AirWatch console, and get response of DND status in boolean object and DND enable period in NSDate object.
 */

+ (void)fetchDeviceDNDStatus:(void(^)(BOOL responseStatus, BOOL dndStatus, NSDate *dndTime, NSError *error))block;

//@}



/** @name Set Device DND state */
//@{
/** Set the DND state to TRUE OR FALSE on the AirWatch Server.
 
 @param setDndState     The DND state to be set on the server.
 
 @param callBackBlock   The callback block to be executed when a response is received from
    the AirWatch console, and get response of DND status in boolean object and DND enable period in NSDate object.
 */

+ (void)setDeviceDNDStatus:(BOOL)setDndState completionBlock:(void(^)(BOOL responseStatus, BOOL dndStatus, NSDate *dndTime, NSError *error))block;

//@}


@end

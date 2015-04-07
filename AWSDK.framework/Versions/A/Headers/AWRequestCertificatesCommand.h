/*
 * AirWatch iOS Software Development Kit
 * Copyright © 2013 AirWatch. All rights reserved.
 *
 * Unless required by applicable law, this Software Development Kit and sample
 * code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. AirWatch expressly disclaims any and all
 * liability resulting from User’s use of this Software Development Kit. Any
 * modification made to the SDK must have written approval by AirWatch.
 */

/*! @file AWRequestCertificatesCommand.h */

#import <AWSDK/AWCommand.h>


/**
 @brief     Request Certificates Command
 @details   This command is used to signal the request of current certificates in the device.
            This is to support the revocation of unused certificates.
            It is in the best interest of the developer to provide the list of active certificates
            so that the console can revoke them. The list must be provided by the developer.
 @version 3.7.1
 */
@interface AWRequestCertificatesCommand : AWCommand

@end

/*! 
 *  @brief      AirWatch SDK framework umbrella.
 *  @details    A framework header umbrella. Once imported, you can use any feature of the AirWatch SDK.
 *  @version 3.7.1
 *  @file       AWSDKCore.h
 */

/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

// Actions that can be performed on the device e.g. restrict access, lock user, wipe device, etc.
#import <AWSDK/AWAction.h>

//======== Common ========
#import <AWSDK/AWCommon.h>
#import <AWSDK/AWMacro.h>
#import <AWSDK/AWSDKErrors.h>

//======== Access Restriction ========
#import <AWSDK/AWRestrictionsPayload.h>

//======== Analytics ========
#import <AWSDK/AWAnalyticsPayload.h>

//======== Authentication ========
#import <AWSDK/AWAuthenticationPayload.h>

//======== Beacon ========
#import <AWSDK/AWBeacon.h>

#if	TARGET_OS_IPHONE
//======== Branding ========
    #import <AWSDK/AWBrandingPayload.h>
    #import <AWSDK/AWBranding.h>
#endif



//======== Security ========
#import <AWSDK/AWCertificatePayload.h>
#import <AWSDK/AWCertificateTrust.h>

//======== Command Manager ========
#import <AWSDK/AWCommandManager.h>

//======== Policies ========
#import <AWSDK/AWCompliancePayload.h>

//======== Contents ========
#import <AWSDK/AWContentCategory.h>
#import <AWSDK/AWContentController.h>
#import <AWSDK/AWContentEntity.h>
#import <AWSDK/AWContentVersion.h>
#import <AWSDK/AWContentFolder.h>
#import <AWSDK/AWContentRepository.h>
#import <AWSDK/AWRemoveContentCommand.h>

//======== Device ========
#import <AWSDK/AWDeviceStatusConfiguration.h>
#import <AWSDK/AWDeviceStatusController.h>

//======== Enrollment ========
#import <AWSDK/AWEnrollmentAccount.h>
#import <AWSDK/AWEnrollmentAccountAuthenticator.h>
#import <AWSDK/AWEnrollmentAuthenticationCredentialsTypes.h>

//======== Geofencing ========
#import <AWSDK/AWGeofence.h>
#import <AWSDK/AWGeofencePayload.h>
#import <AWSDK/AWGeofenceService.h>
#import <AWSDK/AWLocationModeTypes.h>

//======== Profiles ========
#import <AWSDK/AWInstallContentCommand.h>
#import <AWSDK/AWInstallProfileCommand.h>
#import <AWSDK/AWProfilePayload.h>

/*
//======== Data Sampler ========
#import <AWSDK/AWDataSampler.h>
#import <AWSDK/AWDataSamplerConfiguration.h>
#import <AWSDK/AWDataSamplerTypes.h>
*/
//======== Logging ========
#import <AWSDK/AWLog.h>
#import <AWSDK/AWLogModule.h>

//======== AWServer singleton ========
#import <AWSDK/AWServer.h>
#import <AWSDK/AWSession.h>

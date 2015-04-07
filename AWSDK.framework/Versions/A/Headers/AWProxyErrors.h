/*
 AirWatch iOS Software Development Kit
 Copyright © 2013 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWProxyErrors.h */

#import <Foundation/Foundation.h>

/*! @constatnt Error domain for NSError values stemming from AWProxy */
extern NSString *const AWProxyErrorDomain;

enum
{
	/* Error codes returned from the MAG proxy headers */
    AWProxyErrorMAG407Unknown = 0,
    AWProxyErrorMAG407MissingHeader = 1,
    AWProxyErrorMAG407WrongEncoding = 2,
    AWProxyErrorMAG407IDNotFound = 3,
    AWProxyErrorMAG407WrongALG = 4,
    AWProxyErrorMAG407EmptyCertChain = 5,
    AWProxyErrorMAG407SingleSigner = 6,
    AWProxyErrorMAG407SingleSignerCert = 7,
    AWProxyErrorMAG407InvalidSign = 8,
    AWProxyErrorMAG407UntrustedIssuer = 9,
    AWProxyErrorMAG407MissingSignTime = 10,
    AWProxyErrorMAG407PotentialReplay = 11,
    AWProxyErrorMAG407ForbiddentMethod = 12,
    AWProxyErrorMAG407DataUnavailable = 13,
    AWProxyErrorMAG407InvalidThumbprint = 14,
    AWProxyErrorMAG407NotCompliant = 15,
    AWProxyErrorMAG407NotManaged = 16,
    
    AWProxyError = 1000, /* Generic Proxy Error */
    AWProxyError407 = 1001,
	
	/* Connection errors */
	AWProxyErrorConnectionClosedPrematurely = 1100,
    AWProxyErrorFailedToWriteToSocket = 1101,
	AWProxyErrorFailedToCreateStream = 1102,
    AWProxyErrorOutputStreamDoesNotExist = 1103,
    AWProxyErrorFailedToCreateResponseFromStream = 1104,
    AWProxyErrorFailedToCreateNTLMType1Message = 1105,
    AWProxyErrorFailedToCreateNTLMInfo = 1106,
    AWproxyErrorFailedToCreateNTLMType3Message = 1107,
    AWProxyErrorUnknownURLScheme = 1108,
    
	/* SSL Errors */
    AWProxySSLCertificateValidationError = 2000,
	
	/* Configuration Errors */
    AWProxyErrorAutoConfigURLMissing = 4000,
    AWProxyErrorFailedToGetPACScript = 4001,
    AWProxyErrorInvalidDataFromPACURL = 4002,
    AWProxyErrorProxyIsNotConfigured = 4003,
    AWProxyErrorFailedToRegisterProtocol = 4004,
	
    
	/* F5 Proxy Errors */
	AWPRoxyErrorF5Error = 5000,
    AWProxyErrorF5DNSResolutionFailed = 5001,
    AWProxyErrorF5FailedToConnect = 5002,
    AWProxyErrorF5UsernameAuthFailed = 5003,
    AWProxyErrorF5FailedToSetClientIdentity = 5004,
    AWProxyErrorF5FailedToCheckSessionLifetime = 5005,
    AWProxyErrorF5FailedToSetSession = 5006,
    
	/* MAG Proxy errors */
    AWProxyErrorFailedToSignRequest = 6000,
	AWProxyErrorFailedToFetchMAGCertWithHMAC = 6001,
	AWProxyErrorCertRequestInProgress = 6002,
    AWProxyErrorCertNotPresent = 6003
};
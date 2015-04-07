/*
AirWatch iOS Software Development Kit
Copyright © 2013 AirWatch. All rights reserved.

Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
*/

/*! \file AWProxyPayload.h */

#import <AWSDK/AWProfilePayload.h>

extern NSString *const kProxyPayloadType;
extern NSString *const kProxyPayloadTypeV2;

typedef NS_ENUM(NSInteger, AWProxyType) {
    AWProxyTypeUnknown = -1,
    AWProxyTypeNone = 0,
    AWProxyTypeMAG = 1,
    AWProxyTypeF5 = 2,
    AWProxyTypeStandard = 3
};

typedef NS_ENUM(NSInteger, AWF5AuthenticationMode) {
    AWF5AuthenticationModeUsernamePasswordAndCertificate = 0,
    AWF5AuthenticationModeUsernameAndPassword,
    AWF5AuthenticationModeCertificate
};

@interface AWProxyPayload : AWProfilePayload

@property (nonatomic, assign) AWProxyType proxyType;

@property (nonatomic, assign) BOOL redirectTraffic;

@property (nonatomic, retain) NSString *hostName;

@property (nonatomic, retain) NSNumber *httpPort;

@property (nonatomic, retain) NSNumber *httpsPort;

// V2 Settings
@property (nonatomic, readonly) BOOL publicSSL;

@property (nonatomic, readonly) BOOL f5Integration;

@property (nonatomic, readonly) NSNumber *f5Port;

@property (nonatomic, readonly) NSString *f5Host;

@property (nonatomic, readonly) BOOL f5UseAuthentication;

@property (nonatomic, readonly) NSNumber *f5UserAccountType;

@property (nonatomic, readonly) NSString *f5UserAccountName;

@property (nonatomic, readonly) NSString *f5UserAccountPassword;

@property (nonatomic, readonly) AWF5AuthenticationMode f5AuthenticationMode;

@property (nonatomic, readonly) NSArray *appTunnelDomains;

// Standard Proxy

@property (nonatomic, assign) BOOL standardProxyUseAuth;

@property (nonatomic, readonly) NSString *standardProxyUsername;

@property (nonatomic, readonly) NSString *standardProxyPassword;

@property (nonatomic, assign) BOOL standardProxyAutoConfig;

@property (nonatomic, readonly) NSString *standardProxyAutoConfigURL;

@end

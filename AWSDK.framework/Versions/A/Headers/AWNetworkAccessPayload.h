/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWNetworkAccessPayload.h */

#import <AWSDK/AWProfilePayload.h>

extern NSString *const kNetworkAccessPayloadTypeV2;

typedef NS_ENUM(NSInteger, AWNetworkAccessAllowCellular) {
    AWNetworkAccessAllowCellularAlways = 0,
    AWNetworkAccessAllowCellularNotRoaming = 1,
    AWNetworkAccessAllowCellularNever = 2
};

typedef NS_ENUM(NSInteger, AWNetworkAccessAllowWiFi) {
    AWNetworkAccessAllowWiFiAlways = 1,
    AWNetworkAccessAllowWiFiFilter = 2
};

@interface AWNetworkAccessPayload : AWProfilePayload

@property (nonatomic, readonly) BOOL enableNetworkAccess;
@property (nonatomic, readonly) AWNetworkAccessAllowCellular allowCellularConnection;
@property (nonatomic, readonly) AWNetworkAccessAllowWiFi allowWifiConnection;
@property (nonatomic, readonly) NSArray *allowedSSIDs;

@end

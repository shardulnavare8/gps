//
//  ApplicationInfo.h
//  AWWorkspace
//
//  Created by Pranay Swar on 5/30/13.
//  Copyright (c) 2013 airwatch. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AWApplicationState) {
    AWApplicationStateNone = 0,
    AWApplicationStateNormal,
    AWApplicationStateUnloaded,
    AWApplicationStateNotInstalled,
    AWApplicationStateUpdateAvalible,
    AWApplicationStateNotification
};

typedef enum {
    AWApplicationTypeNone = 0,
    AWApplicationTypeAll,
    AWApplicationTypeInternal,
    AWApplicationTypePublic,
    AWApplicationTypePurchased,
    AWApplicationTypeWebApp
}AWApplicationType;

typedef enum {
    AWApplicationPushModeNone = 0,
    AWApplicationPushModeAuto,
    AWApplicationPushModeOnDemand
}AWApplicationPushMode;

@interface ApplicationInfo : NSObject

@property (nonatomic, retain) NSString *appName;
@property (nonatomic, retain) NSString *bundleId;
@property (nonatomic, retain) NSString *scheme;
@property (nonatomic, retain) UIImage  *appIconImage;
@property (nonatomic, retain) NSString *largeIconUrl;
@property (nonatomic, retain) NSString *mediumIconUrl;
@property (nonatomic, retain) NSString *smallIconUrl;
@property (nonatomic, assign) NSInteger notificationNumber;
@property (nonatomic, retain) NSString *appVersion;
@property (nonatomic, retain) NSString *buildVerison;
@property (nonatomic, retain) NSString *appInstalledVersion;
@property (nonatomic, retain) NSString *appInstaledBuildVersion;
@property (nonatomic, assign) BOOL      allowDeletion;
@property (nonatomic, assign) BOOL      updateAvailable;
@property (nonatomic, assign) AWApplicationState appState;
@property (nonatomic, assign) AWApplicationType appType;
@property (nonatomic, assign) AWApplicationPushMode appPushMode;
@property (nonatomic, assign) BOOL didFetchIconImage;
@property (nonatomic, retain) NSString *webClipUrl;
@property (nonatomic, retain) NSString *publicAppUrl;

- (id)initWithDictionary:(NSDictionary *)dictionary;

- (UIImage *)appImage;

@end

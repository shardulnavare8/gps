/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch. 
 */

/*! \file AWBranding.h */

#import <Foundation/Foundation.h>
#import <AWSDK/AWMacro.h>
#import <AWSDK/AWBrandingPayload.h>

/** Notification that is posted immediately after a skin is updated. */
extern NSString *const AWBrandingSkinDidUpdateNotification;

/** 
 @brief		Branding controller used to manipulate brand skins.
 @details	AWBranding is an object that can be used for branding of Content Locker. It takes in a dictionary, which should be a set of settings for a specific brand.
 @version 3.7.1
 */
@interface AWBranding : NSObject
{
    
}

/**
 @brief Custom branding source bundle
 @details AWBranding can be set to pull branding information from an included Bundle file other than the app's main bundle. The default is source is from the main bundle of the app. If the source branding bundle is not from the app's main bundle, a custom directory will be created in the app's Document directory to store all the branding resources. To set it back to use the app's main bundle, a nil value or main bundle can be set for this property.
 */
@property (nonatomic, retain) NSBundle *sourceBrandingBundle;

/** Brand Intializer. 
 
 @brief AWBranding object made by this function. 
 @param configDictionary The dictionary representation of settings to create a brand.
 @return A newly initialized enrollment account. 
 */
+ (AWBranding *) sharedBranding;
//@}

- (NSString *)title;
- (NSString *)organizationName;

- (UIColor *)loginTitleColor;
- (UIColor *)primaryColor;
- (UIColor *)secondaryColor;
- (UIColor *)tertiaryColor;
- (UIColor *)toolbarColor;

- (UIColor *)primaryTextColor;
- (UIColor *)secondaryTextColor;
- (UIColor *)tertiaryTextColor;

- (UIImage *)primaryImage;
- (UIImage *)secondaryImage;

// AppWrap only
- (UIColor *)backgroundColor;
- (UIColor *)toolbarColor2;
- (UIColor *)toolbarTextColor;
- (UIColor *)textColor;

- (BOOL)usePrimaryImage;
- (BOOL)useSecondaryImage;
- (BOOL)enablePoweredBy;
- (BOOL)customBrandingEnabled;

- (UIColor *) getLoginTitleColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getPrimaryColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getSecondaryColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getTertiaryColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getPrimaryText AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getSecondaryText AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getTertiaryText AW_DEPRECATED_ATTRIBUTE;
- (NSString *) getTitle AW_DEPRECATED_ATTRIBUTE;
- (UIImage *) getPrimaryImage AW_DEPRECATED_ATTRIBUTE;
- (UIImage *) getSecondaryImage AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getSettingTitleBarColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *) getSettingIconColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *)settingsTitleBarColor AW_DEPRECATED_ATTRIBUTE;
- (UIColor *)settingsIconColor AW_DEPRECATED_ATTRIBUTE;

- (void) parseBrandingInfoFromCommand:(NSDictionary *)brandingDictionary;

/*!
 Persists the branding settings contained in a payload. This must be called
 to set any of the branding attributes.
 @param payload The AWBrandingPayload containing the settings to be persisted.
 */

- (void)synchronizeBrandingFormPayload:(AWBrandingPayload *)payload;

@end

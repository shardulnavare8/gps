/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */

/*! \file AWAppCatalogApplication.h */


#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>


typedef enum {
	kReimbursementNotApplicable = -1,               ///< Reimbursement not applicable.
	kReimbursementNo,                               ///< Reimbursement not available.
	kReimbursementYes                               ///< Reimbursement available.
} AWAppCatalogPublicApplicationReimbursementType;


/**
 @brief		Root class of most of AWAppCatalogCore application types.
 @details	Through "AWAppCatalogApplication" application objects inherit a basic application interface.
 @version	1.0
 */
@interface AWAppCatalogApplication : NSObject {
    
}


/**
 The application icon image object.
 */
@property (nonatomic, retain) UIImage *iconImage;

/**
 The application icon image blob.
 */
@property (nonatomic, copy) NSData *iconData;

/**
 The URL of application's large icon.
 */
@property (nonatomic, copy) NSString *largeIconUrl;

/**
 The URL of application's medium icon.
 */
@property (nonatomic, copy) NSString *mediumIconUrl;

/**
 The URL of application's small icon.
 */
@property (nonatomic, copy) NSString *smallIconUrl;

/**
 The application name.
 */
@property (nonatomic, copy) NSString *name;

/**
 The application version.
 */
@property (nonatomic, copy) NSString *version;

/**
 The application bundle identifier.
 */
@property (nonatomic, copy) NSString *bundleId;

/**
 The URL of application's screen shots.
 */
@property (nonatomic, retain) NSMutableArray *screenshotUrls;

/**
 The application's description text.
 */
@property (nonatomic, copy) NSString *applicationDescription;

/**
 The application's license agreement text.
 */
@property (nonatomic, copy) NSString *license;

/**
 The URL of application's manifest.
 */
@property (nonatomic, copy) NSString *manifestUrl;

/**
 The application's department.
 */
@property (nonatomic, copy) NSString *department;

/**
 The application's support phone.
 */
@property (nonatomic, copy) NSString *supportPhone;

/**
 The application's support email.
 */
@property (nonatomic, copy) NSString *supportEmail;

/**
 The URL of application's support website.
 */
@property (nonatomic, copy) NSString *supportUrl;

/**
 The email where the users can leave their feedback about the application.
 */
@property (nonatomic, copy) NSString *feedbackEmail;

/**
 The categories to which the application belongs to.
 */
@property (nonatomic, copy) NSMutableArray *categories;

/**
 The application's SKU code.
 */
@property (nonatomic, copy) NSString *sku;

/**
 Boolean object indicating whether the application has Eula.
 */
@property (nonatomic, assign) BOOL hasEula;

/**
 The application's major revision number.
 */
@property (nonatomic, copy) NSString *verMajor;

/**
 The application's minor revision number.
 */
@property (nonatomic, copy) NSString *verMinor;

/**
 The application's build version number.
 */
@property (nonatomic, copy) NSString *verBuild;

/**
 The application's identifier.
 */
@property (nonatomic, copy) NSNumber *applicationId;

/**
 Date object on which the application was posted.
 */
@property (nonatomic, copy) NSDate *postDate;

/**
 The importance of the application.
 */
@property (nonatomic, copy) NSString *importance;

/**
 Boolean object indicating whether the application is installed.
 */
@property (nonatomic, assign) BOOL installed;

/**
 The application's root location group.
 */
@property (nonatomic, copy) NSString *rootLg;

/**
 The application's root location group.
 */
@property (nonatomic, copy) NSString *locationGroup;

/**
 The location groups to which the application belongs.
 */
@property (nonatomic, copy) NSMutableArray *locationGroups;

/**
 The application's url.
 */
@property (nonatomic, copy) NSString *url;

/**
 The company which developed the application.
 */
@property (nonatomic, copy) NSString *company;

/**
 Indicates whether reimbursement is applicable and available with the application.
 */
@property (nonatomic, assign) AWAppCatalogPublicApplicationReimbursementType reimbursement;

/**
 The various comments on the application by the users.
 */
@property (nonatomic, copy) NSString *comments;

/**
 The Application's rank/rating.
 */
@property (nonatomic, assign) int rank;

/**
 Boolean object indicating the application is managed.
 */
@property (nonatomic, assign) BOOL managed;


@end

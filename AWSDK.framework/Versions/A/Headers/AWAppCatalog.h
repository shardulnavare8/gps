//
//  AWAppCatalog.h
//  AirWatch
//
//  Created by Syed Yusuf on 5/30/13.
//  Copyright (c) 2013 AirWatch. All rights reserved.
//

#import <Foundation/Foundation.h>


@class AWAppCatalogApplication;

/**
 @brief
 @version 1.1
 */
@interface AWAppCatalog : NSObject {

}

/**
 Retrieves all the Internal Applications
 
 @brief By using this method user can fetch available internal applications and onSuccessfully fetching \link (void(^)(BOOL success, NSError *error, NSArray *internalApplications))completion \endlink block gets notified and get internal applications in NSArray object. On failing to fetching internal applications \link (void(^)(BOOL success, NSError *error, NSArray *internalApplications))completion \endlink block gets notified and get error in NSError object.
 */
- (void)fetchInternalApplicationsWithCompletion:
    (void(^)(BOOL success, NSError *error, NSArray *internalApplications))completion;

/**
 Retrieves all the Public Applications
 
 @brief By using this method user can fetch available public recomended applications and onSuccessfully fetching \link (void(^)(BOOL success, NSError *error, NSArray *publicApplications))completion \endlink block gets notified and get public applications in NSArray object. On failing to fetching public applications \link (void(^)(BOOL success, NSError *error, NSArray *publicApplications))completion \endlink block gets notified and get error in NSError object.
 */
- (void)fetchPublicApplicationsWithCompletion:
    (void(^)(BOOL success, NSError *error, NSArray *publicApplications))completion;

/**
 Retrieves all the Blacklisted Applications
 
 @brief By using this method user can fetch available public blacklisted applications and onSuccessfully fetching \link (void(^)(BOOL success, NSError *error, NSArray *blackListedApplications))completion \endlink block gets notified and get blacklisted applications in NSArray object. On failing to fetching blacklisted applications \link (void(^)(BOOL success, NSError *error, NSArray *blackListedApplications))completion \endlink block gets notified and get error in NSError object.
 */
- (void)fetchBlacklistedApplicationsWithCompletion:
    (void(^)(BOOL success, NSError *error, NSArray *blackListedApplications))completion;

/**
 Retrieves all the available Application Updates
 
 @brief By using this method user can fetch available application updates and onSuccessfully fetching \link (void(^)(BOOL success, NSError *error, NSArray *updateApplications))completion \endlink block gets notified and get updated applications in NSArray object. On failing to fetching updated applications \link (void(^)(BOOL success, NSError *error, NSArray *updateApplications))completion \endlink block gets notified and get error in NSError object.
 */
- (void)fetchApplicationUpdatesWithCompletion:
    (void(^)(BOOL success, NSError *error, NSArray *updateApplications))completion;

/**
 Retrieves all the available info of the given application
 
 @brief By using this method user can fetch available info of an application and onSuccessfully fetching \link (void(^)(BOOL success, NSError *error, AWAppCatalogApplication *application))completion  \endlink block gets notified and get the application in AWAppCatalogApplication object. On failing to fetching application info \link (void(^)(BOOL success, NSError *error, AWAppCatalogApplication *application))completion \endlink block gets notified and get error in NSError object.
 @param application The Application whose application id used to identify the application info.
 */
- (void)fetchInfoForApplication:(AWAppCatalogApplication *)application
                 withCompletion:(void(^)(BOOL success, NSError *error, AWAppCatalogApplication *application))completion;

/**
 Retrieves icon data of the given application
 
 @brief By using this method user can fetch icon data of an application and onSuccessfully fetching \link (void(^)(BOOL success, NSError *error,  NSData *iconData))completion  \endlink block gets notified and get the data in iconData object. On failing to fetching icon data \link (void(^)(BOOL success, NSError *error, NSData *iconData))completion \endlink block gets notified and get error in NSError object.
 @param application The Application whose icon data is needed to be fetched.
 */
- (void)fetchIconForApplication:(AWAppCatalogApplication *)application
                 withCompletion:(void(^)(BOOL success, NSError *error, NSData *iconData))completion;

@end

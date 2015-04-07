/*
 AirWatch iOS Software Development Kit
 Copyright © 2012 AirWatch. All rights reserved.
 
 Unless required by applicable law, this Software Development Kit and sample code is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 KIND, either express or implied. AirWatch expressly disclaims any and all liability resulting from User’s use of this Software Development Kit. Any modification made to the SDK must have written approval by AirWatch.
 */
/*! \file AWProxy.h */

#import <Foundation/Foundation.h>

typedef enum
{
    AWProxyServerTypeUnknown = -1,
    AWProxyServerTypeStandard = 0,
    AWproxyServerTypeMAG = 1,
}AWProxyServerType;

typedef void (^certificateFetchCallback)(BOOL success, NSError *error);

@class AWProxyCredentials;


@protocol AWProxyDelegate <NSObject>

@required
- (AWProxyCredentials *)useCredentialsForProxyAuthentication;
- (void)proxyFailedWithError:(NSError *)error;

@optional

- (BOOL)proxyShouldHandleRequest:(NSURLRequest *)request;

@end


@interface AWProxy : NSObject


/**
 The hostname of MAG proxy.
 */
@property(nonatomic, copy)NSString *host;

/*!
 The port to connect MAG proxy.
 */
@property(nonatomic, assign)NSInteger httpPort;

/*!
 The port to use for secure connections to the proxy.
 @discussion If the proxy only accepts connections over one port httpsPort is used.
 */
@property(nonatomic, assign)NSInteger httpsPort;

/**
 The MAG proxy requires password.
 */
@property(nonatomic, assign) BOOL requiresAuth;

@property (nonatomic, retain) AWProxyCredentials *credentials;

@property (nonatomic, assign) AWProxyServerType type;


@property (nonatomic, retain) NSURL *autoConfigURL;


/** Property to indicate whether or not traffic is currently routed through the proxy. **/
@property(nonatomic, assign, readonly)BOOL isEnabled;

/** 
 Property to indicate whether it supports Public SSL certificate or Airwatch Internal certificate. 
 Default is Airwatch Internal Certificate /. 
 */
@property (nonatomic, assign) BOOL usePublicMAGCert;


@property (nonatomic, assign) BOOL shouldSignRequests;

@property (nonatomic, assign) id<AWProxyDelegate> delegate;

@property (nonatomic, retain) NSURLCache *sharedProxyCache;

/**  Gets the shared instance of the MAG Proxy module.
 Method should be called when other classes need to access the MAGProxy instance.
 @return a pointer to the AWProxy object.
 */
+ (AWProxy*)sharedInstance;

/*!
 @method configure 
 @abstract Configure the AirWatch Proxy 
 @discussion Configure Airwatch Proxy with host, http port, https port and server type.
 */
- (void)configureWithHost:(NSString *)host httpPort:(NSInteger)http httpsPort:(NSInteger)https serverType:(AWProxyServerType)type;


/*!
 @method fetchMAGCertificate
 @abstract Fetches certificate required for MAG Proxy
 */
- (void)fetchMAGCertificate:(certificateFetchCallback)callback;

/*!
 @method start
 @abstract This method registers the AirWatch Proxy implementation
 to hook all calls through NSURLConnection, and route via the
 AirWatch Mobile Access Gateway. 
 @discussion If your applications makes calls at the CFNetwork layer
 instead of the NSURL* layer, the calls will not be intercepted for
 proxy. Only connections at the NSURL* layer will be intercepted.
 @return BOOL indicating if the service was started. The only reason this would be NO is if the
 server property is nil.
 */
- (BOOL)start:(NSError**)error;

/*!
 @method stop
 @abstract Stop using the AirWatch Proxy.
 @discussion After stopping, the AirWatch proxy is no longer used
 to route traffic via the MAG Proxy.
 */
- (void)stop;

@end

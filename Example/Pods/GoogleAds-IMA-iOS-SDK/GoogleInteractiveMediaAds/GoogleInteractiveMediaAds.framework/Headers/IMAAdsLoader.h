//
//  IMAAdsLoader.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Declares a set of classes used when loading ads.

#import <Foundation/Foundation.h>

@class IMAAdError;
@class IMAAdsLoader;
@class IMAAdsManager;
@class IMAStreamManager;
@class IMAAdsRequest;
@class IMAStreamRequest;
@class IMASettings;

#pragma mark - IMAAdsLoadedData

/**
 *  Ad data that is returned when the ads loader loads the ad.
 */
@interface IMAAdsLoadedData : NSObject

/**
 *  The ads manager instance created by the ads loader.
 *  Will be nil when using dynamic ad insertion.
 */
@property(nonatomic, strong, readonly) IMAAdsManager *adsManager;

/**
 *  The stream manager instance created by the ads loader.
 *  Will be nil when requesting ads client side.
 */
@property(nonatomic, strong, readonly) IMAStreamManager *streamManager;

/**
 *  The user context specified in the ads request.
 */
@property(nonatomic, strong, readonly) id userContext;

@end


#pragma mark - IMAAdLoadingErrorData

/**
 *  Ad error data that is returned when the ads loader fails to load the ad.
 */
@interface IMAAdLoadingErrorData : NSObject

/**
 *  The ad error that occurred while loading the ad.
 */
@property(nonatomic, strong, readonly) IMAAdError *adError;

/**
 *  The user context specified in the ads request.
 */
@property(nonatomic, strong, readonly) id userContext;

@end

#pragma mark - IMAAdsLoaderDelegate

/**
 *  Delegate object that receives state change callbacks from IMAAdsLoader.
 */
@protocol IMAAdsLoaderDelegate

/**
 *  Called when ads are successfully loaded from the ad servers by the loader.
 *
 *  @param loader        the IMAAdsLoader that received the loaded ad data
 *  @param adsLoadedData the IMAAdsLoadedData instance containing ad data
 */
- (void)adsLoader:(IMAAdsLoader *)loader adsLoadedWithData:(IMAAdsLoadedData *)adsLoadedData;

/**
 *  Error reported by the ads loader when loading or requesting an ad fails.
 *
 *  @param loader      the IMAAdsLoader that received the error
 *  @param adErrorData the IMAAdLoadingErrorData instance with error information
 */
- (void)adsLoader:(IMAAdsLoader *)loader failedWithErrorData:(IMAAdLoadingErrorData *)adErrorData;

@end

#pragma mark - IMAAdsLoader

/**
 *  The IMAAdsLoader class allows the requesting of ads from the ad server.
 *  Use the delegate to receive the loaded ads or loading error
 *  in case of failure.
 */
@interface IMAAdsLoader : NSObject

/**
 *  SDK-wide settings. Note that certain settings will only be evaluated during initialization of
 *  the adsLoader.
 */
@property(nonatomic, copy, readonly) IMASettings *settings;

/**
 *  Delegate that receives IMAAdsLoaderDelegate callbacks.
 */
@property(nonatomic, weak) id<IMAAdsLoaderDelegate> delegate;

/**
 *  Returns the SDK version.
 *
 *  @return the SDK version
 */
+ (NSString *)sdkVersion;

/**
 *  Initializes an IMAAdsLoader with specific settings. The loader takes 1-2 seconds to setup once
 *  initialized, therefore reusing a single instance of the ads loader is encouraged to minimize ad
 *  request times.
 *
 *  @param settings the IMASettings to use for SDK wide settings. Uses defaults when nil.
 *
 *  @return an IMAAdsLoader instance with given IMASettings
 */
- (instancetype)initWithSettings:(IMASettings *)settings;

/**
 *  Initializes the IMAAdsLoader with default settings. The loader takes 1-2 seconds to setup once
 *  initialized, therefore reusing a single instance of the ads loader is encouraged to minimize ad
 *  request times.
 *
 *  @return an IMAAdsLoader instance with default IMASettings
 */
- (instancetype)init;

/**
 *  Request ads from the ad server. The loader takes 1-2 seconds to setup on init and become ready
 *  to make ad requests. So reusing the same IMAAdsLoader instance is encouraged when making ad
 *  requests in order to minimize ad request times.
 *
 *  @param request the IMAAdsRequest. If it was created for use with Picture-in-Picture, this
 *                 IMAAdsLoader instance's IMASettings must have backround playback enabled
 */
- (void)requestAdsWithRequest:(IMAAdsRequest *)request;

/**
 *  Request a stream with ads inserted dynamically. Reusing the same IMAAdsLoader instance is
 *  encouraged when making stream requests in order to minimize stream request latency.
 *
 *  @param request the stream request
 */
- (void)requestStreamWithRequest:(IMAStreamRequest *)request;

/**
 *  Signal to the SDK that the content has completed. The SDK will play
 *  post-rolls at this time, if any are scheduled.
 */
- (void)contentComplete;

@end

//
//  IMAAdsRequest.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Declares a simple ad request class.

#import <Foundation/Foundation.h>

@class IMAAdDisplayContainer;
@class IMAAVPlayerContentPlayhead;
@class IMAAVPlayerVideoDisplay;
@class IMAPictureInPictureProxy;
@protocol IMAContentPlayhead;

/**
 *  Data class describing the ad request.
 */
@interface IMAAdsRequest : NSObject

/**
 *  Specifies the full URL to use for ads loading from an ad server. Required
 *  for any <code>adsRequest</code>. For details on constructing the ad tag url,
 *  see <a href="https://support.google.com/dfp_premium/answer/1068325">
 *  Create a master video tag manually</a>.
 */
@property(nonatomic, copy, readonly) NSString *adTagUrl;

/**
 *  Specifies a VAST, VMAP, or ad rules response to be used instead of making a
 *  request via an ad tag URL. This can be useful for debugging and other situations
 *  in which an ad response is already available.
 */
@property(nonatomic, copy, readonly) NSString *adsResponse;

/**
 *  The ad display container.
 */
@property(nonatomic, strong, readonly) IMAAdDisplayContainer *adDisplayContainer;

/**
 *  The user context.
 */
@property(nonatomic, strong, readonly) id userContext;

/**
 *  Specifies whether the player intends to start the content and ad in
 *  response to a user action or whether they will be automatically played.
 *  Changing this setting will have no impact on ad playback.
 */
@property(nonatomic) BOOL adWillAutoPlay;

/*
 *  Specifies the duration of the content in seconds to be shown. Used in AdX requests. This
 *  parameter is optional.
 */
@property(nonatomic) float contentDuration;

/*
 *  Specifies the keywords used to describe the content to be shown. Used in AdX requests. This
 *  parameter is optional.
 */
@property(nonatomic, copy) NSArray<NSString *> *contentKeywords;

/*
 *  Specifies the title of the content to be shown. Used in AdX requests. This parameter is
 *  optional.
 */
@property(nonatomic, copy) NSString *contentTitle;

/*
 *  Specifies the VAST load timeout in milliseconds for the initial request and any subsequent
 *  wrappers. This parameter is optional and will override the default timeout.
 */
@property(nonatomic) float vastLoadTimeout;

/*
 *  Specifies the maximum amount of time to wait, after calling requestAds, before requesting
 *  the ad tag URL. This can be used to stagger requests during a live-stream event, in order
 *  to mitigate spikes in the number of requests.
 */
@property(nonatomic) float liveStreamPrefetchSeconds;

/**
 *  Initializes an ads request instance with the given canned ads response and ad display
 *  container with Picture-in-Picture support. Serial ad requests may reuse the
 *  same IMAAdDisplayContainer by first calling [IMAAdsManager destroy] on its
 *  current adsManager. Concurrent requests must use different ad containers.
 *
 *  @param adsResponse           the canned ads response
 *  @param adDisplayContainer    the IMAAdDisplayContainer for rendering the ad UI
 *  @param avPlayerVideoDisplay  the IMAAVPlayerVideoDisplay for rendering ads
 *  @param pictureInPictureProxy the IMAPictureInPictureProxy for tracking PIP events
 *  @param userContext           the user context for tracking requests (optional)
 *
 *  @return the IMAAdsRequest instance
 */
- (instancetype)initWithAdsResponse:(NSString *)adsResponse
                 adDisplayContainer:(IMAAdDisplayContainer *)adDisplayContainer
               avPlayerVideoDisplay:(IMAAVPlayerVideoDisplay *)avPlayerVideoDisplay
              pictureInPictureProxy:(IMAPictureInPictureProxy *)pictureInPictureProxy
                        userContext:(id)userContext;

/**
 *  Initializes an ads request instance with the given canned ads response and ad display
 *  container. Serial ad requests may reuse the same IMAAdDisplayContainer by
 *  first calling [IMAAdsManager destroy] on its current adsManager. Concurrent
 *  requests must use different ad containers. Does not support Picture-in-Picture.
 *
 *  @param adsResponse        the canned ads response
 *  @param adDisplayContainer the IMAAdDisplayContainer for rendering the ad UI
 *  @param contentPlayhead    the IMAContentPlayhead for the content player (optional)
 *  @param userContext        the user context for tracking requests (optional)
 *
 *  @return the IMAAdsRequest instance
 */
- (instancetype)initWithAdsResponse:(NSString *)adsResponse
                 adDisplayContainer:(IMAAdDisplayContainer *)adDisplayContainer
                    contentPlayhead:(NSObject<IMAContentPlayhead> *)contentPlayhead
                        userContext:(id)userContext NS_DESIGNATED_INITIALIZER;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support. Serial ad requests may reuse the
 *  same IMAAdDisplayContainer by first calling [IMAAdsManager destroy] on its
 *  current adsManager. Concurrent requests must use different ad containers.
 *
 *  @param adTagUrl              the ad tag URL
 *  @param adDisplayContainer    the IMAAdDisplayContainer for rendering the ad UI
 *  @param avPlayerVideoDisplay  the IMAAVPlayerVideoDisplay for rendering ads
 *  @param pictureInPictureProxy the IMAPictureInPictureProxy for tracking PIP events
 *  @param userContext           the user context for tracking requests (optional)
 *
 *  @return the IMAAdsRequest instance
 */
- (instancetype)initWithAdTagUrl:(NSString *)adTagUrl
              adDisplayContainer:(IMAAdDisplayContainer *)adDisplayContainer
            avPlayerVideoDisplay:(IMAAVPlayerVideoDisplay *)avPlayerVideoDisplay
           pictureInPictureProxy:(IMAPictureInPictureProxy *)pictureInPictureProxy
                     userContext:(id)userContext;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container. Serial ad requests may reuse the same IMAAdDisplayContainer by
 *  first calling [IMAAdsManager destroy] on its current adsManager. Concurrent
 *  requests must use different ad containers. Does not support Picture-in-Picture.
 *
 *  @param adTagUrl           the ad tag URL
 *  @param adDisplayContainer the IMAAdDisplayContainer for rendering the ad UI
 *  @param contentPlayhead    the IMAContentPlayhead for the content player (optional)
 *  @param userContext        the user context for tracking requests (optional)
 *
 *  @return the IMAAdsRequest instance
 */
- (instancetype)initWithAdTagUrl:(NSString *)adTagUrl
              adDisplayContainer:(IMAAdDisplayContainer *)adDisplayContainer
                 contentPlayhead:(NSObject<IMAContentPlayhead> *)contentPlayhead
                     userContext:(id)userContext NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@end

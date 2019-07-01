//
//  JXAVideoOperator.h
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/19.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "JXAVideoAds.h"
#import "JXAVideoParamsBuilder.h"

@interface JXAVideoOperator : NSObject

@property (nonatomic, strong, readonly) JXAVideoAds *ads;

/**
 *  You have to call the remove method in UIViewController's viewDidDisappear method,
 * destroy the ads operator.
 */

- (void)remove;

/**
 *  Clear the current playing state
 */

- (void)clear;


/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container.  Concurrent requests must use different ad containers.
 *   Does not support Picture-in-Picture.
 *
 *  @param tagUrl               the ad tag URL
 *  @param container            the container for rendering the ad UI
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                Callbacks to AD event responses and status
 *
 *  @return the JXAVideoOperator instance
 */

- (instancetype)initWithTagUrl:(NSString *)tagUrl
                   containerView:(UIView *)container
                     userContext:(id)userContext
                           state:(StateBlock)state;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support.
 *  Concurrent requests must use different ad containers.
 *
 *  @param tagUrl               the ad tag URL
 *  @param container            the container for rendering the ad UI
 *  @param player               the player for play ads and video
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                Callbacks to AD event responses and status
 *  @param progress             Play a callback to the video progress
 *
 *  @return the JXAVideoOperator instance
 */

- (instancetype)initWithTagUrl:(NSString *)tagUrl
                   containerView:(UIView *)container
                        player:(AVPlayer *)player
                     userContext:(id)userContext
                           state:(StateBlock)state
                      progress:(ProgressBlock)progress;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container.  Concurrent requests must use different ad containers.
 *   Does not support Picture-in-Picture.
 *
 *  @param params               params contains all the advertising parameters of the SDK
 *  @param container            the container for rendering the ad UI
 *  @param state                Callbacks to AD event responses and status
 *
 *  @return the JXAVideoOperator instance
 */

- (instancetype)initWithParams:(ParamsBlock)params
 containerView:(UIView *)container
         state:(StateBlock)state;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support.
 *  Concurrent requests must use different ad containers.
 *
 *  @param params               params contains all the advertising parameters of the SDK
 *  @param player               the player for play ads and video
 *  @param state                Callbacks to AD event responses and status
 *  @param progress             Play a callback to the video progress
 *
 *  @return the JXAVideoOperator instance
 */

- (instancetype)initWithParams:(ParamsBlock)params
 containerView:(UIView *)container
        player:(AVPlayer *)player
         state:(StateBlock)state
      progress:(ProgressBlock)progress;


/**
 *  Initializes an ads request instance with the given canned ads response and ad display
 *  container. Concurrent requests must use different ad containers.
 *  Does not support Picture-in-Picture.
 *
 *  @param adsResponse          the canned ads response
 *  @param container            the container for rendering the ad UI
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                Callbacks to AD event responses and status
 *
 *  @return the JXAVideoOperator instance
 */

- (instancetype)initWithAdsResponse:(NSString *)adsResponse
                 containerView:(UIView *)container
                   userContext:(id)userContext
                         state:(StateBlock)state;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support.
 *  Concurrent requests must use different ad containers.
 *
 *  @param adsResponse          the canned ads response
 *  @param container            the container for rendering the ad UI
 *  @param player               the player for play ads and video
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                Callbacks to AD event responses and status
 *  @param progress             Play a callback to the video progress
 *
 *  @return the JXAVideoOperator instance
 */

- (instancetype)initWithAdsResponse:(NSString *)adsResponse
                      containerView:(UIView *)container
                             player:(AVPlayer *)player
                        userContext:(id)userContext
                              state:(StateBlock)state
                           progress:(ProgressBlock)progress;


@end

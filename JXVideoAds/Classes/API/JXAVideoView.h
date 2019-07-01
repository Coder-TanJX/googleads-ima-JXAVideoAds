//
//  JXAVideoView.h
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/20.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "JXAVideoAds.h"
#import "JXAVideoParamsBuilder.h"

@interface JXAVideoView : UIView

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
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                Callbacks to AD event responses and status
 *
 */

- (void)tagUrl:(NSString *)tagUrl
   userContext:(id)userContext
         state:(StateBlock)state;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support.
 *  Concurrent requests must use different ad containers.
 *
 *  @param tagUrl               the ad tag URL
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                Callbacks to AD event responses and status
 *  @param progress             Play a callback to the video progress
 *
 */

- (void)tagUrl:(NSString *)tagUrl
   userContext:(id)userContext
         state:(StateBlock)state
      progress:(ProgressBlock)progress;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container.  Concurrent requests must use different ad containers.
 *   Does not support Picture-in-Picture.
 *
 *  @param params               params contains all the advertising parameters of the SDK
 *  @param state                Callbacks to AD event responses and status
 *
 */

- (void)params:(ParamsBlock)params
         state:(StateBlock)state;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support.
 *  Concurrent requests must use different ad containers.
 *
 *  @param params               params contains all the advertising parameters of the SDK
 *  @param state                Callbacks to AD event responses and status
 *  @param progress             Play a callback to the video progress
 *
 */

- (void)params:(ParamsBlock)params
         state:(StateBlock)state
      progress:(ProgressBlock)progress;

/**
 *  Initializes an ads request instance with the given canned ads response and ad display
 *  container. Concurrent requests must use different ad containers.
 *  Does not support Picture-in-Picture.
 *
 *  @param adsResponse          the canned ads response
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                callbacks to AD event responses and status
 *
 */

- (void)adsResponse:(NSString *)adsResponse
                        userContext:(id)userContext
                              state:(StateBlock)state;

/**
 *  Initializes an ads request instance with the given ad tag URL and ad display
 *  container with Picture-in-Picture support.
 *  Concurrent requests must use different ad containers.
 *
 *  @param adsResponse          the canned ads response
 *  @param userContext          the user context for tracking requests (optional)
 *  @param state                callbacks to AD event responses and status
 *  @param progress             play a callback to the video progress
 *
 */

- (void)adsResponse:(NSString *)adsResponse
                        userContext:(id)userContext
                              state:(StateBlock)state
                           progress:(ProgressBlock)progress;

@end 

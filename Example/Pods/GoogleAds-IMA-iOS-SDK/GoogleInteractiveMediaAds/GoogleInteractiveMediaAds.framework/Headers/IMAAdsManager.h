//
//  IMAAdsManager.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Declares IMAAdsManager interface that manages ad playback.
//  The interface represents an abstract API. There can be one or more ads
//  managed by a single ads manager.
//  The implementing code should respond to the callbacks as defined in
//  IMAAdsManagerDelegate.
//
//  A typical ad playback session:
//    1. Ads manager is retrieved. Delegate is set.
//    2. [adsManager initialize...];  - ad is initialized and loads.
//    3. delegate.didReceiveAdEvent is called with a kIMAAdEventLoaded event.
//    4. [adsManager start];
//    5. delegate.adsManagerDidRequestContentPause: is called. The content
//       playback should pause now.
//    6. Ad display container master view is unhidden and playback starts.
//    7. delegate.didReceiveAdEvent is called with ad events.
//    8. Ad finishes.
//    9. delegate.adsManagerDidRequestContentResume: is called. The content
//       playback should resume now.
//    10. delegate.didReceiveAdEvent: is called with the
//        kIMAAdEvent_ALL_ADS_COMPLETED event.
//        It is possible to detach the delegate and destroy the ads manager.
//
//  If multiple ads are managed by the ads manager, steps 5-9 may repeat several
//  times. Step 5 will happen at times predetermined by the ads server.
//  The implementing code should listen to callbacks until
//  kIMAAdEvent_ALL_ADS_COMPLETED is received.

#import <Foundation/Foundation.h>

@class IMAAdDisplayContainer;
@class IMAAdError;
@class IMAAdEvent;
@class IMAAdsRenderingSettings;

#import "IMAAdPlaybackInfo.h"
#import "IMAContentPlayhead.h"

@class IMAAdsManager;

#pragma mark IMAAdsManagerDelegate

/**
 *  A callback protocol for IMAAdsManager.
 */
@protocol IMAAdsManagerDelegate

/**
 *  Called when there is an IMAAdEvent.
 *
 *  @param adsManager the IMAAdsManager receiving the event
 *  @param event      the IMAAdEvent received
 */
- (void)adsManager:(IMAAdsManager *)adsManager didReceiveAdEvent:(IMAAdEvent *)event;

/**
 *  Called when there was an error playing the ad.
 *  Only resume playback when didRequestContentResumeForAdsManager: is called.
 *  Continue to listen for callbacks until didReceiveAdEvent: with
 *  kIMAAdEvent_ALL_ADS_COMPLETED is called.
 *
 *  @param adsManager the IMAAdsManager that errored
 *  @param error      the IMAAdError received
 */
- (void)adsManager:(IMAAdsManager *)adsManager didReceiveAdError:(IMAAdError *)error;

/**
 *  Called when an ad is ready to play.
 *  The implementing code should pause the content playback and prepare the UI
 *  for ad playback.
 *
 *  @param adsManager the IMAAdsManager requesting content pause
 */
- (void)adsManagerDidRequestContentPause:(IMAAdsManager *)adsManager;

/**
 *  Called when an ad has finished or an error occurred during the playback.
 *  The implementing code should resume the content playback.
 *
 *  @param adsManager the IMAAdsManager requesting content resume
 */
- (void)adsManagerDidRequestContentResume:(IMAAdsManager *)adsManager;

@optional

/**
 *  Called every 200ms to provide time updates for the current ad.
 *
 *  @param adsManager the IMAAdsManager tracking ad playback
 *  @param mediaTime  the current media time in seconds
 *  @param totalTime  the total media length in seconds
 */
- (void)adsManager:(IMAAdsManager *)adsManager
    adDidProgressToTime:(NSTimeInterval)mediaTime
              totalTime:(NSTimeInterval)totalTime;

/**
 *  Called when the current ad is sufficiently buffered and playback is likely
 *  to keep up.
 *
 *  @param adsManager the IMAAdsManager with ad playback ready
 */
- (void)adsManagerAdPlaybackReady:(IMAAdsManager *)adsManager;

/**
 *  Called when the current ad media buffer is empty and playback did stall.
 *
 *  @param adsManager the IMAAdsManager tracking the stalled ad
 */
- (void)adsManagerAdDidStartBuffering:(IMAAdsManager *)adsManager;

/**
 *  Called as the current ad media buffers.
 *
 *  @param adsManager the IMAAdsManager tracking the ad's media buffer
 *  @param mediaTime  the current buffered media time in seconds
 */
- (void)adsManager:(IMAAdsManager *)adsManager adDidBufferToMediaTime:(NSTimeInterval)mediaTime;

@end

#pragma mark - IMAAdsManager

/**
 *  The IMAAdsManager class is responsible for playing ads.
 */
@interface IMAAdsManager : NSObject

/**
 *  The IMAAdsManagerDelegate to notify with events during ad playback.
 */
@property(nonatomic, weak) NSObject<IMAAdsManagerDelegate> *delegate;

/**
 *  List of content time offsets at which ad breaks are scheduled.
 *  Array of NSNumber double values in seconds.
 *  Empty NSArray for single ads or if no ad breaks are scheduled.
 */
@property(nonatomic, copy, readonly) NSArray *adCuePoints;

/**
 *  Groups various properties about the linear ad playback.
 */
@property(nonatomic, strong, readonly) id<IMAAdPlaybackInfo> adPlaybackInfo;

/**
 *  Set and get the volume for the current ad. From 0 (muted) to 1 (loudest). This volume is
 *  relative to device volume, not absolute. Default value is 1.
 */
@property(nonatomic, assign) float volume;

/**
 *  Initializes and loads the ad.
 *
 *  @param adsRenderingSettings the IMAAdsRenderingSettings. Pass in to influence ad rendering.
 *                              Use nil to default to standard rendering.
 */
- (void)initializeWithAdsRenderingSettings:(IMAAdsRenderingSettings *)adsRenderingSettings;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  Starts advertisement playback.
 */
- (void)start;

/**
 *  Pauses advertisement.
 */
- (void)pause;

/**
 *  Resumes the advertisement.
 */
- (void)resume;

/**
 *  Skips the advertisement.
 */
- (void)skip;

/**
 *  Performs a clickthrough on the advertisement if the UI was successfully disabled via
 *  AdsRenderingSettings.disableUi.
 */
- (void)clicked;

/**
 *  Causes the ads manager to stop the ad and clean its internal state.
 */
- (void)destroy;

/**
 *  If an ad break is currently playing, discard it and resume content.
 *  Otherwise, ignore the next scheduled ad break.
 */
- (void)discardAdBreak;

@end

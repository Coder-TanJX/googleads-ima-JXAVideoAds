//
//  IMAVideoDisplay.h
//  GoogleIMA3
//
//  Copyright (c) 2015 Google Inc. All rights reserved.
//
//  Declares a simple video display class used for ad playback.

#import "IMAAdPlaybackInfo.h"
@protocol IMAVideoDisplay;

/**
 *  Delegate object that receives state change callbacks from IMAVideoDisplay.
 */
@protocol IMAVideoDisplayDelegate<NSObject>

/**
 *  Informs the SDK the ad has started playback.
 *
 *  @param videoDisplay the IMAVideoDisplay that started ad playback
 */
- (void)videoDisplayDidPlay:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad has paused.
 *
 *  @param videoDisplay the IMAVideoDisplay that paused ad playback
 */
- (void)videoDisplayDidPause:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad has resumed playback.
 *
 *  @param videoDisplay the IMAVideoDisplay that resumed ad playback
 */
- (void)videoDisplayDidResume:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad has started playback.
 *
 *  @param videoDisplay the IMAVideoDisplay that started ad playback
 */
- (void)videoDisplayDidStart:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad has completed playback.
 *
 *  @param videoDisplay the IMAVideoDisplay that completed ad playback
 */
- (void)videoDisplayDidComplete:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad was clicked.
 *
 *  @param videoDisplay the IMAVideoDisplay that received the ad click
 */
- (void)videoDisplayDidClick:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad playback failed due to an error.
 *
 *  @param videoDisplay the IMAVideoDisplay that failed to play the ad
 */
- (void)videoDisplayDidReceiveError:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad was skipped.
 *
 *  @param videoDisplay the IMAVideoDisplay that skipped the ad
 */
- (void)videoDisplayDidSkip:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad skip button appeared.
 *
 *  @param videoDisplay the IMAVideoDisplay that showed the skip button
 */
- (void)videoDisplayDidShowSkip:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK that the ad has loaded.
 *
 *  @param videoDisplay the IMAVideoDisplay that loaded the ad
 */
- (void)videoDisplayDidLoad:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK that the ad volume was changed.
 *
 *  @param videoDisplay the IMAVideoDisplay that changed the ad volume
 *  @param volume       the new volume of the ad being played
 */
- (void)videoDisplay:(id<IMAVideoDisplay>)videoDisplay volumeChangedTo:(NSNumber *)volume;

/**
 *  Informs the SDK that the video ad progressed.
 *
 *  @param videoDisplay the IMAVideoDisplay that progressed
 *  @param mediaTime    the current time of the ad being played
 *  @param duration     the total duration of the ad being played
 */
- (void)videoDisplay:(id<IMAVideoDisplay>)videoDisplay
    didProgressWithMediaTime:(NSTimeInterval)mediaTime
                   totalTime:(NSTimeInterval)duration;

/**
 *  Informs the SDK that timed metadata was received.
 *
 *  @param videoDisplay the IMAVideoDisplay that received the timed metadata event
 *  @param metadata     the metadata dictionary received with the timed metadata event
 */
- (void)videoDisplay:(id<IMAVideoDisplay>)videoDisplay
    didReceiveTimedMetadata:(NSDictionary *)metadata;

@optional

/**
 *  Informs the SDK the video ad is buffered to |mediaTime| in seconds.
 *
 *  @param videoDisplay the IMAVideoDisplay whose buffer was updated
 *  @param mediaTime    the time in seconds of ad media that has been buffered.
 */
- (void)videoDisplay:(id<IMAVideoDisplay>)videoDisplay
    didBufferToMediaTime:(NSTimeInterval)mediaTime;

/**
 *  Informs the SDK the ad is buffered and playback is likely to keep up.
 *
 *  @param videoDisplay the IMAVideoDisplay that is playback ready
 */
- (void)videoDisplayIsPlaybackReady:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Informs the SDK the ad's media buffer is empty and playback will stall.
 *
 *  @param videoDisplay the IMAVideoDisplay that started buffering
 */
- (void)videoDisplayDidStartBuffering:(id<IMAVideoDisplay>)videoDisplay;

@end

/**
 *  Declares a simple video display class used for ad playback.
 */
@protocol IMAVideoDisplay <IMAAdPlaybackInfo>

/**
 *  Allows the publisher to send player events to the SDK.
 */
@property(nonatomic, weak) id<IMAVideoDisplayDelegate> delegate;

/**
 *  Set and get the volume for the current ad. From 0 (muted) to 1 (loudest). This volume is
 *  relative to device volume, not absolute. Default value is 1.
 */
@property(nonatomic, assign) float volume;

/**
 *  Called to inform the VideoDisplay to load the passed URL with the subtitles for the stream.
 *  Subtitles are available only for dynamic ad insertion VOD streams and can be ignored
 *  for client side ads or dynamic ad insertion live streams.
 *
 *  @param streamURL  the URL of the stream
 *  @param subtitles  the subtitles for the stream. Each entry in the subtitles array is an
 *                    *NSDictionary* that corresponds to a language. Each dictionary will have a
 *                    *language* key with a two letter language string value and one or more
 *                    subtitle key/value pairs. Here's an example NSDictionary for English:
 *
 *                    "language" -> "en"
 *                    "webvtt" -> "https://somedomain/vtt/en.vtt"
 *                    "ttml" -> "https://somedomain/ttml/en.ttml"
 */
- (void)loadStream:(NSURL *)streamURL withSubtitles:(NSArray *)subtitles;

/**
 *  Called to inform the VideoDisplay to load the passed URL.
 *
 *  @param url  the media URL of the ad to be played
 */
- (void)loadUrl:(NSURL *)url;

/**
 *  Called to inform the VideoDisplay to play.
 */
- (void)play;

/**
 *  Called to inform the VideoDisplay to pause.
 */
- (void)pause;

/**
 *  Called to remove all video assets from the player.
 */
- (void)reset;

@end

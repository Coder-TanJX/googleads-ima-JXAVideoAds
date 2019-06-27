//
//  IMAAVPlayerVideoDisplay.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Declares an object that reuses an AVPlayer for both content and ad playback

#import <UIKit/UIKit.h>

#import "IMAVideoDisplay.h"

@class AVPlayer;
@class AVPlayerItem;

/**
 *  The key for subtitle language.
 */
extern NSString *const kIMASubtitleLanguage;

/**
 *  The key for the WebVTT sidecar subtitle URL.
 */
extern NSString *const kIMASubtitleWebVTT;

/**
 *  The key for the TTML sidecar subtitle URL.
 */
extern NSString *const kIMASubtitleTTML;

/**
 *  An implementation of the IMAVideoDisplay protocol. This object is intended
 *  to be initialized with the content player, and will reuse the player for
 *  playing ads.
 */
@interface IMAAVPlayerVideoDisplay : NSObject <IMAVideoDisplay>

/**
 *  The content player used for both content and ad video playback.
 */
@property(nonatomic, strong, readonly) AVPlayer *player;

/**
 *  The player item that will be played by the player. Access to the player item is provided
 *  so the item can be seeked before it is ready to play.
 */
@property(nonatomic, strong, readonly) AVPlayerItem *playerItem;

/**
 *  The subtitles for the current stream. Will be nil until the stream starts playing.
 */
@property(nonatomic, strong, readonly) NSArray *subtitles;

/**
 *  Creates an IMAAVPlayerVideoDisplay that will play ads in the passed in
 *  content player.
 *
 *  @param player the AVPlayer instance used for playing content
 *
 *  @return an IMAAVPlayerVideoDisplay instance
 */
- (instancetype)initWithAVPlayer:(AVPlayer *)player;

- (instancetype)init NS_UNAVAILABLE;

@end

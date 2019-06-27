//
//  IMAAVPlayerContentPlayhead.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Declares IMAAVPlayerContentPlayhead, a wrapper for tracking AVPlayer-based
//  video players.

#import <AVFoundation/AVFoundation.h>

#import "IMAContentPlayhead.h"

/**
 *  An implementation of IMAContentPlayhead for AVPlayer. Use this class to
 *  provide content tracking if your content player of choice is an AVPlayer
 *  or its subclass.
 */
@interface IMAAVPlayerContentPlayhead : NSObject<IMAContentPlayhead>

/**
 *  The player to track.
 */
@property(nonatomic, strong, readonly) AVPlayer *player;

/**
 *  Initializes a IMAAVPlayerContentPlayhead that tracks a player. It will attach a periodic time
 *  observer to the player immediately.
 *
 *  @param  player the AVPlayer to track.
 *
 *  @return the IMAAVPlayerContentPlayhead instance
 */
- (instancetype)initWithAVPlayer:(AVPlayer *)player;

- (instancetype)init NS_UNAVAILABLE;

@end

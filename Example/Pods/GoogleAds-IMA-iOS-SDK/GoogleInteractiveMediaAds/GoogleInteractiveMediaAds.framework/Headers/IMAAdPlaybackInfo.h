//
//  IMAAdPlaybackInfo.h
//  GoogleIMA3
//
//  Copyright (c) 2014 Google Inc. All rights reserved.
//
//  Defines a protocol for providing ad playback information.

#import <Foundation/Foundation.h>

/**
 *  Groups various properties of the ad player.
 */
@protocol IMAAdPlaybackInfo<NSObject>

/**
 *  The current media time of the ad, or 0 if no ad loaded.
 */
@property(nonatomic, readonly) NSTimeInterval currentMediaTime;

/**
 *  The total media time of the ad, or 0 if no ad loaded.
 */
@property(nonatomic, readonly) NSTimeInterval totalMediaTime;

/**
 *  The buffered media time of the ad, or 0 if no ad loaded.
 */
@property(nonatomic, readonly) NSTimeInterval bufferedMediaTime;

/**
 *  Whether or not the ad is currently playing.
 */
@property(nonatomic, readonly, getter=isPlaying) BOOL playing;

@end

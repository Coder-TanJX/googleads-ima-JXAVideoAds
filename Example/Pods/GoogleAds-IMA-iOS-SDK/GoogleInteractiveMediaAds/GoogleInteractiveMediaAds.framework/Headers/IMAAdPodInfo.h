//
//  IMAAdPodInfo.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Represents podding metadata for a single ad.

#import <Foundation/Foundation.h>

/**
 *  Simple data object containing podding metadata.
 */
@interface IMAAdPodInfo : NSObject

/**
 *  Total number of ads in the pod this ad belongs to. Will be 1 for standalone ads.
 */
@property(nonatomic, readonly) int totalAds;

/**
 *  The position of this ad within an ad pod. Will be 1 for standalone ads.
 */
@property(nonatomic, readonly) int adPosition;

/**
 *  Specifies whether the ad is a bumper. Bumpers are short videos used to open
 *  and close ad breaks.
 */
@property(nonatomic, readonly) BOOL isBumper;

/**
 *  The index of the pod, where pre-roll pod is 0, mid-roll pods are 1 .. N
 *  and the post-roll is -1.
 */
@property(nonatomic, readonly) int podIndex;

/**
 *  The position of the pod in the content in seconds. Pre-roll returns 0,
 *  post-roll returns -1 and mid-rolls return the scheduled time of the pod.
 */
@property(nonatomic, readonly) NSTimeInterval timeOffset;

/**
 *  The maximum duration of the pod in seconds. For unknown duration, -1 is returned.
 */
@property(nonatomic, readonly) NSTimeInterval maxDuration;

- (instancetype)init NS_UNAVAILABLE;

@end

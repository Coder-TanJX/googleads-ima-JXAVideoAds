//
//  JXAVideoTool.m
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/21.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import "JXAVideoTool.h"

@implementation JXAVideoTool

/// Updates progress  for provided time and duration.
+ (void)getProgresseTime:(CMTime)time
                duration:(CMTime)duration
                  result:(void(^)(CGFloat current, CGFloat duration))result{
    
    if (CMTIME_IS_INVALID(time) ||
        CMTIME_IS_INVALID(duration))  return;
    Float64 currentTime = CMTimeGetSeconds(time);
    Float64 durationValue = CMTimeGetSeconds(duration);
    if (isnan(currentTime) ||
        isnan(durationValue))  return;
    result(currentTime, durationValue);
}

/// Get the duration value from the player item.
+ (CMTime)getDuration:(AVPlayerItem *)item {
    CMTime itemDuration = kCMTimeInvalid;
    if ([item respondsToSelector:@selector(duration)]) {
        itemDuration = item.duration;
    } else {
        if (item.asset &&
            [item.asset respondsToSelector:@selector(duration)]) {
            // Sometimes the test app hangs here for ios 4.2.
            itemDuration = item.asset.duration;
        }
    }
    return itemDuration;
}

@end

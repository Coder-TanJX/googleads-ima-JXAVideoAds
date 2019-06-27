//
//  JXAVideoTool.h
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/21.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface JXAVideoTool : NSObject

/// Updates progress  for provided time and duration.
+ (void)getProgresseTime:(CMTime)time
             duration:(CMTime)duration
                  result:(void(^)(CGFloat current, CGFloat duration))result;

/// Get the duration value from the player item.
+ (CMTime)getDuration:(AVPlayerItem *)item;

@end

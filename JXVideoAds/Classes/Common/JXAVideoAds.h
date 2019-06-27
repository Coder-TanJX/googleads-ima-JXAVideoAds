//
//  JXAVideoAds.h
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/21.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "JXAGoogleImaApi.h"

@class JXAVideoAds;

typedef enum : NSUInteger {
    JXAVideoAdsState_Loaded,    // 广告已加载完成
    JXAVideoAdsState_Started,   // 广告已开始播放
    JXAVideoAdsState_Skipped,   // 广告已跳过
    JXAVideoAdsState_Pause,     // 广告已暂停
    JXAVideoAdsState_Resume,    // 中途打断, 继续播放广告
    JXAVideoAdsState_Ended,     // 广告已播放结束
    JXAVideoAdsState_Error,     // 广告加载错误
} JXAVideoAdsState;

typedef void (^StateBlock)(JXAVideoAdsState state, JXAVideoAds *video);
typedef void (^ProgressBlock)(CGFloat current, CGFloat duration);

@interface JXAVideoAds : NSObject <AVPictureInPictureControllerDelegate>

- (void)play;

- (void)pause;

- (void)skip;

- (void)resume;

@end

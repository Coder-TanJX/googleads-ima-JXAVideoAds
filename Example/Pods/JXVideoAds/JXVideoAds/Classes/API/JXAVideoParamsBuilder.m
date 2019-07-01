//
//  JXAVideoParamsBuilder.m
//  JXAVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/22.
//  Copyright © 2019 TanJiaXiang. All rights reserved.
//

#import "JXAVideoParamsBuilder.h"
#define ITA_WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

@implementation JXAVideoParamsBuilder

- (instancetype)init
{
    self = [super init];
    if (self) {
        _params = [JXAVideoParams new];
        _params.autoPlayAdBreaks = NO;
        _params.language = @"en";
        _params.enableBackgroundPlayback = YES;
        _params.volume = @1;
    }
    return self;
}

- (JXAVideoParamsBuilder *(^)(BOOL))autoPlayAdBreaks {
    ITA_WS(weakSelf)
    return ^(BOOL autoPlayAdBreaks) {
        weakSelf.params.autoPlayAdBreaks = autoPlayAdBreaks;
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(NSString *))language {
    ITA_WS(weakSelf)
    return ^(NSString * language) {
        weakSelf.params.language = [language copy];
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(BOOL))enableBackgroundPlayback {
    ITA_WS(weakSelf)
    return ^(BOOL enableBackgroundPlayback) {
        weakSelf.params.enableBackgroundPlayback = enableBackgroundPlayback;
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(NSNumber *))volume {
    ITA_WS(weakSelf)
    return ^(NSNumber * volume) {
        weakSelf.params.volume = volume;
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(NSString *))adTagUrl {
    ITA_WS(weakSelf)
    return ^(NSString * adTagUrl) {
        weakSelf.params.adTagUrl = [adTagUrl copy];
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(NSString *))userContext {
    ITA_WS(weakSelf)
    return ^(NSString * userContext) {
        weakSelf.params.userContext = [userContext copy];
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(AVPlayer *))player {
    ITA_WS(weakSelf)
    return ^(AVPlayer * player) {
        weakSelf.params.player = player;
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(NSArray *))mimeTypes {
    ITA_WS(weakSelf)
    return ^(NSArray * mimeTypes) {
        weakSelf.params.mimeTypes = [mimeTypes copy];
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(int))bitrate {
    ITA_WS(weakSelf)
    return ^(int bitrate) {
        weakSelf.params.bitrate = bitrate;
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(UIViewController *))webOpenerPresentingController {
    ITA_WS(weakSelf)
    return ^(UIViewController * webOpenerPresentingController) {
        weakSelf.params.webOpenerPresentingController = webOpenerPresentingController;
        return weakSelf;
    };
}

- (JXAVideoParamsBuilder *(^)(id<JXAWebOpenerDelegate>))webOpenerDelegate {
    ITA_WS(weakSelf)
    return ^(id<JXAWebOpenerDelegate> webOpenerDelegate) {
        weakSelf.params.webOpenerDelegate = webOpenerDelegate;
        return weakSelf;
    };
}

@end

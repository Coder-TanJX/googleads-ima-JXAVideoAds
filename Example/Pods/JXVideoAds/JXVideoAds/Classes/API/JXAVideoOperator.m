//
//  JXAVideoOperator.m
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/19.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import "JXAVideoOperator.h"

#import "JXAVideoAds+Extension.h"
#import "JXAGoogleImaApi.h"
#import "JXAVideoTool.h"

@interface JXAVideoOperator ()
@property (nonatomic, strong) AVPlayer *player;
@property(nonatomic, strong) id playHeadObserver;
@property (nonatomic, copy) ProgressBlock progress;

@end

@implementation JXAVideoOperator


- (instancetype)initWithTagUrl:(NSString *)tagUrl
                   containerView:(UIView *)container
                     userContext:(id)userContext
                           state:(StateBlock)state{
    
    _ads = [JXAVideoAds new];
    
    if (tagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return self;
    }
    
    _ads.stateBlock = state;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.enableBackgroundPlayback = YES;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:container
                                               companionSlots:nil];

    _ads.request = [[JXAAdsRequest alloc]
                              initWithAdTagUrl:tagUrl
                              adDisplayContainer:displayContainer
                              contentPlayhead:nil
                              userContext:userContext];
    _ads.request.contentDuration = 5;
    [_ads.adsLoader requestAdsWithRequest:_ads.request];

    
    return self;
}

- (instancetype)initWithTagUrl:(NSString *)tagUrl
                 containerView:(UIView *)container
                        player:(AVPlayer *)player
                   userContext:(id)userContext
                         state:(StateBlock)state
                      progress:(ProgressBlock)progress{
    
    _ads = [JXAVideoAds new];
    
    if (tagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return self;
    }
    
    _progress = progress;
    _ads.stateBlock = state;
    self.player = player;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.enableBackgroundPlayback = YES;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    [self playHeadObserver];
    

    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:container
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                              initWithAdTagUrl:tagUrl
                              adDisplayContainer: displayContainer
                              avPlayerVideoDisplay:[[JXAAVPlayerVideoDisplay alloc] initWithAVPlayer:self.player]
                              pictureInPictureProxy:_ads.pictureInPictureProxy
                              userContext:nil];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];

    return self;
}

- (instancetype)initWithParams:(ParamsBlock)params
                 containerView:(UIView *)container
                         state:(StateBlock)state {
    _ads = [JXAVideoAds new];
    
    JXAVideoParams *videoParams = params([JXAVideoParamsBuilder new]).params;
    
    if (videoParams.adTagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return self;
    }
    
    _ads.stateBlock = state;
    _ads.params = videoParams;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = videoParams.autoPlayAdBreaks;
    setting.enableBackgroundPlayback = videoParams.enableBackgroundPlayback;
    setting.language = videoParams.language;
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:container
                                               companionSlots:nil];
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdTagUrl:videoParams.adTagUrl
                    adDisplayContainer:displayContainer
                    contentPlayhead:nil
                    userContext:videoParams.userContext];
    _ads.request.contentDuration = 5;
    [_ads.adsLoader requestAdsWithRequest:_ads.request];

    return self;
}

- (instancetype)initWithParams:(ParamsBlock)params
                 containerView:(UIView *)container
                        player:(AVPlayer *)player
                         state:(StateBlock)state
                      progress:(ProgressBlock)progress {
    
    
    _ads = [JXAVideoAds new];
    JXAVideoParams *videoParams = params([JXAVideoParamsBuilder new]).params;
    
    if (videoParams.adTagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return self;
    }
    
    _progress = progress;
    _ads.stateBlock = state;
    _ads.params = videoParams;
    self.player = player;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = videoParams.autoPlayAdBreaks;
    setting.enableBackgroundPlayback = videoParams.enableBackgroundPlayback;
    setting.language = videoParams.language;
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    [self playHeadObserver];
    
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:container
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdTagUrl:videoParams.adTagUrl
                    adDisplayContainer: displayContainer
                    avPlayerVideoDisplay:[[JXAAVPlayerVideoDisplay alloc] initWithAVPlayer:self.player]
                    pictureInPictureProxy:_ads.pictureInPictureProxy
                    userContext:videoParams.userContext];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
    
    return self;
}


- (instancetype)initWithAdsResponse:(NSString *)adsResponse
                      containerView:(UIView *)container
                        userContext:(id)userContext
                              state:(StateBlock)state {
    _ads = [JXAVideoAds new];
    
    if (adsResponse.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return self;
    }
    
    _ads.stateBlock = state;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.enableBackgroundPlayback = YES;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:container
                                               companionSlots:nil];
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdsResponse:adsResponse
                    adDisplayContainer:displayContainer
                    contentPlayhead:nil
                    userContext:userContext];
    _ads.request.contentDuration = 5;
    [_ads.adsLoader requestAdsWithRequest:_ads.request];

    return self;
}

- (instancetype)initWithAdsResponse:(NSString *)adsResponse
                      containerView:(UIView *)container
                             player:(AVPlayer *)player
                        userContext:(id)userContext
                              state:(StateBlock)state
                           progress:(ProgressBlock)progress {
    
    _ads = [JXAVideoAds new];
    
    if (adsResponse.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return self;
    }
    
    _progress = progress;
    _ads.stateBlock = state;
    self.player = player;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.enableBackgroundPlayback = YES;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    [self playHeadObserver];
    
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:container
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdsResponse:adsResponse
                    adDisplayContainer:displayContainer
                    avPlayerVideoDisplay:[[JXAAVPlayerVideoDisplay alloc] initWithAVPlayer:self.player]
                    pictureInPictureProxy:_ads.pictureInPictureProxy
                    userContext:userContext];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
    
    return self;
    
}

- (void)remove {
    
    if (self.player) {
        [self.player pause];
    }
    if (self.ads.adsManager) {
        [self.ads.adsManager destroy];
        self.ads.adsManager = nil;
    }
    if (self.playHeadObserver) {
        [self.player removeTimeObserver:self.playHeadObserver];
        self.playHeadObserver = nil;
    }
}

#pragma mark - Private Method
- (id)playHeadObserver {
    if (!_playHeadObserver) {
        __weak JXAVideoOperator *controller = self;
        _playHeadObserver = [controller.player
                             addPeriodicTimeObserverForInterval:CMTimeMake(1, 30)
                             queue:NULL
                             usingBlock:^(CMTime time) {
                                 CMTime duration = [JXAVideoTool
                                                    getDuration:controller.player.currentItem];
                                 [JXAVideoTool getProgresseTime:time
                                                       duration:duration
                                                         result:^(CGFloat current,
                                                                  CGFloat duration) {
                                                             if (controller.progress) {
                                                                 controller.progress(current,
                                                                                     duration);
                                                             }
                                                         }];
                             }];
    }
    return _playHeadObserver;
}

- (void)setUpITA {
    
    // Set ourselves up for PiP.
    _ads.pictureInPictureProxy =
    [[JXAPictureInPictureProxy alloc] initWithAVPictureInPictureControllerDelegate:_ads];
    
    if (_ads.adsManager) {
        [_ads.adsManager destroy];
    }
    
    [_ads.adsLoader contentComplete];
    _ads.adsLoader.delegate = _ads;
}

@end



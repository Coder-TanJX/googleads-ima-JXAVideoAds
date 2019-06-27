//
//  JXAVideoView.m
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/20.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//


#import "JXAVideoView.h"

#import "JXAGoogleImaApi.h"
#import "JXAVideoTool.h"
#import "JXAVideoAds+Extension.h"

@interface JXAVideoView ()
@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, strong) AVPlayerLayer *playerLayer;

@property(nonatomic, strong) id playHeadObserver;
@property (nonatomic, copy) ProgressBlock progress;

@end

@implementation JXAVideoView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        _ads = [JXAVideoAds new];
    }
    return self;
}

- (void)awakeFromNib {
    [super awakeFromNib];
    _ads = [JXAVideoAds new];
}

- (void)layoutSubviews {
    [super layoutSubviews];
    self.playerLayer.frame = self.bounds;
}

#pragma mark - API
- (void)tagUrl:(NSString *)tagUrl
   userContext:(id)userContext
         state:(StateBlock)state; {

    if (tagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return;
    }
    
    _ads.stateBlock = state;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];

    [self setUpITA];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:self
                                               companionSlots:nil];

    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdTagUrl:tagUrl
                    adDisplayContainer:displayContainer
                    contentPlayhead:nil
                    userContext:userContext];
    _ads.request.contentDuration = 5;
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
}

- (void)tagUrl:(NSString *)tagUrl
   userContext:(id)userContext
         state:(StateBlock)state
      progress:(ProgressBlock)progress{

    if (tagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return ;
    }
    
    _progress = progress;
    _ads.stateBlock = state;

    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.enableBackgroundPlayback = YES;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    [self playHeadObserver];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:self
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                              initWithAdTagUrl:tagUrl
                              adDisplayContainer: displayContainer
                              avPlayerVideoDisplay:[[JXAAVPlayerVideoDisplay alloc] initWithAVPlayer:self.player]
                              pictureInPictureProxy:_ads.pictureInPictureProxy
                              userContext:nil];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
}

- (void)params:(ParamsBlock)params
         state:(StateBlock)state {
    
    JXAVideoParams *videoParams = params([JXAVideoParamsBuilder new]).params;
    
    if (videoParams.adTagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return;
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
                                               initWithAdContainer:self
                                               companionSlots:nil];

    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdTagUrl:videoParams.adTagUrl
                    adDisplayContainer:displayContainer
                    contentPlayhead:nil
                    userContext:videoParams.userContext];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
}

- (void)params:(ParamsBlock)params
         state:(StateBlock)state
      progress:(ProgressBlock)progress {
    
    JXAVideoParams *videoParams = params([JXAVideoParamsBuilder new]).params;
    
    if (videoParams.adTagUrl.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return;
    }
    
    _progress = progress;
    _ads.stateBlock = state;
    _ads.params = videoParams;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = videoParams.autoPlayAdBreaks;
    setting.enableBackgroundPlayback = videoParams.enableBackgroundPlayback;
    setting.language = videoParams.language;
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    [self playHeadObserver];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:self
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdTagUrl:videoParams.adTagUrl
                    adDisplayContainer: displayContainer
                    avPlayerVideoDisplay:[[JXAAVPlayerVideoDisplay alloc] initWithAVPlayer:self.player]
                    pictureInPictureProxy:_ads.pictureInPictureProxy
                    userContext:nil];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
}

- (void)adsResponse:(NSString *)adsResponse
                userContext:(id)userContext
                      state:(StateBlock)state {
    if (adsResponse.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return;
    }
    
    _ads.stateBlock = state;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:self
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdsResponse:adsResponse
                    adDisplayContainer:displayContainer
                    contentPlayhead:nil
                    userContext:userContext];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
}

- (void)adsResponse:(NSString *)adsResponse
                userContext:(id)userContext
                      state:(StateBlock)state
                   progress:(ProgressBlock)progress {
    
    if (adsResponse.length == 0) {
        _ads.stateBlock = state;
        [_ads setState:JXAVideoAdsState_Error];
        return ;
    }
    
    _progress = progress;
    _ads.stateBlock = state;
    
    JXASettings *setting = [[JXASettings alloc] init];
    setting.autoPlayAdBreaks = NO;
    setting.enableBackgroundPlayback = YES;
    setting.language = @"en";
    _ads.adsLoader = [[JXAAdsLoader alloc] initWithSettings:setting];
    
    [self setUpITA];
    [self playHeadObserver];
    
    JXAAdDisplayContainer *displayContainer = [[JXAAdDisplayContainer alloc]
                                               initWithAdContainer:self
                                               companionSlots:nil];
    
    _ads.request = [[JXAAdsRequest alloc]
                    initWithAdsResponse:adsResponse
                    adDisplayContainer:displayContainer
                    avPlayerVideoDisplay:[[JXAAVPlayerVideoDisplay alloc] initWithAVPlayer:self.player]
                    pictureInPictureProxy:_ads.pictureInPictureProxy
                    userContext:userContext];
    [_ads.adsLoader requestAdsWithRequest:_ads.request];
}

#pragma mark - Private methods
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

- (id)playHeadObserver {
    if (!_playHeadObserver) {
        __weak JXAVideoView *controller = self;
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

- (void)remove {
    [self.player pause];
    if (self.ads.adsManager) {
        [self.ads.adsManager destroy];
        self.ads.adsManager = nil;
    }
    if (self.playHeadObserver) {
        [self.player removeTimeObserver:self.playHeadObserver];
        self.playHeadObserver = nil;
    }
    self.playerLayer = nil;
    self.player = nil;
}

#pragma mark - Private Method

- (AVPlayer *)player {
    if (!_player) {
        NSURL *url = [NSURL new];
        _player = [AVPlayer playerWithURL:url];
    }
    return _player;
}

- (AVPlayerLayer *)playerLayer {
    if (!_playerLayer) {
        self.playerLayer = [AVPlayerLayer playerLayerWithPlayer:self.player];
        self.playerLayer.frame = self.layer.bounds;
        [self.layer addSublayer:self.playerLayer];
    }
    return _playerLayer;
}

@end


//
//  JXOpratorViewController.m
//  ITAGoogleVideoAds
//
//  Created by tanjiaxiang on 06/19/2019.
//  Copyright (c) 2019 tanjiaxiang. All rights reserved.
//

#import "JXOpratorViewController.h"

#import "JXAVideoOperator.h"

static NSString *const tagOne = @"https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/single_ad_samples&ciu_szs=300x250&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ct%3Dlinear&correlator=";

static NSString *const tagTwo = @"https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/ad_rule_samples&ciu_szs=300x250&ad_rule=1&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ar%3Dpremidpostpod&cmsid=496&vid=short_onecue&correlator=";

@interface JXOpratorViewController ()<JXAWebOpenerDelegate>
@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (nonatomic, strong) JXAVideoOperator *operator;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *bottomConstraint;
@property (nonatomic, strong) AVPlayerLayer *playerLayer;
@property (nonatomic, strong) AVPlayer *player;

@end

@implementation JXOpratorViewController


- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [self.operator remove];
}

- (IBAction)mNormal:(id)sender {
    
    self.operator = [[JXAVideoOperator alloc]
                    initWithTagUrl:tagOne
                    containerView:self.containerView
                    userContext:nil
                    state:^(JXAVideoAdsState state,
                            JXAVideoAds *video) {
                        switch (state) {
                                
                            case JXAVideoAdsState_Loaded:
                                NSLog(@"广告加载完毕 - JXAVideoAdsState_Loaded");
                                [video play];
                                break;
                                
                            case JXAVideoAdsState_Started:
                                NSLog(@"已经开始播放广告 - JXAVideoAdsState_Started");
                                break;
                            case JXAVideoAdsState_Error:
                                NSLog(@"加载错误 - JXAVideoAdsState_Error");
                                break;
                            case JXAVideoAdsState_Pause:
                                NSLog(@"广告暂停 - JXAVideoAdsState_Pause");
                                break;
                            case JXAVideoAdsState_Ended:
                                NSLog(@"广告播放结束 - JXAVideoAdsState_Ended");
                                break;
                            case JXAVideoAdsState_Skipped:
                                NSLog(@"广告已经跳过 - JXAVideoAdsState_Skipped");
                                break;
                                
                            default:
                                break;
                        }
                    }];
}
- (IBAction)mProgress:(id)sender {
    
    NSString *kDFPContentPath = @"https://s0.2mdn.net/instream/videoplayer/media/android.mp4";
    
    self.player = [AVPlayer playerWithURL:[NSURL URLWithString:kDFPContentPath]];
    self.playerLayer = [AVPlayerLayer playerLayerWithPlayer:self.player];
    self.playerLayer.frame = self.containerView.layer.bounds;
    [self.containerView.layer addSublayer:self.playerLayer];
    
    self.operator = [[JXAVideoOperator alloc]
                    initWithTagUrl:tagOne
                    containerView:self.containerView
                    player: self.player
                    userContext:nil
                    state:^(JXAVideoAdsState state,
                            JXAVideoAds *video) {
                        switch (state) {
                                
                            case JXAVideoAdsState_Loaded:
                                NSLog(@"广告加载完毕 - JXAVideoAdsState_Loaded");
                                [video play];
                                break;
                                
                            case JXAVideoAdsState_Started:
                                NSLog(@"已经开始播放广告 - JXAVideoAdsState_Started");
                                break;
                            case JXAVideoAdsState_Error:
                                NSLog(@"加载错误 - JXAVideoAdsState_Error");
                                [self.player play];
                                break;
                            case JXAVideoAdsState_Pause:
                                NSLog(@"广告暂停 - JXAVideoAdsState_Pause");
                                break;
                            case JXAVideoAdsState_Ended:
                                NSLog(@"广告播放结束 - JXAVideoAdsState_Ended");
                                [self.player play];
                                break;
                            case JXAVideoAdsState_Skipped:
                                NSLog(@"广告已经跳过 - JXAVideoAdsState_Skipped");
                                [self.player play];
                                break;
                                
                            default:
                                break;
                        }
                    } progress:^(CGFloat current, CGFloat duration) {
                        
                        //                        NSLog(@"currentTime -- %f \n duration -- %f", current, duration);
                        
                    }];
}


- (IBAction)params:(id)sender {
    
    self.operator = [[JXAVideoOperator alloc]
                    initWithParams:^JXAVideoParamsBuilder *(JXAVideoParamsBuilder *paramsBuilder) {
                        return  paramsBuilder
                        .autoPlayAdBreaks(NO)
                        .language(@"en")
                        .enableBackgroundPlayback(YES)
                        .volume(@1)
                        .adTagUrl(tagOne)
                        .userContext(nil)
                        .player(nil)
                        .mimeTypes(@[ @"video/mp4", @"application/x-mpegURL"])
                        .bitrate(1024)
                        .webOpenerPresentingController([JXOpratorViewController new])
                        .webOpenerDelegate(self);
                    }
                    containerView:self.containerView
                    state:^(JXAVideoAdsState state, JXAVideoAds *video) {
                        switch (state) {
                                
                            case JXAVideoAdsState_Loaded:
                                NSLog(@"广告加载完毕 - JXAVideoAdsState_Loaded");
                                //                                [video play];
                                break;
                                
                            case JXAVideoAdsState_Started:
                                NSLog(@"已经开始播放广告 - JXAVideoAdsState_Started");
                                break;
                            case JXAVideoAdsState_Error:
                                NSLog(@"加载错误 - JXAVideoAdsState_Error");
                                break;
                            case JXAVideoAdsState_Pause:
                                NSLog(@"广告暂停 - JXAVideoAdsState_Pause");
                                break;
                            case JXAVideoAdsState_Ended:
                                NSLog(@"广告播放结束 - JXAVideoAdsState_Ended");
                                break;
                            case JXAVideoAdsState_Skipped:
                                NSLog(@"广告已经跳过 - JXAVideoAdsState_Skipped");
                                break;
                                
                            default:
                                break;
                        }
                    }];
}

- (IBAction)paramsProgress:(id)sender {
    
    NSString *kDFPContentPath = @"https://s0.2mdn.net/instream/videoplayer/media/android.mp4";
    
    self.player = [AVPlayer playerWithURL:[NSURL URLWithString:kDFPContentPath]];
    self.playerLayer = [AVPlayerLayer playerLayerWithPlayer:self.player];
    self.playerLayer.frame = self.containerView.layer.bounds;
    [self.containerView.layer addSublayer:self.playerLayer];

    self.operator = [[JXAVideoOperator alloc]
                    initWithParams:^JXAVideoParamsBuilder *(JXAVideoParamsBuilder *paramsBuilder) {
                        return  paramsBuilder
                        .autoPlayAdBreaks(NO)
                        .language(@"en")
                        .enableBackgroundPlayback(YES)
                        .volume(@1)
                        .adTagUrl(tagOne)
                        .userContext(nil)
                        .player(nil)
                        .mimeTypes(@[ @"video/mp4", @"application/x-mpegURL"])
                        .bitrate(1024)
                        .webOpenerPresentingController([JXOpratorViewController new])
                        .webOpenerDelegate(self);
                    } containerView:self.containerView
                    player:self.player
                    state:^(JXAVideoAdsState state, JXAVideoAds *video) {
                        switch (state) {
                                
                            case JXAVideoAdsState_Loaded:
                                NSLog(@"广告加载完毕 - JXAVideoAdsState_Loaded");
                                //                                [video play];
                                break;
                                
                            case JXAVideoAdsState_Started:
                                NSLog(@"已经开始播放广告 - JXAVideoAdsState_Started");
                                break;
                            case JXAVideoAdsState_Error:
                                NSLog(@"加载错误 - JXAVideoAdsState_Error");
                                break;
                            case JXAVideoAdsState_Pause:
                                NSLog(@"广告暂停 - JXAVideoAdsState_Pause");
                                break;
                            case JXAVideoAdsState_Ended:
                                NSLog(@"广告播放结束 - JXAVideoAdsState_Ended");
                                break;
                            case JXAVideoAdsState_Skipped:
                                NSLog(@"广告已经跳过 - JXAVideoAdsState_Skipped");
                                break;
                                
                            default:
                                break;
                        }
                    } progress:^(CGFloat current, CGFloat duration) {
                        NSLog(@"currentTime -- %f \n duration -- %f", current, duration);
                    }];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    self.playerLayer.frame = self.containerView.layer.bounds;
}

- (IBAction)fullScreen:(id)sender {
    self.bottomConstraint.constant = 0;
}

- (IBAction)smallScreen:(id)sender {
    self.bottomConstraint.constant = 400;
}

- (IBAction)skip:(id)sender {
    [self.operator.ads skip];
}
- (IBAction)pause:(id)sender {
    [self.operator.ads pause];
}
- (IBAction)play:(id)sender {
    [self.operator.ads play];
}
- (IBAction)resume:(id)sender {
    [self.operator.ads resume];
}

- (void)viewWillTransitionToSize:(CGSize)size
       withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator {
    if (size.width > size.height) {
        // 横屏布局
        self.bottomConstraint.constant = 0;
    } else {
        // 竖屏布局
        self.bottomConstraint.constant = 400;
    }
}

#pragma mark - JXAWebOpenerDelegate
/**
 *  Called when Safari is about to be opened.
 *
 *  @param webOpener the receiving object
 */
- (void)webOpenerWillOpenExternalBrowser:(NSObject *)webOpener {
    NSLog(@"%s",__func__);
}

/**
 *  Called before in-app browser opens.
 *
 *  @param webOpener the receiving object
 */
- (void)webOpenerWillOpenInAppBrowser:(NSObject *)webOpener {
    NSLog(@"%s",__func__);
}

/**
 *  Called when the in app browser is shown on the screen.
 *
 *  @param webOpener the receiving object
 */
- (void)webOpenerDidOpenInAppBrowser:(NSObject *)webOpener {
    NSLog(@"%s",__func__);
}

/**
 *  Called when in-app browser is about to close.
 *
 *  @param webOpener the receiving object
 */
- (void)webOpenerWillCloseInAppBrowser:(NSObject *)webOpener {
    NSLog(@"%s",__func__);
}

/**
 *  Called when in-app browser finishes closing.
 *
 *  @param webOpener the receiving object
 */
- (void)webOpenerDidCloseInAppBrowser:(NSObject *)webOpener {
    NSLog(@"%s",__func__);
}

- (void)dealloc {
    NSLog(@"%s - %@",__func__, NSStringFromClass([self class]));
}

@end

//
//  JXViewController.m
//  ITAGoogleVideoAds
//
//  Created by tanjiaxiang on 06/19/2019.
//  Copyright (c) 2019 tanjiaxiang. All rights reserved.
//

#import "JXViewController.h"

#import "JXAVideoView.h"

static NSString *const tagOne = @"https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/single_ad_samples&ciu_szs=300x250&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ct%3Dlinear&correlator=";

static NSString *const tagTwo = @"https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/ad_rule_samples&ciu_szs=300x250&ad_rule=1&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ar%3Dpremidpostpod&cmsid=496&vid=short_onecue&correlator=";

@interface JXViewController ()<JXAWebOpenerDelegate>
@property (weak, nonatomic) IBOutlet JXAVideoView *containerView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *bottomConstraint;

@end

@implementation JXViewController

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [self.containerView remove];
}

- (IBAction)adsNormal:(id)sender {

    [self.containerView tagUrl:tagOne
                   userContext:nil
                         state:^(JXAVideoAdsState state, JXAVideoAds *video) {
                             switch (state) {
                                     
                                 case JXAVideoAdsState_Loaded:
                                     NSLog(@"已经加载完毕 - JXAVideoAdsState_Loaded");
//                                     [video play];
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
- (IBAction)adsProgress:(id)sender {
    [self.containerView tagUrl:tagOne
                   userContext:nil
                         state:^(JXAVideoAdsState state, JXAVideoAds *video) {
                             switch (state) {
                                     
                                 case JXAVideoAdsState_Loaded:
                                     NSLog(@"已经加载完毕 - JXAVideoAdsState_Loaded");
//                                                                          [video play];
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
                             //                             NSLog(@"currentTime -- %f \n duration -- %f", current, duration);
                         }];
}

- (IBAction)params:(id)sender {
    NSString *tag = @"https://pubads.g.doubleclick.net/gampad/ads?sz=640x480&iu=/124319096/external/single_ad_samples&ciu_szs=300x250&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&cust_params=deployment%3Ddevsite%26sample_ct%3Dskippablelinear&correlator=";
    [self.containerView params:^JXAVideoParamsBuilder *(JXAVideoParamsBuilder *paramsBuilder) {
        return  paramsBuilder
        .autoPlayAdBreaks(YES)
        .language(@"en")
        .enableBackgroundPlayback(NO)
        .volume(@0.2)
        .adTagUrl(tag)
        .userContext(nil)
        .player(nil)
        .mimeTypes(@[ @"video/mp4", @"application/x-mpegURL"])
        .bitrate(1024)
        .webOpenerPresentingController(nil)
        .webOpenerDelegate(nil);
    } state:^(JXAVideoAdsState state, JXAVideoAds *video) {
        switch (state) {
                
            case JXAVideoAdsState_Loaded:
                NSLog(@"已经加载完毕 - JXAVideoAdsState_Loaded");
//                [video play];
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

- (IBAction)paramsP:(id)sender {
    
    [self.containerView params:^JXAVideoParamsBuilder *(JXAVideoParamsBuilder *paramsBuilder) {
        return  paramsBuilder
        .autoPlayAdBreaks(YES)
        .language(@"en")
        .enableBackgroundPlayback(YES)
        .volume(@1)
        .adTagUrl(tagOne)
        .userContext(nil)
        .player(nil)
        .mimeTypes(@[ @"video/mp4", @"application/x-mpegURL"])
        .bitrate(1024)
        .webOpenerPresentingController([JXViewController new])
        .webOpenerDelegate(self);
    } state:^(JXAVideoAdsState state, JXAVideoAds *video) {
        switch (state) {
                
            case JXAVideoAdsState_Loaded:
                NSLog(@"已经加载完毕 - JXAVideoAdsState_Loaded");
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
    } progress:^(CGFloat current, CGFloat duration) {
        NSLog(@"currentTime -- %f \n duration -- %f", current, duration);
    }];
}

- (IBAction)fullScreen:(id)sender {
    self.bottomConstraint.constant = 0;
}

- (IBAction)smallScreen:(id)sender {
    self.bottomConstraint.constant = 400;
}

- (IBAction)skip:(id)sender {
    [self.containerView.ads skip];
}
- (IBAction)pause:(id)sender {
    [self.containerView.ads pause];
}
- (IBAction)play:(id)sender {
    [self.containerView.ads play];
}
- (IBAction)resume:(id)sender {
    [self.containerView.ads resume];
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
    NSLog(@"------%s ------------------------------------", __func__);
}



@end

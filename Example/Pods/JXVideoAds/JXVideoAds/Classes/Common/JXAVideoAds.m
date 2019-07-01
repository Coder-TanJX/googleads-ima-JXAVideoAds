//
//  JXAVideoAds.m
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/21.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import "JXAVideoAds.h"

#import "JXAGoogleImaApi.h"
#import "JXAVideoAds+Extension.h"

@interface JXAVideoAds () <
IMAAdsLoaderDelegate,
IMAAdsManagerDelegate>

@end

@implementation JXAVideoAds


- (void)setState:(JXAVideoAdsState)state {
    if (self.stateBlock) {
        self.stateBlock(state, self);
    }
}

- (void)play {
    [self.adsManager start];
}

- (void)pause {
    [self.adsManager pause];
}

- (void)skip {
    [self.adsManager skip];
    [self.adsLoader contentComplete];
}

- (void)resume {
    [self.adsManager resume];
}

#pragma mark - IMAAdsLoaderDelegate

- (void)adsLoader:(IMAAdsLoader *)loader
adsLoadedWithData:(IMAAdsLoadedData *)adsLoadedData {
    
    self.adsManager = (JXAAdsManager *)adsLoadedData.adsManager;
    self.adsManager.delegate = self;
    if (self.params.volume) {
        self.adsManager.volume = self.params.volume.floatValue;
    }
    
    
    IMAAdsRenderingSettings *adsRenderingSettings = [IMAAdsRenderingSettings new];
    if (self.params.mimeTypes) {
        adsRenderingSettings.mimeTypes = self.params.mimeTypes;
    }
    if (self.params.bitrate) {
        adsRenderingSettings.bitrate = self.params.bitrate;
    }
    if (self.params.webOpenerPresentingController) {
        adsRenderingSettings.webOpenerPresentingController = self.params.webOpenerPresentingController;
    }
    if (self.params.webOpenerDelegate) {
        adsRenderingSettings.webOpenerDelegate = self.params.webOpenerDelegate;
    }
    [self.adsManager initializeWithAdsRenderingSettings:adsRenderingSettings];
}

- (void)adsLoader:(IMAAdsLoader *)loader
failedWithErrorData:(IMAAdLoadingErrorData *)adErrorData {
    [self setState:JXAVideoAdsState_Error];
}

#pragma mark - IMAAdsManagerDelegate

- (void)adsManager:(IMAAdsManager *)adsManager
 didReceiveAdError:(IMAAdError *)error {
    [self setState:JXAVideoAdsState_Error];
}

- (void)adsManager:(IMAAdsManager *)adsManager
 didReceiveAdEvent:(IMAAdEvent *)event {
    switch (event.type) {
            
        case kIMAAdEvent_LOADED:
            [self setState:JXAVideoAdsState_Loaded];
            break;
        case kIMAAdEvent_AD_BREAK_READY:
            [self setState:JXAVideoAdsState_Loaded];
            break;
            
        case kIMAAdEvent_STARTED:
            [self setState:JXAVideoAdsState_Started];
            break;
            
        case kIMAAdEvent_SKIPPED:
            [self setState:JXAVideoAdsState_Skipped];
            break;
            
        case kIMAAdEvent_PAUSE:
            [self setState:JXAVideoAdsState_Pause];
            break;
            
        case kIMAAdEvent_RESUME:
            [self setState:JXAVideoAdsState_Resume];
            break;
            
        case kIMAAdEvent_COMPLETE:
            //            [self setState:JXAVideoAdsState_Ended];
//                        [self.adsLoader contentComplete];
            break;
            
        default:
            break;
    }
}

- (void)adsManagerDidRequestContentPause:(IMAAdsManager *)adsManager {
//    [self.player pause];
}

- (void)adsManagerDidRequestContentResume:(IMAAdsManager *)adsManager {
    [self setState:JXAVideoAdsState_Ended];
    [self.adsLoader contentComplete];
}



@end

//
//  JXAVideoAds+Extension.h
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/21.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import "JXAVideoAds.h"
#import "JXAVideoParams.h"

@interface JXAVideoAds (Extension)
@property (nonatomic, strong) JXAAdsLoader *adsLoader;
@property (nonatomic, strong) JXAAdsManager *adsManager;
@property (nonatomic, strong) JXAAdsRequest *request;

// PiP objects.
@property(nonatomic, strong) AVPictureInPictureController *pictureInPictureController;
@property(nonatomic, strong) JXAPictureInPictureProxy *pictureInPictureProxy;

//Cutsom
@property (nonatomic, strong) JXAVideoParams *params;
@property (nonatomic, copy) StateBlock stateBlock;
- (void)setState:(JXAVideoAdsState)state;

@end

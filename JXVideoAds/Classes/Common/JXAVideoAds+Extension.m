//
//  JXAVideoAds+Extension.m
//  JXVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/21.
//  Copyright © 2019 tanjiaxiang. All rights reserved.
//

#import "JXAVideoAds+Extension.h"

#import <objc/message.h>

@implementation JXAVideoAds (Extension)

- (void)setAdsLoader:(JXAAdsLoader *)adsLoader {
    objc_setAssociatedObject(self,
                             @selector(adsLoader),
                             adsLoader,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setAdsManager:(JXAAdsManager *)adsManager {
    objc_setAssociatedObject(self,
                             @selector(adsManager),
                             adsManager,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setRequest:(JXAAdsRequest *)request {
    objc_setAssociatedObject(self,
                             @selector(request),
                             request,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setPictureInPictureProxy:(JXAPictureInPictureProxy *)pictureInPictureProxy {
    objc_setAssociatedObject(self,
                             @selector(pictureInPictureProxy),
                             pictureInPictureProxy,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setPictureInPictureController:(AVPictureInPictureController *)pictureInPictureController  API_AVAILABLE(ios(9.0)){
    objc_setAssociatedObject(self,
                             @selector(pictureInPictureController),
                             pictureInPictureController,
                             OBJC_ASSOCIATION_COPY_NONATOMIC);
}

- (void)setParams:(JXAVideoParams *)params {
    objc_setAssociatedObject(self,
                             @selector(params),
                             params,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)setStateBlock:(StateBlock)stateBlock {
    objc_setAssociatedObject(self,
                             @selector(stateBlock),
                             stateBlock,
                             OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (JXAAdsLoader *)adsLoader {
    return objc_getAssociatedObject(self, _cmd);
}

- (JXAAdsManager *)adsManager {
    return objc_getAssociatedObject(self, _cmd);
}

- (JXAAdsRequest *)request {
    return objc_getAssociatedObject(self, _cmd);
}

- (JXAPictureInPictureProxy *)pictureInPictureProxy {
    return objc_getAssociatedObject(self, _cmd);
}

- (AVPictureInPictureController *)pictureInPictureController  API_AVAILABLE(ios(9.0)){
    return objc_getAssociatedObject(self, _cmd);
}

- (JXAVideoParams *)params {
    return objc_getAssociatedObject(self, _cmd);
}

- (StateBlock)stateBlock {
    return objc_getAssociatedObject(self, _cmd);
}

- (void)setState:(JXAVideoAdsState)state {
    if (self.stateBlock) {
        self.stateBlock(state, self);
    }
}

- (void)remove {

    [self.adsManager pause];
    if (self.adsManager) {
        [self.adsManager destroy];
        self.adsManager = nil;
    }
    
    if (self.adsLoader) {
        [self.adsLoader contentComplete];
        self.adsLoader = nil;
    }
}

@end

//
//  GoogleInteractiveMediaAds.h
//  GoogleInteractiveMediaAds
//
//  Copyright © 2016 Google. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for GoogleInteractiveMediaAds.
FOUNDATION_EXPORT double GoogleInteractiveMediaAdsVersionNumber;

//! Project version string for GoogleInteractiveMediaAds.
FOUNDATION_EXPORT const unsigned char GoogleInteractiveMediaAdsVersionString[];

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_8_0
#error The IMA SDK requires a deployment target of 8.0 or later.
#endif

#import <GoogleInteractiveMediaAds/IMAAVPlayerContentPlayhead.h>
#import <GoogleInteractiveMediaAds/IMAAVPlayerVideoDisplay.h>
#import <GoogleInteractiveMediaAds/IMAAd.h>
#import <GoogleInteractiveMediaAds/IMAAdDisplayContainer.h>
#import <GoogleInteractiveMediaAds/IMAAdError.h>
#import <GoogleInteractiveMediaAds/IMAAdEvent.h>
#import <GoogleInteractiveMediaAds/IMAAdPlaybackInfo.h>
#import <GoogleInteractiveMediaAds/IMAAdPodInfo.h>
#import <GoogleInteractiveMediaAds/IMAAdsLoader.h>
#import <GoogleInteractiveMediaAds/IMAAdsManager.h>
#import <GoogleInteractiveMediaAds/IMAAdsRenderingSettings.h>
#import <GoogleInteractiveMediaAds/IMAAdsRequest.h>
#import <GoogleInteractiveMediaAds/IMACompanionAdSlot.h>
#import <GoogleInteractiveMediaAds/IMAContentPlayhead.h>
#import <GoogleInteractiveMediaAds/IMACuepoint.h>
#import <GoogleInteractiveMediaAds/IMALiveStreamRequest.h>
#import <GoogleInteractiveMediaAds/IMAPictureInPictureProxy.h>
#import <GoogleInteractiveMediaAds/IMASettings.h>
#import <GoogleInteractiveMediaAds/IMAStreamManager.h>
#import <GoogleInteractiveMediaAds/IMAStreamRequest.h>
#import <GoogleInteractiveMediaAds/IMAUiElements.h>
#import <GoogleInteractiveMediaAds/IMAVODStreamRequest.h>
#import <GoogleInteractiveMediaAds/IMAVideoDisplay.h>

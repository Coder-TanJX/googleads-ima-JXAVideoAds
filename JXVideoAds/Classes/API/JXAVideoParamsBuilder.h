//
//  JXAVideoParamsBuilder.h
//  JXAVideoAds_Example
//
//  Created by Code-TanJX on 2019/6/22.
//  Copyright © 2019 TanJiaXiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JXAVideoParams.h"

@class JXAVideoParamsBuilder;

typedef JXAVideoParamsBuilder * (^ParamsBlock)(JXAVideoParamsBuilder *paramsBuilder);

@interface JXAVideoParamsBuilder : NSObject

@property(nonatomic, strong, readonly) JXAVideoParams *params;

/**
 *  Specifies whether to automatically play VMAP and ad rules ad breaks. The
 *  default value is YES.
 */
@property (nonatomic, copy) JXAVideoParamsBuilder *(^autoPlayAdBreaks)(BOOL);

/**
 *  Language specification used for localization. |Language| must be formatted as
 *  a canonicalized IETF BCP 47 language identifier such as would be returned by
 *  [NSLocale preferredLanguages]. Setting this property after it has been sent
 *  to the IMAAdsLoader will be ignored and a warning will be logged.
 */
@property (nonatomic, copy) JXAVideoParamsBuilder *(^language)(NSString *);

/**
 *  Enable background audio playback for the SDK. The default value is NO.
 */
@property (nonatomic, copy) JXAVideoParamsBuilder *(^enableBackgroundPlayback)(BOOL);

/**
 *  Set and get the volume for the current ad. From 0 (muted) to 1 (loudest). This volume is
 *  relative to device volume, not absolute. Default value is 1.
 */
@property (nonatomic, copy) JXAVideoParamsBuilder *(^volume)(NSNumber *);

/**
 *  Specifies the full URL to use for ads loading from an ad server. Required
 *  for any <code>adsRequest</code>. For details on constructing the ad tag url,
 *  see <a href="https://support.google.com/dfp_premium/answer/1068325">
 *  Create a master video tag manually</a>.
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^adTagUrl)(NSString *);

/**
 *  The user context.
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^userContext)(NSString *);

/**
 *  The player to track.
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^player)(AVPlayer *);

/**
 *  If specified, the SDK will prioritize the media with MIME type on the list.
 *  List of strings specifying the MIME types. When nil or empty, the SDK will
 *  use it's default list of MIME types supported on iOS.
 *  Example: @[ @"video/mp4", @"application/x-mpegURL" ]
 *  The property is an empty array by default.
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^mimeTypes)(NSArray *);

/**
 *  Maximum recommended bitrate. The value is in kbit/s.
 *  SDK will pick media with bitrate below the specified max, or the closest
 *  bitrate if there is no media with smaller bitrate found.
 *  Default value, |kIMAAutodetectBitrate|, means the bitrate will be selected
 *  by the SDK, using the currently detected network speed (cellular or Wi-Fi).
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^bitrate)(int);

/**
 *  Specifies the optional UIViewController that will be used to present an
 *  in-app browser.
 *  When nil, tapping the video ad "Learn More" button or companion ads
 *  will result in opening Safari browser. If provided, in-app browser will
 *  be used, allowing the user to stay in the app and return easily.
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^webOpenerPresentingController)(UIViewController *);

/**
 *  The IMAWebOpenerDelegate to be notified when in-app or external browser opens/closes.
 */
@property(nonatomic, copy) JXAVideoParamsBuilder *(^webOpenerDelegate)(id<JXAWebOpenerDelegate>);

@end

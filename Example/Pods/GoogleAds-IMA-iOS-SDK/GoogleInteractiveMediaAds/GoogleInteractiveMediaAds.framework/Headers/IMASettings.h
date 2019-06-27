//
//  IMASettings.h
//  GoogleIMA3
//
//  Copyright (c) 2015 Google Inc. All rights reserved.
//
//  Stores SDK wide settings. Only instantiated in the SDK.

#import <Foundation/Foundation.h>

/**
 *  The IMASettings class stores SDK wide settings.
 */
@interface IMASettings : NSObject <NSCopying>

/**
 *  Publisher Provided Identification (PPID) sent with ads request.
 */
@property(nonatomic, copy) NSString *ppid;

/**
 *  Language specification used for localization. |Language| must be formatted as
 *  a canonicalized IETF BCP 47 language identifier such as would be returned by
 *  [NSLocale preferredLanguages]. Setting this property after it has been sent
 *  to the IMAAdsLoader will be ignored and a warning will be logged.
 */
@property(nonatomic, copy) NSString *language;

/**
 *  Specifies maximum number of redirects after which subsequent redirects will
 *  be denied, and the ad load aborted. The number of redirects directly affects
 *  latency and thus user experience. This applies to all VAST wrapper ads. If
 *  the number of redirects exceeds |maxRedirects|, the ad request will fail with
 *  error code 302. The default value is 4.
 */
@property(nonatomic) NSUInteger maxRedirects;

/**
 *  Enable background audio playback for the SDK. The default value is NO.
 */
@property(nonatomic) BOOL enableBackgroundPlayback;

/**
 *  Specifies whether to automatically play VMAP and ad rules ad breaks. The
 *  default value is YES.
 */
@property(nonatomic) BOOL autoPlayAdBreaks;

/**
 *  Specifies whether to update the MPNowPlayingInfoCenter content with the
 *  title "Advertisement". If disabled, MPNowPlayingInfoCenter is untouched.
 *  The default value is NO.
 */
@property(nonatomic) BOOL disableNowPlayingInfo;

/**
 *  The partner specified video player that is integrating with the SDK.
 */
@property(nonatomic, copy) NSString *playerType;

/**
 *  The partner specified player version that is integrating with the SDK.
 */
@property(nonatomic, copy) NSString *playerVersion;

/**
 *  Toggles debug mode which will output detailed log information to the console.
 *  Debug mode should be disabled in Release and will display a watermark when
 *  enabled. The default value is NO.
 */
@property(nonatomic) BOOL enableDebugMode;

@end


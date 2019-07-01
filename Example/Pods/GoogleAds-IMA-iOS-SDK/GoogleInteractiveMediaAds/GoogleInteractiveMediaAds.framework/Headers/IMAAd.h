//
//  IMAAd.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Represents metadata of a single ad. The user can use this metadata for
//  positioning nonlinear ads (isLinear, width, height), internal tracking
//  (adId, adTitle) or custom behavior (traffickingParameters).

#import <Foundation/Foundation.h>

#import "IMAAdPodInfo.h"

/**
 *  Data object representing a single ad.
 */
@interface IMAAd : NSObject

/**
 *  The ad ID as specified in the VAST response.
 */
@property(nonatomic, copy, readonly) NSString *adId;

/**
 *  The ad title from the VAST response.
 */
@property(nonatomic, copy, readonly) NSString *adTitle;

/**
 *  The ad description.
 */
@property(nonatomic, copy, readonly) NSString *adDescription;

/**
 *  The source ad server information included in the ad response.
 */
@property(nonatomic, copy, readonly) NSString *adSystem;

/**
 *  Content type of the currently selected creative. For linear creatives
 *  returns the content type of the currently selected media file. Returns
 *  empty string if no creative or media file is selected on this ad.
 */
@property(nonatomic, copy, readonly) NSString *contentType;

/**
 *  The duration of the ad from the VAST response.
 */
@property(nonatomic, readonly) NSTimeInterval duration;

/**
 *  The UI elements that will be displayed during ad playback.
 */
@property(nonatomic, copy, readonly) NSArray *uiElements;

/**
 *  Whether or not the ad UI will be disabled for this ad.
 */
@property(nonatomic, readonly, getter=isUiDisabled) BOOL uiDisabled;

/**
 *  The width of the ad asset. For non-linear ads, this is the actual width
 *  of the ad representation. For linear ads, since they scale seamlessly, we
 *  currently return 0 for width.
 */
@property(nonatomic, readonly) int width;

/**
 *  The height of the ad asset. For non-linear ads, this is the actual height
 *  of the ad representation. For linear ads, since they scale seamlessly, we
 *  currently return 0 for height.
 */
@property(nonatomic, readonly) int height;

/**
 *  Specifies whether the ad is linear or non-linear.
 */
@property(nonatomic, readonly, getter=isLinear) BOOL linear;

/**
 *  Specifies whether the ad is skippable.
 */
@property(nonatomic, readonly, getter=isSkippable) BOOL skippable;

/**
 *  The number of seconds of playback before the ad becomes skippable. -1 is returned for non
 *  skippable ads or if this is unavailable.
 */
@property(nonatomic, readonly) NSTimeInterval skipTimeOffset;

/**
 *  Set of ad podding properties.
 */
@property(nonatomic, strong, readonly) IMAAdPodInfo *adPodInfo;

/**
 *  String representing custom trafficking parameters from the VAST response.
 */
@property(nonatomic, copy, readonly) NSString *traffickingParameters;

/**
 *  Returns the ID of the selected creative for the ad.
 */
@property(nonatomic, copy, readonly) NSString *creativeID;

/**
 *  Returns the ISCI (Industry Standard Commercial Identifier) code for an ad. This
 *  is the Ad-ID of the selected creative in the VAST response.
 */
@property(nonatomic, copy, readonly) NSString *creativeAdID;

/**
 *  The UniversalAdId of the selected creative for the ad. Returns the id value or "unknown"
 *  if unavailable.
 */
@property(nonatomic, copy, readonly) NSString *universalAdIdValue;

/**
 *  The registry associated with cataloging the UniversalAdId of the selected creative for the ad.
 *  Returns the registry value, or "unknown" if unavailable.
 */
@property(nonatomic, copy, readonly) NSString *universalAdIdRegistry;

/**
 *  The advertiser name as defined by the serving party.
 */
@property(nonatomic, copy, readonly) NSString *advertiserName;

/**
 *  Returns the URL associated with the survey for the given ad.
 */
@property(nonatomic, copy, readonly) NSString *surveyURL;

/**
 *  Returns the first deal ID present in the wrapper chain for the current ad,
 *  starting from the top.
 */
@property(nonatomic, copy, readonly) NSString *dealID;

/**
 *  The IDs of the ads, starting with the first wrapper ad.
 */
@property(nonatomic, copy, readonly) NSArray<NSString *> *wrapperAdIDs;

/**
 *  The IDs of the ads' creatives, starting with the first wrapper ad.
 */
@property(nonatomic, copy, readonly) NSArray<NSString *> *wrapperCreativeIDs;

/**
 *  Ad systems used for wrapper ads. The ad systems returned begin with the
 *  first wrapper ad and continue to each wrapper ad recursively.
 */
@property(nonatomic, copy, readonly) NSArray<NSString *> *wrapperSystems;


- (instancetype)init NS_UNAVAILABLE;

@end

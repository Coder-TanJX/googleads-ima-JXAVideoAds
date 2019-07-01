/*! \file IMAAdEvent.h
 *  GoogleIMA3
 *
 *  Copyright (c) 2013 Google Inc. All rights reserved.
 *
 *  Defines a data object used to convey information during ad playback.
 *  This object is sent to the IMAAdsManager delegate.
 */

#import <Foundation/Foundation.h>

#import "IMAAd.h"

#pragma mark IMAAdEventType

/**
 *  Different event types sent by the IMAAdsManager to its delegate.
 */
typedef NS_ENUM(NSInteger, IMAAdEventType){
  /**
   *  Ad break ready.
   */
  kIMAAdEvent_AD_BREAK_READY,
  /**
   *  Ad break ended (only used for dynamic ad insertion).
   */
  kIMAAdEvent_AD_BREAK_ENDED,
  /**
   *  Ad break started (only used for dynamic ad insertion).
   */
  kIMAAdEvent_AD_BREAK_STARTED,
  /**
   *  All ads managed by the ads manager have completed.
   */
  kIMAAdEvent_ALL_ADS_COMPLETED,
  /**
   *  Ad clicked.
   */
  kIMAAdEvent_CLICKED,
  /**
   *  Single ad has finished.
   */
  kIMAAdEvent_COMPLETE,
  /**
   *  Cuepoints changed for VOD stream (only used for dynamic ad insertion).
   *  For this event, the <code>IMAAdEvent.adData</code> property contains a list of
   *  <code>IMACuepoint</code>s at <code>IMAAdEvent.adData[@"cuepoints"]</code>.
   */
  kIMAAdEvent_CUEPOINTS_CHANGED,
  /**
   *  First quartile of a linear ad was reached.
   */
  kIMAAdEvent_FIRST_QUARTILE,
  /**
   *  An ad was loaded.
   */
  kIMAAdEvent_LOADED,
  /**
   *  A log event for the ads being played. These are typically non fatal errors.
   */
  kIMAAdEvent_LOG,
  /**
   *  Midpoint of a linear ad was reached.
   */
  kIMAAdEvent_MIDPOINT,
  /**
   *  Ad paused.
   */
  kIMAAdEvent_PAUSE,
  /**
   *  Ad resumed.
   */
  kIMAAdEvent_RESUME,
  /**
   *  Ad has skipped.
   */
  kIMAAdEvent_SKIPPED,
  /**
   *  Ad has started.
   */
  kIMAAdEvent_STARTED,
  /**
   *  Stream has loaded (only used for dynamic ad insertion).
   */
  kIMAAdEvent_STREAM_LOADED,
  /**
   *  Stream has started playing (only used for dynamic ad insertion). Start
   *  Picture-in-Picture here if applicable.
   */
  kIMAAdEvent_STREAM_STARTED,
  /**
   *  Ad tapped.
   */
  kIMAAdEvent_TAPPED,
  /**
   *  Third quartile of a linear ad was reached.
   */
  kIMAAdEvent_THIRD_QUARTILE
};

#pragma mark - Ad Data Keys

/**
 *  The key for the time in seconds when the AD_BREAK_READY event fired.
 */
static NSString *const kIMAAdBreakTime = @"kIMAAdBreakTime";

#pragma mark - IMAAdEvent

/**
 *  Simple data class used to transport ad playback information.
 */
@interface IMAAdEvent : NSObject

/**
 *  Type of the event.
 */
@property(nonatomic, readonly) IMAAdEventType type;

/**
 *  Stringified type of the event.
 */
@property(nonatomic, copy, readonly) NSString *typeString;

/**
 *  The current ad that is playing or just played. This will be nil except for
 *  events where an ad is available (start, quartiles, midpoint, complete, and tap).
 */
@property(nonatomic, strong, readonly) IMAAd *ad;

/**
 *  Extra data about the ad. Can be nil.
 */
@property(nonatomic, copy, readonly) NSDictionary *adData;

- (instancetype)init NS_UNAVAILABLE;

@end

/*! \file IMAUiElements.h
 *  GoogleIMA3
 *
 *  Copyright (c) 2013 Google Inc. All rights reserved.
 *
 *  Defines an enum containing the possible UI elements that can be
 *  customized by the publisher during ad playback.
 */


#import <Foundation/Foundation.h>

#pragma mark IMAUiElementType

/**
 *  Different UI elements that can be customized.
 */
typedef NS_ENUM(NSInteger, IMAUiElementType){
  /**
   *  Ad attribution UI element.
   */
  kIMAUiElements_AD_ATTRIBUTION,
  /**
   *  Ad countdown element.
   */
  kIMAUiElements_COUNTDOWN
};

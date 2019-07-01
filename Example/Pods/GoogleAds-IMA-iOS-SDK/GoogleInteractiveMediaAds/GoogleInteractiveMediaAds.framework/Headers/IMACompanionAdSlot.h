//
//  IMACompanionAdSlot.h
//  GoogleIMA3
//
//  Copyright (c) 2013 Google Inc. All rights reserved.
//
//  Declares a data class that describes a companion ad slot.

#import <UIKit/UIKit.h>

@class IMACompanionAdSlot;

#pragma mark IMACompanionDelegate

/**
 *  Delegate to receive events from the companion ad slot.
 */
@protocol IMACompanionDelegate<NSObject>

@optional

/**
 *  Called when the slot is either filled or not filled.
 *
 *  @param slot   the IMACompanionAdSlot receiving the event
 *  @param filled is the slot filled or not
 */
- (void)companionSlot:(IMACompanionAdSlot *)slot filled:(BOOL)filled;

/**
 *  Called when the slot is clicked on by the user and will
 *  successfully navigate away.
 *
 *  @param slot   the IMACompanionAdSlot receiving the event
 */
- (void)companionSlotWasClicked:(IMACompanionAdSlot *)slot;

@end

#pragma mark - IMACompanionAdSlot

/**
 *  Ad slot for companion ads. The SDK will put a subview inside the provided
 *  UIView container. The companion will be matched to the width and height
 *  provided here.
 */
@interface IMACompanionAdSlot : NSObject

/**
 *  The view the companion will be rendered in. Display this view in your
 *  application before video ad starts.
 */
@property(nonatomic, strong, readonly) UIView *view;

/**
 *  Width of the slot, in pixels. This value is sent to the DFP ad server for
 *  targeting.
 */
@property(nonatomic, readonly) int width;

/**
 *  Height of the slot, in pixels. This value is sent to the DFP ad server for
 *  targeting.
 */
@property(nonatomic, readonly) int height;

/**
 *  The IMACompanionDelegate for receiving events from the companion ad slot.
 */
@property(nonatomic, weak) id<IMACompanionDelegate> delegate;

/**
 *  Initializes an instance of a IMACompanionAdSlot with design ad width and height.
 *
 *  @param view   the UIView that will contain the companion ad
 *  @param width  the desired width of the ad
 *  @param height the desired height of the ad
 *
 *  @return the IMACompanionAdSlot instance
 */
- (instancetype)initWithView:(UIView *)view width:(int)width height:(int)height;

- (instancetype)init NS_UNAVAILABLE;

@end

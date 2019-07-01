//
//  IMAPictureInPictureProxy.h
//  GoogleIMA3
//
//  Copyright (c) 2015 Google Inc. All rights reserved.
//
//  Defines a proxy for wrapping an AVPlayerViewControllerDelegate or
//  AVPictureInPictureControllerDelegate for handling Picture-in-Picture.

#import <AVKit/AVKit.h>
#import <Foundation/Foundation.h>

@protocol AVPlayerViewControllerDelegate;
@protocol AVPictureInPictureControllerDelegate;

/**
 *  A proxy class for allowing the SDK to detect entering and exiting
 *  Picture-in-Picture.
 *
 *  To use the proxy, create an instance of IMAPictureInPictureProxy with the
 *  Picture-in-Picture delegate as an argument, and then simply set the
 *  Picture-in-Picture controller's delegate to the proxy. For example with an
 *  AVPictureInPictureController instance:
 *
 *  \@interface ViewController : UIViewController <AVPictureInPictureControllerDelegate>
 *
 *  \@property(nonatomic, strong) AVPictureInPictureController *pictureInPictureController;
 *
 *  \@property(nonatomic, strong) AVPlayerLayer *playerLayer;
 *
 *  \@property(nonatomic, strong) IMAPictureInPictureProxy *pictureInPictureProxy;
 *
 *  \@end
 *
 *  \@implementation ViewController
 *
 *  - (void)loadView {
 *
 *    ...
 *
 *    self.pictureInPictureProxy =
 *        [[IMAPictureInPictureProxy alloc] initWithAVPictureInPictureControllerDelegate:self];
 *
 *    self.pictureInPictureController =
 *        [[AVPictureInPictureController alloc] initWithPlayerLayer:self.playerLayer];
 *
 *    self.pictureInPictureController.delegate = self.pictureInPictureProxy;
 *
 *    ...
 *  }
 *
 *  \@end
 */
@interface IMAPictureInPictureProxy : NSProxy <AVPictureInPictureControllerDelegate,
                                               AVPlayerViewControllerDelegate>
/**
 *  Whether or not Picture-in-Picture is currently active.
 */
@property(nonatomic, readonly, getter=isPictureInPictureActive) BOOL pictureInPictureActive;

/**
 *  Whether or not Picture-in-Picture is supported on this device.
 */
+ (BOOL)isPictureInPictureSupported;

/**
 *  Instantiates an IMAPictureInPictureProxy that will proxy delegate
 *  messages from an AVPictureInPictureController, and forward them
 *  to the AVPictureInPictureControllerDelegate passed on init.
 *
 *  @param delegate the AVPictureInPictureControllerDelegate
 *
 *  @return an IMAPictureInPictureProxy instance
 */
- (instancetype)initWithAVPictureInPictureControllerDelegate:
    (id<AVPictureInPictureControllerDelegate>)delegate;

/**
 *  Instantiates an IMAPictureInPictureProxy that will proxy delegate
 *  messages from an AVPlayerViewController, and forward them to the
 *  AVPlayerViewControllerDelegate passed on init.
 *
 *  @param delegate the AVPlayerViewControllerDelegate
 *
 *  @return an IMAPictureInPictureProxy instance
 */
- (instancetype)initWithAVPlayerViewControllerDelegate:(id<AVPlayerViewControllerDelegate>)delegate;

@end

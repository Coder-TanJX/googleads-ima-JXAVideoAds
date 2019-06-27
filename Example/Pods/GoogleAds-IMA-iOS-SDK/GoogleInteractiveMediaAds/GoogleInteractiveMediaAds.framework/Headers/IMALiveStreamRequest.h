//
//  IMALiveStreamRequest.h
//  GoogleIMA3_ios
//
//  Declares a representation of a stream request for live streams.
//
//

#import "IMAStreamRequest.h"

@class IMAAdDisplayContainer;
@protocol IMAVideoDisplay;

/**
 * Data object describing a live stream request.
 */

@interface IMALiveStreamRequest : IMAStreamRequest

/**
 *  This is used to determine which stream should be played.
 *  The live stream request asset key is an identifier which can be
 *  <a href="https://goo.gl/wjL9DI">found in the DFP UI</a>.
 *
 *  @type {!string}
 */
@property(nonatomic, copy, readonly) NSString *assetKey;

/**
 *  Initializes a live stream request instance with the given assetKey. Uses the given ad display
 *  container to display the stream.
 *
 *  @param assetKey           the stream assetKey
 *  @param adDisplayContainer the IMAAdDisplayContainer for rendering the ad UI
 *  @param videoDisplay       the IMAVideoDisplay for playing the stream
 *
 *  @return the IMALiveStreamRequest instance
 */
- (instancetype)initWithAssetKey:(NSString *)assetKey
              adDisplayContainer:(IMAAdDisplayContainer *)adDisplayContainer
                    videoDisplay:(id<IMAVideoDisplay>)videoDisplay;

/**
 *  Initializes a live stream request instance with the given assetKey. Uses the given ad display
 *  container to display the stream. Uses the picture in picture proxy to track PIP events.
 *
 *  @param assetKey              the stream assetKey
 *  @param adDisplayContainer    the IMAAdDisplayContainer for rendering the ad UI
 *  @param videoDisplay          the IMAVideoDisplay for playing the stream
 *  @param pictureInPictureProxy the IMAPictureInPictureProxy for tracking PIP events
 *
 *  @return the IMALiveStreamRequest instance
 */
- (instancetype)initWithAssetKey:(NSString *)assetKey
              adDisplayContainer:(IMAAdDisplayContainer *)adDisplayContainer
                    videoDisplay:(id<IMAVideoDisplay>)videoDisplay
           pictureInPictureProxy:(IMAPictureInPictureProxy *)pictureInPictureProxy;

- (instancetype)init NS_UNAVAILABLE;

@end

//
//  IMACuepoint.h
//  GoogleIMA3_ios
//
//  Represents a cuepoint with a start and end time.


#import <Foundation/Foundation.h>

/**
 *  Data object representation of a cuepoint for a single ad break.
 */
@interface IMACuepoint : NSObject

/**
 *  The start time of the cuepoint in seconds.
 */
@property(nonatomic, readonly) NSTimeInterval startTime;

/**
 *  The end time of the cuepoint in seconds.
 */
@property(nonatomic, readonly) NSTimeInterval endTime;

/**
 *  Specifies whether this cuepoint has been played.
 */
@property(nonatomic, readonly, getter=isPlayed) BOOL played;

- (instancetype)init NS_UNAVAILABLE;

@end

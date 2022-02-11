//
//  MBFrameGrabberRecognizer.h
//  MicroblinkDev
//
//  Created by Jura Skrlec on 02/01/2018.
//

#import <Foundation/Foundation.h>
#import "MBMicroblinkDefines.h"
#import "MBRecognizer.h"

@protocol MBBFrameGrabberRecognizerDelegate;

@class MBBImage;

NS_ASSUME_NONNULL_BEGIN

/**
 * A recognizer that can returns success frame.
 */
MB_CLASS_AVAILABLE_IOS(8.0) MB_FINAL
@interface MBBFrameGrabberRecognizer : MBBRecognizer<NSCopying>

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrameGrabberDelegate:(id<MBBFrameGrabberRecognizerDelegate>)frameGrabberDelegate NS_SWIFT_NAME(init(frameGrabberDelegate:));

/**
 * Allow sending focused camera frames to MBBFrameGrabberRecognizerDelegate.
 *
 * Default: YES
 */
@property(nonatomic, assign) BOOL grabFocusedFrames;

/**
 * Allow sending unfocused camera frames to MBBFrameGrabberRecognizerDelegate.
 *
 * Default: NO
 */
@property(nonatomic, assign) BOOL grabUnfocusedFrames;

@end

@protocol MBBFrameGrabberRecognizerDelegate <NSObject>
@required
/**
 * Called when {FrameGrabberRecognizer} received new frame for processing.
 * Note that all buffers associated with image are available only during life of this method.
 * As soon as this method exits, there is no guarantee that buffers will be valid. If you need
 * to store image for later processing, showing or saving, make sure you create a copy of it.
 * @param cameraFrame The {MBBImage} containing frame that will be processed.
 * @param focused Information whether or not given frame is considered to be in focus. This
 *                  information is calculated on the basis of frame quality estimation algorithm
 *                  combined with information about actual frame that was provided by camera device.
 * @param frameQuality A number indicating calculated quality of given frame. This number is
 *                     non-negative, however it's maximum is not defined - the higher the number
 *                     is, the better the observed quality of frame is.
 */
- (void)onFrameAvailable:(MBBImage *)cameraFrame isFocused:(BOOL)focused frameQuality:(CGFloat)frameQuality;

@end

NS_ASSUME_NONNULL_END
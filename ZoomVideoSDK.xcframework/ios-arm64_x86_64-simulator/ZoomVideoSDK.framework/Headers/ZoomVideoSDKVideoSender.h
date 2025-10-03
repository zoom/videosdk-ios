/**
 * @file ZoomVideoSDKVideoSender.h
 * @brief Interface for sending custom video data through external video source protocols.
 */

#import <Foundation/Foundation.h>
/**
 * @class ZoomVideoSDKVideoSender
 * @brief A class for user to send video raw data.
 */
@interface ZoomVideoSDKVideoSender : NSObject

/**
 * @brief Send one frame data.
 * @param frameBuffer YUVI420 buffer.
 * @param width frame width.
 * @param height frame height.
 * @param dataLength buffer length.
 * @param rotation buffer rotation.
 * @param format buffer format.
 */
- (void)sendVideoFrame:(char *)frameBuffer width:(NSUInteger)width height:(NSUInteger)height dataLength:(NSUInteger)dataLength rotation:(ZoomVideoSDKVideoRawDataRotation)rotation format:(ZoomVideoSDKFrameDataFormat)format;

@end


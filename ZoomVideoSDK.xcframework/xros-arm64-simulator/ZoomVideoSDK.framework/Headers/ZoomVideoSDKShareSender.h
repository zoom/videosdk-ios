/**
 * @file ZoomVideoSDKShareSender.h
 * @brief Interface for sending custom share content data through external share source protocols.
 */

#import <Foundation/Foundation.h>
/**
 * @class ZoomVideoSDKShareSender
 * @brief A class for user to send video raw data.
 */
@interface ZoomVideoSDKShareSender : NSObject
/**
 * @brief Send one frame data.
 * @param frameBuffer FrameBuffer YUVI420 buffer.
 * @param width Frame width.
 * @param height Frame height.
 * @param frameLength Buffer length.
 * @param format buffer format.
 * @return If the function succeeds, the return value is Errors_Success.Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)sendShareFrame:(char*)frameBuffer width:(int)width height:(int)height frameLength:(int)frameLength format:(ZoomVideoSDKFrameDataFormat)format;

@end


/**
 * @file ZoomVideoSDKVideoCapability.h
 * @brief Interface for video capability information including supported resolutions and video feature capabilities.
 */

#import <Foundation/Foundation.h>

/**
 * @class ZoomVideoSDKVideoCapability
 * @brief Capabilitiy infomation of video source.
 */
@interface ZoomVideoSDKVideoCapability : NSObject
/**
 * @brief width of video.
 */
@property (nonatomic, assign) int width;
/**
 * @brief height of video.
 */
@property (nonatomic, assign) int height;
/**
 * @brief frame rate of video.
 */
@property (nonatomic, assign) int frame;

@end

/**
 * @file ZoomVideoSDKRemoteCameraControlHelper.h
 * @brief Interface for remote camera control operations including pan, tilt, zoom, and camera movement management.
 */

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>

/**
 * @class ZoomVideoSDKRemoteCameraControlHelper
 * @brief Remote camera control helper object interface.
 */
@interface ZoomVideoSDKRemoteCameraControlHelper : NSObject
/**
 * @brief Request to control remote camera.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)requestControlRemoteCamera;

/**
 * @brief Give up control of the remote camera.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)giveUpControlRemoteCamera;

/**
 * @brief Turn the camera to the left.
 * @param range The rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)turnLeft:(unsigned int)range;

/**
 * @brief Turn the camera to the right.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)turnRight:(unsigned int)range;

/**
 * @brief Turn the camera up.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)turnUp:(unsigned int)range;

/**
 * @brief Turn the camera down.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)turnDown:(unsigned int)range;

/**
 * @brief Zoom the camera in.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)zoomIn:(unsigned int)range;

/**
 * @brief Zoom the camera out.
 * @param range rotation range, 10 <= range <= 100.
 * @return If the function succeeds, it will return Errors_Success.
 */
-(ZoomVideoSDKError)zoomOut:(unsigned int)range;
@end

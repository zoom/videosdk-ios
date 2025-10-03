//
//  ZoomVideoSDKWhiteboardHelper.h
//  ZoomVideoSDK
//
//  Created by ZOOM  on 2025/6/23.
//  Copyright © 2025 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * @brief The whiteboard helper interface.
 * @note IMPORTANT: To prevent whiteboard data loss, developers must call \link exportWhiteboard: \endlink before the following scenarios:
 *       - Closing the whiteboard (calling \link stopShareWhiteboard \endlink)
 *       - Leaving the session (calling \link ZoomVideoSDK::leaveSession \endlink)
 *       - Joining a sub-session (calling \link SubSessionKit::joinSubSession \endlink or \link SubSessionKit::joinSubSessionByUserRequest \endlink)
 *       KNOWN ISSUE: Data loss is unavoidable in crash or failover scenarios. To minimize potential data loss, implement periodic auto-save functionality using \link exportWhiteboard: \endlink.
 */
@interface ZoomVideoSDKWhiteboardHelper : NSObject

/**
 * @brief Displays the whiteboard view when someone is sharing the whiteboard.
 * @param vc The view controller to attach the whiteboard view to.
 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
 * @note The view controller should be hidden when whiteboard sharing is stopped, or the user who is sharing the whiteboard leaves session, or the session is failover for Errors_Session_Reconncting.
 */
-(ZoomVideoSDKError)subscribeWhiteboard:(UIViewController*)vc  API_UNAVAILABLE(visionos);

/**
 * @brief Hides the whiteboard sharing view when someone is sharing the whiteboard.
 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
 */
-(ZoomVideoSDKError)unSubscribeWhiteboard  API_UNAVAILABLE(visionos);

/**
 * @brief Checks whether the current user can start whiteboard sharing. Only the host can start whiteboard sharing.
 * @return true if the user can start whiteboard sharing, otherwise it returns false.
 * @note The whiteboard service is an add-on, be sure to enable it by package zm-annoter & whiteboard module, otherwise this method will always returns false.
 */
-(BOOL)canStartShareWhiteboard  API_UNAVAILABLE(visionos);

/**
 * @brief Starts whiteboard sharing in the session.
 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
 */
-(ZoomVideoSDKError)startShareWhiteboard  API_UNAVAILABLE(visionos);

/**
 * @brief Checks whether the current user can stop whiteboard sharing.
 * @return true if the user can stop whiteboard sharing, otherwise it returns false.
 */
-(BOOL)canStopShareWhiteboard  API_UNAVAILABLE(visionos);

/**
 * @brief Stops whiteboard sharing in the session.
 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
 */
-(ZoomVideoSDKError)stopShareWhiteboard  API_UNAVAILABLE(visionos);

/**
 * @brief Checks whether another user is currently sharing a whiteboard.
 * @return true if another user is sharing whiteboard; otherwise it returns false.
 */
-(BOOL)isOtherSharingWhiteboard  API_UNAVAILABLE(visionos);

/**
 * @brief Exports the currently shared whiteboard.
 * @param format The export format.
 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKErrors \endlink enum.
 * @note The exported data is delivered via \link ZoomVideoSDKDelegate::onWhiteboardExported:data: \endlink. Be sure to implement this callback in your delegate to handle the exported data.
 * @warning During the export process (before receiving the \link ZoomVideoSDKDelegate::onWhiteboardExported:data: \endlink callback), calling \link stopShareWhiteboard \endlink will cause data loss. Wait until the export is complete before stopping the whiteboard share.
 */
-(ZoomVideoSDKError)exportWhiteboard:(ZoomVideoSDKWhiteboardExportFormatType)format  API_UNAVAILABLE(visionos);

@end


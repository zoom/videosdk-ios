//
//  ZoomVideoSDKBroadcastStreamingHelper.h
//  ZoomVideoSDK
//
//  Created by ZOOM  on 2025/7/28.
//  Copyright © 2025 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface ZoomVideoSDKBroadcastStreamingHelper : NSObject

/**
 * @brief Check if the session supports broadcast streaming.
 * @return true if supported; false if not
 */
- (BOOL)isBroadcastStreamingSupported;

/**
 * @brief Check if the user has permission to start broadcast.
 * @return YES if allow; NO if not
 */
- (BOOL)canStartBroadcast;

/**
 * @brief Start broadcast streaming asynchronously.The result is notified via the callback '-[ZoomVideoSDKDelegate onStartBroadcastResponse:channelID:]'.
 * @return Errors_Success If the function succeeds, otherwise  the method failed..
 */
- (ZoomVideoSDKError)startBroadcast;

/**
 * @brief Stops broadcast streaming asynchronously. The result is notified via the callback ''-[ZoomVideoSDKDelegate onStopBroadcastResponse:]'
 * @param channelID broadcast streaming channel id.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed. For detailed error codes, see \link ZoomVideoSDKError \endlink enum.
 */
- (ZoomVideoSDKError)stopBroadcast:(NSString * _Nonnull)channelID;

/**
 * @brief Get broadcast status asynchronously.The result is notified via the callback -[ZoomVideoSDKDelegate onGetBroadcastControlStatus:status:]'.
 * @param channelID broadcast streaming channel ID.
 * @return Errors_Success If the function succeeds, otherwise fthe method failed
 */
- (ZoomVideoSDKError)getBroadcastStatus:(NSString * _Nonnull)channelID;

@end

/**
 * @brief Streaming join context.
 */
@interface ZoomVideoSDKStreamingJoinContext : NSObject
@property (nonatomic,copy) NSString * token;
@property (nonatomic,copy) NSString * channelID;
@end



@interface ZoomVideoSDKBroadcastStreamingViewerHelper : NSObject
/**
 * @brief Join broadcast streaming asynchronously. Result is notified via the callback '-[ZoomVideoSDKDelegate onStreamingJoinStatusChanged:]'.
 * @param joinContext join context.
 * @return Errors_Success If the function succeeds, otherwise failed.
 */
- (ZoomVideoSDKError)joinStreaming:(ZoomVideoSDKStreamingJoinContext* _Nullable)joinContext;

/**
 * @brief Leave broadcast streaming asynchronously. Result is notified via the callback [ZoomVideoSDKDelegate onStreamingJoinStatusChanged:]'.
 * @return Errors_Success If the function succeeds, otherwise failed.
 */
- (ZoomVideoSDKError)leaveStreaming;

/**
 * @brief Get  the currentstreaming join status.
 * @return The Join status,See \link ZoomVideoSDKStreamingJoinStatus \endlink .
*/
- (ZoomVideoSDKStreamingJoinStatus)getStreamingJoinStatus;

/**
 * @brief Subscribe to streaming video.
 * @param resolution The desired video resolution, Ssupported: See \link ZoomVideoSDKVideoResolution \endlink.
 * @param delegate  the raw video data callback object, See \link ZoomVideoSDKBroadcastStreamingVideoDelegate \endlink.
 * @return Errors_Success If the function succeeds, otherwise failed.
*/
- (ZoomVideoSDKError)subscribeVideoWithDelegate:(id<ZoomVideoSDKBroadcastStreamingVideoDelegate> _Nullable)delegate  resolution:(ZoomVideoSDKVideoResolution)resolution;
/**
 * @brief Unsubscribe from streaming video raw data.
 * @return Errors_Success If the function succeeds, otherwise failed.

*/
- (ZoomVideoSDKError)unSubscribeVideo;

/**
 * @brief Subscribe to streaming audio.
 * @param delegate The raw audio data callback object, See \link ZoomVideoSDKBroadcastStreamingAudioDelegate \endlink.
 * @return Errors_Success If the function succeeds, otherwise failed.
*/
- (ZoomVideoSDKError)subscribeAudioWithDelegate:(id<ZoomVideoSDKBroadcastStreamingAudioDelegate> _Nullable)delegate;

/**
 * @brief Unsubscribe from streaming audio raw data.
 * @return Errors_Success If the function succeeds, otherwise failed.
*/
- (ZoomVideoSDKError)unSubscribeAudio;


@end




NS_ASSUME_NONNULL_END

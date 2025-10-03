/**
 * @file ZoomVideoSDKLiveStreamHelper.h
 * @brief Interface for live streaming operations including starting/stopping live streams and managing incoming live stream status.
 */

#import <Foundation/Foundation.h>
/**
 * @class ZoomVideoSDKLiveStreamSetting
 * @brief Live stream settings configuration class for Zoom Video SDK.
 * This class contains layout and close caption settings for live streaming.
 */
@interface ZoomVideoSDKLiveStreamSetting : NSObject

/**
 * The layout type for the live stream.
 */
@property(nonatomic, assign) ZoomVideoSDKLiveStreamLayout layout;

/**
 * The close caption setting for the live stream.
 */
@property(nonatomic, assign) ZoomVideoSDKLiveStreamCloseCaption closeCaption;

@end

/**
 * @class ZoomVideoSDKLiveStreamParams
 * @brief Live stream parameters for starting live stream.
 * This class contains all the necessary parameters to configure and start a live stream.
 */
@interface ZoomVideoSDKLiveStreamParams : NSObject

/**
 * The live stream URL where the stream will be sent (e.g., YouTube, Facebook Live).
 */
@property(nonatomic, copy, nullable) NSString* streamUrl;

/**
 * The live stream key for authentication with the streaming platform.
 */
@property(nonatomic, copy, nullable) NSString* key;

/**
 * The live stream broadcast URL where viewers can watch the stream.
 */
@property(nonatomic, copy, nullable) NSString* broadcastUrl;

/**
 * Live stream settings including layout and close caption options.
 */
@property(nonatomic, retain, nullable) ZoomVideoSDKLiveStreamSetting* setting;

@end


/**
 * @class ZoomVideoSDKLiveStreamHelper
 * @brief A class to operate the live stream.
 */
@interface ZoomVideoSDKLiveStreamHelper : NSObject

/**
 * @brief Call the function to start live stream.
 * @param streamingURL The live stream URL by which you can live the session.
 * @param key Stream key offered by the third platform on which you want to live stream your session.
 * @param broadcastURL The URL of live stream website.
 * @return Success means that the method is called successfully, otherwise not.
 * @warning Only session host can start live Stream successfully.
 * @deprecated This method is deprecated. Use startLiveStreamWithParams: instead.
 */
- (ZoomVideoSDKError)startLiveStreamWithStreamingURL:(NSString * _Nullable)streamingURL StreamingKey:(NSString * _Nullable)key BroadcastURL:(NSString * _Nullable)broadcastURL __deprecated_msg("Use startLiveStreamWithParams: instead");

/**
 * @brief Start a live stream of the current session using ZoomVideoSDKLiveStreamParams.
 * @param param The live stream parameters containing URL, key, broadcast URL and settings.
 * @return Success means that the method is called successfully, otherwise not.
 * @warning Only session host can start live Stream successfully.
 */
- (ZoomVideoSDKError)startLiveStreamWithParams:(ZoomVideoSDKLiveStreamParams * _Nullable)param;

/**
 * @brief Set to stop live streaming.
 * @return YES means stopping live streaming successfully, otherwise not.
 * @warning The function is available only for host.
 */
- (ZoomVideoSDKError)stopLiveStream;

/**
 * @brief Check to see if you can start live streaming.
 * @return The result of it.
 */
- (ZoomVideoSDKError)canStartLiveStream;

/**
 * @brief Get the current live stream settings for the current session.
 * @return The current live stream settings. Returns nil if no live stream is active.
 */
- (ZoomVideoSDKLiveStreamSetting * _Nullable)getCurrentLiveStreamSetting;

/**
 * @brief Update the live stream settings for the current session.
 * @param setting The new live stream settings to apply.
 * @return Success means that the method is called successfully, otherwise not.
 * @warning The function is available only for host.
 * @note If the same settings as the previous call are passed, this function will return Errors_Wrong_Usage.
 */
- (ZoomVideoSDKError)updateLiveStreamSetting:(ZoomVideoSDKLiveStreamSetting * _Nullable)setting;

/**
 * @brief Check if the current user can get or update live stream settings.
 * @return true if the user can get or update live stream settings, false otherwise.
 * @note Live stream must be started, and only the person who started the live stream can get or update the setting.
 */
- (BOOL)canGetOrUpdateLiveStreamSetting;

@end

/**
 * @class ZoomVideoSDKIncomingLiveStreamStatus
 * @brief Incoming live stream status.
 */
@interface ZoomVideoSDKIncomingLiveStreamStatus : NSObject
/**
 * @brief The incoming live stream ID.
 */
@property(nonatomic, copy) NSString* _Nullable streamKeyID;
/**
 * @brief Is the streaming software(such as OBS) connected to the Zoom platform?
 */
@property(nonatomic, assign) BOOL isRTMPConnected;
/**
 * @brief Has the video stream been pushed to the session?
 */
@property(nonatomic, assign) BOOL isStreamPushed;

@end

/**
 * @class ZoomVideoSDKIncomingLiveStreamHelper
 * @brief Incoming live stream helper interface.
 */
@interface ZoomVideoSDKIncomingLiveStreamHelper : NSObject

/**
 * @brief Bind incoming live stream with a stream key ID.
 * @param streamKeyID The stream key ID to bind.
 * @return If the function succeeds, it will return Errors_Success.
 * @warning Only host can bind incoming live stream.
 */
- (ZoomVideoSDKError)bindIncomingLiveStream:(NSString *_Nullable)streamKeyID;

/**
 * @brief Unbind the binded incoming live stream.
 * @param streamKeyID The stream key ID to bind.
 * @return If the function succeeds, it will return Errors_Success.
 * @warning Only host can unbind incoming live stream.
 */
- (ZoomVideoSDKError)unbindIncomingLiveStream:(NSString *_Nullable)streamKeyID;

/**
 * @brief Get the status of binded streams.
 * @note Will receive callback "-onIncomingLiveStreamStatusResponse:".
 * @return If the function succeeds, it will return Errors_Success.
 * @warning Only host can get incoming live stream status.
 */
- (ZoomVideoSDKError)getIncomingLiveStreamStatus;

/**
 * @brief Start the binded stream as a special participant.
 * @param streamKeyID The stream key ID to bind.
 * @return If the function succeeds, it will return Errors_Success.
 * @warning Only host can start incoming live stream.
 */
- (ZoomVideoSDKError)startIncomingLiveStream:(NSString *_Nullable)streamKeyID;

/**
 * @brief Stop the binded stream as a special participant.
 * @param streamKeyID The stream key ID to bind.
 * @return If the function succeeds, it will return Errors_Success.
 * @warning Only host can stop incoming live stream.
 */
- (ZoomVideoSDKError)stopIncomingLiveStream:(NSString *_Nullable)streamKeyID;

@end


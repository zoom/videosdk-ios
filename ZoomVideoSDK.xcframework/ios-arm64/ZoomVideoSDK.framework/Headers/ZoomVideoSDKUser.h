/**
 * @file ZoomVideoSDKUser.h
 * @brief Interface for user information and operations including user properties, audio/video status, statistics, and user interaction methods.
 */

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKRawDataPipe.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoCanvas.h>
#import <ZoomVideoSDK/ZoomVideoSDKRemoteCameraControlHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKShareHelper.h>

/**
 * @class ZoomVideoSDKVideoStatisticInfo
 * @brief Video statistic information.
 */
@interface ZoomVideoSDKVideoStatisticInfo : NSObject
/**
 * @brief frame width.
 */
@property (nonatomic, assign) NSInteger     width;
/**
 * @brief frame height.
 */
@property (nonatomic, assign) NSInteger     height;
/**
 * @brief frame per second.
 */
@property (nonatomic, assign) NSInteger     fps;
/**
 * @brief bits per second.
 */
@property (nonatomic, assign) NSInteger     bps;
/**
 * @brief Get video network status.
 */
@property (nonatomic, assign) ZoomVideoSDKNetworkStatus videoNetworkStatus;
@end

/**
 * @class ZoomVideoSDKShareStatisticInfo
 * @brief Share statistic information.
 */
@interface ZoomVideoSDKShareStatisticInfo : NSObject
/**
 * @brief frame width.
 */
@property (nonatomic, assign) NSInteger     width;
/**
 * @brief frame height.
 */
@property (nonatomic, assign) NSInteger     height;
/**
 * @brief frame per second.
 */
@property (nonatomic, assign) NSInteger     fps;
/**
 * @brief bits per second.
 */
@property (nonatomic, assign) NSInteger     bps;
/**
 * @brief Get share network status.
 */
@property (nonatomic, assign) ZoomVideoSDKNetworkStatus shareNetworkStatus;
@end

/**
 * @class ZoomVideoSDKAudioStatus
 * @brief Audio status of user.
 */
@interface ZoomVideoSDKAudioStatus : NSObject
/**
 * @brief Determine whether the audio is muted.
 */
@property (nonatomic, assign) BOOL          isMuted;
/**
 * @brief Determine whether the user is talking.
 */
@property (nonatomic, assign) BOOL          talking;
/**
 * @brief Get audio type: VOIP (Voice over IP), Telephony, or None.
 */
@property (nonatomic, assign) ZoomVideoSDKAudioType  audioType;

@end

/**
 * @class ZoomVideoSDKUser
 * @brief Zoom Video SDK user information.
 */
@interface ZoomVideoSDKUser : NSObject
/**
 * @brief Get the user's id.
 * @return The user's id.
 */
- (NSInteger)getUserID;
/**
 * @brief Get the name of the user in the session.
 * @return The user's name.
 */
- (NSString *_Nullable)getUserName;
/**
 * @brief Get the user's custom identity. Which pass in jwt token or in SDKSessionContext.customUserId.
 * @return The user's custom identity.
 */
- (NSString *_Nullable)getCustomUserId;
/**
 * @brief Get the user's reference.
 * @return The user's reference.
 */
- (NSString *_Nullable)getUserReference;
/**
 * @brief Determine whether the user is the host.
 * @return YES if the user is the host, otherwise NO.
 */
- (BOOL)isHost;
/**
 * @brief Determine whether the user is the manager.
 * @return YES if the user is the manager, otherwise NO.
 */
- (BOOL)isManager;
/**
 * @brief are user agreed with the individual record.
 * @return YES if the user agreed with the individual record, otherwise NO.
 */
- (BOOL)isIndividualRecordAgreed;
/**
 * @brief check if user be spotlighted.
 * @return YES if the user is spotlighted, otherwise NO.
 */
- (BOOL)isVideoSpotLighted;
/**
 * @brief Get the user's audio status.
 * @return The user's audio status.
 */
- (ZoomVideoSDKAudioStatus *_Nullable)audioStatus;
/**
 * @brief Get the user's video statistic information.
 * @return The user's video statistic information.
 */
- (ZoomVideoSDKVideoStatisticInfo *_Nullable)getVideoStatisticInfo;
/**
 * @brief Get the user's share statistic information.
 * @return The user's share statistic information.
 */
- (ZoomVideoSDKShareStatisticInfo *_Nullable)getShareStatisticInfo;
/**
 * @brief Get the user's video pipe.
 * @return The user's video pipe.
 */
- (ZoomVideoSDKRawDataPipe *_Nullable)getVideoPipe;
/**
 * @brief Get the user's multi-camera stream list.
 * @return a list of all streaming cameras pipe. For more information, see [ZoomVideoSDKRawDataPipe].
 */
- (NSArray <ZoomVideoSDKRawDataPipe *> *_Nullable)getMultiCameraStreamList;

/**
 * @brief Get the user's video canvas.
 * @return The user's video canvas.
 */
- (ZoomVideoSDKVideoCanvas *_Nullable)getVideoCanvas;
/**
 * @brief Get the user's multi-camera canvas list.
 * @return a list of all video canvas. For more information, see [ZoomVideoSDKVideoCanvas].
 */
- (NSArray <ZoomVideoSDKVideoCanvas *> *_Nullable)getMultiCameraCanvasList;

/**
 * @brief Get the helper class instance to access the remote camera control.
 * @return If the function succeeds, the return value is the remote camera control helper object. Otherwise returns null.
 */
- (ZoomVideoSDKRemoteCameraControlHelper *_Nullable)getRemoteCameraControlHelper;

/**
 * @brief Get the user's share-action list.
 * @return A list of all share information.
 */
- (NSArray <ZoomVideoSDKShareAction *>*_Nullable)getShareActionList;

/**
 * @brief Set the user's local volume. This does not affect how other participants hear the user.
 * @param volume value can be >= 0 and <=10. If volume is 0, the user won't be able to hear related audio.
 * @param isSharingAudio if true, sets the volume of shared audio, otherwise sets the volume of the microphone.
 * @return if success return YES, otherwise NO.
 * @deprecated Use \link setUserPlaybackVolume:isSharingAudio: \endlink instead.
 */
- (BOOL)setUserVolume:(float)volume isShareAudio:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -setUserPlaybackVolume:isSharingAudio: instead");

/**
 * @brief Get user volume.
 * @param volume Store the obtained value.
 * @param isSharingAudio if true, gets the volume of shared audio, otherwise gets the volume of the microphone.
 * @return if success return YES, otherwise NO.
 * @deprecated Use \link getUserPlaybackVolume:isSharingAudio: \endlink instead.
 */
- (BOOL)getUserVolume:(float * _Nullable)volume isShareAudio:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -getUserPlaybackVolume:isSharingAudio: instead");

/**
 * @brief Determine which audio you can set, shared audio or microphone.
 * @param isSharingAudio if true, checks whether you can set the volume of shared audio, otherwise you can set the volume of the microphone.
 * @return if success return YES, otherwise NO.
 * @deprecated Use \link canSetUserPlaybackVolume: \endlink instead.
 */
- (BOOL)canSetUserVolume:(BOOL)isSharingAudio DEPRECATED_MSG_ATTRIBUTE("Use -canSetUserPlaybackVolume: instead");

/**
 * @brief Sets the user's local volume. This does not affect how other participants hear the user.
 * @param volume Value can between 0 and 10. If 0, the user won't hear the related audio.
 * @param isSharingAudio YES Sets the volume of shared audio (such as shared computer audio);  otherwise sets the microphone volume.
 * @return YES  if the operation succeeds; otherwise, NO.
 */
- (BOOL)setUserPlaybackVolume:(float)volume isSharingAudio:(BOOL)isSharingAudio;

/**
 * @brief Gets the local user volume.
 * @param volume The user volume.
 * @param isSharingAudio YES to get the volume of shared audio (such as shared computer audio); otherwise gets the microphone volume.
 * @return YES if the operation succeeds; otherwise, NO.
 */
- (BOOL)getUserPlaybackVolume:(float * _Nullable)volume isSharingAudio:(BOOL)isSharingAudio;

/**
 * @brief Checks whether you can set the volume for shared audio or microphone.
 * @param isShareAudio YES to check if you can set the volume of shared audio; otherwise, you can set the volume of the microphone.
 * @return YES if you can set the volume of shared audio, otherwise, NO.
 */
- (BOOL)canSetUserPlaybackVolume:(BOOL)isShareAudio;

/**
 * @brief Gets the current audio level of a remote user.
 * @return The current audio level.
 */
- (unsigned int)getAudioLevel;

/**
 * @brief Send file to current user.
 * @param filePath The local path of the file.
 * @return If the function succeeds, the return value is Errors_Success.
 * @warning this interface will related with chat  privilege see @{ZoomVideoSDKChatPrivilegeType}.
 */
- (ZoomVideoSDKError)transferFile:(NSString * _Nullable)filePath;

/**
 * @brief Determine whether the user is an incoming live stream user.
 * @return YES indicates that the user is an incoming live stream, otherwise NO.
 */
- (BOOL)isIncomingLiveStreamUser;
/**
 * @brief Get the whiteboard share status of the user.
 * @return The whiteboard share status.
 */
- (ZoomVideoSDKWhiteboardStatus)getWhiteboardStatus;
/**
 * @brief Determine whether the user is in SubSession.
 * @return YES indicates that the user is an incoming live stream user, otherwise false.
 */
- (BOOL)isInSubSession;
/**
 * @brief Gets the network quality level of the specified data type for the user.
 * @param type The data type, such as audio, video, or share.
 * @return The current network status level for the specified data type.
 */
- (ZoomVideoSDKNetworkStatus)getNetworkLevel:(ZoomVideoSDKDataType)type;
/**
 * @brief Gets the overall network quality level of the user.
 * @return The overall network status level.
 */
- (ZoomVideoSDKNetworkStatus)getOverallNetworkLevel;
@end

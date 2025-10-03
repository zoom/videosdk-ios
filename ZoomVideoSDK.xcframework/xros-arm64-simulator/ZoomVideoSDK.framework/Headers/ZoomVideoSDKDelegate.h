/**
 * @file ZoomVideoSDKDelegate.h
 * @brief Protocol defining callback methods for session events, user events, audio/video events, sharing events, and other SDK notifications.
 */

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKConstants.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoRawData.h>
#import <ZoomVideoSDK/ZoomVideoSDKAudioRawData.h>
#import <ZoomVideoSDK/ZoomVideoSDKChatHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKPreProcessRawData.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoSender.h>
#import <ZoomVideoSDK/ZoomVideoSDKShareSender.h>
#import <ZoomVideoSDK/ZoomVideoSDKShareAudioSender.h>
#import <ZoomVideoSDK/ZoomVideoSDKAudioSender.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoCapability.h>
#import <ZoomVideoSDK/ZoomVideoSDKVideoHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKAudioHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKShareHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKRecordingHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKLiveStreamHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKUserHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKLiveTranscriptionHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKFileTranserHandle.h>
#import <ZoomVideoSDK/ZoomVideoSDKSubSessionHelper.h>
#import <ZoomVideoSDK/ZoomVideoSDKWhiteboardHelper.h>
#import <ReplayKit/ReplayKit.h>
@class ZoomVideoSDKRawDataPipe;
@class ZoomVideoSDKVideoCanvas;
@class ZoomVideoSDKUser;
@class ZoomVideoSDKProxySettingHandler;
@class ZoomVideoSDKSSLCertificateInfo;
@class ZoomVideoSDKSubSessionUserHelpRequestHandler;

/**
 * @protocol ZoomVideoSDKDelegate
 * @brief A listener class that groups together the callbacks related to a session.
 */
@protocol ZoomVideoSDKDelegate <NSObject>
@optional
/**
 * @brief Callback: Invoked when the current user joins the session.
 */
- (void)onSessionJoin;

/**
 * @brief Callback: Invoked when the current user leaves the session.
 * @deprecated Use onSessionLeave: instead.
 */
- (void)onSessionLeave DEPRECATED_MSG_ATTRIBUTE("use onSessionLeave: instead");

/**
 * @brief Invoked when the current user leaves the session with reason.
 * @param reason Leave session reason. See [ZoomVideoSDKSessionLeaveReason] for more information.
 */
- (void)onSessionLeave:(ZoomVideoSDKSessionLeaveReason)reason;

/**
 * @brief Callback: Invoked when errors occur.
 * @param ErrorType Provides error code associated with the error. See [ZoomVideoSDKError] for more information.
 * @param details The detail of error message.
 */
- (void)onError:(ZoomVideoSDKError)ErrorType detail:(NSInteger)details;

/**
 * @brief Callback: Invoked when a user joins the session.
 * @param helper User help utility.
 * @param userArray List of users who have just joined the session.
 */
- (void)onUserJoin:(ZoomVideoSDKUserHelper * _Nullable)helper users:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/**
 * @brief Callback: Invoked when a user leaves the session.
 * @param helper User helper utility.
 * @param userArray List of users who have just left the session.
 */
- (void)onUserLeave:(ZoomVideoSDKUserHelper * _Nullable)helper users:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/**
 * @brief Invoked when a user makes changes to their video, such as starting or stopping their video.
 * @param helper Video helper utility.
 * @param userArray List of users who have just left the session.
 */
- (void)onUserVideoStatusChanged:(ZoomVideoSDKVideoHelper * _Nullable)helper user:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/**
 * @brief Callback: Invoked when a user makes changes to their audio, such as muting or unmuting their audio.
 * @param helper Audio helper utility.
 * @param userArray List of users who have just left the session.
 */
- (void)onUserAudioStatusChanged:(ZoomVideoSDKAudioHelper * _Nullable)helper user:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/**
 * @brief Invoked when a user makes changes to their sharing status, such as starting screen sharing, starting view sharing, or stopping sharing.
 * @param helper The pointer to a share helper object.
 * @param user The pointer to a user object.
 * @param shareAction The pointer to the ZoomVideoSDKShareAction object.
 */
- (void)onUserShareStatusChanged:(ZoomVideoSDKShareHelper * _Nullable)helper user:(ZoomVideoSDKUser * _Nullable)user shareAction:(ZoomVideoSDKShareAction*_Nullable)shareAction;

/**
 * @brief Invoked when a user failed to start sharing.
 * @param helper The pointer to a share helper object.
 * @param user The pointer to a user object.
 */
- (void)onFailedToStartShare:(ZoomVideoSDKShareHelper* _Nonnull)helper user:(ZoomVideoSDKUser* _Nullable)user;
/**
 * @brief Notification of share setting changed.
 * @param setting The share setting.
 */
- (void)onShareSettingChanged:(ZoomVideoSDKShareSetting)setting;

/**
 * @brief Callback: Invoked when a user makes changes to their live stream status.
 * @param helper Live stream helper utility.
 * @param status Live stream status in enumeration. See [ZoomVideoSDKLiveStreamStatus].
 */
- (void)onLiveStreamStatusChanged:(ZoomVideoSDKLiveStreamHelper * _Nullable)helper status:(ZoomVideoSDKLiveStreamStatus)status;

/**
 * @brief The chat privilege of participant has changed.
 * @param helper Chat helper utility.
 * @param currentPrivilege The new chat privilege. See [ZoomVideoSDKChatPrivilegeType].
 */
- (void)onChatPrivilegeChanged:(ZoomVideoSDKChatHelper * _Nullable)helper privilege:(ZoomVideoSDKChatPrivilegeType)currentPrivilege;

/**
 * @brief Callback: Invoked when receiving a chat message.
 * @param helper Chat helper utility.
 * @param chatMessage the object which contains the message content. See [ZoomVideoSDKChatMessage].
 */
- (void)onChatNewMessageNotify:(ZoomVideoSDKChatHelper * _Nullable)helper message:(ZoomVideoSDKChatMessage * _Nullable)chatMessage;

/**
 * @brief Callback: Invoked when a user deletes a chat message.
 * @param helper Chat helper utility.
 * @param msgID The deleted message's ID.
 * @param type Indicates by whom the message was deleted, which is defined in [ZoomVideoSDKChatMsgDeleteBy].
 */
- (void)onChatMsgDeleteNotification:(ZoomVideoSDKChatHelper * _Nullable)helper messageID:(NSString * _Nonnull)msgID deleteBy:(ZoomVideoSDKChatMsgDeleteBy)type;

/**
 * @brief Callback: Invoked when the session host changes.
 * @param helper User helper utility.
 * @param user The host userInfo.
 */
- (void)onUserHostChanged:(ZoomVideoSDKUserHelper * _Nullable)helper users:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback: Invoked when the manager of the session changes.
 * @param user See [ZoomVideoSDKUser].
 */
- (void)onUserManagerChanged:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback: Invoked when a user changes their name.
 * @param user See [ZoomVideoSDKUser].
 */
- (void)onUserNameChanged:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback: Invoked when the active audio changes.
 * @param helper Audio helper utility.
 * @param userArray Active audio list.
 */
- (void)onUserActiveAudioChanged:(ZoomVideoSDKUserHelper * _Nullable)helper users:(NSArray <ZoomVideoSDKUser *>* _Nullable)userArray;

/**
 * @brief Callback: Invoked when the session requires a password to join.
 * @param completion the block for this callback.
 */
- (void)onSessionNeedPassword:(ZoomVideoSDKError (^ _Nullable)(NSString * _Nullable password, BOOL leaveSessionIgnorePassword))completion;

/**
 * @brief Callback: Invoked when the provided session password is wrong or invalid.
 * @param completion the block for this callback.
 */
- (void)onSessionPasswordWrong:(ZoomVideoSDKError (^ _Nullable)(NSString * _Nullable password, BOOL leaveSessionIgnorePassword))completion;

/**
 * @brief Callback: Invoked when mixed (all users) audio raw data received.
 * @param rawData Audio raw data. see [ZoomVideoSDKAudioRawData].
 */
- (void)onMixedAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

/**
 * @brief Callback: Invoked when individual user's audio raw data received.
 * @param rawData Raw audio data. see [ZoomVideoSDKAudioRawData].
 * @param user  See [ZoomVideoSDKUser].
 */
- (void)onOneWayAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData user:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback: Invoked when receiving shared raw audio data.
 * @param rawData rawData Raw audio data. See [ZoomVideoSDKAudioRawData].
 */
- (void)onSharedAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

/**
 * @brief Callback: Invoked when the invite by phone status changes to any other valid status such as Calling, Ringing, Success, or Failed.
 * @param status Invite by phone status. See [ZoomVideoSDKPhoneStatus].
 * @param failReason Invite by phone failed reason. See [ZoomVideoSDKPhoneFailedReason].
 */
- (void)onInviteByPhoneStatus:(ZoomVideoSDKPhoneStatus)status failReason:(ZoomVideoSDKPhoneFailedReason)failReason;

/**
 * @brief Callback: Invoked when the invite by phone user joined session success.
 * @param user success joined user,  See [ZoomVideoSDKUser].
 * @param phoneNumber phone number of callout.
 */
- (void)onCalloutJoinSuccess:(ZoomVideoSDKUser * _Nullable)user phoneNumber:(NSString * _Nullable)phoneNumber;

/**
 * @brief Callback: Invoked when the command channel is ready to be used. When the SDK attempts to establish a connection for the command channel when joining a session, this callback is triggered once the connection attempt for the command channel is completed.
 * @param success  YES,command channel is ready to be used. NO, Failure, command channel was unable to connect.
 */
- (void)onCmdChannelConnectResult:(BOOL)success;

/**
 * @brief Callback: Invoked when receiving a message, data, or a command from the command channel. Once the command channel is active, this callback is triggered each time a message is received.
 * @param commandContent Received command.
 * @param sendUser The user who sent the command.
 */
- (void)onCommandReceived:(NSString * _Nullable)commandContent sendUser:(ZoomVideoSDKUser * _Nullable)sendUser;

/**
 * @brief Callback for when the current user is granted camera control access.
 * @note Once the current user sends the camera control request, this callback will be triggered with the result of the request.
 * @param user The pointer to the user who received the request.
 * @param isApproved The result of the camera control request.
 */
- (void)onCameraControlRequestResult:(ZoomVideoSDKUser* _Nullable)user approved:(BOOL)isApproved;

/**
 * @brief Callback: Invoked when cloud recording status has started, paused, stopped, resumed, or otherwise changed.
 * @param status  Cloud recording status defined in [ZoomVideoSDKRecordingStatus].
 * @param handler  could handle the action user Accept or Decline;.
 */
- (void)onCloudRecordingStatus:(ZoomVideoSDKRecordingStatus)status recordAgreementHandler:(ZoomVideoSDKRecordAgreementHandler * _Nullable)handler;

/**
 * @brief Callback: user agreement status change.
 * @param user  the user which agree the record.
 */
- (void)onUserRecordAgreementNotification:(ZoomVideoSDKUser * _Nullable)user;
/**
 * @brief Callback: Invoked when a host requests you to unmute yourself.
 */
- (void)onHostAskUnmute;

/**
 * @brief Callback: Invoked when someone in a given session enables or disables multi-camera. All participants in the session receive this callback.
 * @param status  Status for multipul camera user join or left. See [ZoomVideoSDKMultiCameraStreamStatus].
 * @param user The user who enabled multi-camera. See [ZoomVideoSDKUser].
 * @param videoPipe the data pipe for the multi-camera. See [ZoomVideoSDKRawDataPipe].
 */
- (void)onMultiCameraStreamStatusChanged:(ZoomVideoSDKMultiCameraStreamStatus)status parentUser:(ZoomVideoSDKUser *_Nullable)user videoPipe:(ZoomVideoSDKRawDataPipe *_Nullable)videoPipe;

/**
 * @brief Callback: Invoked when someone enables/disables multi-camera. This callback is received by all participants.
 * @param status  Status for multipul camera user join or left. See [ZoomVideoSDKMultiCameraStreamStatus].
 * @param user The user who enabled multi-camera. See [ZoomVideoSDKUser].
 * @param videoCanvas the video canvas for the multi-camera. See [ZoomVideoSDKVideoCanvas].
 */
- (void)onMultiCameraStreamStatusChanged:(ZoomVideoSDKMultiCameraStreamStatus)status parentUser:(ZoomVideoSDKUser *_Nullable)user videoCanvas:(ZoomVideoSDKVideoCanvas *_Nullable)videoCanvas;

/**
 * @brief Callback: Notify the mic status when testing.
 * @param status The mic status. For more details, See [ZoomVideoSDKTestMicStatus].
 */
- (void)onTestMicStatusChanged:(ZoomVideoSDKTestMicStatus)status;

/**
 * @brief Callback: Notify the current mic or speaker volume when testing.
 * @param micVolume Specify the volume of the mic when testing or in session.
 * @param speakerVolume Specify the volume of the speaker when testing.
 */
- (void)onMicSpeakerVolumeChanged:(int)micVolume speakerVolume:(int)speakerVolume;

/**
 * @brief Called when the audio level change of participants changes.
 * @param level The current audio level of the user, in the range [0, 9].
 * @param bAudioSharing YES if the audio level is from shared audio, such as computer audio; otherwise it's from the microphone.
 * @param user The user whose audio level has changed.
 */
- (void)onAudioLevelChanged:(NSUInteger)level audioSharing:(BOOL)bAudioSharing user:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback: Invoked when the SDK requires system permissions to continue functioning.
 * @param permissionType The type of system permission that is required. See [ZoomVideoSDKSystemPermissionType].
 */
- (void)onSystemPermissionRequired:(ZoomVideoSDKSystemPermissionType)permissionType;

/**
 * @brief Callback: Invoked when live transcription status changes.
 * @param status The live transcription status. See [ZoomVideoSDKLiveTranscriptionStatus].
 */
- (void)onLiveTranscriptionStatus:(ZoomVideoSDKLiveTranscriptionStatus)status;

/**
 * @brief Callback: when a live transcription message is received.
 * @param messageInfo The live transcription message.
 */
- (void)onLiveTranscriptionMsgReceived:(ZoomVideoSDKLiveTranscriptionMessageInfo *_Nullable)messageInfo;

/**
 * @brief Callback: Original language message received callback.
 * @param messageInfo messageInfo The spoken language message.
 */
- (void)onOriginalLanguageMsgReceived:(ZoomVideoSDKLiveTranscriptionMessageInfo *_Nullable)messageInfo;

/**
 * @brief Callback: Invoked when a live translation error occurs.
 * @param spokenLanguage The spoken message language.
 * @param transcriptLanguage The message language you want to translate.
 */
- (void)onLiveTranscriptionMsgError:(ZoomVideoSDKLiveTranscriptionLanguage *_Nullable)spokenLanguage transLanguage:(ZoomVideoSDKLiveTranscriptionLanguage *_Nullable)transcriptLanguage;

/**
 * @brief Callback when the spoken language has changed.
 * @param spokenLanguage The spoken message language..
 */
- (void)onSpokenLanguageChanged:(ZoomVideoSDKLiveTranscriptionLanguage* _Nullable)spokenLanguage;

/**
 * @brief The callback will be triggered if the proxy requests to input the username and password.Use the handler to configure the related information.
 * @param handler The handler will be destroyed once the function calls end.
 */
- (void)onProxySettingNotification:(ZoomVideoSDKProxySettingHandler *_Nonnull)handler;

/**
 * @brief The callback will be triggered when the SSL is verified.Use the handler to check the related information.
 * @param handler The handler will be destroyed once the function calls end.
 */
- (void)onSSLCertVerifiedFailNotification:(ZoomVideoSDKSSLCertificateInfo *_Nonnull)handler;


/**
 * @brief Called when a user's network status changes (Lite SDK only).
 * @param status The user's network status.
 * @param user The pointer to the user who speaks the message.
 * @deprecated use \link onUserNetworkStatusChanged:level:user: \endlink instead.
 */
- (void)onUserVideoNetworkStatusChanged:(ZoomVideoSDKNetworkStatus)status user:(ZoomVideoSDKUser *_Nullable)user DEPRECATED_MSG_ATTRIBUTE("Use -onUserNetworkStatusChanged:level:user: instead");

/**
 * @brief Notification of the current user's share network quality changes.
 * @param shareNetworkStatus share network quality.
 * @param isSendingShare Indicates the direction of the share. If YES, it refers to the sending share; if NO, it refers to the receiving share.
 * @deprecated use \link onUserNetworkStatusChanged:level:user: \endlink instead.
 */
- (void)onUserShareNetworkStatusChanged:(ZoomVideoSDKNetworkStatus)shareNetworkStatus isSending:(BOOL)isSendingShare DEPRECATED_MSG_ATTRIBUTE("Use -onUserNetworkStatusChanged:level:user: instead");

/**
 * @brief Called when the user's share network quality changes.
 * @param type The data type whose network status changed.
 * @param level The new network quality level for the specified data type.
 * @param user The user whose network status has changed.
 */
- (void)onUserNetworkStatusChanged:(ZoomVideoSDKDataType)type level:(ZoomVideoSDKNetworkStatus)level user:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback event when a user's overall network status changes.
 * @param level The new overall network quality level.
 * @param user The user whose overall network status has changed.
 */
- (void)onUserOverallNetworkStatusChanged:(ZoomVideoSDKNetworkStatus)level user:(ZoomVideoSDKUser * _Nullable)user;


/**
 * @brief Callback event of the call CRC device's status.
 * @param state The call out status.
 */
- (void)onCallCRCDeviceStatusChanged:(ZoomVideoSDKCRCCallStatus)state;

/**
 * @brief Callback for the annotation helper clean up. After this callback, SDK will release the ZoomVideoSDKAnnotationHelper as well.
 * @param helper The helper clean up object.
 */
- (void)onAnnotationHelperCleanUp:(ZoomVideoSDKAnnotationHelper *_Nullable)helper;

/**
 * @brief Callback for the annotation privilege change.
 * @param enable YES means the user is able to annotate, NO means the user is not able to annotate.
 * @param user The user who changed viewer's annotation privilege.
 * @deprecated use -[ZoomVideoSDKDelegate onAnnotationPrivilegeChangeWithUser:shareAction:] instead.
 */
- (void)onAnnotationPrivilegeChange:(BOOL)enable shareOwner:(ZoomVideoSDKUser *_Nullable)user DEPRECATED_MSG_ATTRIBUTE("use -[ZoomVideoSDKDelegate onAnnotationPrivilegeChangeWithUser:shareAction:] instead");

/**
 * @brief Callback for the annotation privilege change.
 * @param user The pointer to a user object who changed viewer's annotation privilege.
 * @param shareAction The pointer to a share object.
 */
- (void)onAnnotationPrivilegeChangeWithUser:(ZoomVideoSDKUser *_Nullable)user shareAction:(ZoomVideoSDKShareAction*_Nullable)shareAction;

/**
 * @brief Callback: Invoked when a user makes changes to their share content type, such as switching camera share to normal share. Find the share type in \link ZoomVideoSDKShareType \endlink.
 * @param shareHelper share helper util.
 * @param user current start or stop share userInfo.
 * @param shareAction The pointer to a share object.
 */
- (void)onShareContentChanged:(ZoomVideoSDKShareHelper *_Nullable)shareHelper user:(ZoomVideoSDKUser *_Nullable)user shareAction:(ZoomVideoSDKShareAction *_Nullable)shareAction;

/**
 * Called when the size of a user's share capture changes.
 *
 * @param shareHelper  The share helper object associated with the share.
 * @param user The user whose share capture size has changed.
 * @param shareAction  The share action details, such as start, stop, or resize.
 */
- (void)onShareCaptureSizeChanged:(ZoomVideoSDKShareHelper *_Nullable)shareHelper user:(ZoomVideoSDKUser *_Nullable)user shareAction:(ZoomVideoSDKShareAction *_Nullable)shareAction;

/**
 * @brief Callback event for the subscribed user's video fail reason.
 * @param failReason The fail reason.
 * @param user The pointer to the user whose view we would like to subscribe.
 * @param view The view that failed to subscribe.
 */
- (void)onVideoCanvasSubscribeFail:(ZoomVideoSDKSubscribeFailReason)failReason user:(ZoomVideoSDKUser *_Nullable)user view:(UIView *_Nullable)view;

/**
 * @brief Callback event for the subscribed user's share fail reason.
 * @param failReason The fail reason.
 * @param user The pointer to the user whose view we would like to subscribe.
 * @param view The view that failed to subscribe.
 * @deprecated use -[ZoomVideoSDKDelegate onShareCanvasSubscribeFailWithUser:view:shareAction:] instead.
 */
- (void)onShareCanvasSubscribeFail:(ZoomVideoSDKSubscribeFailReason)failReason user:(ZoomVideoSDKUser *_Nullable)user view:(UIView *_Nullable)view DEPRECATED_MSG_ATTRIBUTE("use -[ZoomVideoSDKDelegate onShareCanvasSubscribeFailWithUser:view:shareAction:] instead");

/**
 * @brief Callback event for the share canvas that failed to subscribe.
 * @param user The pointer to the user object whose view we would like to subscribe to.
 * @param view The view that failed to subscribe.
 * @param shareAction The pointer to a share object.
 */
- (void)onShareCanvasSubscribeFailWithUser:(ZoomVideoSDKUser *_Nullable)user view:(UIView *_Nullable)view shareAction:(ZoomVideoSDKShareAction*_Nullable)shareAction;

/**
 * @brief Invoked when send file status make change.
 * @param file The class to sendfile object.
 * @param status The stauts of file transfer.
 */
- (void)onSendFileStatus:(ZoomVideoSDKSendFile * _Nullable)file status:(ZoomVideoSDKFileTransferStatus)status;

/**
 * @brief Invoked when send file status make change.
 * @param file The class to receive file object.
 * @param status The stauts of file transfer.
 */
- (void)onReceiveFileStatus:(ZoomVideoSDKReceiveFile * _Nullable)file status:(ZoomVideoSDKFileTransferStatus)status;

/**
 * @brief Callback event of video alpha channel mode changes.
 * @param isAlphaChannelOn True means that alpha channel mode is on, otherwise off.
 */
- (void)onVideoAlphaChannelStatusChanged:(BOOL)isAlphaChannelOn;

/**
 * @brief Callback event of spotlighted video user changes.
 * @param videoHelper The pointer of video helper object.
 * @param userList List of users who has been spotlighted.
 */
- (void)onSpotlightVideoChanged:(ZoomVideoSDKVideoHelper * _Nullable)videoHelper userList:(NSArray <ZoomVideoSDKUser *>* _Nullable)userList;

/**
 * @brief Callback event of binds the incoming live stream.
 * @param helper Incoming live stream helper utility.
 * @param success YES is success, otherwise NO.
 * @param streamKeyID Corresponding stream key ID.
 */
- (void)onBindIncomingLiveStreamResponse:(ZoomVideoSDKIncomingLiveStreamHelper * _Nullable)helper success:(BOOL)success streamKeyID:(NSString *_Nullable)streamKeyID;

/**
 * @brief Callback event of unbinds the incoming live stream.
 * @param helper Incoming live stream helper utility.
 * @param success YES is success, otherwise NO.
 * @param streamKeyID Corresponding stream key ID.
 */
- (void)onUnbindIncomingLiveStreamResponse:(ZoomVideoSDKIncomingLiveStreamHelper * _Nullable)helper success:(BOOL)success streamKeyID:(NSString *_Nullable)streamKeyID;

/**
 * @brief Callback event of gets the streams status.
 * @param helper Incoming live stream helper utility.
 * @param success YES is success, otherwise NO.
 * @param streamsStatusList The streams status list.
 */
- (void)onIncomingLiveStreamStatusResponse:(ZoomVideoSDKIncomingLiveStreamHelper * _Nullable)helper success:(BOOL)success streamsStatusList:(NSArray<ZoomVideoSDKIncomingLiveStreamStatus *> *_Nullable)streamsStatusList;

/**
 * @brief Callback event of starts the binded stream.
 * @param helper Incoming live stream helper utility.
 * @param success YES is success, otherwise NO.
 * @param streamKeyID Corresponding stream key ID.
 */
- (void)onStartIncomingLiveStreamResponse:(ZoomVideoSDKIncomingLiveStreamHelper * _Nullable)helper success:(BOOL)success streamKeyID:(NSString *_Nullable)streamKeyID;

/**
 * @brief Callback event of stops the binded stream.
 * @param helper Incoming live stream helper utility.
 * @param success YES is success, otherwise NO.
 * @param streamKeyID Corresponding stream key ID.
 */
- (void)onStopIncomingLiveStreamResponse:(ZoomVideoSDKIncomingLiveStreamHelper * _Nullable)helper success:(BOOL)success streamKeyID:(NSString *_Nullable)streamKeyID;

/**
 * @brief Invoked when the share content size has changed.
 * @param helper The pointer to a share helper object.
 * @param user The pointer to a user object who's share content size has changed.
 * @param shareAction The pointer to the ZoomVideoSDKShareAction object.
 * @note A share content size change may occur in two cases: 
 *       when the first frame of shared content is received (from no content to having a size), 
 *       or when the content size actually changes during sharing.
 */
- (void)onShareContentSizeChanged:(ZoomVideoSDKShareHelper * _Nullable)helper user:(ZoomVideoSDKUser * _Nullable)user shareAction:(ZoomVideoSDKShareAction*_Nullable)shareAction;

#pragma mark - external camera change -
/**
 * @brief Callback is invoked when  the external UVC camera status changes.
 * @param status UVC camera status.
 * @warning Only iOS 17.0 or above and iPad device can receive this callback.
 */
- (void)onUVCCameraStatusChange:(ZoomVideoSDKUVCCameraStatus)status;

#pragma mark - sub-sessiion -
/**
 * @brief Callback event that the SubSession status changed.
 * @param status The SubSession status.
 * @param pSubSessionKitList The new SubSession list.
 */
- (void)onSubSessionStatusChanged:(ZoomVideoSDKSubSessionStatus)status subSession:(NSArray <ZoomVideoSDKSubSessionKit*>* _Nonnull)pSubSessionKitList;

/**
 * @brief Callback event that the user has SubSession manager privilege.
 * @param pManager The SubSession manager object.
 */
- (void)onSubSessionManagerHandle:(ZoomVideoSDKSubSessionManager* _Nullable)pManager;

/**
 * @brief Callback event that the user has SubSession attendee privilege.
 * @param pParticipant The SubSession attendee object.
 */
- (void)onSubSessionParticipantHandle:(ZoomVideoSDKSubSessionParticipant* _Nullable)pParticipant;

/**
 * @brief Callback event that the users of a SubSession has updated.
 * @param pSubSessionKit The SubSession kit object.
 */
- (void)onSubSessionUsersUpdate:(ZoomVideoSDKSubSessionKit* _Nonnull)pSubSessionKit;

/**
 * @brief Callback event that the user receives the main session broadcast message.
 * @param sMessage The message content.
 * @param sUserName The name of the user who broadcast this message.
 */
- (void)onBroadcastMessageFromMainSession:(NSString* _Nonnull) sMessage userName:(NSString* _Nonnull)sUserName;

/**
 * @brief Callback event that the user receives the help request from SubSession.
 * @param pHandler The request handler object.
 */
- (void)onSubSessionUserHelpRequestHandler:(ZoomVideoSDKSubSessionUserHelpRequestHandler*_Nonnull) pHandler;
/**
 * @brief Callback event that the result of help request.
 * @param result The result of help reques.
 */
- (void)onSubSessionUserHelpRequestResult:(ZoomVideoSDKUserHelpRequestResult)result;

#pragma mark - ZoomVideoSDK audio source change -
/**
 * @brief Callback invoked when the current user's audio source changes.
 * @param device The updated audio device. See{@link ZoomVideoSDKAudioDevice}.
 */
- (void)onMyAudioSourceTypeChanged:(ZoomVideoSDKAudioDevice *_Nullable)device;

#pragma mark - In app screen share -
/**
 * @brief Called when in-app screen sharing session encounters an error or success.
 * @param code Error code in {@link RPRecordingErrorCode}.
 */
- (void)onInAppScreenShareErrorCode:(RPRecordingErrorCode)code;

/**
 * @brief Called when the availablity of in-app screen sharing changes. Use this callback to enable or disable screen sharing controls in your UI based on current availability.
 * @param available Available or not {@link RPScreenRecorder}.
 */
- (void)onInAppScreenShareAvailableChanged:(BOOL)available;

/**
 * @brief Notificates of the response of broadcast streaming.
 * @param isSuccess YES if broadcast streaming started successfully, otherwise false.
 * @param channelID The backend service to identify the broadcast streaming channel ID returned by the backend.
*/
- (void)onStartBroadcastResponse:(BOOL)isSuccess channelID:(NSString* _Nonnull)channelID ;

/**
 * @brief Notificates of the response of broadcast streaming.
 * @param isSuccess YES if broadcast stopped successfully, otherwise false.
*/
- (void)onStopBroadcastResponse:(BOOL)isSuccess;

/**
 * @brief Notificates of the response that gets broadcast status.
 * @param isSuccess YES if the request succeeded, otherwise false.
 * @param status The current broadcast status, See \link ZoomVideoSDKBroadcastControlStatus \endlink.
*/
- (void)onGetBroadcastControlStatus:(BOOL)isSuccess status:(ZoomVideoSDKBroadcastControlStatus)status;

/**
 * @brief Notificates when the viewer's joins status changes.
 * @param status The current join status, See \link ZoomVideoSDKStreamingJoinStatus \endlink.
*/
- (void)onStreamingJoinStatusChanged:(ZoomVideoSDKStreamingJoinStatus)status ;

/**
@brief Callback invoked when a whiteboard file export completes.
@param format The export format. See \link ZoomVideoSDKWhiteboardExportFormatType \endlink.
@param data The export whiteboard data as NSData.
 */
- (void)onWhiteboardExported:(ZoomVideoSDKWhiteboardExportFormatType)format data:(NSData*_Nonnull)data  API_UNAVAILABLE(visionos);

/**
@brief Callback invoked when a user changes their whiteboard sharing status, such as starting or stopping whiteboard sharing.
@param user The user who's whiteboard sharing status changed. Check the current status via \link ZoomVideoSDKUser \endlink.
@param whiteboardHelper The whiteboard helper object.
 */
-(void)onUserWhiteboardShareStatusChanged:(ZoomVideoSDKUser *_Nonnull)user whiteboardhelper:(ZoomVideoSDKWhiteboardHelper*_Nonnull)whiteboardHelper  API_UNAVAILABLE(visionos);

@end

#pragma mark - ZoomVideoSDKVirtualAudioSpeaker
/**
 * @protocol ZoomVideoSDKVirtualAudioSpeaker
 * @brief An interface that handles the virtual audio speaker.
 */
@protocol ZoomVideoSDKVirtualAudioSpeaker <NSObject>

@optional

/**
 * @brief Callback event for receiving the mixed audio raw data from the virtual speaker.
 * @param rawData Audio's raw data.
 */
- (void)onVirtualSpeakerMixedAudioReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

/**
 * @brief Callback event for receiving the one way audio raw data of a selected user from the virtual speaker.
 * @param rawData Audio's raw data.
 */
- (void)onVirtualSpeakerOneWayAudioReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData user:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Callback event for receiving the share audio raw data such as buffer, sampleRate, etc.
 * @param rawData Audio's raw data.
 */
- (void)onVirtualSpeakerSharedAudioReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;

@end

#pragma mark - ZoomVideoSDKRawDataPipeDelegate
/**
 * @protocol ZoomVideoSDKRawDataPipeDelegate
 * @brief Methods to manage events for receiving video raw data.
 */
@protocol ZoomVideoSDKRawDataPipeDelegate <NSObject>

@optional

/**
 * @brief This method is used to receive video's NV12 data(CVPixelBufferRef).
 * @param pixelBuffer Video's CVPixelBufferRef data.
 */
- (void)onPixelBuffer:(CVPixelBufferRef _Nullable )pixelBuffer
             rotation:(ZoomVideoSDKVideoRawDataRotation)rotation;

/**
 * @brief This method is used to receive video's YUV420 data.
 * @param rawData Video's YUV420 data.
 */
- (void)onRawDataFrameReceived:(ZoomVideoSDKVideoRawData * _Nullable)rawData;

/**
 * @brief Callback event when the sender stop/start to sending raw data.
 * @param userRawdataStatus Raw data is sending or not.
 */
- (void)onRawDataStatusChanged:(ZoomVideoSDKUserRawdataStatus)userRawdataStatus;

@end

#pragma mark - ZoomVideoSDKVideoSourcePreProcessor
/**
 * @protocol ZoomVideoSDKVideoSourcePreProcessor
 * @brief Methods to modify default device capture raw data.
 */
@protocol ZoomVideoSDKVideoSourcePreProcessor <NSObject>

@optional
/**
 * @brief Callback on device capture video frame.
 * @param rawData It is a pointer of YUV process data I420 object.
 */
- (void)onPreProcessRawData:(ZoomVideoSDKPreProcessRawData * _Nullable)rawData;

@end

#pragma mark - ZoomVideoSDKVideoSource
/**
 * @protocol ZoomVideoSDKVideoSource
 * @brief Custom external video source interface.
 */
@protocol ZoomVideoSDKVideoSource <NSObject>

@optional

/**
 * @brief Callback for video source prepare.
 * @param rawDataSender The pointer of video sender object.
 * @param supportCapabilityArray The list of supported video capability.
 * @param suggestCapability Suggest video capability.
 */
- (void)onInitialize:(ZoomVideoSDKVideoSender *_Nonnull)rawDataSender
supportCapabilityArray:(NSArray *_Nonnull)supportCapabilityArray
   suggestCapability:(ZoomVideoSDKVideoCapability *_Nonnull)suggestCapability;

/**
 * @brief Callback for video size or fps changed.
 * @param supportCapabilityArray The list of supported video capability.
 * @param suggestCapability Suggest video capability.
 */
- (void)onPropertyChange:(NSArray *_Nonnull)supportCapabilityArray
       suggestCapability:(ZoomVideoSDKVideoCapability *_Nonnull)suggestCapability;

/**
 * @brief Callback for video source should start send raw data.
 */
- (void)onStartSend;

/**
 * @brief Callback for video source should stop send raw data. eg.user mute video.
 */
- (void)onStopSend;

/**
 * @brief Callback for video source uninitialized. eg.leave session.
 */
- (void)onUninitialized;

@end

/**
 * @protocol ZoomVideoSDKVirtualAudioMic
 * @brief An interface that handles a virtual audio microphone.
 */
@protocol ZoomVideoSDKVirtualAudioMic <NSObject>

@optional
/**
 * @brief Callback for virtual audio microphone initialization.
 * @param rawDataSender you can send audio data based on this object.
 */
- (void)onMicInitialize:(ZoomVideoSDKAudioSender *_Nonnull)rawDataSender;

/**
 * @brief Callback for microphone to start sending raw data. For example, this could be sent if the user unmuted audio.
 */
- (void)onMicStartSend;

/**
 * @brief Callback for microphone to stop sending raw data. For example, this could be sent if the user muted audio.
 */
- (void)onMicStopSend;

/**
 * @brief Callback sent when the microphone is uninitialized. For example, if the user left the session.
 */
- (void)onMicUninitialized;

@end

#pragma mark - ZoomVideoSDKShareSource
/**
 * @protocol ZoomVideoSDKShareSource
 * @brief Custom external share source interface.
 */
@protocol ZoomVideoSDKShareSource <NSObject>

@optional
/**
 * @brief Callback for share source can start send raw data.
 * @param rawDataSender The sender object.
 */
- (void)onShareSendStarted:(ZoomVideoSDKShareSender *_Nullable)rawDataSender;

/**
 * @brief Callback for share source stop send raw data.
 */
- (void)onShareSendStopped;

@end

#pragma mark - ZoomVideoSDKShareAudioSource
/**
 * @protocol ZoomVideoSDKShareAudioSource
 * @brief Custom external share source interface.
 */
@protocol ZoomVideoSDKShareAudioSource <NSObject>

@optional
/**
 * @brief Callback for audio source to start sending raw data.
 * @param sender The object of MobileRTCShareSender to send share source.
 */
- (void)onStartSendAudio:(ZoomVideoSDKShareAudioSender *_Nonnull)sender;

/**
 * @brief Callback for audio source to stop sending raw data.
 */
- (void)onStopSendAudio;

@end

#pragma mark - ZoomVideoSDKSharePreprocessor
/**
 * @protocol ZoomVideoSDKSharePreprocessor
 * @brief the share pre-processor.
 */
@protocol ZoomVideoSDKSharePreprocessor <NSObject>

@optional
/**
 * @brief You will receive this callback when calling 'startShareWithPreprocessing' successfully.
 * @param rawData You can get the YUV data address through this object and then pre-process the data.
 * @param sender Use this object to send the processed data out.
 */
- (void)onCapturedRawDataReceived:(ZoomVideoSDKVideoRawData *_Nullable)rawData sharePreprocessSender:(ZoomVideoSDKSharePreprocessSender *_Nullable)sender;

/**
 * @brief You will receive this callback when call 'stopShare' successfully. In this event notification, you can perform some stop and destroy actions if necessary.
 */
- (void)onShareStopped;

@end



@protocol ZoomVideoSDKBroadcastStreamingVideoDelegate <NSObject>
@optional
/**
 * @brief Call when subscribed video data received.
 * @param rawData Video's YUV420 data.
 */
- (void)onVideoFrameRecieved:(ZoomVideoSDKVideoRawData * _Nullable)rawData;
/**
 * @brief  Call when subscribed video data received.
 * @param pixelBuffer Video's CVPixelBufferRef data.
 */
- (void)onPixelBuffer:(CVPixelBufferRef _Nullable )pixelBuffer  rotation:(ZoomVideoSDKVideoRawDataRotation)rotation;
@end

@protocol ZoomVideoSDKBroadcastStreamingAudioDelegate <NSObject>
@optional
/**
 * @brief Call when subscribed audio data received.
 * @param rawData Audio data object.
 */
- (void)onAudioRawDataReceived:(ZoomVideoSDKAudioRawData * _Nullable)rawData;
@end

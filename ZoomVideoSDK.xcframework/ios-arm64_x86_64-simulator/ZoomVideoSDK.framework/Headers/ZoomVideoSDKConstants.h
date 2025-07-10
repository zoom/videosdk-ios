//
//  ZoomVideoSDKConstants.h
//  ZoomVideoSDK
//
#ifndef ZoomVideoSDKConstants_h
#define ZoomVideoSDKConstants_h

/**
 * @brief Enumerates all  errors in the VideoSDK.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKError)
{
    /** <Success. */
    Errors_Success = 0,
    /** Wrong usage. */
    Errors_Wrong_Usage,
    /** Internal error. */
    Errors_Internal_Error,
    /** SDK is not initialized. */
    Errors_Uninitialize,
    /** Memory allocation error. */
    Errors_Memory_Error,
    /** Failed to load module. */
    Errors_Load_Module_Error,
    /** Failed to unload module. */
    Errors_UnLoad_Module_Error,
    /** One or more parameters are invalid. */
    Errors_Invalid_Parameter,
    /** API called too frequently. */
    Errors_Call_Too_Frequently,
    /** Function not implemented. */
    Errors_No_Impl,
    /** Feature not supported. */
    Errors_Dont_Support_Feature,
    /** Unknown error. */
    Errors_Unknown,
    /** Failed to remove folder. */
    Errors_Remove_Folder_Fail,

    /** Authorization related errors. */
    Errors_Auth_Base = 1000,
    /** Authorization failure. */
    Errors_Auth_Error,
    /** App key or secret is empty. */
    Errors_Auth_Empty_Key_or_Secret,
    /** App key or secret is incorrect. */
    Errors_Auth_Wrong_Key_or_Secret,
    /** Not support SDK. */
    Errors_Auth_DoesNot_Support_SDK,
    /** SDK is disabled. */
    Errors_Auth_Disable_SDK,

    /** Join session errors. */
    /** Session name is missing. */
    Errors_JoinSession_NoSessionName = 1500,
    /** Session token is missing. */
    Errors_JoinSession_NoSessionToken,
    /** Username is missing. */
    Errors_JoinSession_NoUserName,
    /** Session name is invalid. */
    Errors_JoinSession_Invalid_SessionName,
    /** Password is incorrect. */
    Errors_JoinSession_Invalid_Password,
    /** Session token is invalid. */
    Errors_JoinSession_Invalid_SessionToken,
    /** Session name is too long.*/
    Errors_JoinSession_SessionName_TooLong,
    /** Token does not match session name. */
    Errors_JoinSession_Token_MismatchedSessionName,
    /** Token does not contain a session name. */
    Errors_JoinSession_Token_NoSessionName,
    /** Role type in token is empty or incorrect. */
    Errors_JoinSession_Token_RoleType_EmptyOrWrong,
    /** User identity in token is too long. */
    Errors_JoinSession_Token_UserIdentity_TooLong,

    /** Session-related errors. */
    Errors_Session_Base = 2000,
    /** Session module not found. */
    Errors_Session_Module_Not_Found,
    /** Invalid session service. */
    Errors_Session_Service_Invalid,
    /** Failed to join session. */
    Errors_Session_Join_Failed,
    /** No permission to join session. */
    Errors_Session_No_Rights,
    /** Already in progress. */
    Errors_Session_Already_In_Progress,
    /** Unsupported session type. */
    Errors_Session_Dont_Support_SessionType,
    /** You have no share. */
    Errors_Session_You_Have_No_Share,
    /** Session is reconnecting. */
    Errors_Session_Reconnecting,
    /** Session is disconnecting. */
    Errors_Session_Disconnecting,
    /** Session has not started. */
    Errors_Session_Not_Started = 2010,
    /** Password is required to join. */
    Errors_Session_Need_Password,
    /** Incorrect session password. */
    Errors_Session_Password_Wrong,
    /** Remote database error. */
    Errors_Session_Remote_DB_Error,
    /** Invalid parameter. */
    Errors_Session_Invalid_Param,
    /** Client version is incompatible. */
    Errors_Session_Client_Incompatible,
    /** Free minutes exceeded. */
    Errors_Session_Account_FreeMinutesExceeded,

    /** Audio errors. */
    /** General audio error. */
    Errors_Session_Audio_Error = 3000,
    /** No microphone detected. */
    Errors_Session_Audio_No_Microphone,
    /** No speaker detected. */
    Errors_Session_Audio_No_Speaker,

    /** Video errors. */
    /** General video error. */
    Errors_Session_Video_Error = 4000,
    /** Video device error. */
    Errors_Session_Video_Device_Error,


    /** Live stream error. */
    Errors_Session_Live_Stream_Error = 5000,

    /** Phone error. */
    Errors_Session_Phone_Error = 5500,
    /** Multi-stream video not supported for user. */
    Errors_Dont_Support_Multi_Stream_Video_User,
    /** Failed to assign user privilege. */
    Errors_Fail_Assign_User_Privilege,
    /** No recording in progress. */
    Errors_No_Recording_In_Process,
    /** Failed to set virtual background. */
    Errors_Set_Virtual_Background_Fail,

    /** Raw data errors. */
    /** Memory allocation for raw data failed. */
    Errors_Malloc_Failed = 6001,
    /** Not in session. */
    Errors_Not_In_Session,
    /** No raw data license. */
    Errors_No_License,
    /** Video module not ready. */
    Errors_Video_Module_Not_Ready,
    /** Video module error. */
    Errors_Video_Module_Error,
    /** Video device error. */
    Errors_Video_device_error,
    /** No video data available. */
    Errors_No_Video_Data,
    /** Share module not ready. */
    Errors_Share_Module_Not_Ready,
    /** Share module error. */
    Errors_Share_Module_Error,
    /** No shared data available. */
    Errors_No_Share_Data,
    /** Audio module not ready. */
    Errors_Audio_Module_Not_Ready,
    /** Audio module error. */
    Errors_Audio_Module_Error,
    /** No audio data available. */
    Errors_No_Audio_Data,
    /** Raw data pre-processing failed. */
    Errors_Preprocess_Rawdata_Error,
    /** No device is running. */
    Errors_Rawdata_No_Device_Running,
    /** Failed to initialize media device. */
    Errors_Rawdata_Init_Device,
    /** Virtual device error. */
    Errors_Rawdata_Virtual_Device,
    /** Cannot change virtual device during preview. */
    Errors_Rawdata_Cannot_Change_Virtual_Device_In_Preview,
    /** Internal raw data error. */
    Errors_Rawdata_Internal_Error,
    /** Too much data sent at once. */
    Errors_Rawdata_Send_Too_Much_Data_In_Single_Time,
    /** Data sent too frequently. */
    Errors_Rawdata_Send_Too_Frequently,
    /** Virtual microphone has been terminated. */
    Errors_Rawdata_Virtual_Mic_Is_Terminate,

    /** Session sharing errors. */
    /** General sharing error. */
    Errors_Session_Share_Error = 7001,
    /** Share module not ready. */
    Errors_Session_Share_Module_Not_Ready,
    /** You are not sharing. */
    Errors_Session_Share_You_Are_Not_Sharing,
    /** Unsupported share type. */
    Errors_Session_Share_Type_Is_Not_Support,
    /** Internal share error. */
    Errors_Session_Share_Internal_Error,
    /** Camera video not started for share. */
    Errors_Session_Share_Camera_Video_Not_Start,
    /** Camera conflicts with video effects. */
    Errors_Session_Share_Camera_Conflict_With_Video_Effects,

    /** File transfer errors. */
    /** Unknown file transfer error. */
    Errors_Session_Filetransfer_UnknownError = 7500,
    /** File type is blocked. */
    Errors_Session_Filetransfer_FileTypeBlocked,
    /** File size exceeds limit. */
    Errors_Session_Filetransfer_FileSizelimited,

    /** Spotlight errors. */
    /** Not enough users to spotlight. */
    Errors_Spotlight_NotEnoughUsers = 7600,
    /** Too many spotlighted users. */
    Errors_Spotlight_ToMuchSpotlightedUsers,
    /** User cannot be spotlighted. */
    Errors_Spotlight_UserCannotBeSpotlighted,
    /** User has no video to spotlight. */
    Errors_Spotlight_UserWithoutVideo,
    /** User is not spotlighted. */
    Errors_Spotlight_UserNotSpotlighted,
};

/**
 * @brief Enumeration of session type.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKSessionType)
{
    /** The session type is main session. */
    ZoomVideoSDKSessionType_MainSession = 0,
    /** The session type is subSession. */
    ZoomVideoSDKSessionType_SubSession,
};

/**
 * @brief Enumerates the types of audio.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKAudioType) {
    /** Audio type is VOIP (Voice over IP). */
    ZoomVideoSDKAudioType_None   = 0,
    /** Audio type is telephony. */
    ZoomVideoSDKAudioType_VOIP,
    /** No audio type. */
    ZoomVideoSDKAudioType_TELEPHONY,
    /** Unknown audio type. */
    ZoomVideoSDKAudioType_Unknown,
};

/**
 * @brief Enumeration of the video aspect ratio.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoAspect) {
    /** Display the captured data without any cropping or scaling. */
    ZoomVideoSDKVideoAspect_Original         = 0,
    /** Stretch both horizontally and vertically to fill the display (may cause distortion). */
    ZoomVideoSDKVideoAspect_Full_Filled,
    /** Add black bars to maintain aspect ratio (e.g., 16:9 content on a 4:3 display or vice versa). */
    ZoomVideoSDKVideoAspect_LetterBox,
    /** Crop the sides or top/bottom to fill the screen (e.g., cut sides for 16:9 on 4:3, or top/bottom for 4:3 on 16:9). */
    ZoomVideoSDKVideoAspect_PanAndScan,
};

/**
 * @brief Enumeration of video type.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoType) {
    /** Video Camera Data. */
    ZoomVideoSDKVideoType_VideoData  = 1,
    /** Share Data. */
    ZoomVideoSDKVideoType_ShareData,
};

/**
 * @brief Enumerates the status of sharing.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKReceiveSharingStatus) {
    /** No view or screen share available. */
    ZoomVideoSDKReceiveSharingStatus_None = 0,
    /** User started sharing. */
    ZoomVideoSDKReceiveSharingStatus_Start,
    /** User paused sharing. */
    ZoomVideoSDKReceiveSharingStatus_Pause,
    /** User resumed sharing. */
    ZoomVideoSDKReceiveSharingStatus_Resume,
    /** User stopped sharing. */
    ZoomVideoSDKReceiveSharingStatus_Stop,
};

/**
 * @brief Enumerates the statuses of live streaming.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKLiveStreamStatus) {
    /** The live stream status is none. */
    ZoomVideoSDKLiveStreamStatus_None = 1,
    /** The live stream status is currently in progress. */
    ZoomVideoSDKLiveStreamStatus_InProgress,
    /** The live stream status is in the process of connecting. */
    ZoomVideoSDKLiveStreamStatus_Connecting,
    /** The live stream failed due to a timeout. */
    ZoomVideoSDKLiveStreamStatus_FailedTimeout,
    /** The live stream failed to start. */
    ZoomVideoSDKLiveStreamStatus_StartFailed,
    /** The live stream has ended. */
    ZoomVideoSDKLiveStreamStatus_Ended,
};

/**
 * @brief Enumeration of raw data formats. Defines the color space format and color range for video frames.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKFrameDataFormat) {
    /** I420 format with Limited color range. */
    ZoomVideoSDKFrameDataFormat_I420            = 1,
    /** I420 format with Full color range. */
    ZoomVideoSDKFrameDataFormat_I420_Limit,
};

/**
 * @brief RawDataRotationof the directions of video.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKVideoRawDataRotation) {
    /** Video direction 0 */
    ZoomVideoSDKVideoRawDataRotationNone      = 1,
    /** Video direction 90 */
    ZoomVideoSDKVideoRawDataRotation90,
    /** Video direction 180 */
    ZoomVideoSDKVideoRawDataRotation180,
    /** Video direction 270 */
    ZoomVideoSDKVideoRawDataRotation270,
};

/**
 * @brief Enumeration of render resolution.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoResolution) {
    /** The resolution is 90p. */
    ZoomVideoSDKVideoResolution_90,
    /** The resolution is 180p. */
    ZoomVideoSDKVideoResolution_180,
    /** The resolution is 360p. */
    ZoomVideoSDKVideoResolution_360,
    /** The resolution is 720p. Video resolution might be 1080p based on the user's network condition and device specs. */
    ZoomVideoSDKVideoResolution_720,
    /** The resolution is changed automatically according to the size of the view, only avaliable for video canvas. */
    ZoomVideoSDKVideoResolution_Auto = 100,
};

/**
 * @brief Enumeration of memory modes for raw data handling.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKRawDataMemoryMode) {
    /** The memory mode is srack. */
    ZoomVideoSDKRawDataMemoryModeStack,
    /** The memory mode is heap. */
    ZoomVideoSDKRawDataMemoryModeHeap
};

/**
 * @brief Enumeration the statuses of raw data.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKUserRawdataStatus) {
    /** The raw data status is on. */
    ZoomVideoSDKUserRawdataOn,
    /** The raw data status if off. */
    ZoomVideoSDKUserRawdataOff
};

/**
 * @brief Enumerates the statuses of a phone call.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKPhoneStatus) {
    /** For initialization. */
    ZoomVideoSDKPhoneStatus_None,
    /** In the process of calling out. */
    ZoomVideoSDKPhoneStatus_Calling,
    /** In the process of ringing. */
    ZoomVideoSDKPhoneStatus_Ringing,
    /** Call has been accepted. */
    ZoomVideoSDKPhoneStatus_Accepted,
    /** Call was successful. */
    ZoomVideoSDKPhoneStatus_Success,
    /** Call failed. */
    ZoomVideoSDKPhoneStatus_Failed,
    /** In process of canceling the response to the previous state. */
    ZoomVideoSDKPhoneStatus_Canceling,
    /** The call has been successfully canceled. */
    ZoomVideoSDKPhoneStatus_Canceled,
    /** The attempt to cancel the call has failed. */
    ZoomVideoSDKPhoneStatus_Cancel_Failed,
    /** The call attempt has timed out. */
    ZoomVideoSDKPhoneStatus_Timeout,
};


/**
 * @brief Enumerates the various reasons for a phone call failure.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKPhoneFailedReason) {
    /** For initialization. */
    ZoomVideoSDKPhoneFailedReason_None,
    /** The telephone number is currently busy. */
    ZoomVideoSDKPhoneFailedReason_Busy,
    /** The telephone number is out of service. */
    ZoomVideoSDKPhoneFailedReason_Not_Available,
    /** The user manually hung up the call. */
    ZoomVideoSDKPhoneFailedReason_User_Hangup,
    /** Other reasons. */
    ZoomVideoSDKPhoneFailedReason_Other_Fail,
    /** The user did not answer the call within the allowed time. */
    ZoomVideoSDKPhoneFailedReason_No_Answer,
    /** The call invitation was blocked by the system due to an absent host. */
    ZoomVideoSDKPhoneFailedReason_Block_No_Host,
    /** The call-out attempt was blocked by the system due to the high rates or cost. */
    ZoomVideoSDKPhoneFailedReason_Block_High_Rate,
    /** To join the session, the invitee would press one on the phone.
    An invitee who fails to respond will encounter a timeout.
    If there are too many invitee timeouts, the call invitation feature for this session will be blocked. */
    ZoomVideoSDKPhoneFailedReason_Block_Too_Frequent,
};

/**
 * @brief An enum representing the status of the recording status.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKRecordingStatus) {
    /** For initialization. */
    ZoomVideoSDKRecordingStatus_None,
    /** The recording has successfully started or successfully resumed. */
    ZoomVideoSDKRecordingStatus_Start,
    /** The recording has stopped. */
    ZoomVideoSDKRecordingStatus_Stop,
    /** Recording is unsuccessful due to insufficient storage space..Please try to:1.Free up storage space  2.Purchase additional storage space. */
    ZoomVideoSDKRecordingStatus_DiskFull,
    /** The recording has paused. */
    ZoomVideoSDKRecordingStatus_Pause,
    /** The recording connecting. */
    ZoomVideoSDKRecordingStatus_Connecting,
};

/**
 * @brief Enumerates the video preference modes.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVideoPreferenceMode) {
    /** Balance mode. */
    ZoomVideoSDKVideoPreferenceMode_Balance,
    /** Sharpness mode, prioritizing video clarity. */
    ZoomVideoSDKVideoPreferenceMode_Sharpness,
    /** Smoothness mode, focusing on a smooth video experience. */
    ZoomVideoSDKVideoPreferenceMode_Smoothness,
    /** Custom mode, allowing user-defined video preferences. */
    ZoomVideoSDKVideoPreferenceMode_Custom,
};

/**
 * @brief Enumerates the status of multi-camera streams.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKMultiCameraStreamStatus) {
    /** Current user only. Sent when the current user attempts to use multiple cameras in the session. */
    ZoomVideoSDKMultiCameraStreamStatus_JoinStart,
    /** Current user only. Sent when the current user fails to use multiple cameras in the session. */
    ZoomVideoSDKMultiCameraStreamStatus_JoinFail,
    /** Broadcast to all users. Sent when a new camera has been successfully added to the session as the multiple cameras. */
    ZoomVideoSDKMultiCameraStreamStatus_Joined,
    /** Broadcast to all users. Sent after a camera that is being used as the multiple cameras leaves the session. */
    ZoomVideoSDKMultiCameraStreamStatus_Left,
    /** Broadcast to all users. Sent when a multiple camera is started. */
    ZoomVideoSDKMultiCameraStreamStatus_VideoOn,
    /** Broadcast to all users. Sent when a multiple camera is stopped. */
    ZoomVideoSDKMultiCameraStreamStatus_VideoOff,
};

/**
 * @brief Enumerates the status of live transcription.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKLiveTranscriptionStatus) {
    /** Live transcription is currently stopped. */
    ZoomVideoSDKLiveTranscriptionStatus_Stop,
    /** Live transcription is currently active. */
    ZoomVideoSDKLiveTranscriptionStatus_Start,
};

/**
 * @brief Enumerates the types of operations related to live transcription.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKLiveTranscriptionOperationType) {
    /** No operation specified. */
    ZoomVideoSDKLiveTranscriptionOperationType_None,
    /** Live transcription operation type is added. */
    ZoomVideoSDKLiveTranscriptionOperationType_Add,
    /** Live transcription operation type is updated. */
    ZoomVideoSDKLiveTranscriptionOperationType_Update,
    /** Live transcription operation type is deleted. */
    ZoomVideoSDKLiveTranscriptionOperationType_Delete,
    /** Live transcription operation type is marked as complete. */
    ZoomVideoSDKLiveTranscriptionOperationType_Complete,
    /** Live transcription operation type is not supported. */
    ZoomVideoSDKLiveTranscriptionOperationType_NotSupported,
};

/**
 * @brief Enumerates the types of device permission
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKSystemPermissionType) {
    /** System permission - Camera is needed. */
    ZoomVideoSDKSystemPermissionType_Camera,
    /** System permission - Microphone is needed. */
    ZoomVideoSDKSystemPermissionType_Microphone,
};

/**
 * @brief The chat message delete type are sent in the onChatMsgDeleteNotification:messageID:deleteBy: callback.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKChatMsgDeleteBy)
{
    /** For initialization. */
    ZoomVideoSDKChatMsgDeleteBy_NONE,
    /** Message is deleted by the sender (self deletion). */
    ZoomVideoSDKChatMsgDeleteBy_SELF,
    /** Message is deleted by the session host. */
    ZoomVideoSDKChatMsgDeleteBy_HOST,
    /** Message is deleted by Data Loss Prevention (DLP) system for violating compliance policies. */
    ZoomVideoSDKChatMsgDeleteBy_DLP,
};

/**
 * @brief Enumeration of the number types for calling to join the audio into a meeting.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKDialInNumType)
{
    /** For initialization. */
    ZoomVideoSDKDialInNumType_None,
    /** Paid (toll) number. */
    ZoomVideoSDKDialInNumType_Toll,
    /** Toll-free number. */
    ZoomVideoSDKDialInNumType_TollFree,
};


/**
 * @brief Enumerates the network statuses.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKNetworkStatus)
{
    /** For initialization. */
    ZoomVideoSDKNetworkStatus_None,
    /** The network connection is poor, affecting video quality. */
    ZoomVideoSDKNetworkStatus_Bad,
    /** The network connection is stable with typical performance. */
    ZoomVideoSDKNetworkStatus_Normal,
    /** The network connection is strong and stable, providing optimal performance. */
    ZoomVideoSDKNetworkStatus_Good,
};

/**
 * @brief Enumerates the types of consent for cloud recording.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKRecordAgreementType)
{
    /** Invalid type. */
    ZoomVideoSDKRecordAgreementType_Invalid,
    /** In this case, 'accept' means agree to be recorded to gallery and speaker mode, 'decline' means leave session. */
    ZoomVideoSDKRecordAgreementType_Traditional,
    /** In this case, 'accept' means agree to be recorded to a separate file, 'decline' means stay in session and can't be recorded. */
    ZoomVideoSDKRecordAgreementType_Individual_Only,
};

/**
 * @brief Enumerates the types of virtual backgrounds.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKVirtualBackgroundDataType)
{
    /** No virtual background is applied. */
    ZoomVideoSDKVirtualBackgroundDataType_None,
    /** An image is used as the virtual background. */
    ZoomVideoSDKVirtualBackgroundDataType_Image,
    /** A blur effect is applied to the background. */
    ZoomVideoSDKVirtualBackgroundDataType_Blur,
};

/**
 * @brief Enumerates the types of Call CRC (Circuit-Reliable Communication).
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKCRCProtocol) {
    /** H.323 type. */
    ZoomVideoSDKCRCProtocol_H323        = 0,
    /** SIP type. */
    ZoomVideoSDKCRCProtocol_SIP,
};

/**
 * @brief Enumerates the statuses of a CRC call.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKCRCCallStatus) {
    /** The call was successfully established. */
    ZoomVideoSDKCRCCallStatus_Success        = 0,
    /** The call is ringing (waiting to be answered). */
    ZoomVideoSDKCRCCallStatus_Ring,
    /** The call has timed out. */
    ZoomVideoSDKCRCCallStatus_Timeout,
    /** The line is busy. */
    ZoomVideoSDKCRCCallStatus_Busy,
    /** The call was declined by the recipient. */
    ZoomVideoSDKCRCCallStatus_Decline,
    /** The call failed. */
    ZoomVideoSDKCRCCallStatus_Failed,
};

/**
 * @brief Enumeration of the type for annotation tool. For more information, please visit <https://support.zoom.com/hc/en/article?id=zm_kb&sysparm_article=KB0067931>.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKAnnotationToolType) {
    /** Switch to mouse cursor. For initialization. */
    ZoomVideoSDKAnnotationToolType_None = 0,
    /** Pen. */
    ZoomVideoSDKAnnotationToolType_Pen,
    /** Highlighter. */
    ZoomVideoSDKAnnotationToolType_HighLighter,
    /** A straight line changes automatically in pace with the mouse cursor. */
    ZoomVideoSDKAnnotationToolType_AutoLine,
    /** A rectangle changes automatically in pace with the mouse cursor. */
    ZoomVideoSDKAnnotationToolType_AutoRectangle,
    /** An ellipse changes automatically in pace with the mouse cursor. */
    ZoomVideoSDKAnnotationToolType_AutoEllipse,
    /** An arrow changes automatically in pace with the mouse cursor. */
    ZoomVideoSDKAnnotationToolType_AutoArrow,
    /** A filled rectangle. */
    ZoomVideoSDKAnnotationToolType_AutoRectangleFill,
    /** A filled ellipse. */
    ZoomVideoSDKAnnotationToolType_AutoEllipseFill,
    /** Only available if you started the shared screen or whiteboard. Displays your mouse pointer to all participants when your mouse is within the area being shared. Use this to point out parts of the screen to other participants. */
    ZoomVideoSDKAnnotationToolType_SpotLight,
    /** Displays a small arrow instead of your mouse pointer. Each subsequent click will remove the previous arrow placed. */
    ZoomVideoSDKAnnotationToolType_Arrow,
    /** Erase parts of your annotation. */
    ZoomVideoSDKAnnotationToolType_ERASER,
    /** Only available if you started the shared screen or whiteboard. Select , move, or resize your annotations. */
    ZoomVideoSDKAnnotationToolType_Picker,
    /** A fair rectangle changes automatically in pace with the mouse cursor. */
    ZoomVideoSDKAnnotationToolType_AutoRectangleSemiFill,
    /** A fair ellipse changes automatically in pace with the mouse cursor. */
    ZoomVideoSDKAnnotationToolType_AutoEllipseSemiFill,
    /** A line with a double-arrow. */
    ZoomVideoSDKAnnotationToolType_AutoDoubleArrow,
    /** An unfilled rhombus. */
    ZoomVideoSDKAnnotationToolType_AutoDiamond,
    /** A fixed-size arrow for marking. */
    ZoomVideoSDKAnnotationToolType_AutoStampArrow,
    /** A sign marking that something is correct. */
    ZoomVideoSDKAnnotationToolType_AutoStampCheck,
    /** A sign marking that something is incorrect. */
    ZoomVideoSDKAnnotationToolType_AutoStampX,
    /** A star for marking. */
    ZoomVideoSDKAnnotationToolType_AutoStampStar,
    /** A heart for marking. */
    ZoomVideoSDKAnnotationToolType_AutoStampHeart,
    /** A sign for interrogation. */
    ZoomVideoSDKAnnotationToolType_AutoStampQm,
};

/**
 * @brief Enumeration of the type for clear annotation.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKAnnotationClearType) {
    /** Clear all annotations. Hosts, managers and shared meeting owners can use. */
    ZoomVideoSDKAnnotationClearType_All = 0,
    /** Clear only the others' annotations. Only shared meeting owners can use. */
    ZoomVideoSDKAnnotationClearType_Others,
    /** Clear only your own annotations. Everyone can use. */
    ZoomVideoSDKAnnotationClearType_My,
};

/**
 * @brief Enumerates the reasons for a failed video subscription attempt.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKSubscribeFailReason) {
    /** No subscription failure (initial state). */
    ZoomVideoSDKSubscribeFailReason_None = 0,
    /** The subscription attempt failed because has already subscribed to two shared video streams. */
    ZoomVideoSDKSubscribeFailReason_HasSubscribeShare,
    /** The subscription attempt failed because has exceeded the maximum allowed subscription limit. */
    ZoomVideoSDKSubscribeFailReason_HasSubscribeExceededLimit,
    /** The subscription attempt failed because has already subscribed to a 1080P or 720P video stream. */
    ZoomVideoSDKSubscribeFailReason_HasSubscribe1080POr720P,
    /** Try to subscribe the second share. */
    ZoomVideoSDKSubscribeFailReason_HasSubscribeOneShare,
    /** The subscription attempt failed because subscription requests were made too frequently in a short period of time. */
    ZoomVideoSDKSubscribeFailReason_TooFrequentCall,
};

/**
 * @brief Enumerates the types of content that can be shared in a session.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKShareType)
{
    ZoomVideoSDKShareType_None,
    /** Application or desktop share. */
    ZoomVideoSDKShareType_Normal,
    /** Pure computer audio share. */
    ZoomVideoSDKShareType_PureAudio,
    /** Camera share. */
    ZoomVideoSDKShareType_Camera,
};


/**
 * @brief Enumerates the types of chat privileges.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKChatPrivilegeType) {
    /** Unknown type. */
    ZoomVideoSDKChatPrivilege_Unknown = 0,
    /** The user has the privilege to chat both publicly and privately. */
    ZoomVideoSDKChatPrivilege_Everyone_Publicly_And_Privately,
    /** The user has no chat privileges. */
    ZoomVideoSDKChatPrivilege_No_One,
    /** Allow participant to chat with host,manager and everyone. */
    ZoomVideoSDKChatPrivilege_Everyone_Publicly,
};

/**
 * @brief Enumeration of audio channel types.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKAudioChannel) {
    /** Mono audio channel. */
    ZoomVideoSDKAudioChannel_Mono,
    /** Stereo audio channel. */
    ZoomVideoSDKAudioChannel_Stereo,
};

/**
 * @brief Enumerates the microphone test statuses.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKTestMicStatus) {
    /** The microphone is ready to start a test. */
    ZoomVideoSDKMic_CanTest = 0,
    /** The microphone is currently recording audio for the test. */
    ZoomVideoSDKMic_Recording,
    /** The recorded audio is ready for playback. */
    ZoomVideoSDKMic_CanPlay,
};

/**
 * @brief Enumeration of file transfer status.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKFileTransferStatus) {
    /** The file transfer has no state. */
    FileTransferState_None = 0,
    /** The file transfer is ready to start. */
    FileTransferState_ReadyToTransfer,
    /** The file transfer is in progress. */
    FileTransferState_Transfering,
    /** The file transfer failed. */
    FileTransferState_TransferFailed,
    /** The file transfer completed successfully. */
    FileTransferState_TransferDone,
};

/**
 * @brief Enumerates the possible reasons for leaving a session.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKSessionLeaveReason) {
    /** Unknown. */
    ZoomVideoSDKSessionLeaveReason_Unknown = 0,
    /** Leave session by self. */
    ZoomVideoSDKSessionLeaveReason_BySelf,
    /** Kicked by host. */
    ZoomVideoSDKSessionLeaveReason_KickByHost,
    /** Ended by host. */
    ZoomVideoSDKSessionLeaveReason_EndByHost,
    /** Network error. */
    ZoomVideoSDKSessionLeaveReason_NetworkError,
};

/**
 * @brief Enumeration of the mask shape.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKMaskShape) {
    /** Rectangle. */
    ZoomVideoSDKMaskShape_Rectangle,
    /** Circle. */
    ZoomVideoSDKMaskShape_Circle,
    /** Oval. */
    ZoomVideoSDKMaskShape_Oval,
};

/**
 * @brief Enumeration of the UVC camera status.
 */
typedef NS_ENUM(NSInteger, ZoomVideoSDKUVCCameraStatus) {
    /** UVC camera attached. */
    ZoomVideoSDKUVCCameraStatus_Attached = 0,
    /** UVC camera detached. */
    ZoomVideoSDKUVCCameraStatus_Detached
};

/**
 * @brief Enumeration of subSession statuses.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKSubSessionStatus)
{
    /** The Initialized status. */
    ZoomVideoSDKSubSessionStatus_None,
    /** When a subsession is committed. */
    ZoomVideoSDKSubSessionStatus_Committed,
    /** When a subsession is withdrawn. */
    ZoomVideoSDKSubSessionStatus_Withdrawn,
    /** When the subsession is started. */
    ZoomVideoSDKSubSessionStatus_Started,
    /** When the subsession is stopping. */
    ZoomVideoSDKSubSessionStatus_Stopping,
    /** When the subsession is stopped. */
    ZoomVideoSDKSubSessionStatus_Stopped,
    /** When commit subsession failed. */
    ZoomVideoSDKSubSessionStatus_CommitFailed,
    /** When withdraw subsession failed. */
    ZoomVideoSDKSubSessionStatus_WithdrawFailed,
    /** When start subsession failed. */
    ZoomVideoSDKSubSessionStatus_StartFailed,
    /** When stop subsession failed. */
    ZoomVideoSDKSubSessionStatus_StopFailed,
};

/**
 * @brief Enumeration of subsession user help request results.
 */
typedef NS_ENUM(NSUInteger,ZoomVideoSDKUserHelpRequestResult)
{
    /** The h receive the help request and there is no other one currently requesting for help. */
    ZoomVideoSDKUserHelpRequestResult_Idle = 0,
    /** Host is handling another use's request with the request dialog. */
    ZoomVideoSDKUserHelpRequestResult_Busy,
    /** The host is handling another user's request. */
    ZoomVideoSDKUserHelpRequestResult_Ignore,
    /** The host is already in this subsession. */
    ZoomVideoSDKUserHelpRequestResult_HostAlreadyInSubSession
};

/**
 * @brief Enumeration of share preprocess types.
 */
typedef NS_ENUM(NSUInteger, ZoomVideoSDKSharePreprocessType) {
    /** For initialization. */
    ZoomVideoSDKSharePreprocessType_none,
    /** For share view */
    ZoomVideoSDKSharePreprocessType_view,
};

#endif /* ZoomVideoSDKConstants_h */

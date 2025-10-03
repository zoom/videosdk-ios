/**
 * @file ZoomVideoSDKShareHelper.h
 * @brief Interface for screen sharing operations including view sharing, external source sharing, annotation management, and multi-share support.
 */

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDKAnnotationHelper.h>

@protocol ZoomVideoSDKShareSource;
@protocol ZoomVideoSDKShareAudioSource;
@protocol ZoomVideoSDKSharePreprocessor;
/**
 * @class ZoomVideoSDKShareStatus
 * @brief Share status of user.
 */
@interface ZoomVideoSDKShareStatus : NSObject
/**
 * @brief The user's share status.
 */
@property (nonatomic, assign) ZoomVideoSDKReceiveSharingStatus  sharingStatus;

@end

@class ZoomVideoSDKVideoCanvas;
@class ZoomVideoSDKRawDataPipe;

/**
 * @class ZoomVideoSDKShareAction
 * @brief Share raw data pipe interface.
 */
@interface ZoomVideoSDKShareAction : NSObject
/**
 * @brief Get share source ID.
 * @return The user ID of the user object.
 */
- (NSInteger)getShareSourceId;
/**
 * @brief Get the render canvas object.
 * @return If the function succeeds, the return value is the share render helper object. Otherwise, this function fails and returns NULL.
 */
- (ZoomVideoSDKVideoCanvas *_Nullable)getShareCanvas;
/**
 * @brief Get the share status.
 * @return Share status of the share object.
 */
- (ZoomVideoSDKReceiveSharingStatus )getShareStatus;
/**
 * @brief Get the share raw data pipe.
 * @return The share pipe.
 */
- (ZoomVideoSDKRawDataPipe *_Nullable)getSharePipe;
/**
 * @brief Get the subscribe fail reason.
 * @return failed reason of the subscription.
 */
- (ZoomVideoSDKSubscribeFailReason)getSubscribeFailReason;
/**
 * @brief Determine whether annotation privilege is enabled.
 * @return YES indicates that annotation privilege is enabled, otherwise false.
 */
- (BOOL)isAnnotationPrivilegeEnabled;
/**
 * @brief Get the share type.
 * @return Share type of the share object.
 */
- (ZoomVideoSDKShareType)getShareType;
/**
 * @brief Get the size of the share content.
 * @return The size of share content.
 */
- (CGSize)getShareSourceContentSize;

@end

/**
 * @class ZoomVideoSDKSharePreprocessParam
 * @brief start pre-process share's parameter.
 */
@interface ZoomVideoSDKSharePreprocessParam : NSObject
@property (nonatomic, assign)   ZoomVideoSDKSharePreprocessType type;
/**
 * @brief the view to share and pre-process, no need pass when type is none.
 */
@property (nonatomic, weak)     UIView *view;
@end

/**
 * @class ZoomVideoSDKSharePreprocessParam
 * @brief Start pre-process share's parameter.
 */
@interface ZoomVideoSDKSharePreprocessSender : NSObject

/**
 * @brief Send preprocessed data.
 * @param rawData The processed data object.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)sendPreprocessedData:(ZoomVideoSDKVideoRawData * _Nullable)rawData;

@end



/**
 * @class ZoomVideoSDKShareHelper
 * @brief Share control interface.
 */
@interface ZoomVideoSDKShareHelper : NSObject

/**
 * @brief Share a selected view.
 * @param view The view to be shared.
 * @warning view, recommend to pass a single UIView's object, such as UIView, UIImageView or WKWebView.
 * @warning It is not recommended to pass UIView after add subview WKWebView or UIImageView.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 */
- (ZoomVideoSDKError)startShareWithView:(UIView * _Nullable)view;

/**
 * @brief Share an external source.
 * @param shareDelegate External share source.
 * @param audioDelegate External share audio source.
 * @return If the function succeeds, it will return Errors_Success.Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 * @warning   If audioDelegate is non-null, it means share user-defined audio at the same time.
 * @deprecated Use startSharingExternalSource:andAudioSource:isPlaying: instead.
 */
- (ZoomVideoSDKError)startSharingExternalSource:(id<ZoomVideoSDKShareSource> _Nullable)shareDelegate andAudioSource:(id <ZoomVideoSDKShareAudioSource> _Nullable)audioDelegate DEPRECATED_MSG_ATTRIBUTE("use startSharingExternalSource:andAudioSource:isPlaying: instead");

/**
 * @brief Share an external source.
 * @param shareDelegate External share source.
 * @param audioDelegate External share audio source.
 * @param isPlaying YES to play shared audio raw data, false not to play.
 * @return If the function succeeds, it will return Errors_Success.Otherwise failed. To get extended error information, see [ZoomVideoSDKError].
 * @warning   If audioDelegate is non-null, it means share user-defined audio at the same time.
 */
- (ZoomVideoSDKError)startSharingExternalSource:(id<ZoomVideoSDKShareSource> _Nullable)shareDelegate andAudioSource:(id <ZoomVideoSDKShareAudioSource> _Nullable)audioDelegate isPlaying:(BOOL)isPlaying;

/**
 * @brief Enable or disable local playback of shared audio raw data.
 * @param bPlay YES to play shared audio raw data, NO not to play it.
 * @return If the function succeeds, it will return Errors_Success. Otherwise failed.
 */
- (ZoomVideoSDKError)enablePlaySharingAudioRawdata:(BOOL)bPlay;

/**
 * @brief Stop view or screen share.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed.
 */
- (ZoomVideoSDKError)stopShare;

/**
 * @brief Pause share. For camera share, the presenter can pause the share to support annotation.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed.
 */
- (ZoomVideoSDKError)pauseShare;

/**
 * @brief Resume share. For camera share, the presenter can restart the camera share.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed.
 */
- (ZoomVideoSDKError)resumeShare;

/**
 * @brief Lock sharing the view or screen. Only the host can call this method.
 * @param lock YES to lock sharing.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed.
 * @warning Only Host/Manger can call the function.
 */
- (ZoomVideoSDKError)lockShare:(BOOL)lock;

/**
 * @brief Determine whether sharing the view or screen is locked.
 * @return YES indicates that sharing is locked, otherwise NO.
 */
- (BOOL)isShareLocked;

/**
 * @brief Determine whether the current user is sharing.
 * @return YES indicates the current user is sharing, otherwise NO.
 */
- (BOOL)isSharingOut;

/**
 * @brief Determine whether other user is sharing.
 * @return YES indicates another user is sharing, otherwise NO.
 */
- (BOOL)isOtherSharing;

/**
 * @brief Determine whether the current user is sharing the screen.
 * @return YES indicates the current user is sharing the screen, otherwise NO.
 */
- (BOOL)isScreenSharingOut;

/**
 * @brief Determine if the SDK has enabled share device audio when screen sharing.
 * @return The result of it.
 */
- (BOOL)isShareDeviceAudioEnabled;

/**
 * @brief Enable or disable the device audio  shared together when screen sharing.
 * @param enable share audio out or not.
 * @return The result of it.
 */
- (BOOL)enableShareDeviceAudio:(BOOL)enable;

/**
 * @brief Whether annotation feature is supported or not.
 * @return The result of it.
 */
- (BOOL)isAnnotationFeatureSupport;

/**
 * @brief Disable or enable viewer’s annotation by the share owner.
 * @param disable YES means annotation is disabled, NO means it is enabled.
 * @return The result of this.
 * @warning Only the share owner can call this function.
 */
- (ZoomVideoSDKError)disableViewerAnnotation:(BOOL)disable;

/**
 * @brief Whether annotation on current sharing is disabled or not.
 * @return The result of this.
 * @warning Only the share owner can call this function.
 */
- (BOOL)isViewerAnnotationDisabled;

/**
 * @brief Creates annotation helper based on shared view.
 * @param view the shared view. Pass the nil will return the helper for self sharing.
 * @return The result of it.
 * @warning The view passed in this function should be subscribed share view. And if the share view aspect mode is full fill, the annotate not supported. When the share owner not  support the feature of annotate, the others should not do annotate in that case.
 */
- (ZoomVideoSDKAnnotationHelper * _Nullable)createAnnotationHelper:(UIView * _Nullable)view;

/**
 * @brief Destroys annotation helper.
 * @param helper ZoomVideoSDKAnnotationHelper.
 * @return The result of it.
 */
- (ZoomVideoSDKError)destroyAnnotationHelper:(ZoomVideoSDKAnnotationHelper * _Nullable)helper;

/**
 * @brief Sets the vanishing tool time config.
 * @param displayTime The time in milliseconds the tool remains visible before fading.
 * @param vanishingTime The time in milliseconds for the tool to fade out after displayTime.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see {@link ZoomVideoSDKError}.
 * @note This setting only takes effect for the user's own share. The displayTime can be 0 or up to 15000 milliseconds (15 seconds),
 *      and the vanishingTime must be greater than 1000 milliseconds (1 second) and less than or equal to 15000 milliseconds (15 seconds).
 */
- (ZoomVideoSDKError)setAnnotationVanishingToolTime:(NSUInteger)displayTime vanishingTime:(NSUInteger)vanishingTime;

/**
 * @brief Gets the current vanishing tool display time.
 * @note This function can only retrieve the timer settings for your own share.
 * @return The time in milliseconds the tool remains visible before fading.
 */
- (NSUInteger)getAnnotationVanishingToolDisplayTime;

/**
 * @brief Gets the current vanishing tool vanishing time.
 * @return The time in milliseconds for the tool to fade out after displayTime.
 * @note This function can only retrieve the timer settings for your own share.
 */
- (NSUInteger)getAnnotationVanishingToolVanishingTime;

#pragma mark - multi share -
/**
* @brief Enable or disable participants can share simultaneously.
* @param enable True to enable. False to disable.
* @return If the function succeeds, the return value is Errors_Success.
* @warning When you switch multi share from enable to disable, all sharing will be stopped.
*/
- (ZoomVideoSDKError)enableMultiShare:(BOOL)enable;

/**
 * @brief Determine whether multi share is enabled or not.
 * @return YES enabled, NO not enabled.
 */
- (BOOL)isMultiShareEnabled;

#pragma mark - share camera and anno -
/**
 * @brief Share the select camera. Query the select camera using \link ZoomVideoSDKVideoHelper::getCameraDeviceList \endlink.
 * @param parentView the share view to show the camera for the presenter.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed.
 * @note The presenter can use \link ZoomVideoSDKShareHelper::pauseShare \endlink to enable viewer annotation. If the camera is paused, the presenter can use \link ZoomVideoSDKShareHelper::resumeShare \endlink to resume. Notice: The user should start video before start share camera, otherwise the error \link Errors_Session_Share_Camera_Video_Not_Start \endlink.
 */
- (ZoomVideoSDKError)startShareCamera:(UIView *_Nullable)parentView  API_UNAVAILABLE(visionos);


#pragma mark - share with pre-process -
/**
 * @brief Start share preprocessing.
 * @param param The share preprocessing parameters.
 * @param preProcessDelegate Object that handles preprocessing events.
 * @return If the function succeeds, the return value is ZoomVideoSDKErrors_Success. Otherwise this function fails. To get extended error information, see \link ZoomVideoSDKErrors \endlink enum.
 * @note If pAudioSource is non-null, it means share user-defined audio at the same time.
 * @note This share type should using the CptShare.framework, zm_annoter_dynamic.framework.
 */
- (ZoomVideoSDKError)startShareWithPreprocessing:(ZoomVideoSDKSharePreprocessParam * _Nullable)param sharePreprocessor:(id<ZoomVideoSDKSharePreprocessor> _Nullable)preProcessDelegate;

/**
 * @brief Apply a UIImage overlay to the shared image stream when using (when you share with {@link  startShareWithPreprocessing:sharePreprocessor:} or {@link startInAppScreenShare}). Use this method to cover the shared content with an image during preprocessing.
 * @param image The UIImage to overlay on top of the shared image. The UIImage is fully coverd the current share frame before it is sent to viewers.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see {@link ZoomVideoSDKError}.
 */
- (ZoomVideoSDKError)applyPreprocessingOverlayImage:(UIImage *_Nullable)image;

/**
 * @brief Remove the currently applied UIImage overlay from the shared image stream when using (when you share with {@link  startShareWithPreprocessing:sharePreprocessor:}  or {@link startInAppScreenShare}).
 * @note Once removed, the raw shared content is sent directly to viewers without any overlay. Call this method when you no longer need to display the overlay (for example, when a covered image is no longer required).
 */
- (void)removePreprocessingOverlayImage;

#pragma mark - in-app screen share -

/**
 * @brief Check that the system supports in-app screen share or not.
 * @return return whether the device supports in-app screen share or not. Please refer to {@link RPScreenRecorder}.
 */
- (BOOL)isSupportInAppScreenShare;

/**
 * @brief Start in-app screen share.
 * @return If the function succeeds, the return value is Errors_Success. Otherwise failed. To get extended error information, see {@link ZoomVideoSDKError}.
 * @warning Can only be called once every 500ms.
 */
- (ZoomVideoSDKError)startInAppScreenShare;

/**
 * @brief Sets the annotation view when the view hierarchy changes.
 * @param shareView The top-level view for the shared content.
 * @return {@link ZoomVideoSDKError#Errors_Success} if the operation succeeds; otherwise the method failed.
 * @warning This API is only available in in-app screen share mode.
 */
- (ZoomVideoSDKError)setAnnotationView:(UIView *_Nullable)shareView;

@end



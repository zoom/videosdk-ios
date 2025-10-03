/**
 * @file ZoomVideoSDKAudioHelper.h
 * @brief Interface for managing audio operations including start/stop, mute/unmute, audio device control, and audio raw data subscription.
 */

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDK.h>

/**
 * @class ZoomVideoSDKAudioDevice
 * @brief Represents an audio device used in the Zoom Video SDK.
 */
@interface ZoomVideoSDKAudioDevice : NSObject
/**
 * @brief Gets the audio device type.
 * @return The audio device type. See {@link AVAudioSessionPort}
 */
- (AVAudioSessionPort _Nullable)getAudioSourceType;

/**
 * @brief Get the audio device name.
 * @return The audio device name.
 */
- (NSString *_Nullable)getAudioName;
@end


/**
 * @class ZoomVideoSDKAudioHelper
 * @brief A class to operate the audio action.
 */
@interface ZoomVideoSDKAudioHelper : NSObject

/**
 * @brief Start audio.
 * @return The result of it.
 */
- (ZoomVideoSDKError)startAudio;

/**
 * @brief Stop audio.
 * @return the result of it.
 */
- (ZoomVideoSDKError)stopAudio;

/**
 * @brief Mute user's audio.
 * @return The result of it.
 * @warning If mute self use userid=0.
 * @warning Only host or manager can mute others audio.
 */
- (ZoomVideoSDKError)muteAudio:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Ask unmute user's audio.
 * @return The result of it.
 * @warning If unmute self use userid=0.
 * @warning Only host or manager can unmute others audio.
 * @warning This function will trigger the callback \link onHostAskUnmute \endlink.
 */
- (ZoomVideoSDKError)unmuteAudio:(ZoomVideoSDKUser * _Nullable)user;

/**
 * @brief Mute all user's VOIP audio except my self.
 * @param allowUnmute Yes means allow the user to unmute themself, otherwise NO.
 * @return The result of it.
 * @warning Only host or manager can mute all user's audio.
 */
- (ZoomVideoSDKError)muteAllAudio:(BOOL)allowUnmute;

/**
 * @brief Allow the others to unmute themselves or not.
 * @param allowUnmute Yes means allow the user to unmute themself, otherwise NO.
 * @return The result of it.
 * @warning Only host or manager can change this property.
 */
- (ZoomVideoSDKError)allowAudioUnmutedBySelf:(BOOL)allowUnmute;

/**
 * @brief Ask unmute all user's VOIP audio.
 * @return The result of it.
 * @warning Only host or manager can ask unmute all user's audio.
 * @warning This function will trigger the callback \link onHostAskUnmute \endlink.
 */
- (ZoomVideoSDKError)unmuteAllAudio;

/**
 * @brief Call the function to subscribe audio rawdata.
 * @warning Please check the callack "- (void)onMixedAudioRawDataReceived:(ZoomVideoSDKAudioRawData *)rawData".
 * @warning " - (void)onOneWayAudioRawDataReceived:(ZoomVideoSDKAudioRawData *)rawData user:(ZoomVideoSDKUser *)user.
 */
- (ZoomVideoSDKError)subscribe;

/**
 * @brief Call the function to unSubscribe audio rawdata.
 * @warning Please check the callack "- (void)onMixedAudioRawDataReceived:(ZoomVideoSDKAudioRawData *)rawData".
 * @warning " - (void)onOneWayAudioRawDataReceived:(ZoomVideoSDKAudioRawData *)rawData user:(ZoomVideoSDKUser *)user.
 */
- (ZoomVideoSDKError)unSubscribe;

/**
 * @brief Reset Audio Session including Category and Mode for ZoomVideoSDK Audio Session Environment When developer change audio session in session.
 * @return Yes means set auidio success, otherwise failed.
 * @deprecated Use setSDKAudioSessionEnv instead.
 */
- (BOOL)resetAudioSession DEPRECATED_MSG_ATTRIBUTE("Use setSDKAudioSessionEnv instead");

/**
 * @brief  Set the AVAudio Session Environment for Zoom Video SDK Session.
 * @warning Developer change AVAudio Session by self special needs in SDK session，will cause the audio output abnormal. Then developer can set SDK AVAudio Session environment.
 * @return Yes means set audio success, otherwise failed.
 */
- (BOOL)setSDKAudioSessionEnv;

/**
 * @brief Clean Audio Session including Category and Mode.
 * @warning SDK will restore audio session status after session end. if developer call overrideOutputAudioPort interface wtth AVAudioSessionPortBuiltInSpeaker in AVAudioSessionCategoryPlayAndRecord Category before join session, then sdk can not restore audio session BuiltInSpeaker output when session end,.
 * @deprecated No longer maintain anymore!
 */
- (void)cleanAudioSession DEPRECATED_MSG_ATTRIBUTE("No longer maintain anymore!");

/**
 * @brief Get current audio output port description, @{AVAudioSessionPortDescription}.
 * @return The current audio output port description.
 */
- (ZoomVideoSDKAudioDevice * _Nullable)getCurrentAudioOutputRoute;

/**
 * @brief Set audio output device. See @{ZoomVideoSDKAudioDevice}.
 * @param device The device to set as the audio output.
 * @return YES if the output route was set successfully; otherwise, the method failed.
 */
- (BOOL)setAudioOutputRoute:(ZoomVideoSDKAudioDevice *_Nullable)device;

/**
 * @brief Gets the available audio output port description, @{AVAudioSessionPortDescription}..
 * @return A list of the vailable audio output pott descriptions.
 */
- (NSArray <ZoomVideoSDKAudioDevice *>* _Nullable)getAvailableAudioOutputRoute;

/**
 @brief Displays the system AirPlay picker.
 @param parentView The parent view where the AirPlay picker will be shown.
 @return YES If the picker was shown successfully, otherwise the method failed.
 */
- (BOOL)showAudioOutputDeviceAirPlayPicker:(UIView *_Nullable)parentView;

/**
 @brief Gets the current audio input device. See @{AVAudioSessionPortDescription}.
 @return The current audio input device.
 */
- (ZoomVideoSDKAudioDevice *_Nullable)getCurrentAudioInputDevice;

/**
 @brief Gets the list of available audio input devices. See @{AVAudioSessionPortDescription}.
 @return An array of available audio input devices.
 */
- (NSArray <ZoomVideoSDKAudioDevice *> *_Nullable)getAvailableAudioInputsDevice;

/**
 @brief Sets the audio input device..
 @param device The device to set as the audio input. See @{AVAudioSessionPortDescription}.
 @return YES If the input device was set successfully, otherwise the method failed.
 */
- (BOOL)setAudioInputDevice:(ZoomVideoSDKAudioDevice *_Nullable)device;
@end


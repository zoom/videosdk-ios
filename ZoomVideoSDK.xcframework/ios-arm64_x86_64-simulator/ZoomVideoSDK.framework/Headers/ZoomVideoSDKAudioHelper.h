//
//  ZoomVideoSDKAudioHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 2018/12/6.
//  Copyright © Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDK.h>

/**
 * @class ZoomVideoSDKAudioDevice
 * @brief Zoom Video SDK Audio Device
 */
@interface ZoomVideoSDKAudioDevice : NSObject
/**
 * @brief Audio device type.
 * @return the audio device type. See {@link AVAudioSessionPort}
 */
- (AVAudioSessionPort _Nullable)getAudioSourceType;

/**
 * @brief Audio device name.
 * @return the audio device name.
 */
- (NSString *_Nullable)getAudioName;
@end


/*!
 @class ZoomVideoSDKAudioHelper
 @brief A class to operate the audio action.
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
 * @warning This functinon will trigger the callback \link onHostAskUnmute \endlink.
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
 * @warning Only host or manager can chagne this property.
 */
- (ZoomVideoSDKError)allowAudioUnmutedBySelf:(BOOL)allowUnmute;

/**
 * @brief Ask unmute all user's VOIP audio.
 * @return The result of it.
 * @warning Only host or manager can ask unmute all user's audio.
 * @warning This functinon will trigger the callback \link onHostAskUnmute \endlink.
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
 * @brief Get currently audio output port description, @{AVAudioSessionPortDescription}.
 * @return Return the current audio outout port description.
 */
- (ZoomVideoSDKAudioDevice * _Nullable)getCurrentAudioOutputRoute;

/**
 * @brief Set audio output device, please refer to @{ZoomVideoSDKAudioDevice}.
 * @param device The device port type want to set.
 * @return YES mean the set audio out put route success, otherwise failed.
 */
- (BOOL)setAudioOutputRoute:(ZoomVideoSDKAudioDevice *_Nullable)device;

/**
 * @brief Get avalible audio output port description, @{AVAudioSessionPortDescription}..
 * @return Return the avalible audio outout port description list.
 */
- (NSArray <ZoomVideoSDKAudioDevice *>* _Nullable)getAvalibleAudioOutputRoute;

/*!
 @brief Show the system AirPlay picker.
 @param parentView the parent view which AirPlay picker shows to.
 @return YES means show the picker success, otherwise failed.
 */
- (BOOL)showAudioOutputDeviceAirPlayPicker:(UIView *_Nullable)parentView;

/*!
 @brief Get the current audio input device, please refer to @{AVAudioSessionPortDescription}.
 @return Return the current audio input session port description.
 */
- (ZoomVideoSDKAudioDevice *_Nullable)getCurrentAudioInputDevice;

/*!
 @brief Get the available audio input devices, please refer to @{AVAudioSessionPortDescription}.
 @return Return the array of available audio input session port description.
 */
- (NSArray <ZoomVideoSDKAudioDevice *> *_Nullable)getAvailableAudioInputsDevice;

/*!
 @brief Change the audio input device.
 @param device the audio input device want to change to,  please refer to @{AVAudioSessionPortDescription}.
 @return YES means change audio input device success, otherwise failed.
 */
- (BOOL)setAudioInputDevice:(ZoomVideoSDKAudioDevice *_Nullable)device;
@end


//
//  ZoomVIdeoSDKSubSessionHelper.h
//  ZoomVideoSDK
//
//  Created by Zoom on 2025/5/15.
//  Copyright © 2025 Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ZoomVideoSDKSubSessionUserHelpRequestHandler
 * @brief Subsession user help request handler.
 */
@interface ZoomVideoSDKSubSessionUserHelpRequestHandler : NSObject
/**
 * @brief Get the username of the user who sent this request.
 * @return The username.
 */
-(NSString * _Nullable)getRequestUserName;

/**
 * @brief Get the name of the subsession where the user  sent this request.
 * @return The subsession name.
 */
-(NSString * _Nullable)getRequestSubSessionName;

/**
 * @brief Ignore this request.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @note 'onSubSessionUserHelpRequestResult' is the corresponding callback notification.
 */
-(ZoomVideoSDKError)ignore;

/**
 * @brief Join the subsession which request help is from.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 */
-(ZoomVideoSDKError)joinSubSessionByUserRequest;
@end

/**
 * @class ZoomVideoSDKSubSessionUser
 * @brief Represents a subsession user info.
 */
@interface ZoomVideoSDKSubSessionUser : NSObject
/**
 * @brief Get the subsession user's username.
 * @return The username.
 */
- (NSString *)getUserName;
/**
 * @brief Get the subsession user's GUID.
 * @return The user GUID.
 */
- (NSString *)getUserGUID;
@end

/**
 * @class ZoomVideoSDKSubSessionKit
 * @brief Represents a subsession instance.
 */
@interface ZoomVideoSDKSubSessionKit : NSObject
/**
 * @brief Get the subsession's nam.
 * @return The subsession name.
 */
- (NSString * _Nullable)getSubSessionName;
/**
 * @brief Get the subsessions's ID.
 * @return The subsession ID.
 */
- (NSString * _Nullable)getSubSessionID;

/**
 * @brief Get the user list in this subsessions.
 * @return If the function succeeds, it returns an array of ZoomVideoSDKSubSessionUser. Otherwise returns NULL.
 */
- (NSArray <ZoomVideoSDKSubSessionUser*>* _Nullable)getSubSessionUserList;
/**
 * @brief Join this subsessions.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 */
- (ZoomVideoSDKError)joinSubSession;
@end

/**
 * @class ZoomVideoSDKSubSessionManager
 * @brief Manages subsession lifecycle and communication.
 */
@interface ZoomVideoSDKSubSessionManager : NSObject
/**
 * @brief Start subsession.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @note 'onSubSessionStatusChanged' is the corresponding callback notification.
 */
- (ZoomVideoSDKError)startSubSession;
/**
 * @brief Stop subsession.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @note 'onSubSessionStatusChanged' is the corresponding callback notification.
 */
- (ZoomVideoSDKError)stopSubSession;
/**
 * @brief Determine if the subsession is started .
 * @return If the subsession is started, the return value is true, otherwise not.
 */
- (BOOL)isSubSessionStarted;
/**
 * @brief Broadcast a message to subsession.
 * @param message The message to be broadcast.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @warning 'onBroadcastMessageFromMainSession' is the corresponding callback notification.
 */
- (ZoomVideoSDKError)broadcastMessage:(NSString *_Nonnull)message;

@end

/**
 * @class ZoomVideoSDKSubSessionParticipant
 * @brief SubSession attendee helper interface.
 */
@interface ZoomVideoSDKSubSessionParticipant : NSObject
/**
 * @brief Return to main session.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 */
- (ZoomVideoSDKError)returnToMainSession;
/**
 * @brief Request for help.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @note 'onSubSessionUserHelpRequestResult'is the corresponding callback notification.
 */
- (ZoomVideoSDKError)requestForHelp;

@end

/**
 * @class ZoomVideoSDKSubSessionHelper
 * @brief Subsession helper interface.
 * @note Only session host and manager can get this helper.
 */
@interface ZoomVideoSDKSubSessionHelper : NSObject
/**
 * @brief Add a subsession name to prepared list.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 */
- (ZoomVideoSDKError)addSubSessionToPreList:(NSArray <NSString *>* _Nonnull)subSessionNames;
/**
 * @brief Remove a subsession name from prepared list.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 */
- (ZoomVideoSDKError)removeSubSessionFromPreList:(NSArray <NSString *> *_Nonnull)subSessionNames;
/**
 * @brief Clear the prepared list.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 */
- (ZoomVideoSDKError)clearSubSessionPreList;
/**
 * @brief Get the subsession name prepared list.
 * @return If the function succeeds, it returns an array of SubSession name.
 */
- (NSArray <NSString*>* _Nullable)getSubSessionPreList;
/**
 * @brief Withdraw all committed subsession list and commit the prepared list.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @note If the function succeeds, the prepared list will be cleared, 'onSubSessionListUpdate'is the corresponding callback notification.
 */
- (ZoomVideoSDKError)commitSubSessionList;

/**
 * @brief Get the commited subsession list.
 * @return If the function succeeds, it returns an array of ISubSessionKit. Otherwise returns NULL.
 */
- (NSArray <ZoomVideoSDKSubSessionKit*>* _Nullable)getCommittedSubSessionList;
/**
 * @brief Withdraw all committed subsession list.
 * @return If the function succeeds, the return value is Errors_Success, otherwise not.
 * @note If the function succeeds, the prepared list will be cleared, 'onSubSessionStatusChanged'is the corresponding callback notification.
 */
- (ZoomVideoSDKError)withdrawSubSessionList;

@end

NS_ASSUME_NONNULL_END

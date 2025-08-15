//
//  ZoomVideoSDKFileTranserHandle.h
//  ZoomVideoSDK
//
//  Created by Zoom Video Communications on 4/15/24.
//  Copyright © Zoom Video Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ZoomVideoSDK/ZoomVideoSDK.h>

#pragma mark - File Transfer -

/**
 * @class ZoomVideoSDKFileTransferProgress
 * @brief Represents the progress details of a file transfer.
 */
@interface ZoomVideoSDKFileTransferProgress : NSObject

/**
 * @brief The ratio of the file transfer completed.
 */
@property(nonatomic, assign)    NSUInteger ratio;
/**
 * @brief The size of the file transferred so far in bytes.
 */
@property(nonatomic, assign)    NSUInteger completeSize;
/**
 * @brief The speed of the file transfer in bits per second.
 */
@property(nonatomic, assign)    NSUInteger bitPerSecond;
@end

/**
 * @class ZoomVideoSDKFileStatus
 * @brief Represents the status of a file transfer, including current state and progress.
 */
@interface ZoomVideoSDKFileStatus : NSObject
/**
 * @brief The status of the file transfer.
 */
@property(nonatomic, assign)    ZoomVideoSDKFileTransferStatus transStatus;
/**
 * @brief The progress of the file transfer.
 */
@property(nonatomic, strong, nullable)    ZoomVideoSDKFileTransferProgress *transProgress;
@end

/**
 * @class ZoomVideoSDKFileTransferBaseInfo
 * @brief Represents a file being sent in the session.
 */
@interface ZoomVideoSDKFileTransferBaseInfo : NSObject
- (NSTimeInterval)getTimeStamp;
- (BOOL)isSendToAll;
- (NSUInteger)getFileSize;
- (NSString * _Nullable)getFileName;
- (ZoomVideoSDKFileStatus *_Nullable)getStatus;
@end

/**
 * @class ZoomVideoSDKSendFile
 * @brief Represents a file being sent in the session.
 */
@interface ZoomVideoSDKSendFile : ZoomVideoSDKFileTransferBaseInfo
- (ZoomVideoSDKUser * _Nullable)getReceiver;
- (ZoomVideoSDKError)cancelSend;
@end

/**
 * @class ZoomVideoSDKReceiveFile
 * brief Represents a file being received in the session.
 */
@interface ZoomVideoSDKReceiveFile : ZoomVideoSDKFileTransferBaseInfo
- (ZoomVideoSDKUser * _Nullable)getSender;
- (ZoomVideoSDKError)cancelReceive;
- (ZoomVideoSDKError)startReceive:(NSString * _Nullable)path;
@end


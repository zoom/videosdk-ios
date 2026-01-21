// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "ZoomVideoSDK-iOS",
    platforms: [.iOS(.v15)],
    products: [
        .library(name: "ZoomVideoSDK",            targets: ["ZoomVideoSDK"]),
        .library(name: "CptShare",                targets: ["CptShare"]),
        .library(name: "zoomcml",                 targets: ["zoomcml"]),
        .library(name: "zm_annoter_dynamic",      targets: ["zm_annoter_dynamic"]),
        .library(name: "ZoomTask",                targets: ["ZoomTask"]),
        .library(name: "Whiteboard",              targets: ["Whiteboard"]),
        .library(name: "ZoomVideoSDKScreenShare", targets: ["ZoomVideoSDKScreenShare"]),
    ],
    targets: [
        .binaryTarget(
            name: "CptShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/CptShare.xcframework.zip",
            checksum: "95a50c7511019c4bff8e359ad292536eb1b727a8ce1eb957fbf73d5cace19899"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/Whiteboard.xcframework.zip",
            checksum: "56b00d81aa7318aa4eff6749afc455eb60c368989a5de285de3d788fff2d6dc7"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/zm_annoter_dynamic.xcframework.zip",
            checksum: "92989278e8c663f137dd2f26dd96ed605af06f1f3d64d374ff5ef14aae082cae"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/zoomcml.xcframework.zip",
            checksum: "5d4576c60ea44aead52cb49f2d6ac0eecbb8f35c57d6452a759caddf691a06d1"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/ZoomTask.xcframework.zip",
            checksum: "1c912bb69e3060be21583c3b8897f11f68ae63d883c1d4d851e3e6ab8a300ddb"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/ZoomVideoSDK.xcframework.zip",
            checksum: "c60008b4571c102498697f0e049a714994aa09a44790f6d7287d2a6cac112ebd"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.12/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "02175608132cf9148b1a98775dfec8c05bc252c296d15bdf0788224d1684deda"
        ),
    ]
)


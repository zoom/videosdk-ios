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
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/CptShare.xcframework.zip",
            checksum: "4bd5389c9d046997bce61080204def190acbd4186ae7b4c8c992fda868125ed1"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/Whiteboard.xcframework.zip",
            checksum: "3478f7983b2470a278cb547d82792b37f90e473348c044ca0812c136de5cafb2"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/zm_annoter_dynamic.xcframework.zip",
            checksum: "d17037a853e2d73c00537d0cd8ac61ecbd2b35b03ad834b308f8bba24fa4c248"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/zoomcml.xcframework.zip",
            checksum: "89ce9c5f7b80e758ca62936dc2caeae9cf3e744e79e21ec4c708384ed22485be"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/ZoomTask.xcframework.zip",
            checksum: "ff8b43aceadbdeb8524f0130c25043ce3a9403f2612318ba6b1853fc694150ce"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/ZoomVideoSDK.xcframework.zip",
            checksum: "dfb3018417bc4046190fde0b4f208a2ed004f0c70c92d3adb860cc74137af110"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.4.5/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "71cc896da93c5127a5214b365fca0ac9622150d6376de187272a50f076baea2f"
        ),
    ]
)


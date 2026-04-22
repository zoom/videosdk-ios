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
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/CptShare.xcframework.zip",
            checksum: "387aabfd5f91d9a800e3de7860a5bfadd29ded35eeeb1464624fa1adcdc2490a"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/Whiteboard.xcframework.zip",
            checksum: "02cbfb0e734f3eeb779bf1397d53570f061d4d416efb195121debbbeeaca6623"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/zm_annoter_dynamic.xcframework.zip",
            checksum: "35d82428f7d3b4d56dd2a1a65f2a5d6c82b40b2f1e3688c33944de2357be0b94"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/zoomcml.xcframework.zip",
            checksum: "f0c0a68a7393f8ad2f5e7c4689db9907ed9f5d1d0f1900eb01d6ae3f0d8c0b3a"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/ZoomTask.xcframework.zip",
            checksum: "d336a853032bcd77ef995ccae17299bd8263fdb7fa2e27689b5e0a4df6d42451"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/ZoomVideoSDK.xcframework.zip",
            checksum: "9400de4b4c25029647d58c27e67d074e6f428f8c2d7eaf932bc7b40c27fbe135"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.7/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "0748c2556fc7721f1ac1653164c164b18ef2d662950a7e07df973a5f748d134b"
        ),
    ]
)


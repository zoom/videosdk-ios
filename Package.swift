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
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/CptShare.xcframework.zip",
            checksum: "ce709a4a263b3959775f751a93f7257dfb596f7f5393e1a4a1e69fd4fdc7e91e"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/Whiteboard.xcframework.zip",
            checksum: "c3ce9b70031a2619ee00ca6882a92972ed93f478e68dc0e03a15d08e39c37a98"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/ZoomTask.xcframework.zip",
            checksum: "db63b88c39f79f2ccdb572310925452c077d1fccb5080aa278cf9222a0c729a4"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/ZoomVideoSDK.xcframework.zip",
            checksum: "9f4436ab85c63a1f4874a8b99bc958090685239ffed807504df6592848451448"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "1619c1f988fc825636c0c73a0665f09ad26efa105e50a47d027e5104f7dc50a5"
        ),

        .binaryTarget(
            name: "util",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/util.xcframework.zip",
            checksum: "77a44d347abbd10624d9a1c97b500cac3293bb41e5b86217f487ec621c203667"
        ),

        .binaryTarget(
            name: "zContext",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/zContext.xcframework.zip",
            checksum: "a2534a975976bc8de990889628323232189ad5c60e17e79aae46f03b12f27517"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/zm_annoter_dynamic.xcframework.zip",
            checksum: "77fb954b75fe8c55660d4ec54d6372ddfe7789d2f6a77ceb702fb20c07dc1088"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.11/zoomcml.xcframework.zip",
            checksum: "40e9a9227cf2451c544a42aed9bb63157ee7ba286fdfd140797c678be70354a8"
        ),

    ]
)


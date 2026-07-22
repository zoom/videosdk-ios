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
        .library(name: "util",                    targets: ["util"]),
        .library(name: "zContext",                targets: ["zContext"]),
        .library(name: "ZoomVideoSDKScreenShare", targets: ["ZoomVideoSDKScreenShare"]),
    ],
    targets: [
        .binaryTarget(
            name: "CptShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/CptShare.xcframework.zip",
            checksum: "dd798d35b8e7453b2a074fbb401cef4651f8b3355b9a3c739d3c327677347fbe"
        ),

        .binaryTarget(
            name: "util",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/util.xcframework.zip",
            checksum: "26e41a01bc88be12bf883fbe0167f9c959dd6fcfd9c13d8390545a2e07445429"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/Whiteboard.xcframework.zip",
            checksum: "b3fe5fd852da6ba50f0b1031120a2c2655597a35efb673b9e9202fef672fb106"
        ),

        .binaryTarget(
            name: "zContext",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/zContext.xcframework.zip",
            checksum: "bd1e51755cf66af94ebd86b6418f96d49b5d9a0197878cc3468c4fcaf16590ed"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/zm_annoter_dynamic.xcframework.zip",
            checksum: "79f99629287a22406a1c7f3d4104fbf812028fb90a1c083dc2054cb77833951e"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/zoomcml.xcframework.zip",
            checksum: "33a1ced7b955fc2cae861f8bf0173ab7d0aea81b563d967d00275d5cab1e1b7e"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/ZoomTask.xcframework.zip",
            checksum: "0fc7fa9b896f2ab018b73449ef0ef126db5cef1ac586327a384d4520be373b00"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/ZoomVideoSDK.xcframework.zip",
            checksum: "202b15184cd76623fc6dd34de37ef699634f83b78ec8680063dec993c2fb9bfa"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.5/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "e8b8dd46b4cb42a33bb8ada1a07744b3df06b18d9e0416fd95bc90e2e3c98366"
        ),

    ]
)


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
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/CptShare.xcframework.zip",
            checksum: "22ac24415796d584147e4b52f8ef399450b9396f06c85aae96d6c1b92f8f5eb5"
        ),

        .binaryTarget(
            name: "util",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/util.xcframework.zip",
            checksum: "0895d466c56065890cc36993e6b585275ed96bdc4aa88ce11ebee3dcd3268558"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/Whiteboard.xcframework.zip",
            checksum: "37f0e36b637ce742bdb3b4538d5a51d90f40beb1850b1ba419923900c6ea11ec"
        ),

        .binaryTarget(
            name: "zContext",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/zContext.xcframework.zip",
            checksum: "08a4daf225496796350fc9f7974e62100c784c3bfeb6d434253b7dbb982ca8a8"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/zm_annoter_dynamic.xcframework.zip",
            checksum: "f7a568dfad95cc50c41c2f4751113332b2ce8e8ff9381d54fbf9e670eacf6033"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/zoomcml.xcframework.zip",
            checksum: "cc88b6467906a276bfc4c4acf56a65d335289cf1ce54248b8abd6c1e313c62ce"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/ZoomTask.xcframework.zip",
            checksum: "c7e1cef80f49db09cd1a462946f6328130a224671f2e053fd710a05577b75926"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/ZoomVideoSDK.xcframework.zip",
            checksum: "3ddaa18cee9c3d67f321f66bbe19739b18a649c21b9e7a749f5289de0bcffca6"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.0/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "d2feafd66c5dde4bd37343076e32aa14a8b47dc7633e1397ed65e85b62674eb5"
        ),
    ]
)


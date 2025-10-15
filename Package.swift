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
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/ZoomVideoSDK.xcframework.zip",
            checksum: "f6a31f3387d6638c35e08b7b413a282d3acad3eb01fdadc4692fb74e8736ecf7"
        ),
        .binaryTarget(
            name: "CptShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/CptShare.xcframework.zip",
            checksum: "14d5037a0409883c13d86e49d8b91b244852904263a87a6ba0bdf6d5fb698cc4"
        ),
        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/zoomcml.xcframework.zip",
            checksum: "f50b420bc033c7ead50d28cfb447f80a6dabf6ed57a5af64265e7b449904da62"
        ),
        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/zm_annoter_dynamic.xcframework.zip",
            checksum: "d7dd17f6abfa6855bf3336ea4df6a281348b70d8a9d87a0a2a063ace0c7a2bfd"
        ),
        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/ZoomTask.xcframework.zip",
            checksum: "6d9a84d37a833cbcc04e774e35a00a62511cfdef618907142bb032b3a94e99d6"
        ),
        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/Whiteboard.xcframework.zip",
            checksum: "c139edd38006058e732d13f4ce7ca82b53ffa23cb85788bd26e9fff1cbc1ef8c"
        ),
        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.3.10/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "06e456c4c2c8b27b67b9b75ed825c577d2282e0be6d489d3b3258049000c12bc"
        ),
    ]
)


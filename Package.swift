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
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/CptShare.xcframework.zip",
            checksum: "c62a5190c4297ad35abe0b86bd9e76feccea49575f717d218c7224e241c9c2fd"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/Whiteboard.xcframework.zip",
            checksum: "4464b882e48f8d3c8aab947e2211d7cea650103701430156dc71a5f431259746"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/zm_annoter_dynamic.xcframework.zip",
            checksum: "5380905c42d7382742b1b7b1a0b86157f2b4bf8b8b6a6e29bf847376b97b76ab"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/zoomcml.xcframework.zip",
            checksum: "baa054f7d1b783a5c686d7df48ed7ba07d613487181b521c122c7f73c6a2f7ef"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/ZoomTask.xcframework.zip",
            checksum: "06182c42017cd9b5e777d21431cabdd16d49e26786709a318963869ad0913183"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/ZoomVideoSDK.xcframework.zip",
            checksum: "90774bd9a2a8ec1a0505f01210d529c7382507b9734ffc3cd1954e69dd812716"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.5.10/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "ce203dd3617c784a518708f6efdab562adb26c570a1b7c0bafbda3438b6d492f"
        ),
    ]
)


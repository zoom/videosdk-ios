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
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/CptShare.xcframework.zip",
            checksum: "0d7e5e1c0c741a75fe191c40761ae3957bf622b09121a264d75e91fbdbd51d45"
        ),

        .binaryTarget(
            name: "Whiteboard",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/Whiteboard.xcframework.zip",
            checksum: "e4f2813e064229ec2bce9ceb60e15133536eeb7d97999e184dc8ebf0b76b2b50"
        ),

        .binaryTarget(
            name: "ZoomTask",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/ZoomTask.xcframework.zip",
            checksum: "63498818980049b17542973977f7210208bd6513e724c5bb8132a719a2795a3a"
        ),

        .binaryTarget(
            name: "ZoomVideoSDK",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/ZoomVideoSDK.xcframework.zip",
            checksum: "b61ffa4d42b84187ae7b840015476920fa4ecba1eb064940ef1ed6e950971bb7"
        ),

        .binaryTarget(
            name: "ZoomVideoSDKScreenShare",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/ZoomVideoSDKScreenShare.xcframework.zip",
            checksum: "dc8633a7d239ae7da5d7f3b4a9bdafa2d4acf6e6172c99c913856d77af1eb4b4"
        ),

        .binaryTarget(
            name: "util",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/util.xcframework.zip",
            checksum: "294578e15c0a65a66da90678ebbce37103c845ea6c33d411e16702ec7233c6b9"
        ),

        .binaryTarget(
            name: "zContext",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/zContext.xcframework.zip",
            checksum: "51159677932b77fe9af2305d4b0f8c7fb3cbc9908da3f719e0a02c5395c4ce34"
        ),

        .binaryTarget(
            name: "zm_annoter_dynamic",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/zm_annoter_dynamic.xcframework.zip",
            checksum: "1b8a99fcd0da7056e4d61ee4ea3b3854200e89aaa1bbeaf2363a5a3dc6f4f464"
        ),

        .binaryTarget(
            name: "zoomcml",
            url: "https://github.com/zoom/videosdk-ios/releases/download/v2.6.15/zoomcml.xcframework.zip",
            checksum: "113fbba6991dbf9dccf5ef1a2716223fb616630c93099a2a13e84559842abb57"
        ),

    ]
)


// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let url = "https://github.com/zoom/zoom-video-sdk-iOS/releases/download/v2.3.10/zoom-video-sdk-iOS.zip"
let checksum = "7690696486afb67de0cc096414634b2b2647c0a0966411a0910437b63ec32f37"

let package = Package(
  name: "ZoomVideoSDK-iOS",
  platforms: [.iOS(.v15)],
  products: [
    .library(name: "ZoomVideoSDK",                targets: ["ZoomVideoSDK"]),
    .library(name: "CptShare",                    targets: ["CptShare"]),
    .library(name: "zoomcml",                     targets: ["zoomcml"]),
    .library(name: "zm_annoter_dynamic",          targets: ["zm_annoter_dynamic"]),
    .library(name: "ZoomTask",                    targets: ["ZoomTask"]),
    .library(name: "Whiteboard",                  targets: ["Whiteboard"]),
    .library(name: "ZoomVideoSDKScreenShare",     targets: ["ZoomVideoSDKScreenShare"]),
  ],
  targets: [
    .binaryTarget(name: "ZoomVideoSDK",            url: url, checksum: checksum),
    .binaryTarget(name: "CptShare",                url: url, checksum: checksum),
    .binaryTarget(name: "zoomcml",                 url: url, checksum: checksum),
    .binaryTarget(name: "zm_annoter_dynamic",      url: url, checksum: checksum),
    .binaryTarget(name: "ZoomTask",                url: url, checksum: checksum),
    .binaryTarget(name: "Whiteboard",              url: url, checksum: checksum),
    .binaryTarget(name: "ZoomVideoSDKScreenShare", url: url, checksum: checksum),
  ]
)


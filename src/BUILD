
# ref https://github.com/bazelbuild/bazel/blob/master/examples/windows/dll/BUILD
load("//src:windows_dll_library.bzl", "windows_dll_library")


package(default_visibility = ["//visibility:public"])

windows_dll_library(
    name = "bazel_wrapper",
    srcs = ["bazel_wrapper.cc"],
    hdrs = ["bazel_wrapper.h"],
    deps = [
        "@mediapipe//mediapipe/calculators/core:pass_through_calculator",
        "@mediapipe//mediapipe/framework:calculator_framework",
        "@mediapipe//mediapipe/framework/port:logging",
        "@mediapipe//mediapipe/framework/port:parse_text_proto",
        "@mediapipe//mediapipe/framework/port:status",
    ],
    copts = ["/DCOMPILING_DLL"],
)


cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    deps = [":bazel_wrapper"],
    #data = [":bazel_wrapper.dll"],
)



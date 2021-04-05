load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "capi",
    srcs = ["capi.cpp"],
    hdrs = ["capi.h"],
    visibility = ["//visibility:public"],
    deps = ["//http"],
)

cc_binary(
    name = "capi_example",
    srcs = ["capi_example.c"],
    deps = [":capi"],
)

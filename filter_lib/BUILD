load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "trie",
    srcs = ["trie.cpp"],
    hdrs = ["trie.hpp"],
)

cc_library(
    name = "filter_lib",
    srcs = ["filter.cpp"],
    hdrs = ["filter.hpp"],
    deps = [
        ":trie",
    ]
)


cc_test(
    name = "filter_test",
    size = "small",
    srcs = ["filter_test.cpp"],
    deps = [
        ":filter_lib",
        "@com_google_googletest//:gtest_main",
    ]
)

cc_test(
    name = "trie_test",
    size = "small",
    srcs = ["trie_test.cpp"],
    deps = [
        ":trie",
        "@com_google_googletest//:gtest_main",
    ]
)
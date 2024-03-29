#!/bin/bash
# version = Major.Minor
# Minor should be manually updated any time new functionality is added.
# Major should be manually incremented for major releases.
# Both should be integers with no leading zeroes (ie NOT 2.01)
# Do NOT include a revision string!!
# The Makefile will tack on a revision string (to yield the full version strign eg. 2.1.21) for commits between changes.
# This files documents features and functionality, not patches nor bug fixes
export FEATURE_VERSION_MATHQ=0.42
# 0.42: formally introduce Semantic 2.0 versioning and optional prelease tags. finished introduction
# V0.41 created from v0.40.262-c++20: introduction of *vector calculus*.
# V0.40 created from v3.5.78-c++17: refactotring of MultiArrays such that Scalar, Vector and Matrix are simply type aliases

# nimble-GPU
C++ implementation of GPU (Garbage Processing Unit) - Autonomous Cleaning Arm Vehicle

## Motivation

The original GPU was implemented in Python for faster prototyping.
This is the optimazation of the implementation for better performance.
For the test, googletest is used. The style follows the Google C++ style guide.

## Development Note

### Using googletest

Compile example

```
$ g++ -isystem ${GTEST_DIR}/include -pthread interface_unittest.cc ../../interface/Interface.cpp ../gtest/libgtest.a -o interface_unittest
```

### References

- [google test setup](https://github.com/google/googletest/tree/master/googletest)
- [googletest usage sample](https://stackoverflow.com/questions/31254657/googletest-run-all-tests-not-finding-test-fixtures)
- [goolgetest test code sample official](https://github.com/google/googletest/blob/master/googletest/samples/sample1_unittest.cc)

if(EXISTS "E:/VS2019/Source/Repos/google-code-sample/cpp/out/build/x64-Debug/part4_test[1]_tests.cmake")
  include("E:/VS2019/Source/Repos/google-code-sample/cpp/out/build/x64-Debug/part4_test[1]_tests.cmake")
else()
  add_test(part4_test_NOT_BUILT part4_test_NOT_BUILT)
endif()

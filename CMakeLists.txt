# CMakeLists.txt
cmake_minimum_required(VERSION 3.22.1)

project(TestSo)

# 设置 JNI 包含路径
include_directories(
        /Library/Java/JavaVirtualMachines/jdk1.8.0_151.jdk/Contents/Home/include
        /Library/Java/JavaVirtualMachines/jdk1.8.0_151.jdk/Contents/Home/include/darwin   # macOS
        # ${JAVA_HOME}/include/linux  # Linux
        # ${JAVA_HOME}/include/win32  # Windows
)

#set(CMAKE_CXX_STANDARD 11)
# 设置支持的架构（armeabi-v7a、arm64-v8a、x86_64 等）
set(ANDROID_ABI "armeabi-v7a") # 可改为 arm64-v8a/x86_64
set(ANDROID_PLATFORM "android-21")

# 设置 NDK 路径（请替换为你自己的路径）
#set(ANDROID_NDK "/Users/mlk/Library/Android/sdk/ndk/21.4.7075529")
set(ANDROID_NDK "/Users/mlk/Library/Android/sdk/ndk/25.0.8775105")

# 使用 NDK 提供的 toolchain 文件
set(CMAKE_TOOLCHAIN_FILE "${ANDROID_NDK}/build/cmake/android.toolchain.cmake")

# 引入 toolchain
include(${CMAKE_TOOLCHAIN_FILE})

# 添加头文件目录
#include_directories(include)

# 添加共享库
add_library(TestSo SHARED src/native-lib.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log)
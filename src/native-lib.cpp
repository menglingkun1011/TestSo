//
// Created by MLK on 2025/6/23.
//

//https://www.nxrte.com/jishu/yinshipin/15679.html
// src/native-lib.cpp
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mirsmeng_ndk01_JniUtils_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++, from java JniUtils file";
    return env->NewStringUTF(hello.c_str());
}
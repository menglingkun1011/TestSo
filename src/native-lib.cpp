//
// Created by MLK on 2025/6/23.
//

//https://www.nxrte.com/jishu/yinshipin/15679.html
// src/native-lib.cpp
#include <jni.h>
#include <string>
#include <android/log.h>
#define TAG "native-jni"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_mirsmeng_ndk01_JniUtils_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++, from java JniUtils file";
    jintArray pArray = env->NewIntArray(2);
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_example_mirsmeng_ndk01_JniUtils_intArrFromJNI(
        JNIEnv* env,
        jobject /* this */,
        jintArray jintArr) {
//    jintArray pArray = env->NewIntArray(2);
    jint len = 10;
    jint nativeArr[len];
    env->GetIntArrayRegion(jintArr ,0,len,nativeArr);
    for (int i = 0; i < len; ++i) {
        nativeArr[i] = i + 10;
        LOGI("nativeArr[%d]:%d",i,nativeArr[i]);
    }
    env->SetIntArrayRegion(jintArr,0,len,nativeArr);
}
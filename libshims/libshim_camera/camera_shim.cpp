/*
 * Copyright (C) 2018 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define  LOG_TAG    "libshim_camera"

#include <stdlib.h> // avoid exit warning
#include <stdio.h>
#include <linux/ion.h>
#include <dlfcn.h>
#include <cutils/log.h>

#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" const char _ZN7android16CameraParameters8ISO_AUTOE[] = "auto";
extern "C" const char _ZN7android16CameraParameters7ISO_100E[] = "100";
extern "C" const char _ZN7android16CameraParameters7ISO_200E[] = "200";
extern "C" const char _ZN7android16CameraParameters7ISO_400E[] = "400";
extern "C" const char _ZN7android16CameraParameters7ISO_800E[] = "800";

extern "C" const char _ZN7android16CameraParameters17EFFECT_CARTOONIZEE[] = "cartoonize";
extern "C" const char _ZN7android16CameraParameters23EFFECT_POINT_RED_YELLOWE[] = "point-red-yellow";
extern "C" const char _ZN7android16CameraParameters18EFFECT_POINT_GREENE[] = "point-green";
extern "C" const char _ZN7android16CameraParameters17EFFECT_POINT_BLUEE[] = "point-blue";
extern "C" const char _ZN7android16CameraParameters19EFFECT_VINTAGE_COLDE[] = "vintage-cold";
extern "C" const char _ZN7android16CameraParameters19EFFECT_VINTAGE_WARME[] = "vintage-warm";
extern "C" const char _ZN7android16CameraParameters13EFFECT_WASHEDE[] = "washed";
extern "C" const char _ZN7android16CameraParameters10KEY_CITYIDE[] = "contextualtag-cityid";
extern "C" const char _ZN7android16CameraParameters11KEY_WEATHERE[] = "weather";
extern "C" const char _ZN7android16CameraParameters26PIXEL_FORMAT_YUV420SP_NV21E[] = "nv21";

//This doesn't exist in the android Camera Parameters object any longer
extern "C" int _ZNK7android16CameraParameters8getInt64EPKc(const char *key) {
    return -1;
}

//These no longer in existence
extern "C" void acquire_dvfs_lock(void) { }
extern "C" void release_dvfs_lock(void) { }
/*
 * Copyright (C) 2016 The CyanogenMod Project
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License"
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

#ifndef SAMSUNG_POWER_H
#define SAMSUNG_POWER_H

/*
 * Board specific nodes
 *
 * If your kernel exposes these controls in another place, you can either
 * symlink to the locations given here, or override this header in your
 * device tree.
 */

static const std::vector<std::string> cpuSysfsPaths = {
    "/sys/devices/system/cpu/cpu0"
};

static const std::vector<std::string> cpuInteractivePaths = {
    "/sys/devices/system/cpu/cpufreq/interactive"
};

/* interactive power-save profile */
#define INTERACTIVE_LOW_MIN_SAMPLE_TIME "40000"
#define INTERACTIVE_LOW_HISPEED_FREQ "600000"
#define INTERACTIVE_LOW_GO_HISPEED_LOAD "101"
#define INTERACTIVE_LOW_TARGET_LOADS "70 350000:70 500000:75 600000:85 800000:90 1200000:95 1700000:97 1900000:100"
#define INTERACTIVE_LOW_ABOVE_HISPEED_DELAY "20000 1000000:80000 1200000:100000 1700000:20000"

/* interactive normal profile */
#define INTERACTIVE_NORMAL_MIN_SAMPLE_TIME  "79000"
#define INTERACTIVE_NORMAL_HISPEED_FREQ "1300000"
#define INTERACTIVE_NORMAL_GO_HISPEED_LOAD "90"
#define INTERACTIVE_NORMAL_TARGET_LOADS "55 800000:65 1500000:70"
#define INTERACTIVE_NORMAL_ABOVE_HISPEED_DELAY "19000"

/* interactive high-performance profile */
#define INTERACTIVE_HIGH_MIN_SAMPLE_TIME  "99000"
#define INTERACTIVE_HIGH_HISPEED_FREQ "1400000"
#define INTERACTIVE_HIGH_GO_HISPEED_LOAD "85"
#define INTERACTIVE_HIGH_TARGET_LOADS  "50 1200000:60 1600000:70"
#define INTERACTIVE_HIGH_ABOVE_HISPEED_DELAY "19000"

#endif // SAMSUNG_POWER_H

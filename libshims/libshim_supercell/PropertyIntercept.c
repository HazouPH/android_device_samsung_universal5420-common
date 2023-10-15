#define _GNU_SOURCE

#define LOG_TAG "Libshim_Supercell_Games"
#include <cutils/log.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

typedef int *(*__system_property_get_t)(const char* name, char* value);
__system_property_get_t real___system_property_get;

int *__system_property_get(const char* name, char* value) {
  if (!real___system_property_get) {
    real___system_property_get = dlsym(RTLD_NEXT, "__system_property_get");
  }
  int* result = real___system_property_get(name, value);
  if (strcmp(name, "ro.build.version.sdk") == 0) {
    ALOGD("System Property: %s, changes from %s to 26", name, value); 
    char oldsdk[] = "26";
    memcpy(value, &oldsdk, sizeof oldsdk);
  }
  return result;
}

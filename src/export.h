#pragma once

#ifdef _WIN32
  #ifdef PROJECT_BUILDING
    #define API_EXPORT __declspec(dllexport)
  #elif defined(PROJECT_SHARED)
    #define API_EXPORT __declspec(dllimport)
  #else
    #define API_EXPORT
  #endif
#else
  #if defined(PROJECT_BUILDING)
    #define API_EXPORT __attribute__((visibility("default")))
  #else
    #define API_EXPORT
  #endif
#endif

extern "C" {
    API_EXPORT int run();
}
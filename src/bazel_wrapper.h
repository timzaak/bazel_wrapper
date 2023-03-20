#pragma once

#if defined(_MSC_VER)
#define SYMBOL_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define SYMBOL_EXPORT __attribute__((visibility("default")))
#else
#define SYMBOL_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

SYMBOL_EXPORT void hello_world();

#ifdef __cplusplus
}
#endif

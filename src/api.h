#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define SagittalWall_DLLIMPORT __declspec(dllimport)
#  define SagittalWall_DLLEXPORT __declspec(dllexport)
#  define SagittalWall_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define SagittalWall_DLLIMPORT __attribute__((visibility("default")))
#    define SagittalWall_DLLEXPORT __attribute__((visibility("default")))
#    define SagittalWall_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define SagittalWall_DLLIMPORT
#    define SagittalWall_DLLEXPORT
#    define SagittalWall_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef SagittalWall_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define SagittalWall_DLLAPI
#  define SagittalWall_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef SagittalWall_EXPORTS
#    define SagittalWall_DLLAPI SagittalWall_DLLEXPORT
#  else
#    define SagittalWall_DLLAPI SagittalWall_DLLIMPORT
#  endif // SagittalWall_EXPORTS
#  define SagittalWall_LOCAL SagittalWall_DLLLOCAL
#endif // SagittalWall_STATIC
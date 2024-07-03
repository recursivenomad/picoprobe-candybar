/* SPDX-License-Identifier: MIT-0 OR CC0-1.0 *\
\*    Authored 2024 by Peter S. Hollander    */


/*
   This override hooks into the fact that when an #included file is not in the
   same directory as the file calling it, GCC will search other directories in
   the order they are provided at invokation [1]; in our case, that is the
   order that we list the target_include_directories to CMake [2].

   (Compiling with Clang will similarly search in the order that directories
   are provided [3], but perhaps without prioritizing the calling directory.)

   Since this file name is called from debugprobe/src/probe_config.h, and the
   original "board_debug_probe_config.h" resides in debugprobe/include/, we can
   exploit them being in different directories and present this file of the
   same name earlier to the compiler (defined in our case via CMakeLists.txt).

   [1]: <https://gcc.gnu.org/onlinedocs/gcc-13.2.0/cpp/Invocation.html#index-I>
   [2]: <https://cmake.org/cmake/help/v3.28/command/target_include_directories.html>
   [3]: <https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang-I-dir>
*/

#ifndef OVERRIDE_BOARD_DEBUG_PROBE_H_
#define OVERRIDE_BOARD_DEBUG_PROBE_H_


// Depend on the original Debug Probe configuration to maintain near-parity
#include "../lib/debugprobe/include/board_debug_probe_config.h"


#endif  // OVERRIDE_BOARD_DEBUG_PROBE_H_

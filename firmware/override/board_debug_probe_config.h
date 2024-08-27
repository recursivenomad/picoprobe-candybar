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


// Depend on the original Debug Probe configuration to maintain a superset
#include "../lib/debugprobe/include/board_debug_probe_config.h"

#include "boards/pico.h"


#define PROBE_UART_HWFC


#undef  PROBE_PIN_RESET
#define PROBE_PIN_RESET 2

#ifdef PROBE_UART_HWFC
    #define PROBE_UART_DTR 3
    #define PROBE_UART_CTS 6
    #define PROBE_UART_RTS 7
#endif

#undef  PROBE_UART_RX_LED
#define PROBE_UART_RX_LED 9

#undef  PROBE_USB_CONNECTED_LED
#define PROBE_USB_CONNECTED_LED PICO_DEFAULT_LED_PIN

#undef  PROBE_PRODUCT_STRING
#define PROBE_PRODUCT_STRING "Picoprobe Candybar (CMSIS-DAP)"


#endif  // OVERRIDE_BOARD_DEBUG_PROBE_H_

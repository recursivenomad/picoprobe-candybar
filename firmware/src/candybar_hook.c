/* SPDX-License-Identifier: MIT-0 OR CC0-1.0 *\
\*    Authored 2024 by Peter S. Hollander    */


/*
   debugprobe calls bi_decl_config() from the top of main().
   We point to _this_ file in our CMakeLists.txt - both to add custom binary
   declarations, but also to hook into the start of execution and inject our
   own features on top of debugprobe's, without modifying its source.
*/


#include "probe_config.h"
#include "pico/binary_info.h"

#include "pico_binary_license_info.h"


#define STR_LITERAL(x) #x
#define STR(x) STR_LITERAL(x)


void candybar_hook(void) {
}


void bi_decl_config(void) {

    candybar_hook();

    bi_decl(bi_1pin_with_name(PROBE_PIN_SWCLK, "PROBE SWCLK"));
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDIO, "PROBE SWDIO"));
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDI,  "PROBE SWDI" ));
    bi_decl(bi_1pin_with_name(PROBE_PIN_RESET, "PROBE RESET"));

    bi_decl(bi_1pin_with_name(PROBE_UART_TX, "PROBE UART_TX"));
    bi_decl(bi_1pin_with_name(PROBE_UART_RX, "PROBE UART_RX"));

    bi_decl(bi_1pin_with_name(PROBE_UART_CTS, "PROBE UART_CTS"));
    bi_decl(bi_1pin_with_name(PROBE_UART_RTS, "PROBE UART_RTS"));
    bi_decl(bi_1pin_with_name(PROBE_UART_DTR, "PROBE UART_DTR"));

    bi_decl(bi_1pin_with_name(PROBE_USB_CONNECTED_LED, "LED_USB_CONN"));
    bi_decl(bi_1pin_with_name(PROBE_DAP_CONNECTED_LED, "LED_DAP_CONN"));
    bi_decl(bi_1pin_with_name(PROBE_DAP_RUNNING_LED,   "LED_DAP_RUN" ));
    bi_decl(bi_1pin_with_name(PROBE_UART_TX_LED,       "LED_UART_TX" ));
    bi_decl(bi_1pin_with_name(PROBE_UART_RX_LED,       "LED_UART_RX" ));

    // picotool lists bi_decl's of each category in reverse order
    bi_decl(bi_program_feature(STR(PROBE_UART_BAUDRATE) " baud probe UART"));
    bi_decl(bi_program_feature("Activity indicator LEDs"));
    bi_decl(bi_program_feature("Probe target reset support"));

    bi_decl(bi_program_author("Firmware derived from Raspberry Pi's Debug Probe"));
    bi_decl(bi_program_author("Peter S. Hollander <recursivenomad@protonmail.com>"));

    bi_decl(bi_program_license("See repository or accompanying .TXT for complete notices"));
    bi_decl(bi_program_license("MIT-0 OR CC0-1.0, BSD-3-Clause, MIT, Apache-2.0, SunPro, OAR, BSD-4.3TAHOE, Martin-Birgmeier"));

}


#undef STR
#undef STR_LITERAL

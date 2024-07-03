/* SPDX-License-Identifier: MIT-0 OR CC0-1.0 *\
\*    Authored 2024 by Peter S. Hollander    */


#include "probe_config.h"
#include "pico/binary_info.h"


#define STR_LITERAL(x) #x
#define STR(x) STR_LITERAL(x)


void bi_decl_config() {

    bi_decl(bi_1pin_with_name(PROBE_PIN_SWCLK, "PROBE SWCLK"));
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDIO, "PROBE SWDIO"));
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDI,  "PROBE SWDI" ));
    bi_decl(bi_1pin_with_name(PROBE_PIN_RESET, "PROBE RESET"));

    bi_decl(bi_1pin_with_name(PROBE_UART_TX, "PROBE UART_TX"));
    bi_decl(bi_1pin_with_name(PROBE_UART_RX, "PROBE UART_RX"));

    bi_decl(bi_1pin_with_name(PROBE_USB_CONNECTED_LED, "LED_USB_CONN"));
    bi_decl(bi_1pin_with_name(PROBE_DAP_CONNECTED_LED, "LED_DAP_CONN"));
    bi_decl(bi_1pin_with_name(PROBE_DAP_RUNNING_LED,   "LED_DAP_RUN" ));
    bi_decl(bi_1pin_with_name(PROBE_UART_TX_LED,       "LED_UART_TX" ));
    bi_decl(bi_1pin_with_name(PROBE_UART_RX_LED,       "LED_UART_RX" ));

    bi_decl(bi_program_feature(STR(PROBE_UART_BAUDRATE) " baud probe UART"));
    bi_decl(bi_program_feature("Activity indicator LEDs"));
    bi_decl(bi_program_feature("Probe target reset support"));

}


#undef STR
#undef STR_LITERAL

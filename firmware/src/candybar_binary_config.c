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

    bi_decl(bi_program_feature("PROBE UART INTERFACE " STR(PROBE_UART_INTERFACE)));
    bi_decl(bi_program_feature("PROBE UART BAUDRATE " STR(PROBE_UART_BAUDRATE)));

    bi_decl(bi_1pin_with_name(PROBE_UART_TX, "PROBE UART TX"));
    bi_decl(bi_1pin_with_name(PROBE_UART_RX, "PROBE UART RX"));

}


#undef STR
#undef STR_LITERAL

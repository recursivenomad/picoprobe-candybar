#  SPDX-License-Identifier: MIT-0 OR CC0-1.0  #
#     Authored 2024 by Peter S. Hollander     #


# The (minimum) versions below are what the Pico SDK uses
cmake_minimum_required(VERSION 3.13...3.28.1)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Pico SDK option to define which variant of the Pico we are using
set(PICO_BOARD pico CACHE STRING "Board type")
# Pico SDK option to not optimize anything during debug builds
set(PICO_DEOPTIMIZED_DEBUG ON)
# Pico SDK option to load and run this application from RAM
set(PICO_COPY_TO_RAM ON)

# Include the Pico SDK (various build functions and compiling definitions)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
# Include the FreeRTOS library (invokes the library's CMakeLists.txt)
include(lib/debugprobe/freertos/portable/ThirdParty/GCC/RP2040/FREERTOS_KERNEL_import.cmake)

# Technically compiled at 1.5.0, but only tested with 1.5.1
if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.1")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.1 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}.")
endif()



# Set PROJECT_NAME and languages
project(picoprobe_candybar C CXX ASM)

# Invokes the Pico SDK's CMakeLists.txt
pico_sdk_init()



# Below is informed by lib/debugprobe/CMakeLists.txt:

add_executable(${PROJECT_NAME}
    src/candybar_binary_config.c
    lib/debugprobe/src/led.c
    lib/debugprobe/src/main.c
    lib/debugprobe/src/usb_descriptors.c
    lib/debugprobe/src/probe.c
    lib/debugprobe/src/cdc_uart.c
    lib/debugprobe/src/get_serial.c
    lib/debugprobe/src/sw_dp_pio.c
    lib/debugprobe/src/tusb_edpt_handler.c
)

target_sources(${PROJECT_NAME} PRIVATE
    lib/debugprobe/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP.c
    lib/debugprobe/CMSIS_5/CMSIS/DAP/Firmware/Source/DAP_vendor.c
)

target_include_directories(${PROJECT_NAME} PRIVATE
    lib/debugprobe/src/
    lib/debugprobe/include/
    lib/debugprobe/CMSIS_5/CMSIS/DAP/Firmware/Include/
    lib/debugprobe/CMSIS_5/CMSIS/Core/Include/
)

# Specify BEFORE here to assert 'override/' being first include dir in the list
target_include_directories(${PROJECT_NAME} BEFORE PRIVATE
    override/
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pico_multicore
    pico_stdlib
    pico_unique_id
    tinyusb_device
    tinyusb_board
    hardware_pio
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap1
)

target_compile_definitions (${PROJECT_NAME} PRIVATE
	PICO_RP2040_USB_DEVICE_ENUMERATION_FIX=1
)



# Creates "probe.pio.h" at build-time
pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/lib/debugprobe/src/probe.pio)
# Creates map/bin/hex/uf2 files, in addition to elf
pico_add_extra_outputs(${PROJECT_NAME})

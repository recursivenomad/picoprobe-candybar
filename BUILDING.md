# Development Environment

> 🐉 These are fast and loose instructions right now, follow with scrutiny.



## Overview

*Development was done using Windows 10, but should use the same tools regardless.*

Firmware build environment:
- Arm GNU Toolchain *(arm-none-eabi)* [13.2.Rel1][URL-ARM]
- GCC/G++ [13.2.0][URL-GCC]
- CMake [3.30.2][URL-CMake]
- Raspberry Pi Pico SDK [1.5.1][URL-Pico-SDK]
  - Python [3.12.4][URL-Python]

Firmware development environment:
- OpenOCD *(built after commit 8af4d44; **0.12.0 does NOT work**)*
- Serial monitor *(example: [Serial Studio][URL-Serial-Studio])*
- VSCodium [1.85.2][URL-VSCodium] *(later versions break debugging)*
  - CMake Tools
    - CMake language server
  - clangd language server 
  - Cortex-Debug
    - debug-tracker-vscode
    - MemoryView
    - Peripheral Viewer
    - RTOS Views

PCB export & development environment:
- KiCad [8.0.4][URL-KiCad]



## Specific build/development environment setup

> *This section will be filled out in the future, but in the meantime similar steps can loosely be followed from:*  
> *https://gitlab.com/recursivenomad/capacitance-measurement-module/-/blob/main/BUILDING.md*



## Build processes

Firmware:
- In [`./firmware/CMakeLists.txt`](./firmware/CMakeLists.txt), update `pico_set_program_version()` appropriately
- From the repository root, call:
  ```bash
  mkdir -p ./firmware/build/ && cd $_
  cmake ..
  make
  ```
- The built firmware is in `./firmware/build/picoprobe_candybar.uf2`

Schematic:
- Open [`./pcb/picoprobe-candybar.kicad_sch`](./pcb/picoprobe-candybar.kicad_sch)
- Set revision number and date in title block, and save
- `File` > `Plot`
- Output Directory: `./build/`
- Output Format: **PDF**
- Options:
  - Page size: **Schematic size**
  - Plot drawing sheet: **Checked**
  - Output mode: **Color**
  - Color theme: **KiCad Default**
  - Plot background color: *Unchecked*
  - Minimum line width: `0.1254` mm
- PDF Options:
  - Generate property popups: *Unchecked*
- `Plot All Pages`
- The exported schematic is in `./pcb/build/picoprobe-candybar.pdf`



## Assembling a release

Releases will have 4 components (firmware, schematic, board files, and housings)

Each component will be available for download separately for convenience, and also as one .zip for completeness.

- From the repository root, call:
  ```bash
  mkdir -p ./releases/picoprobe-candybar_0.0.0/ && cd $_
  cp ../../firmware/build/picoprobe_candybar.uf2  picoprobe-candybar-firmware_0.0.0.uf2
  cp      ../../pcb/build/picoprobe-candybar.pdf  picoprobe-candybar-schematic_Rev0.pdf
  cp    ../../LICENSE.txt  LICENSE.txt
  cp      ../../README.md  README.txt
  cp ../../ATTRIBUTION.md  ATTRIBUTION.txt
  ```
  *(Replacing the version numbers above based on the revision/release)*

- Create `NOTICES.txt`, and include any license notices required by the build tools used.
  > *This can be a lot of work, and may vary depending on build tools used.*  
  > *My approach was a rough script that runs each gcc command from a `compile_commands.json` file generated by CMake, appending `-H -fsyntax-only -w`.*
  > *Then I can filter through that list and identify the license applied to each file touched by compilation.*  
  > *If no `#include` directives have changed since the latest release, and you are building with the exact same build tools as documented above, then you can reuse the list found in the latest release's `NOTICES.txt` for convenience.*

- Make any additional edits to `README.txt`, `ATTRIBUTION.txt`, or `LICENSE.txt` as needed.

Zip the contents of `./releases/picoprobe-candybar_0.0.0/` into an archive of the same name.

Upload the following files for release:
- `picoprobe-candybar_0.0.0.zip`
- `picoprobe-candybar-firmware_0.0.0.uf2`
- `picoprobe-candybar-schematic_Rev0.pdf`






[URL-ARM]: <https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads>
[URL-GCC]: <https://github.com/niXman/mingw-builds-binaries/releases/tag/13.2.0-rt_v11-rev1/>
[URL-CMake]: <https://github.com/Kitware/CMake/releases/tag/v3.30.2>
[URL-Pico-SDK]: <https://github.com/raspberrypi/pico-sdk/releases/tag/1.5.1>
[URL-Python]: <https://www.python.org/downloads/release/python-3124/>

[URL-Serial-Studio]: <https://github.com/Serial-Studio/Serial-Studio>
[URL-VSCodium]: <https://github.com/VSCodium/vscodium/releases/tag/1.85.2.24019>

[URL-KiCad]: <https://github.com/KiCad/kicad-source-mirror/releases/tag/8.0.4>

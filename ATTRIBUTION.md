# Picoprobe Candybar project attributions

&nbsp;






## Peter S. Hollander

Project created by Peter S. Hollander in 2024, and made freely available under your choice of the [*MIT-0*](./LICENSE.txt) license or [*CC0-1.0*][URL-CC0] public domain dedication.  
KiCad libraries created from 2022-2024 with the same permissions.

*Contact: <recursivenomad@protonmail.com>*  
*Repository: <https://gitlab.com/recursivenomad/picoprobe-candybar/>*



## Raspberry Pi

This project relies almost entirely on Raspberry Pi's [Debug Probe repository][URL-Debug-Probe] for its firmware source, which is incorporated into this project as a git submodule in the directory [`./firmware/lib/`](./firmware/lib/).

For achieving a feature superset of Raspberry Pi's [Debug Probe hardware][URL-Debug-Probe-Brief], documentation was acquired from Raspberry Pi for reference in 2024:

- [Raspberry Pi Pico datasheet (schematic)][URL-Pico-Schematic]
- [Raspberry Pi Pico 2 datasheet (schematic)][URL-Pico-2-Schematic]
- [Debug Probe documentation][URL-Debug-Probe-Docs]
  - [Debug Probe schematic][URL-Debug-Probe-Schematic]

Various aspects of the schematic layout were inspired by the Debug Probe schematic.

&nbsp;






> *Additional attributions specific to certain elements can be found at the following locations:*  
> `./pcb/project-libraries/ki-lime-pi-pico/ATTRIBUTION.md` ([local link](./pcb/project-libraries/ki-lime-pi-pico/ATTRIBUTION.md)) ([online link](https://github.com/recursivenomad/ki-lime-pi-to-go/blob/main/ATTRIBUTION.md))  
> `./pcb/project-libraries/picoprobe-candybar-interface/ATTRIBUTION.md` ([local link](./pcb/project-libraries/picoprobe-candybar-interface/ATTRIBUTION.md)) ([online link](https://gitlab.com/recursivenomad/picoprobe-candybar-interface/-/blob/main/ATTRIBUTION.md))

&nbsp;






# Tools utilized

- [KiCad][URL-KiCad] - Circuit design
- [VSCodium][URL-VSCodium] - Firmware composition
- [Raspberry Pi Pico SDK][URL-Pico-SDK]






[URL-MIT-0]: <https://opensource.org/license/mit-0/>
[URL-CC0]: <https://creativecommons.org/publicdomain/zero/1.0/>

[URL-Debug-Probe]: <https://github.com/raspberrypi/debugprobe/>
[URL-Debug-Probe-Brief]: <https://datasheets.raspberrypi.com/debug/raspberry-pi-debug-probe-product-brief.pdf>
[URL-Debug-Probe-Docs]: <https://www.raspberrypi.com/documentation/microcontrollers/debug-probe.html>
[URL-Debug-Probe-Schematic]: <https://datasheets.raspberrypi.com/debug/raspberry-pi-debug-probe-schematics.pdf>
[URL-Pico-Schematic]: <https://datasheets.raspberrypi.com/pico/pico-datasheet.pdf#pico-schematic>
[URL-Pico-2-Schematic]: <https://datasheets.raspberrypi.com/pico/pico-2-datasheet.pdf#schematic>

[URL-KiCad]: <https://www.kicad.org/>
[URL-VSCodium]: <https://vscodium.com/>
[URL-Pico-SDK]: <https://github.com/raspberrypi/pico-sdk>

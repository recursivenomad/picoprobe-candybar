🍫 **A charming debug probe using the Raspberry Pi Pico**
=========================================================

### With a custom breakout, interface, and enclosure for Raspberry Pi's [Debug Probe][URL-Debug-Probe] firmware


[![](../../../gitlab-redirect/raw/main/redirect.png)][URL-Repository]






***Features***
==============

Quick in-progress list:
- Logic level-shifting for interfacing with 5V/2.5V/1.8V boards (left switch)
- Power output selection (5V/none/3.3V) (right switch)
- 2 hardware interrupt breakpoints (rising & falling edge; left side pins)
- 9 pins wired for future implementation of a logic analyzer (3 analog, 3 logic level-shifted digital, 3 raw digital)
- Status LEDs (UART RX/TX, debug CONNECTED/RUNNING)
- Power rocker switch
- Debug access port for debugging with a second Picoprobe Candybar






***Cloning***
=============

```bash
git clone https://gitlab.com/recursivenomad/picoprobe-candybar.git
cd picoprobe-candybar/
git submodule update --init --single-branch
cd firmware/lib/debugprobe/
git config --local submodule.CMSIS_5.branch master
GIT_LFS_SKIP_SMUDGE=1 git submodule update --init --depth 1
git submodule foreach 'git fetch --depth 1'   # redundant, but gets the checked-out tag
cd ../../..
```

&nbsp;






***License / Access***
======================

This original work is freely available under your choice of the [*MIT-0*](./LICENSE.txt) license or [*CC0-1.0*][URL-CC0] public domain dedication.  
Although attribution is not required, sharing when you've made something with my work is really cool 💖

<details> <summary> <b><i>This work as a whole contains greater source code restrictions, fully listed here:</i></b> </summary>

  > Importing the [Debug Probe](https://github.com/raspberrypi/debugprobe/tree/debugprobe-v2.0.1/) submodule from Raspberry Pi introduces the following restrictions:  
  > *Linked to in [`./firmware/lib/`](./firmware/lib/)*
  >   - [*MIT License*][URL-MIT]
  >   - [*3-Clause BSD License*][URL-BSD-3-Clause]
  >   - [*Apache License, Version 2.0*][URL-Apache-2.0]
  >
  > Binaries are built using the [Pico SDK][URL-Pico-SDK] and [Arm GNU Toolchain][URL-ARM-Toolchain], and will add the following notices for distribution:
  >   - [*GCC Runtime Library Exception*][URL-GCC-Exception]
  >   - [*SunPro License*][URL-SunPro]
  >   - [*OAR License*][URL-OAR]
  >   - [*BSD 4.3 TAHOE License*][URL-BSD-4.3TAHOE]
  >   - [*Martin Birgmeier License*][URL-Martin-Birgmeier]

</details>

----------------------

*Repository: <https://gitlab.com/recursivenomad/picoprobe-candybar/>*  
*Contact: <recursivenomad@protonmail.com>*

----------------------






[URL-MIT-0]: <https://opensource.org/license/mit-0/>
[URL-CC0]: <https://creativecommons.org/publicdomain/zero/1.0/>

[URL-MIT]: <https://opensource.org/license/mit>
[URL-BSD-3-Clause]: <https://opensource.org/license/bsd-3-clause>
[URL-Apache-2.0]: <https://opensource.org/license/apache-2-0>

[URL-GCC-Exception]: <https://www.gnu.org/licenses/gcc-exception-3.0.en.html>
[URL-SunPro]: <https://spdx.org/licenses/SunPro.html>
[URL-OAR]: <https://spdx.org/licenses/OAR.html>
[URL-BSD-4.3TAHOE]: <https://spdx.org/licenses/BSD-4.3TAHOE.html>
[URL-Martin-Birgmeier]: <https://spdx.org/licenses/Martin-Birgmeier.html>


[URL-Repository]: <https://gitlab.com/recursivenomad/picoprobe-candybar/>

[URL-ARM-Toolchain]: <https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain>
[URL-Debug-Probe]: <https://github.com/raspberrypi/debugprobe/>
[URL-Pico-SDK]: <https://github.com/raspberrypi/pico-sdk>

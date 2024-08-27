# UEFI for NVIDIA Jetson

This repository contains sources necessary to build UEFI for NVIDIA Jetson.
UEFI for NVIDIA Jetson is based on [EDK2](https://github.com/tianocore/edk2).

See the [wiki](https://github.com/NVIDIA/edk2-nvidia/wiki) for more
information, including build and flash instructions.

# About custom Splash screen

The reeplaced splash screen images should be 24 bit BMP Image with the following weights.

* 6220854 bytes for 1080p
* 2764854 bytes for 720p
* 921654  bytes for 480p

The total uefi_jetson.bin image size should not exceed the 3.5 MB configured in partitions xml file.
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

Default uefi_jetson.bin for JL35.5 is 2818048 bytes

# Build the project

This repository only contains the modifications done to de EDK2-Nvidia by Plantium. You need to pull several repositories to compile the UEFI.
[Build information by NVIDIA](https://github.com/NVIDIA/edk2-nvidia/wiki/Build-with-docker)

```
# Point to the Ubuntu-22 dev image
export EDK2_DEV_IMAGE="ghcr.io/tianocore/containers/ubuntu-22-dev:latest"

# Required
export EDK2_USER_ARGS="-v \"${HOME}\":\"${HOME}\" -e EDK2_DOCKER_USER_HOME=\"${HOME}\""

# Required, unless you want to build in your home directory.
# Change "/build" to be a suitable build root on your system.
export EDK2_BUILD_ROOT="/build"
export EDK2_BUILDROOT_ARGS="-v \"${EDK2_BUILD_ROOT}\":\"${EDK2_BUILD_ROOT}\""

# Create the alias
alias edk2_docker="docker run -it --rm -w \"\$(pwd)\" ${EDK2_BUILDROOT_ARGS} ${EDK2_USER_ARGS} \"${EDK2_DEV_IMAGE}\""

# Test the docker to pull the image
edk2_docker echo hello

#Configure the repository
edk2_docker init_edkrepo_conf
edk2_docker edkrepo manifest-repos add nvidia https://github.com/NVIDIA/edk2-edkrepo-manifest.git main nvidia

# Create workspace
mkdir workspace
cd /workspace
# The last is the tag for the version of Jetson Linux. 
edk2_docker edkrepo clone nvidia-uefi NVIDIA-Platforms r35.5.0 

# You should paste the contents of this folder in the edk2-nvidia inside of your workspace!!!
cd nvidia-uefi
cp -r Platform edk2-nvidia
cp -r Silicon edk2-nvidia

# Build UEFI
edk2_docker edk2-nvidia/Platform/NVIDIA/Jetson/build.sh
```

/** @file
*
*  Copyright (c) 2022-2023, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#ifndef __FLOOR_SWEEPING_INTERNAL_LIB_H__
#define __FLOOR_SWEEPING_INTERNAL_LIB_H__

#include <Uefi/UefiBaseType.h>

/**
  Get CPU info for a platform

**/
BOOLEAN
EFIAPI
GetCpuInfoInternal (
  IN  UINT32  SocketMask,
  IN  UINTN   MaxSupportedCores,
  OUT UINT64  *EnabledCoresBitMap
  );

/**
  Floorsweep DTB

**/
BOOLEAN
EFIAPI
FloorSweepDtbInternal (
  IN  UINT32  SocketMask,
  IN  VOID    *Dtb
  );

BOOLEAN
EFIAPI
CheckAndRemapCpuInternal (
  IN UINT32       LogicalCore,
  IN OUT UINT64   *Mpidr,
  OUT EFI_STATUS  *Status
  );

#endif //__FLOOR_SWEEPING_INTERNAL_LIB_H__

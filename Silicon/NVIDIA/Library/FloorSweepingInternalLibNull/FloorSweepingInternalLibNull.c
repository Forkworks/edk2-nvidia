/** @file
*
*  Copyright (c) 2022-2023, NVIDIA CORPORATION & AFFILIATES. All rights reserved.
*
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include <Library/FloorSweepingInternalLib.h>

/**
  Get CPU info for a platform

**/
BOOLEAN
EFIAPI
GetCpuInfoInternal (
  IN  UINT32  SocketMask,
  IN  UINTN   MaxSupportedCores,
  OUT UINT64  *EnabledCoresBitMap
  )
{
  return FALSE;
}

/**
  Floorsweep DTB

**/
BOOLEAN
EFIAPI
FloorSweepDtbInternal (
  IN  UINT32  SocketMask,
  IN  VOID    *Dtb
  )
{
  return FALSE;
}

BOOLEAN
EFIAPI
CheckAndRemapCpuInternal (
  IN UINT32       LogicalCore,
  IN OUT UINT64   *Mpidr,
  OUT EFI_STATUS  *Status
  )
{
  return FALSE;
}

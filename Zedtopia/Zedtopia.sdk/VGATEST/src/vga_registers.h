#ifndef VGA_REGISTERS_H_
#define VGA_REGISTERS_H_

#include <stdint.h>

volatile uint32_t * vga_registers_pntr_t;

//Register Byte Offsets

#define VGA_REGISTERS_SYSID 0x00000000
#define VGA_REGISTERS_IFID 0x00000004
#define VGA_REGISTERS_REVID 0x00000008
#define VGA_REGISTERS_WRAPBACK 0x0000000C
#define VGA_REGISTERS_KEYLABEL 0x00000010
#define VGA_REGISTERS_KEYCTRL 0x00000014
#define VGA_REGISTERS_KEYSIZE 0x00000018
#define VGA_REGISTERS_KEYREMAIN 0x0000001C
#define VGA_REGISTERS_KEYSTATUS 0x00000020
#define VGA_REGISTERS_KEYACTIVE 0x00000024
#define VGA_REGISTERS_VIDEOPTR 0x00000030
#define VGA_REGISTERS_VIDEOCTRL 0x00000034
#define VGA_REGISTERS_VIDEOX 0x00000038
#define VGA_REGISTERS_VIDEOY 0x0000003C
#define VGA_REGISTERS_SCREENX 0x00000040
#define VGA_REGISTERS_SCREENY 0x00000044
#define VGA_REGISTERS_SCREENOFSX 0x00000048
#define VGA_REGISTERS_SCREENOFSY 0x0000004C


//Bitfield Structures

struct vga_registers_SYSID_s {
  uint32_t systemID_f : 32;
};

union union_vga_registers_SYSID {
  struct vga_registers_SYSID_s __SYSID;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_SYSID vga_registers_SYSID_t;


struct vga_registers_IFID_s {
  uint32_t interfaceID_f : 32;
};

union union_vga_registers_IFID {
  struct vga_registers_IFID_s __IFID;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_IFID vga_registers_IFID_t;


struct vga_registers_REVID_s {
  uint32_t class_f : 7;
  uint32_t year_f : 11;
  uint32_t month_f : 4;
  uint32_t day_f : 5;
  uint32_t hour_f : 5;
};

union union_vga_registers_REVID {
  struct vga_registers_REVID_s __REVID;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_REVID vga_registers_REVID_t;


struct vga_registers_WRAPBACK_s {
  uint32_t wrapData_f : 32;
};

union union_vga_registers_WRAPBACK {
  struct vga_registers_WRAPBACK_s __WRAPBACK;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_WRAPBACK vga_registers_WRAPBACK_t;


struct vga_registers_KEYLABEL_s {
  uint32_t keyLabel_f : 32;
};

union union_vga_registers_KEYLABEL {
  struct vga_registers_KEYLABEL_s __KEYLABEL;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_KEYLABEL vga_registers_KEYLABEL_t;


struct vga_registers_KEYCTRL_s {
  uint32_t reserved00_f : 31;
  uint32_t acquire_f : 1;
};

union union_vga_registers_KEYCTRL {
  struct vga_registers_KEYCTRL_s __KEYCTRL;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_KEYCTRL vga_registers_KEYCTRL_t;


struct vga_registers_KEYSIZE_s {
  uint32_t lblSize_f : 32;
};

union union_vga_registers_KEYSIZE {
  struct vga_registers_KEYSIZE_s __KEYSIZE;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_KEYSIZE vga_registers_KEYSIZE_t;


struct vga_registers_KEYREMAIN_s {
  uint32_t lblRemain_f : 32;
};

union union_vga_registers_KEYREMAIN {
  struct vga_registers_KEYREMAIN_s __KEYREMAIN;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_KEYREMAIN vga_registers_KEYREMAIN_t;


struct vga_registers_KEYSTATUS_s {
  uint32_t reserved00_f : 31;
  uint32_t lblActive_f : 1;
};

union union_vga_registers_KEYSTATUS {
  struct vga_registers_KEYSTATUS_s __KEYSTATUS;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_KEYSTATUS vga_registers_KEYSTATUS_t;


struct vga_registers_KEYACTIVE_s {
  uint32_t lastLbl_f : 32;
};

union union_vga_registers_KEYACTIVE {
  struct vga_registers_KEYACTIVE_s __KEYACTIVE;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_KEYACTIVE vga_registers_KEYACTIVE_t;


struct vga_registers_VIDEOPTR_s {
  uint32_t ptr_f : 32;
};

union union_vga_registers_VIDEOPTR {
  struct vga_registers_VIDEOPTR_s __VIDEOPTR;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_VIDEOPTR vga_registers_VIDEOPTR_t;


struct vga_registers_VIDEOCTRL_s {
  uint32_t rst_f : 1;
  uint32_t reserved00_f : 30;
  uint32_t ena_f : 1;
};

union union_vga_registers_VIDEOCTRL {
  struct vga_registers_VIDEOCTRL_s __VIDEOCTRL;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_VIDEOCTRL vga_registers_VIDEOCTRL_t;


struct vga_registers_VIDEOX_s {
  uint32_t reserved00_f : 16;
  uint32_t xSize_f : 16;
};

union union_vga_registers_VIDEOX {
  struct vga_registers_VIDEOX_s __VIDEOX;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_VIDEOX vga_registers_VIDEOX_t;


struct vga_registers_VIDEOY_s {
  uint32_t reserved00_f : 16;
  uint32_t ySize_f : 16;
};

union union_vga_registers_VIDEOY {
  struct vga_registers_VIDEOY_s __VIDEOY;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_VIDEOY vga_registers_VIDEOY_t;


struct vga_registers_SCREENX_s {
  uint32_t reserved00_f : 16;
  uint32_t xSize_f : 16;
};

union union_vga_registers_SCREENX {
  struct vga_registers_SCREENX_s __SCREENX;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_SCREENX vga_registers_SCREENX_t;


struct vga_registers_SCREENY_s {
  uint32_t reserved00_f : 16;
  uint32_t ySize_f : 16;
};

union union_vga_registers_SCREENY {
  struct vga_registers_SCREENY_s __SCREENY;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_SCREENY vga_registers_SCREENY_t;


struct vga_registers_SCREENOFSX_s {
  uint32_t reserved00_f : 16;
  uint32_t ofsX_f : 16;
};

union union_vga_registers_SCREENOFSX {
  struct vga_registers_SCREENOFSX_s __SCREENOFSX;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_SCREENOFSX vga_registers_SCREENOFSX_t;


struct vga_registers_SCREENOFSY_s {
  uint32_t reserved00_f : 16;
  uint32_t ofsY_f : 16;
};

union union_vga_registers_SCREENOFSY {
  struct vga_registers_SCREENOFSY_s __SCREENOFSY;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_vga_registers_SCREENOFSY vga_registers_SCREENOFSY_t;


//Macros

#define vga_registers(var,regname,field) (var.regname_s.field_f)


#endif

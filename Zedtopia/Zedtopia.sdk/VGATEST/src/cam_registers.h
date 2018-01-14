#ifndef CAM_REGISTERS_H_
#define CAM_REGISTERS_H_

#include <stdint.h>

volatile uint32_t * cam_registers_pntr_t;

//Register Byte Offsets

#define CAM_REGISTERS_SYSID 0x00000000
#define CAM_REGISTERS_IFID 0x00000004
#define CAM_REGISTERS_REVID 0x00000008
#define CAM_REGISTERS_WRAPBACK 0x0000000C
#define CAM_REGISTERS_KEYLABEL 0x00000010
#define CAM_REGISTERS_KEYCTRL 0x00000014
#define CAM_REGISTERS_KEYSIZE 0x00000018
#define CAM_REGISTERS_KEYREMAIN 0x0000001C
#define CAM_REGISTERS_KEYSTATUS 0x00000020
#define CAM_REGISTERS_KEYACTIVE 0x00000024
#define CAM_REGISTERS_VIDEOPTR 0x00000030
#define CAM_REGISTERS_VIDEOCTRL 0x00000034
#define CAM_REGISTERS_VIDEOX 0x00000038
#define CAM_REGISTERS_VIDEOY 0x0000003C
#define CAM_REGISTERS_CAMERAX 0x00000040
#define CAM_REGISTERS_CAMERAY 0x00000044
#define CAM_REGISTERS_CAMERAOFSX 0x00000048
#define CAM_REGISTERS_CAMERAOFSY 0x0000004C
#define CAM_REGISTERS_TWIDEVICE 0x00000100
#define CAM_REGISTERS_TWIREGISTER 0x00000104
#define CAM_REGISTERS_TWIWDATA 0x00000108
#define CAM_REGISTERS_TWIRREQ 0x0000010C
#define CAM_REGISTERS_TWIRDATA 0x00000110
#define CAM_REGISTERS_TWISTATUS 0x00000114


//Bitfield Structures

struct cam_registers_SYSID_s {
  uint32_t systemID_f : 32;
};

union union_cam_registers_SYSID {
  struct cam_registers_SYSID_s __SYSID;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_SYSID cam_registers_SYSID_t;


struct cam_registers_IFID_s {
  uint32_t interfaceID_f : 32;
};

union union_cam_registers_IFID {
  struct cam_registers_IFID_s __IFID;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_IFID cam_registers_IFID_t;


struct cam_registers_REVID_s {
  uint32_t class_f : 7;
  uint32_t year_f : 11;
  uint32_t month_f : 4;
  uint32_t day_f : 5;
  uint32_t hour_f : 5;
};

union union_cam_registers_REVID {
  struct cam_registers_REVID_s __REVID;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_REVID cam_registers_REVID_t;


struct cam_registers_WRAPBACK_s {
  uint32_t wrapData_f : 32;
};

union union_cam_registers_WRAPBACK {
  struct cam_registers_WRAPBACK_s __WRAPBACK;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_WRAPBACK cam_registers_WRAPBACK_t;


struct cam_registers_KEYLABEL_s {
  uint32_t keyLabel_f : 32;
};

union union_cam_registers_KEYLABEL {
  struct cam_registers_KEYLABEL_s __KEYLABEL;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_KEYLABEL cam_registers_KEYLABEL_t;


struct cam_registers_KEYCTRL_s {
  uint32_t reserved00_f : 31;
  uint32_t acquire_f : 1;
};

union union_cam_registers_KEYCTRL {
  struct cam_registers_KEYCTRL_s __KEYCTRL;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_KEYCTRL cam_registers_KEYCTRL_t;


struct cam_registers_KEYSIZE_s {
  uint32_t lblSize_f : 32;
};

union union_cam_registers_KEYSIZE {
  struct cam_registers_KEYSIZE_s __KEYSIZE;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_KEYSIZE cam_registers_KEYSIZE_t;


struct cam_registers_KEYREMAIN_s {
  uint32_t lblRemain_f : 32;
};

union union_cam_registers_KEYREMAIN {
  struct cam_registers_KEYREMAIN_s __KEYREMAIN;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_KEYREMAIN cam_registers_KEYREMAIN_t;


struct cam_registers_KEYSTATUS_s {
  uint32_t reserved00_f : 31;
  uint32_t lblActive_f : 1;
};

union union_cam_registers_KEYSTATUS {
  struct cam_registers_KEYSTATUS_s __KEYSTATUS;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_KEYSTATUS cam_registers_KEYSTATUS_t;


struct cam_registers_KEYACTIVE_s {
  uint32_t lastLbl_f : 32;
};

union union_cam_registers_KEYACTIVE {
  struct cam_registers_KEYACTIVE_s __KEYACTIVE;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_KEYACTIVE cam_registers_KEYACTIVE_t;


struct cam_registers_VIDEOPTR_s {
  uint32_t ptr_f : 32;
};

union union_cam_registers_VIDEOPTR {
  struct cam_registers_VIDEOPTR_s __VIDEOPTR;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_VIDEOPTR cam_registers_VIDEOPTR_t;


struct cam_registers_VIDEOCTRL_s {
  uint32_t reserved00_f : 31;
  uint32_t ena_f : 1;
};

union union_cam_registers_VIDEOCTRL {
  struct cam_registers_VIDEOCTRL_s __VIDEOCTRL;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_VIDEOCTRL cam_registers_VIDEOCTRL_t;


struct cam_registers_VIDEOX_s {
  uint32_t reserved00_f : 16;
  uint32_t xSize_f : 16;
};

union union_cam_registers_VIDEOX {
  struct cam_registers_VIDEOX_s __VIDEOX;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_VIDEOX cam_registers_VIDEOX_t;


struct cam_registers_VIDEOY_s {
  uint32_t reserved00_f : 16;
  uint32_t ySize_f : 16;
};

union union_cam_registers_VIDEOY {
  struct cam_registers_VIDEOY_s __VIDEOY;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_VIDEOY cam_registers_VIDEOY_t;


struct cam_registers_CAMERAX_s {
  uint32_t reserved00_f : 16;
  uint32_t xSize_f : 16;
};

union union_cam_registers_CAMERAX {
  struct cam_registers_CAMERAX_s __CAMERAX;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_CAMERAX cam_registers_CAMERAX_t;


struct cam_registers_CAMERAY_s {
  uint32_t reserved00_f : 16;
  uint32_t ySize_f : 16;
};

union union_cam_registers_CAMERAY {
  struct cam_registers_CAMERAY_s __CAMERAY;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_CAMERAY cam_registers_CAMERAY_t;


struct cam_registers_CAMERAOFSX_s {
  uint32_t reserved00_f : 16;
  uint32_t ofsX_f : 16;
};

union union_cam_registers_CAMERAOFSX {
  struct cam_registers_CAMERAOFSX_s __CAMERAOFSX;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_CAMERAOFSX cam_registers_CAMERAOFSX_t;


struct cam_registers_CAMERAOFSY_s {
  uint32_t reserved00_f : 16;
  uint32_t ofsY_f : 16;
};

union union_cam_registers_CAMERAOFSY {
  struct cam_registers_CAMERAOFSY_s __CAMERAOFSY;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_CAMERAOFSY cam_registers_CAMERAOFSY_t;


struct cam_registers_TWIDEVICE_s {
  uint32_t reserved00_f : 25;
  uint32_t addr_f : 7;
};

union union_cam_registers_TWIDEVICE {
  struct cam_registers_TWIDEVICE_s __TWIDEVICE;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_TWIDEVICE cam_registers_TWIDEVICE_t;


struct cam_registers_TWIREGISTER_s {
  uint32_t reserved00_f : 24;
  uint32_t camreg_f : 8;
};

union union_cam_registers_TWIREGISTER {
  struct cam_registers_TWIREGISTER_s __TWIREGISTER;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_TWIREGISTER cam_registers_TWIREGISTER_t;


struct cam_registers_TWIWDATA_s {
  uint32_t reserved00_f : 24;
  uint32_t wrdata_f : 8;
};

union union_cam_registers_TWIWDATA {
  struct cam_registers_TWIWDATA_s __TWIWDATA;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_TWIWDATA cam_registers_TWIWDATA_t;


struct cam_registers_TWIRREQ_s {
  uint32_t reserved00_f : 31;
  uint32_t req_f : 1;
};

union union_cam_registers_TWIRREQ {
  struct cam_registers_TWIRREQ_s __TWIRREQ;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_TWIRREQ cam_registers_TWIRREQ_t;


struct cam_registers_TWIRDATA_s {
  uint32_t reserved00_f : 24;
  uint32_t rddata_f : 8;
};

union union_cam_registers_TWIRDATA {
  struct cam_registers_TWIRDATA_s __TWIRDATA;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_TWIRDATA cam_registers_TWIRDATA_t;


struct cam_registers_TWISTATUS_s {
  uint32_t reserved00_f : 25;
  uint32_t wbusy_f : 1;
  uint32_t wstat_f : 2;
  uint32_t reserved01_f : 1;
  uint32_t rbusy_f : 1;
  uint32_t rstat_f : 2;
};

union union_cam_registers_TWISTATUS {
  struct cam_registers_TWISTATUS_s __TWISTATUS;
  uint8_t  byte[4];
  uint16_t word[2];
  uint32_t dword;
};

typedef union union_cam_registers_TWISTATUS cam_registers_TWISTATUS_t;


//Macros

#define cam_registers(var,regname,field) (var.regname_s.field_f)


#endif

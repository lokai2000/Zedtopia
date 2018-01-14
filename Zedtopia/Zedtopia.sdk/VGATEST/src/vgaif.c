#include "vga_registers.h"
#include "vgaif.h"
#include "xil_types.h"
#include "sleep.h"


void assign_vgaif_target_dma(void *vgaPtr, void *memPtr){
	vgaPtr_t ptr = (vgaPtr_t *)(vgaPtr);
    ptr[VGA_REGISTERS_VIDEOPTR/4] = (unsigned int)(memPtr);
}


void enable_vgaif(void *vgaPtr){
	vgaPtr_t ptr = (vgaPtr_t *)(vgaPtr);
	ptr[VGA_REGISTERS_VIDEOCTRL/4] = 0x1;
}

void disable_vgaif(void *vgaPtr){
	vgaPtr_t ptr = (vgaPtr_t *)(vgaPtr);
	ptr[VGA_REGISTERS_VIDEOCTRL/4] = 0x0;
}


void reset_vgaif(void *vgaPtr){
	vgaPtr_t ptr = (vgaPtr_t *)(vgaPtr);
	ptr[VGA_REGISTERS_VIDEOCTRL/4] = 0x80000000;
	usleep(100);
}


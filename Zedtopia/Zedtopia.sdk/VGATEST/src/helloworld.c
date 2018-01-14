/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <malloc.h>
#include <stdint.h>
#include "sleep.h"

#include "xparameters.h"

#include "cam_registers.h"
#include "camif.h"

#include "vga_registers.h"
#include "vgaif.h"


volatile uint32_t *vgaptr = (volatile uint32_t *)(XPAR_VGAIF_1_BASEADDR);
volatile uint32_t *camptr = (volatile uint32_t *)(XPAR_CAMIF_0_BASEADDR);

volatile uint32_t *memptr;

int main()
{
	unsigned int val;

	short int camData;

    init_platform();

    reset_vgaif((void *)vgaptr);

    print("Hello World\n\r");

    memptr = (volatile uint32_t *) malloc(sizeof(unsigned int)*2048*2048);

    assign_vgaif_target_dma((void *)vgaptr,(void *)memptr);
    assign_camif_target_dma((void *)camptr,(void *)memptr);

    enable_vgaif((void *)vgaptr);
    enable_camif((void *)camptr);

    //Set both contexts to enable binning and the 2-ADC mode.
    //The border appears to be required.  Things go bad if disabled.
    camif_write_i2c_register((void *)camptr, 0x20, 0x8300);
    camif_write_i2c_register((void *)camptr, 0x20, 0x8300);


    //Disable MT9D111 image processor
    //Set page 1
    camif_write_i2c_register((void *)camptr, 0xF0, 0x1);
    //Select and clear variable
    camif_write_i2c_register((void *)camptr, 0xC6, 0xA102);
    camif_write_i2c_register((void *)camptr, 0xC8, 0x0000);

    //shorten the default integration time to increase frame rate
    //select page 0
    camif_write_i2c_register((void *)camptr, 0xF0, 0x0);
    //set integration time
    camif_write_i2c_register((void *)camptr, 0x09, 0x0100);

    //camData = camif_read_i2c_register((void *)camptr, 0x2B);
    //camData = camif_read_i2c_register((void *)camptr, 0x2C);
    //camData = camif_read_i2c_register((void *)camptr, 0x2D);
    //camData = camif_read_i2c_register((void *)camptr, 0x2E);
    //camif_write_i2c_register((void *)camptr, 0x2F, 0x00D0);


    //Quality is not as good but speed is much much better.
    camif_write_i2c_register((void *)camptr, 0x2B, 0x03D0);
    camif_write_i2c_register((void *)camptr, 0x2C, 0x03FD);
    camif_write_i2c_register((void *)camptr, 0x2D, 0x03D0);
    camif_write_i2c_register((void *)camptr, 0x2E, 0x03D0);


    //camif_write_i2c_register((void *)camptr, 0x09, 0x04D0);

    //camData = camif_read_i2c_register((void *)camptr, 0x09);
    //camData = camif_read_i2c_register((void *)camptr, 0x0C);



    //camif_write_i2c_register((void *)camptr, 0x09, 0x0AD0);
    //camif_write_i2c_register((void *)camptr, 0x09, 0x04D0);

    disable_vgaif((void *)vgaptr);
    disable_camif((void *)vgaptr);


    cleanup_platform();
    free(memptr);
    return 0;
}

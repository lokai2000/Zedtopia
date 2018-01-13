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
#include "xil_cache.h"

#include "xparameters.h"
#include "cam_registers.h"

#include "camif.h"


volatile unsigned int* vgaptr = (volatile unsigned int *)(XPAR_VGAIF_1_BASEADDR);
volatile unsigned int* camptr = (volatile unsigned int *)(XPAR_CAMIF_0_BASEADDR);



volatile unsigned int* memptr;


int main()
{
	unsigned int val;
	unsigned int X;
	unsigned int Y;

	short int camData;

    init_platform();

    print("Hello World\n\r");

    memptr = (volatile unsigned int*) malloc(sizeof(unsigned int)*2048*2048);

    val = camptr[CAM_REGISTERS_TWIDEVICE/4];


    camData = camif_read_i2c_register(camptr, 0x00);
    camData = camif_read_i2c_register(camptr, 0xF0);
    camData = camif_read_i2c_register(camptr, 0x26);

    val = vgaptr[0];
    val = vgaptr[1];
    val = vgaptr[2];
    val = vgaptr[3];
    vgaptr[3] = 0xDEADBEEF;
    val = vgaptr[3];

    val = vgaptr[14];
    val = vgaptr[15];
    val = vgaptr[16];
    val = vgaptr[17];

    vgaptr[12] = memptr;
    val = vgaptr[12];
    vgaptr[13] = 0x80000000;
    print("Delay");
    val = vgaptr[12];
    vgaptr[12] = memptr;
    val = vgaptr[12];

    camptr[12] = memptr;
    val = camptr[12];


    vgaptr[13] = 0x1;
    val = vgaptr[13];
    camptr[13] = 0x1;
    val = camptr[13];

    //Break here as the next section shuts off the VGA.

    vgaptr[13] = 0x0;
    val = vgaptr[13];
    camptr[13] = 0x0;
    val = camptr[13];


    cleanup_platform();
    free(memptr);
    return 0;
}

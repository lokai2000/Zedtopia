/*
 * camif.c
 *
 *  Created on: Jan 5, 2018
 *      Author: max
 */

#include "cam_registers.h"
#include "camif.h"
#include "xil_types.h"

/*
    camptr[65] = 0x00;
    camptr[67] = 0x01;
    print("Waiting\n\r");
    val = camptr[69];
    val = camptr[68];

    camptr[65] = 0xF1;
    camptr[67] = 0x01;
    print("Waiting\n\r");
    val = camptr[69];
    val = camptr[68];
*/

uint16_t camif_read_i2c_register(void *camPtr, uint8_t reg){

	camPtr_t ptr = (camPtr_t *)(camPtr);
	uint16_t retVal;
	uint32_t readVal;

	ptr[CAM_REGISTERS_TWIREGISTER/4] = reg;
	ptr[CAM_REGISTERS_TWIRREQ/4] = 1;

	do{
		readVal = ptr[CAM_REGISTERS_TWISTATUS/4] & 0x4;
	} while (readVal);

	readVal = ptr[CAM_REGISTERS_TWIRDATA/4];
	retVal = readVal << 8;

	ptr[CAM_REGISTERS_TWIREGISTER/4] = 0xF1;
	ptr[CAM_REGISTERS_TWIRREQ/4] = 1;

	do{
		readVal = ptr[CAM_REGISTERS_TWISTATUS/4] & 0x4;
	} while (readVal);

	readVal = ptr[CAM_REGISTERS_TWIRDATA/4];
	retVal |= readVal;

	return retVal;
}

void camif_write_i2c_register(void *camPtr, uint8_t reg, uint16_t val){

	camPtr_t ptr = (camPtr_t *)(camPtr);
	uint8_t  writeVal;
	uint32_t readVal;

	writeVal = val >> 8;

	ptr[CAM_REGISTERS_TWIREGISTER/4] = reg;
	ptr[CAM_REGISTERS_TWIWDATA/4] = writeVal;

	do{
		readVal = ptr[CAM_REGISTERS_TWISTATUS/4] & 0x40;
	} while (readVal);

	writeVal = val & 0xFF;

	ptr[CAM_REGISTERS_TWIREGISTER/4] = 0xF1;
	ptr[CAM_REGISTERS_TWIWDATA/4] = writeVal;

	do{
		readVal = ptr[CAM_REGISTERS_TWISTATUS/4] & 0x40;
	} while (readVal);

}




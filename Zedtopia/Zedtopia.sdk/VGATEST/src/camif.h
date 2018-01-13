/*
 * camif.h
 *
 *  Created on: Jan 5, 2018
 *      Author: max
 */

#ifndef SRC_CAMIF_H_
#define SRC_CAMIF_H_


#include <stdint.h>

uint16_t camif_read_i2c_register(void *, uint8_t);
void camif_write_i2c_register(void *, uint8_t, uint16_t);

typedef volatile unsigned int *  camPtr_t ;



#endif /* SRC_CAMIF_H_ */

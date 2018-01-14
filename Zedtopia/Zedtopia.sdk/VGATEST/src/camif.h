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
void enable_camif(void *);
void disable_camif(void *);
void assign_camif_target_dma(void *, void *);

typedef volatile uint32_t *  camPtr_t;



#endif /* SRC_CAMIF_H_ */

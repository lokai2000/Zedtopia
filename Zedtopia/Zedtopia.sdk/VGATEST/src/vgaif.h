#ifndef SRC_VGAIF_H_
#define SRC_VGAIF_H_

#include <stdint.h>

void enable_vgaif(void *);
void disable_vgaif(void *);
void assign_vgaif_target_dma(void *, void *);
void reset_vgaif(void *);

typedef volatile uint32_t *  vgaPtr_t;


#endif /* SRC_VGAIF_H_ */

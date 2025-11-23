#ifndef _CIRCULARBUFFER_H
#define _CIRCULARBUFFER_H

#include <stdint.h>
#include <stdbool.h>

void CircularBuffer_Create(uint8_t zero_value);
bool CircularBuffer_Put(uint8_t value);
uint8_t CircularBuffer_Get(void);

#endif
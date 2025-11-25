#ifndef _CIRCULARBUFFER_H
#define _CIRCULARBUFFER_H

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1

void CircularBuffer_Create(uint8_t zero_value);
bool CircularBuffer_Put(uint8_t value);
uint8_t CircularBuffer_Get(void);
uint8_t CircularBuffer_GetTotalSize(void);
uint8_t CircularBuffer_GetSize(void);

#endif
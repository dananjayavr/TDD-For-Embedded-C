#include "CircularBuffer.h"

uint8_t buffer[BUFFER_SIZE] = {0};
uint8_t write = 0;
uint8_t read = 0;

void CircularBuffer_Create(uint8_t zero_value) {
    memset(buffer,zero_value,BUFFER_SIZE);
}
bool CircularBuffer_Put(uint8_t value) {
    buffer[write] = value;
    write += 1;
    return true;
}
uint8_t CircularBuffer_Get(void) {
    uint8_t value = buffer[read];
    read += 1;
    
    return value;
}
uint8_t CircularBuffer_GetTotalSize(void) {
    return BUFFER_SIZE;
}

uint8_t CircularBuffer_GetSize(void) {
    return 1;
}
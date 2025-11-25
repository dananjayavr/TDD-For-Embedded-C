#ifndef _RUNTIME_ERROR_STUB_H
#define _RUNTIME_ERROR_STUB_H

#include "RuntimeError.h"

void RuntimeError_Stub_Reset(void);
const char *RuntimeError_Stub_GetLastError(void);
int RuntimeError_Stub_GetLastParameter(void);

#endif

/***********************************************************************************************************************************
Buffer Handler
***********************************************************************************************************************************/
#ifndef COMMON_TYPE_BUFFER_H
#define COMMON_TYPE_BUFFER_H

/***********************************************************************************************************************************
Buffer object
***********************************************************************************************************************************/
typedef struct Buffer Buffer;

#include "common/memContext.h"
#include "common/type/string.h"

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
Buffer *bufNew(size_t size);
Buffer *bufNewC(size_t size, const void *buffer);
Buffer *bufNewStr(const String *string);
Buffer *bufNewZ(const char *string);

Buffer *bufCat(Buffer *this, const Buffer *cat);
Buffer *bufCatC(Buffer *this, const unsigned char *cat, size_t catOffset, size_t catSize);
Buffer *bufCatSub(Buffer *this, const Buffer *cat, size_t catOffset, size_t catSize);
bool bufEq(const Buffer *this, const Buffer *compare);
String *bufHex(const Buffer *this);
Buffer *bufMove(Buffer *this, MemContext *parentNew);
Buffer *bufResize(Buffer *this, size_t size);

bool bufFull(const Buffer *this);
void bufLimitClear(Buffer *this);
void bufLimitSet(Buffer *this, size_t limit);
unsigned char *bufPtr(const Buffer *this);
size_t bufRemains(const Buffer *this);
unsigned char *bufRemainsPtr(const Buffer *this);
size_t bufSize(const Buffer *this);
size_t bufUsed(const Buffer *this);
void bufUsedInc(Buffer *this, size_t inc);
void bufUsedSet(Buffer *this, size_t used);
void bufUsedZero(Buffer *this);

void bufFree(Buffer *this);

/***********************************************************************************************************************************
Macros for function logging
***********************************************************************************************************************************/
String *bufToLog(const Buffer *this);

#define FUNCTION_LOG_BUFFER_TYPE                                                                                                   \
    Buffer *
#define FUNCTION_LOG_BUFFER_FORMAT(value, buffer, bufferSize)                                                                      \
    FUNCTION_LOG_STRING_OBJECT_FORMAT(value, bufToLog, buffer, bufferSize)

#endif

/***********************************************************************************************************************************
Restore File
***********************************************************************************************************************************/
#ifndef COMMAND_RESTORE_FILE_H
#define COMMAND_RESTORE_FILE_H

#include "common/crypto/common.h"
#include "common/type/string.h"
#include "storage/storage.h"

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
bool restoreFile(
    const String *repoFile, const String *repoFileReference, bool repoFileCompressed, const String *pgFile,
    const String *pgFileChecksum, bool pgFileZero, uint64_t pgFileSize, time_t pgFileModified, mode_t pgFileMode,
    const String *pgFileUser, const String *pgFileGroup, time_t copyTimeBegin, bool delta, bool deltaForce,
    const String *cipherPass);

#endif
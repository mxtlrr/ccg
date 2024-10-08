/* Operations on files in the filesystem */
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "libc/string.h"
#include "fs/fs.h"

// Returns the NODE with the index.
fs_node_t tmpfs_readfile(uint32_t index);

#define FS_SUCCESS 0
#define FS_FAILURE 1

// Writes 'buffer' to the node 'n' on the filesystem.
int tmpfs_writefile(uint8_t node, char* buffer);

/* Operations on files in the filesystem */
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "fs/fs.h"

// Returns the NODE with the index.
fs_node_t tmpfs_readfile(uint32_t index);
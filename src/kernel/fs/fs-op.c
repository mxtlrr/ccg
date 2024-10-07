#include "fs/fs-op.h"

fs_node_t tmpfs_readfile(uint32_t index){
  return globl_tmpfs.nodes[index];
}
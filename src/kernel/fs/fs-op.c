#include "fs/fs-op.h"

fs_node_t tmpfs_readfile(uint32_t index){
  return globl_tmpfs.nodes[index];
}

int tmpfs_writefile(uint8_t node, char* buffer){
	// Can't write to a file that has insufficient permissions
	if(globl_tmpfs.nodes[node].permissions != PERMISSION_READWRITE)
		return FS_FAILURE;

	strcpy(globl_tmpfs.nodes[node].buffer, buffer);
	return FS_SUCCESS;
}

#include "fs/fs.h"

fs_t init_fs(void){
	fs_t tmpfs;
	for(int i = 0; i < 10; i++){
		// Set everything to zero.
		for(int j = 0; j < 256; j++) tmpfs.nodes[i].buffer[j] = 0;
		for(int k = 0; k < 32; k++)  tmpfs.nodes[i].buffer[k] = 0;
		tmpfs.nodes[i].permissions = PERMISSION_READWRITE;
	}
	return tmpfs;
}

#pragma once

#include <stdint.h>

// Syscall stuff
enum Syscall_Vc {
	FS_WRITE_FILE = 0,
	FS_READ_FILE  = 1
};

// Permissions for each node
enum Permissions {
	PERMISSION_READONLY  = 0x00,
	PERMISSION_READWRITE = 0xFF
};


// A node can either be a file or a folder.
// TODO: implement subfolders
typedef struct {
	char* name[32];
	// do stuff for a folder.
	char buffer[256];
	uint8_t permissions;
} fs_node_t;


typedef struct {
	fs_node_t nodes[10]; // Increase?
} fs_t;

// Generates a simple TmpFS with no files, but multiple nodes
// to create files (think of them like empty nodes)
fs_t init_fs(void);


extern fs_t globl_tmpfs;
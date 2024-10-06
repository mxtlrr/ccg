#pragma once

#include <stdint.h>

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
	char* buffer[256];
	uint8_t permissions;
} fs_node_t;


typedef struct {
	fs_node_t nodes[10]; // Increase?
} fs_t;

// Generates a simple TmpFS with no files, but multiple nodes
// to create files (think of them like empty nodes)
fs_t init_fs(void);

/* CCG shell. For now it's UART0 */
#pragma once

#include <stdint.h>
#include <stddef.h>

#include "libc/stdio.h"
#include "libc/string.h"

enum SPECIAL_CHARACTERS {
	BACKSPACE		= 0x7f,
	ENTER				= 0x0d,
	TAB					= 0x09
	// TODO: arrow keys
};

typedef struct {
	char params[256];
} shell_call_t;
typedef void (*shell_app_t)(shell_call_t);

extern shell_app_t apps[256];
extern char* app_name[256]; // 1-to-1 correspondence.

// Registers 'f' ass an app at index 'n' with name 'name'.
void register_shell_app(uint8_t n, shell_app_t f, char* name);

// Find the index of the app to run by it's name.
uint8_t find_app(char* name);

// This function just removes the caller and gets the buffer. This
// helps for passing stuff to caller
shell_call_t get_param(char* full_buff);

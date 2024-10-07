/* CCG shell. For now it's UART0 */
#pragma once

#include <stdint.h>
#include <stddef.h>

enum SPECIAL_CHARACTERS {
	BACKSPACE		= 0x7f,
	ENTER				= 0x0d,
	TAB					= 0x09
	// TODO: arrow keys
};

#include "shell.h"

shell_app_t apps[256]; char* app_name[256];

uint8_t find_app(char* name){
	for(int i = 0; i < 256; i++){
		if(strcmp(name, app_name[i]) == 0) return i;
	}
	return 0;
}

void register_shell_app(uint8_t n, shell_app_t f, char* name){
	strcpy(app_name[n], name);		// Copy name of app to structs.
	apps[n] = f;
	printf("[shell] registered app \"%s\" to index=%d.\n", name, n);
}

shell_call_t get_param(char* full_buff){
	shell_call_t pm;
	memset(pm.params, 0, 256);
	char params[256];
	
	uint8_t l = 0;
	for(int i = 0; (full_buff[i] != ' '); i++) {
		if(i >= 255) break;
		l = i;
	}
	if(l == 255) {
		shell_call_t p2 = { .params = 0 };
		return p2;
	}
	l += 2;

	// Now get the rest.
	for(int j = l; full_buff[j] != '\0'; j++) params[j-l] = full_buff[j];

	memcpy(pm.params, params, strlen(params));
	return pm;
}

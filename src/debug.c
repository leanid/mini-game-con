#include "debug.h"

#ifdef __linux__

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
/*
 * link using flag -rdynamic for gcc linker to show function names
 */
void debug_init(void) {
	signal(SIGSEGV, debug_set_hook_on_crush);
}

void debug_set_hook_on_crush(int signal) {
	int j, nptrs;
#define SIZE 256
	void *buffer[SIZE] = { 0 };
	char **strings;

	nptrs = backtrace(buffer, SIZE);
	fprintf(stderr, "backtrace() returned %d addresses\n", nptrs);

	backtrace_symbols_fd(buffer, nptrs, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

#else
void debug_init(void) {}
void debug_set_hook_on_crush(int) {};
#endif

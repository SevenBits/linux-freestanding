#include <syscall.h>  // defines SYS_exit

static int strlen(const char *str) {
	const char *p = str;
	for ( ; *p != '\0'; p++);
	return p - str;
}

int puts(const char *message) {
	int result;
	long size = strlen(message);
	__asm__ volatile (
		"syscall"
		: "=a" (result)
		: "0" (__NR_write), "D" (0), "S" (message), "d" (size)
	);
	return result;
}

void exit(int code) {
	int result;
    __asm__ volatile (
        "syscall"
        : "=a" (result)
        : "a" (SYS_exit), "D" (code)
	);
}

void _start(void) {
	puts("Hello, world!\n");
	exit(0);
}

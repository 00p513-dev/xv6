// Shuts down the system by using the halt() system call
// to send a special signal to QEMU.

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	halt();
	exit();
}
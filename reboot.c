// Reboot the system by using the reboot() system call

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	reboot();
	exit();
}

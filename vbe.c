#include "types.h"
#include "defs.h"
#include "stat.h"
#include "x86.h"

#include "vbe.h"

void BgaWriteRegister(unsigned short IndexValue, unsigned short DataValue)
{
	outb(VBE_DISPI_IOPORT_INDEX, IndexValue);
	outb(VBE_DISPI_IOPORT_DATA, DataValue);
}

unsigned short BgaReadRegister(unsigned short IndexValue)
{
	outb(VBE_DISPI_IOPORT_INDEX, IndexValue);
	return inb(VBE_DISPI_IOPORT_DATA);
}

int BgaIsAvailable(void)
{
	return (BgaReadRegister(VBE_DISPI_INDEX_ID) == VBE_DISPI_ID4);
}

void BgaSetVideoMode(unsigned int Width, unsigned int Height, unsigned int BitDepth, int UseLinearFrameBuffer, int ClearVideoMemory)
{
	BgaWriteRegister(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_DISABLED);
	BgaWriteRegister(VBE_DISPI_INDEX_XRES, Width);
	BgaWriteRegister(VBE_DISPI_INDEX_YRES, Height);
	BgaWriteRegister(VBE_DISPI_INDEX_BPP, BitDepth);
	BgaWriteRegister(VBE_DISPI_INDEX_ENABLE, VBE_DISPI_ENABLED |
		(UseLinearFrameBuffer ? VBE_DISPI_LFB_ENABLED : 0) |
		(ClearVideoMemory ? 0 : VBE_DISPI_NOCLEARMEM));
}

void BgaSetBank(unsigned short BankNumber)
{
	BgaWriteRegister(VBE_DISPI_INDEX_BANK, BankNumber);
}

void vbeTest(void)
{
	int vbeAvailable = inb(VBE_DISPI_INDEX_ID)+'0';
	cprintf("%x - CHECK THIS \n", vbeAvailable);
	cprintf("bye \n");
}

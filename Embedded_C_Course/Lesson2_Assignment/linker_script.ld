ENTRY(reset)
MEMORY
{
	MEM(rwx): ORIGIN = 0, LENGTH = 64M /*rwx is an attribute "read/write and including exectuabel code"*/
}

SECTIONS
{
	. = 0x10000;
	.reset . :
	{
		startup.o(.text)
	}> MEM
	.text :
	{
		*(.text) *(.rodata)
	}> MEM
	.data :
	{
		*(.data)
	}> MEM
	.bss :
	{
		*(.bss)
	}> MEM
	. = . + 0x1000;
	stack_top = .;
	
}
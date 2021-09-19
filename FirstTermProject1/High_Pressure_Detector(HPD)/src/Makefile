#@Ziad (Learn-in-Depth)

CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I ../inc
LIBS= 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As  = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = High_Press_Detect

all: $(Project_name).bin
	@echo ====================== Build Succeded ======================
%.o: %.c
	$(CC)gcc $(CFLAGS) -c  $(INCS) $< -o $@
	
%.o: %.s
	$(CC)as $(CFLAGS) -c  $(INCS) $< -o $@
#The .axf extension for debugging purposes.
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.Map
	cp $(Project_name).elf $(Project_name).axf 
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy -O binary $<  $@
clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin

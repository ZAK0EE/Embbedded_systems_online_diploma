/*
 * keypad.c
 *
 * Created: 22/07/31 05:29:15 PM
 *  Author: Ziad
 */ 

#include "keypad.h"
char KPAD_Chars[4][4] = {
							{'7', '8', '9', '/'},
							{'4', '5', '6', '*'},
							{'1', '2', '3', '-'},
							{'c', '0', '=', '+'}
						};
void KPAD_Init()
{
	KPAD_DDR &= ~(0b1111); // Rows as input
	KPAD_DDR |= (0b1111 << 4); // Columns as output
	
	KPAD_PORT = 0xFF;
}

char KPAD_Get_Char()
{
	int Ri, Ci;
	for(Ci = KPAD_C0; Ci < KPAD_C0 + 4; Ci++)
	{
		// All columns HIGH
		KPAD_PORT |= (1 << KPAD_C0) | (1 << KPAD_C1) | (1 << KPAD_C2) | (1 << KPAD_C3);
		
		// Ground once column
		KPAD_PORT &= ~(1 << Ci);
		for(Ri = KPAD_R0; Ri < KPAD_R0 + 4; Ri++)
		{
			// Check if row i is low
			if(!(KPAD_PIN & (1 << Ri)))
			{
				// Key is still pressed
				while(!(KPAD_PIN & (1 << Ri)));
				return KPAD_Chars[Ri][Ci - KPAD_C0];
					
			}
		}
	}
		
	return 0;
	 
}
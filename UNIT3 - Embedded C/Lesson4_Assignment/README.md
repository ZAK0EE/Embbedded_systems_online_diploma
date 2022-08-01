main symbols:\
00000000 T main
____________
startup symbols:\
       U _E_bss\
       U _E_DATA\
       U _E_text\
       U _S_bss\
       U _S_DATA\
00000000 T Default_Handler\
00000000 W H_Fault_Handler\
       U main\
00000000 W NMI_Handler\
0000000c T Reset_Handler\
00000000 b Stack_top\
00000000 R vectors\
_____________
Final exe symbols:\
20000400 B _E_bss\
20000000 D _E_DATA\
00000100 T _E_text\
20000000 B _S_bss\
20000000 D _S_DATA\
00000080 T Default_Handler\
00000080 W H_Fault_Handler\
00000010 T main\
00000080 W NMI_Handler\
0000008c T Reset_Handler\
20000000 b Stack_top\
00000000 T vectors\


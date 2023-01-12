
#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES
unsigned char pad1;
unsigned char pad1_new;
unsigned char pad2;
unsigned char pad2_new;
unsigned char controller;
unsigned char x;
unsigned char y;


#pragma bss-name(push, "BSS")

unsigned char c_map[240];// collision map

// PROTOTYPES
void draw_controller(void);
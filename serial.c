#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "LIB/nesalan.h"
#include "serial.h"

const unsigned char bg_pal[16] = {
		0x00, 0x00, 0x10, 0x30,
		0x2c, 0x05, 0x37, 0x15,
		0x2c, 0x0f, 0x20, 0x11,
		0x2c, 0x19, 0x2a, 0x0f};

const unsigned char sp_pal[]={
0x0f, 0x0f, 0x0f, 0x28, 
0x0f, 0x0f, 0x0f, 0x12, 
0,0,0,0,
0,0,0,0
}; 
const unsigned char text[]="Serial Test";
const unsigned char blank[]="        ";

const unsigned char label1[]="PAD 1";
const unsigned char label2[]="PAD 2";


void main(void)
{
	ppu_off();
	pal_bg(bg_pal);
	pal_spr(sp_pal);
	bank_spr(1);
	
	ppu_wait_nmi(); // wait
	set_vram_buffer(); // points ppu update to vram_buffer, do this at least once
	multi_vram_buffer_horz(text, sizeof(text), NTADR_A(10,5)); // pushes 12 bytes, horz
	multi_vram_buffer_horz(label1, sizeof(label1), NTADR_A(7,15)); // pushes 12 bytes, horz
	multi_vram_buffer_horz(label2, sizeof(label2), NTADR_A(16,15)); // pushes 12 bytes, horz
	ppu_on_all();

	while (1) // game loop
	{
		// infinite loop
		ppu_wait_nmi(); // wait till beginning of the frame

		//get pad presses
		pad1_new = pad_trigger(0);
		pad1 = pad_state(0);

		pad2 = serial_data(pad1);


		//todo:
		/*
		 * start of frame (ppu_wait_nmi)
		 * read pad state
		 * serial magic:
		 * sync clock with primary/secondary
		 * send pad state across / read it
		 * 
		 */

		//draw presses
		multi_vram_buffer_horz(blank, sizeof(blank), NTADR_A(6,17));
		multi_vram_buffer_horz(blank, sizeof(blank), NTADR_A(15,17));

		controller = pad1;
		x = 6;
		draw_controller();

		controller = pad2;
		x = 15;
		draw_controller();

		//display them
	}


}
	void draw_controller(void)
	{
		if(controller & PAD_RIGHT){
			one_vram_buffer('R', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_LEFT){
			one_vram_buffer('L', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_DOWN){
			one_vram_buffer('D', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_UP){
			one_vram_buffer('U', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_START){
			one_vram_buffer('S', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_SELECT){
			one_vram_buffer('*', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_B){
			one_vram_buffer('B', NTADR_A(x,17));
		}
		++x;
		if(controller & PAD_A){
			one_vram_buffer('A', NTADR_A(x,17));
		}
	}
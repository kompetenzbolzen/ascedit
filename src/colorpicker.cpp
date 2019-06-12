#include "colorpicker.h"


colorpicker::colorpicker() 
{
	setSize(32,17);
	update();
}
colorpicker::~colorpicker()
{
	destruct();
}

void colorpicker::onClick(sPos _pos, unsigned int _button)
{
	
}

uint16_t colorpicker::getColor()
{
	return currentFG | (currentBG << 8);
}

void colorpicker::update()
{
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 16; x++) {
			uint16_t xx = x, yy = y;
			drawText("  ", {2*x,y}, _COL_WHITE | ((16u*yy + xx) << 8));
		}
	}

	char text[17];
	snprintf(text, 16,"asdf");
	drawText(text, {0,16}, _COL_WHITE_BG | _COL_BLACK);
}

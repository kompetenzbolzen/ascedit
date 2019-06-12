#include "colorpicker.h"


colorpicker::colorpicker() 
{
	setSize(32,17);

	currentFG = _COL_WHITE;
	currentBG = _COL_BLACK;
	update();
}
colorpicker::~colorpicker()
{
	destruct();
}

void colorpicker::onClick(sPos _pos, unsigned int _button)
{
	uint8_t color = (16*_pos.y + _pos.x/2);
	
	if ((_button & 0x03) == 0)
		currentFG = color;
	else if ((_button & 0x03) == 2)
		currentBG = color;

	update();
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

	char text[33];
	snprintf(text, 32, "FG/BG");
	drawText(text, {0,16}, _COL_WHITE_BG | _COL_BLACK);

	drawText("  ", {7,16}, _COL_WHITE | currentFG << 8 ); 
	drawText("  ", {10,16}, _COL_WHITE | currentBG << 8 ); 
}

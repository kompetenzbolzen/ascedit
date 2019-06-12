#include "editor.h"

editor::editor(sPos _size)
{
	setSize(_size.x + 2, _size.y + 2);
	size = _size;

	currentPosition = {0,0};
	currentColor = _COL_WHITE | _COL_BLACK_BG;
	currentChar = ' ';
	currentMode = 0;

	storage = new cObject(size.x, size.y);
	storage->drawRectangle(currentChar, currentChar, {0,0}, {size.x-1, size.y-1}, _COL_BLACK_BG | _COL_WHITE, _COL_BLACK_BG | _COL_WHITE);
	storage->setPosition(1,1);

	drawLine('-', {1,0}, {_size.x, 0}, _COL_DEFAULT);
	drawLine('-', {1, _size.y + 1}, {_size.x, _size.y + 1}, _COL_DEFAULT);
	drawLine('|', {0,1}, {0,_size.y}, _COL_DEFAULT);
	drawLine('|', {_size.x + 1,1}, {_size.x + 1,_size.y}, _COL_DEFAULT);

	drawPoint('+', {0,0} ,_COL_DEFAULT);
	drawPoint('+', {_size.x + 1,0} ,_COL_DEFAULT);
	drawPoint('+', {0,_size.y + 1} ,_COL_DEFAULT);
	drawPoint('+', {_size.x + 1,_size.y + 1} ,_COL_DEFAULT);

	update();
}

editor::~editor()
{
	delete storage;
	destruct();
}

void editor::onChar(unsigned char _c)
{
	storage->drawPoint(_c, currentPosition, _COL_DEFAULT);
	currentChar = _c;
	update();
}

void editor::onClick(sPos _pos, unsigned int _button)
{
	if (_pos.x < 1 || _pos.y < 1 || _pos.x > size.x || _pos.y > size.y)
		return;

	currentPosition = {_pos.x - 1, _pos.y - 1};

	update();
}

void editor::setCursor(sPos _pos)
{

	if (_pos.x < 0 || _pos.y < 0 || _pos.x >= size.x || _pos.y >= size.y)
		return;

	currentPosition = _pos;

	update();
}

void editor::setColor(uint16_t _color)
{
	currentColor = _color;

	update();
}

void editor::setChar(unsigned char _c)
{
	currentChar = _c;

	update();
}

void editor::update()
{
	storage->write(this, {0,0});
	
	int tx = currentPosition.x + 1;
	int ty = currentPosition.y + 1;
	
	drawPoint( cScreen[tx][ty], {tx, ty}, _COL_WHITE_BG | _COL_BLACK);

	char text[5];
	snprintf(text, 4, "#%c#", currentChar);
	drawText(text, {0, size.y + 1}, currentColor);
}

void editor::moveCursor(sPos _relMovement)
{
	setCursor({currentPosition.x + _relMovement.x, currentPosition.y + _relMovement.y});
}

void editor::accept()
{
	switch (currentMode) {
		default:
			storage->drawPoint(currentChar, currentPosition, currentColor);
			update();
			break;
	};
}

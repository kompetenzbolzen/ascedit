#include <cObject.h>
#include <cObjectHandler.h>
#include <cRender.h>
#include <cInput.h>

#include <stdint.h>

class editor : public cObject
{
public:
	editor(sPos _size);
	~editor();

	void onChar(unsigned char _c);
	void onClick(sPos _pos, unsigned int _button);
	void moveCursor(sPos _relMovement);

	void setCursor(sPos _pos);
	void setColor(uint16_t _color);
	void setChar(unsigned char _c);

	void setMode(uint8_t _mode);

	void update();
private:
	sPos currentPosition;
	unsigned char currentChar;
	uint16_t currentColor;
	uint8_t currentMode;

	sPos size;
	unsigned char char_under_cursor;

	cObject *storage;

};


#include <cObject.h>
#include <cObjectHandler.h>
#include <cRender.h>
#include <cInput.h>

#include <stdint.h>

class colorpicker : public cObject
{

public:
	colorpicker(); 
	~colorpicker();

	void onClick(sPos _pos, unsigned int _button);

	uint16_t getColor();

	void update();
private:
	uint8_t currentFG;
	uint8_t currentBG;
};

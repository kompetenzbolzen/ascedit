#include <cObject.h>
#include <cObjectHandler.h>
#include <cRender.h>
#include <cInput.h>

#include "editor.h"
#include "colorpicker.h"

class status : public cObject
{
public:
	status(unsigned int width) { setSize(10,5); }
	~status() { destruct(); }
};

int main() {
	cRender render(' ', _COL_DEFAULT);
	cObjectHandler handler(&render, true, false);
	cInput input;
	render.render();

	editor edit({30,30});
	unsigned int edit_id = handler.createObject(&edit);

	colorpicker pick;
	unsigned int pick_id = handler.createObject(&pick);

	handler.moveObject(pick_id, {34, 0}, _MOVE_ABSOLUTE);

	render.setTargetFPS( 60 );

	while ( 1 ){
		sInputEvent ie = input.poll();
		if ( ie.type != _EVENT_NULL ) {
			if ( ie.type == _EVENT_KEY ) {
				switch ( ie.c ) {
					case 'A'://up
						edit.moveCursor({0,-1});
						break;
					case 'B'://down
						edit.moveCursor({0,1});
						break;
					case 'D'://Left
						edit.moveCursor({-1,0});
						break;
					case 'C'://Right
						edit.moveCursor({1,0});
						break;
				};//switch
			}//if
			else if ( ie.type == _EVENT_MOUSE ) {
				if ( ie.b == 0 )
					handler.clickEvent({ie.x, ie.y}, 0);
			}// if
			else if ( ie.type == _EVENT_CHAR )
			{
				switch ( ie.c )
				{
					case 'w':
						break;
					case 's':
						break;
					case 'g':
						render.enableDebugInfo(true);
						break;
					case 'G':
						render.enableDebugInfo(false);
						break;
					default:
						handler.charEvent( ie.c );
				};//switch
			}//if
			else if ( ie.type == _EVENT_TERM ) {
				return 0;
			}//if
		}//if

		handler.write();
		render.render();
	}
	
	return 0;
}

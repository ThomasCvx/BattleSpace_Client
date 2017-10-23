#pragma once
#pragma once
#ifndef LOBBIES_STATE
# define LOBBIES_STATE

#include "Eventreceiver.h"
#include <irrlicht.h>

class LobbiesState : public State {
private:
	irr::IrrlichtDevice *device_;
	irr::gui::IGUIEditBox *editbox;

public:
	LobbiesState(irr::IrrlichtDevice& device);
	~LobbiesState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();
};


#endif // !LOBBIES_STATE


#pragma once
#ifndef INTRO_STATE
# define INTRO_STATE

#include "Eventreceiver.h"
#include <irrlicht.h>

class IntroState : public State {
private:
	irr::IrrlichtDevice *device_;
	irr::gui::IGUIEditBox *editbox;

public:
	IntroState(irr::IrrlichtDevice& device);
	~IntroState();

	void Events(EventReceiver *receiver);
	void Update();
	void Render();
};


#endif // !INTRO_STATE

#include "IntroState.h"
#include <irrlicht.h>
#include "EventReceiver.h"
#include "StateManager.h"
#include "LobbiesState.h"

IntroState::IntroState(irr::IrrlichtDevice& device) {
	device_ = &device;
}

IntroState::~IntroState() {
}

void IntroState::Events(EventReceiver *receiver) {

	if (editbox->getText() != NULL)
	{
		if (receiver->IsKeyPressed(irr::KEY_RETURN)) {
			LobbiesState *ls = new LobbiesState(*device_);

			StateManager::get().replace(ls);
		}
		if (receiver->IsKeyPressed(irr::KEY_ESCAPE)) {
			LobbiesState *ls = new LobbiesState(*device_);

			StateManager::get().replace(ls);
		}
	}
}

void IntroState::Update() {
	// Nothing here (I think)
}

void IntroState::Render() {
	irr::video::IVideoDriver* driver = device_->getVideoDriver();
	//irr::scene::ISceneManager* smgr = device.getSceneManager();
	irr::gui::IGUIEnvironment* env = device_->getGUIEnvironment();

	irr::gui::IGUIEditBox *editbox;

	irr::gui::IGUISkin *skin = env->getSkin();



	//irr::gui::IGUIFont *font = env->getFont("media/fontlucida.png");
	//if (font)
		//skin->setFont(font);

	irr::video::ITexture *image = driver->getTexture("media/IntroStateBackground.jpg");
	irr::core::dimension2d<unsigned int> taille = image->getSize();
	irr::core::position2d<irr::s32> position0;
	position0.X = 0;
	position0.Y = 0;
	irr::core::position2d<irr::s32> position1;
	position1.X = taille.Width;
	position1.Y = taille.Height;
	irr::core::rect<irr::s32> rectangle;
	rectangle.UpperLeftCorner = position0;
	rectangle.LowerRightCorner = position1;
	driver->beginScene(true, true, irr::video::SColor(0, 120, 120, 120));
	driver->draw2DImage(image, position0, rectangle, 0, irr::video::SColor(255, 255, 255, 255), true);

	env->addStaticText(L"Press ENTER/ESCAPE to launch", irr::core::rect<irr::s32>(860, 50, 1060, 150), false, false);

	//smgr->drawAll();
	env->drawAll();
	driver->endScene();
}

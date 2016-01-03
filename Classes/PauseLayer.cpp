#include "PauseLayer.h"
#include "MainGameScene.h"
#include "BandSelectScene.h"
USING_NS_CC;
using namespace cocos2d::experimental;

bool PauseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto cover = LayerColor::create(Color4B(0, 0, 0, 220));
	addChild(cover, 0);

	// regist cover listener
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [=](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		return true;
	};

	listener1->retain();

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, cover);


	auto back = LayerColor::create(Color4B(77,96,156,255));
	back->changeWidthAndHeight(500, 300);
	back->setPosition(960 - 500/2, 540- 300/2);
	addChild(back, 1);

	auto resumeItem = MenuItemImage::create("main/resume.png", "main/resume_sel.png", [this](Ref* sender) {
		MainGameScene* scene = (MainGameScene*)(this->getParent());

		Director::getInstance()->resume();
		AudioEngine::resume(scene->_backId);
		this->removeFromParentAndCleanup(true);
	});
	auto backItem  = MenuItemImage::create("main/return.png", "main/return_sel.png", [this](Ref* sender) {
		MainGameScene* scene = (MainGameScene*)(this->getParent());

		AudioEngine::stop(scene->_backId);
		Director::getInstance()->resume();
		Director::getInstance()->replaceScene(BandSelectScene::createScene());

	});

	resumeItem->setPosition(960, 540 + 65);
	backItem->setPosition(960 , 540 - 65);

	auto pauseMenu = Menu::create(resumeItem, backItem, nullptr);
	pauseMenu->setPosition(Vec2::ZERO);
	
	addChild(pauseMenu, 10);


	

	return true;

}




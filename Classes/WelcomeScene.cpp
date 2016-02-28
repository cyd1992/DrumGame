#include "WelcomeScene.h"

#include "ModeSelectScene.h"
USING_NS_CC;

Scene* WelcomeScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = WelcomeScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool WelcomeScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.


	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label


	//load backgroud
	auto background = Sprite::create("welcome/welcome.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(1.5);

	addChild(background, 10);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);
	listener1->onTouchBegan = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		return true;
	};

	listener1->onTouchEnded = [&](Touch* touch, Event* event) {
		Director::getInstance()->replaceScene(ModeSelectScene::createScene());
	};

	listener1->retain();

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, background);


	//add button
	//add a menu
	auto start = Sprite::create("welcome/start.png");
	start->setPosition(visibleSize.width / 2, 150);
	addChild(start, 20);

	auto title = Sprite::create("welcome/title.png");
	title->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(title, 30);


	return true;
}

void WelcomeScene::menuCallback(cocos2d::Ref* sender)
{
	Director::getInstance()->replaceScene(ModeSelectScene::createScene());
}


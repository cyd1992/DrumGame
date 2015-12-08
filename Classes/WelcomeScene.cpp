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
	auto background = Sprite::create("welcome.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	background->setScale(1);

	addChild(background, 10);


	//add button
	//add a menu
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");
	auto item1 = MenuItemFont::create("START", CC_CALLBACK_1(WelcomeScene::menuCallback, this));

	auto menu = Menu::create(item1, nullptr);
	menu->alignItemsVertically();

	addChild(menu, 9);
	menu->setPosition(Vec2(visibleSize.width / 2, visibleSize.height* 0.22));

	return true;
}

void WelcomeScene::menuCallback(cocos2d::Ref* sender)
{
	Director::getInstance()->replaceScene(ModeSelectScene::createScene());
}


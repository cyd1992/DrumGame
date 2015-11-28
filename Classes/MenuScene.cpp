#include "MenuScene.h"

#include "XMLParserUtil.h"

#include "BandSelectScene.h"
#include "MainGameScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
 
// on "init" you need to initialize your instance
bool MenuScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto s = Director::getInstance()->getWinSize();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MenuScene::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menuClose = Menu::create(closeItem, NULL);
	menuClose->setPosition(Vec2::ZERO);
	this->addChild(menuClose, 1);

	/////////////////////////////
	// 3. add your codes below...

	//add a menu
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");
	auto item1 = MenuItemFont::create("DrumGameScene", CC_CALLBACK_1(MenuScene::menuCallbackMain, this));
	auto item2 = MenuItemFont::create("Band Mode", CC_CALLBACK_1(MenuScene::menuCallbackDisk, this));
	auto item3 = MenuItemFont::create("---", CC_CALLBACK_1(MenuScene::menuCallbackDisk, this));

	auto menu = Menu::create(item1,item2,item3, nullptr);
	menu->alignItemsVertically();

	addChild(menu);
	menu->setPosition(Vec2(s.width / 2, s.height / 2));
	// add a label shows "Hello World"
	// create and initialize a label

// 	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
// 
// 	// position the label on the center of the screen
// 	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
// 		origin.y + visibleSize.height - label->getContentSize().height));
// 
// 	// add the label as a child to this layer
// 	this->addChild(label, 1);
// 
// 	// add "HelloWorld" splash screen"
// 	auto sprite = Sprite::create("HelloWorld.png");
// 
// 	// position the sprite on the center of the screen
// 	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
// 
// 	// add the sprite as a child to this layer
// 	this->addChild(sprite, 0);

	return true;
}

void MenuScene::menuCallback(Ref* sender)
{

}

void MenuScene::menuCallbackAudio(Ref* sender)
{
	//Director::getInstance()->replaceScene(AudioTestScene::createScene());
}

void MenuScene::menuCallbackDisk(Ref* sender)
{
	Director::getInstance()->replaceScene(BandSelectScene::createScene());
}


void MenuScene::menuCloseCallback(Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void MenuScene::menuCallbackMain(cocos2d::Ref* sender)
{
	XMLParseUtil::ParseLevel("level/level_sample.xml");

	Director::getInstance()->replaceScene(MainGameScene::createScene());
}

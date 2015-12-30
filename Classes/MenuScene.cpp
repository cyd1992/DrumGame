#include "MenuScene.h"

#include "XMLParseUtil.h"

#include "BandSelectScene.h"
#include "MainGameScene.h"

#include "WelcomeScene.h"

#include "NoteNode.h"

#include "ComboNode.h"

#include "PracticeSelectScene.h"

#include "ToastSprite.h"

#include "JiesuanScene.h"

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
	auto item2 = MenuItemFont::create("Jiesuan", CC_CALLBACK_1(MenuScene::menuCallbackDisk, this));
	auto item3 = MenuItemFont::create("WelcomeScene", CC_CALLBACK_1(MenuScene::menuCallbackAudio, this));
	auto item4 = MenuItemFont::create("Practice Mode", CC_CALLBACK_1(MenuScene::menuCallbackPractice, this));

	item1->setScale(2);
	item2->setScale(2);
	item3->setScale(2);
	item4->setScale(2);

	auto menu = Menu::create(item1,item2,item4, nullptr);
	menu->alignItemsVertically();
	

	addChild(menu);
	menu->setPosition(Vec2(s.width / 2, s.height / 2));

// note node test
// 	auto note = NoteNode::create(10);
// 	note->setPosition(visibleSize.width * 0, visibleSize.height*0.2);
// 	addChild(note);

//draw test
// 	auto draw = DrawNode::create();
// 	addChild(draw, 10);

// draw a line
	/*draw->drawLine(Vec2(0, 0), Vec2(s.width, s.height), Color4F(1.0, 0.0, 0.0, 0.5));*/

	//combo test
	auto combo = ComboNode::create(10);
	combo->setPosition(visibleSize.width * 0.2, visibleSize.height * 0.8);

	addChild(combo);

	//toast test
	auto toast = ToastSprite::create(0);
	toast->setPosition(visibleSize.width * 0.2, visibleSize.height * 0.6);
	addChild(toast);

	return true;
}

void MenuScene::menuCallback(Ref* sender)
{

}

void MenuScene::menuCallbackAudio(Ref* sender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
}

void MenuScene::menuCallbackDisk(Ref* sender)
{
	Director::getInstance()->replaceScene(JiesuanScene::createScene());
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
	XMLParseUtil::ParseLevel("level/level_sample_1.xml");

	Director::getInstance()->replaceScene(MainGameScene::createScene());
}

void MenuScene::menuCallbackPractice(cocos2d::Ref* sender)
{
	Director::getInstance()->replaceScene(PracticeSelectScene::createScene());
}

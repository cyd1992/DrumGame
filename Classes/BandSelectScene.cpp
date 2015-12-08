#include "BandSelectScene.h"

#include "MainGameScene.h"

#include "XMLParseUtil.h"
#include "MenuScene.h"
#include "MainGameScene.h"

USING_NS_CC;

Scene* BandSelectScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = BandSelectScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool BandSelectScene::init()
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

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(BandSelectScene::menuCallbackBack, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menuBack = Menu::create(closeItem, NULL);
	menuBack->setPosition(Vec2::ZERO);
	this->addChild(menuBack, 100);

	//add a menu
	MenuItemFont::setFontName("fonts/Marker Felt.ttf");
	auto item1 = MenuItemFont::create("Level1", CC_CALLBACK_1(BandSelectScene::menuCallbackLevel1, this));
	auto item2 = MenuItemFont::create("Level2", CC_CALLBACK_1(BandSelectScene::menuCallbackLevel2, this));
	auto item3 = MenuItemFont::create("Level3", CC_CALLBACK_1(BandSelectScene::menuCallbackLevel3, this));

	auto menu = Menu::create(item1, item2, item3, nullptr);
	menu->alignItemsVertically();

	addChild(menu);
	menu->setPosition(Vec2(s.width / 2, s.height / 2));

	//load backgroud
// 	auto background = Sprite::create("band.png");
// 	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
// 	background->setScale(0.5);
// 
// 	addChild(background, 10);

	return true;
}

void BandSelectScene::menuCallbackBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}

void BandSelectScene::menuCallbackLevel1(cocos2d::Ref* sender)
{
	XMLParseUtil::ParseLevel("level/level1/level1.xml");

	Director::getInstance()->replaceScene(MainGameScene::createScene());
}

void BandSelectScene::menuCallbackLevel2(cocos2d::Ref* sender)
{
	XMLParseUtil::ParseLevel("level/level2/level2.xml");

	Director::getInstance()->replaceScene(MainGameScene::createScene());
}

void BandSelectScene::menuCallbackLevel3(cocos2d::Ref* sender)
{
	XMLParseUtil::ParseLevel("level/level3/level3.xml");

	Director::getInstance()->replaceScene(MainGameScene::createScene());
}

#include "JiesuanScene.h"

#include "MenuScene.h"
USING_NS_CC;

Scene* JiesuanScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = JiesuanScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool JiesuanScene::init()
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
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(JiesuanScene::menuCallbackBack, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	closeItem->setScale(2);
	// create menu, it's an autorelease object
	auto menuBack = Menu::create(closeItem, NULL);
	menuBack->setPosition(Vec2::ZERO);
	this->addChild(menuBack, 100);

	auto back = Sprite::create("jiesuan/jiesuan.png");
	back->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(back, 0);


	



	return true;
}

void JiesuanScene::menuCallbackBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}
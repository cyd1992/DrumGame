#include "BandSelectScene.h"

#include "XMLParseUtil.h"
#include "MenuScene.h"
#include "MainGameScene.h"
#include "ModeSelectScene.h"

USING_NS_CC;

BandSelectScene::BandSelectScene()
{

}

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

	my_init();

	return true;
}

void BandSelectScene::my_init_old()
{
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

	item1->setScale(2);
	item2->setScale(2);
	item3->setScale(2);

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
}

void BandSelectScene::my_init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//load backgroud
	auto background = Sprite::create("mode/mode.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background, 0);

	// slider 
	auto item1 = MenuItemImage::create("band/slider_left.png", "band/slider_left_sel.png", CC_CALLBACK_1(BandSelectScene::CallbackLeft, this));
	auto item2 = MenuItemImage::create("band/slider_right.png", "band/slider_right_sel.png", CC_CALLBACK_1(BandSelectScene::CallbackRight, this));

	item1->setPosition(120, 540);
	item2->setPosition(1800, 540);

	auto menu = Menu::create(item1, item2, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu,10);


	//item
	_bandItem[0] = createItem(0);
	_bandItem[0]->setPosition(960, 540);
	_bandItem[0]->setTag(0);
	addChild(_bandItem[0], 10);

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemFont::create("返回", CC_CALLBACK_1(BandSelectScene::menuCallbackBack, this));
	closeItem->setFontSize(80);
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2 - 20,
		origin.y + closeItem->getContentSize().height / 2 + 20));

	// create menu, it's an autorelease object
	auto menuBack = Menu::create(closeItem, NULL);
	menuBack->setPosition(Vec2::ZERO);
	this->addChild(menuBack, 100);


	
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
		char buf[100] = { 0 };
		//log("Key %d was pressed!", (int)keyCode);


	};

	listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event) {
		char buf[100] = { 0 };
		//log("Key %d was released!", (int)keyCode);
		if (keyCode == EventKeyboard::KeyCode::KEY_BACK)
		{
			Director::getInstance()->replaceScene(ModeSelectScene::createScene());
		}

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}





void BandSelectScene::menuCallbackBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(ModeSelectScene::createScene());
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

void BandSelectScene::CallbackRight(cocos2d::Ref* sender)
{
	if (_curIndex < _maxItem -1)
	{
		_bandItem[_curIndex]->runAction( Sequence::create( MoveBy::create(0.5, Vec2(-1920, 0)), 
										 CallFunc::create([this]() {this->getChildByTag(_curIndex-1)->removeFromParentAndCleanup(true); })
										 ,nullptr));
		_curIndex++;
		_bandItem[_curIndex] = createItem(_curIndex);
		_bandItem[_curIndex]->setPosition(1920 + 960, 540);
		_bandItem[_curIndex]->setTag(_curIndex);
		addChild(_bandItem[_curIndex], 10);
		_bandItem[_curIndex]->runAction(MoveBy::create(0.5, Vec2(-1920, 0)));

	}


}

void BandSelectScene::CallbackLeft(cocos2d::Ref* sender)
{
	if (_curIndex > 0)
	{
		_bandItem[_curIndex]->runAction(Sequence::create(MoveBy::create(0.5, Vec2(1920, 0)),
			CallFunc::create([this]() {this->getChildByTag(_curIndex + 1)->removeFromParentAndCleanup(true); })
			, nullptr));

		_curIndex--;
		_bandItem[_curIndex] = createItem(_curIndex);
		_bandItem[_curIndex]->setPosition(-1920 + 960, 540);
		_bandItem[_curIndex]->setTag(_curIndex);
		addChild(_bandItem[_curIndex], 10);
		_bandItem[_curIndex]->runAction(MoveBy::create(0.5, Vec2(1920, 0)));

	}
}

cocos2d::Node* BandSelectScene::createItem(int index)
{
	auto node = Node::create();

	auto menuItem = MenuItemImage::create(_thumbFile[index], _thumbFile[index], [this](Ref *sender) {
		XMLParseUtil::ParseLevel(_musicFile[_curIndex].c_str());
		Director::getInstance()->replaceScene(MainGameScene::createScene());
	});


	auto menu = Menu::create(menuItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	node->addChild(menu, 0);

	auto title = LabelTTF::create();
	title->setString(_title[index]);
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		title->setFontName("fonts/MF.ttf");
	else title->setFontName("goma block");
	title->setFontSize(70);

	title->setPosition(0, -320);
	node->addChild(title, 10);

	return node;

}




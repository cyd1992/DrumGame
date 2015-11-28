#include "MainGameScene.h"
#include "MenuScene.h"
#include "DJScheduler.h"

#include "math.h"

#include "DrumSprite.h"

#include "XMLParserUtil.h"


USING_NS_CC;
using namespace cocos2d::experimental;

Scene* MainGameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainGameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MainGameScene::init()
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

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(MainGameScene::menuCallbackBack, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);

	////////////////////////////
	//drum
	auto drum = Sprite::create("drum2.png");
	//drum->ignoreAnchorPointForPosition(true);
	drum->setPosition(visibleSize.width/2, visibleSize.height *0.45);
	drum->setScale(0.5);
	addChild(drum, 10);


	//audio profile
	_audioProfile.name = "DrumPanel";
	_audioProfile.maxInstances = 10;
	_audioProfile.minDelay = 0.05;

	auto drumSprite1 = DrumSprite::create("CyanSquare.png");
	drumSprite1->setPosition(Vec2(visibleSize.width * 0.21, visibleSize.height * 0.24));
	drumSprite1->setMusicFile(* XMLParseUtil::_musicPath[0]);
	drumSprite1->setScaleX(2.5);
	drumSprite1->setScaleY(1.9);
	drumSprite1->setOpacity(100);
	addChild(drumSprite1, 0);

	drumSprite1->RegistListener(_audioProfile);


	auto drumSprite2 = DrumSprite::create("CyanSquare.png");
	drumSprite2->setPosition(Vec2(visibleSize.width * 0.36, visibleSize.height * 0.51));
	drumSprite2->setMusicFile(*XMLParseUtil::_musicPath[1]);
	drumSprite2->setScaleX(1.8);
	drumSprite2->setScaleY(1.8);
	drumSprite2->setOpacity(100);
	addChild(drumSprite2, 0);

	drumSprite2->RegistListener(_audioProfile);


	auto drumSprite3 = DrumSprite::create("CyanSquare.png");
	drumSprite3->setPosition(Vec2(visibleSize.width * 0.12, visibleSize.height * 0.51));
	drumSprite3->setMusicFile(*XMLParseUtil::_musicPath[2]);
	drumSprite3->setScaleX(2.7);
	drumSprite3->setScaleY(1.8);
	drumSprite3->setOpacity(100);
	addChild(drumSprite3, 0);

	drumSprite3->RegistListener(_audioProfile);


	auto drumSprite4 = DrumSprite::create("CyanSquare.png");
	drumSprite4->setPosition(Vec2(visibleSize.width * 0.50, visibleSize.height * 0.13));
	drumSprite4->setMusicFile(*XMLParseUtil::_musicPath[3]);
	drumSprite4->setScaleX(2.5);
	drumSprite4->setScaleY(1.6);
	drumSprite4->setOpacity(100);
	addChild(drumSprite4, 0);

	drumSprite4->RegistListener(_audioProfile);

	auto drumSprite5 = DrumSprite::create("CyanSquare.png");
	drumSprite5->setPosition(Vec2(visibleSize.width * 0.78, visibleSize.height * 0.20));
	drumSprite5->setMusicFile(*XMLParseUtil::_musicPath[4]);
	drumSprite5->setScaleX(2.8);
	drumSprite5->setScaleY(2.4);
	drumSprite5->setOpacity(100);
	addChild(drumSprite5, 0);

	drumSprite5->RegistListener(_audioProfile);

	auto drumSprite6 = DrumSprite::create("CyanSquare.png");
	drumSprite6->setPosition(Vec2(visibleSize.width * 0.61, visibleSize.height * 0.51));
	drumSprite6->setMusicFile(*XMLParseUtil::_musicPath[5]);
	drumSprite6->setScaleX(1.8);
	drumSprite6->setScaleY(1.8);
	drumSprite6->setOpacity(100);
	addChild(drumSprite6, 0);
	drumSprite6->RegistListener(_audioProfile);

	//top panel
	auto panelDrum = Sprite::create("CyanSquare.png");
	panelDrum->setPosition(visibleSize.width * 0.1, visibleSize.height * 0.9);
	panelDrum->setScale(0.8);
	addChild(panelDrum, 10);


	
	// scheduler test
	auto sche = DJScheduler::create();
	addChild(sche);

	//background music
	//XMLParseUtil::ParseLevel("level/level1.xml");
	//XMLParseUtil::PrintVec();

	_backId = AudioEngine::play2d(* XMLParseUtil::_bgmPath, false, 0.3f, &_audioProfile);
	log("backid: %d", _backId);
//note test
// 	auto note = NoteSprite::create("note.png");
// 	note->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
// 	panel->addChild(note);
// 	note->StartDrop();

	sche->StartTimer();


	return true;
}


void MainGameScene::menuCallbackBack(Ref* pSender)
{
	AudioEngine::stop(_backId);

	Director::getInstance()->replaceScene(MenuScene::createScene());
}

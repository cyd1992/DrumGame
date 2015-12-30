#include "MainGameScene.h"
#include "MenuScene.h"
#include "DJScheduler.h"

#include "math.h"

#include "DrumSprite.h"

#include "XMLParseUtil.h"

#include "ToastSprite.h"

#include "HUD.h"


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

	//my_init_old();
	my_init();
	

	return true;
}


void MainGameScene::menuCallbackBack(Ref* pSender)
{
	AudioEngine::stop(_backId);

	Director::getInstance()->replaceScene(MenuScene::createScene());
}

void MainGameScene::my_init_old()
{
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
	auto drum = Sprite::create("drum5.png");
	//drum->ignoreAnchorPointForPosition(true);
	drum->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	drum->setScale(1);
	addChild(drum, 10);


	//panel
	auto panel = Sprite::create("panel.png");
	//drum->ignoreAnchorPointForPosition(true);
	panel->setPosition(visibleSize.width / 2, visibleSize.height* 0.48);
	panel->setScale(1);
	addChild(panel, 11);


	//audio profile
	_audioProfile.name = "DrumPanel";
	_audioProfile.maxInstances = 10;
	_audioProfile.minDelay = 0.05;

	auto drumSprite1 = DrumSprite::create("CyanSquare.png");
	drumSprite1->setPosition(Vec2(visibleSize.width * 0.23, visibleSize.height * 0.22));
	drumSprite1->setMusicFile(*XMLParseUtil::_musicPath[0]);
	drumSprite1->setScaleX(2.4 * 2);
	drumSprite1->setScaleY(1.7 * 2);
	drumSprite1->setOpacity(100);
	addChild(drumSprite1, 0);

	drumSprite1->RegistListener(_audioProfile);


	auto drumSprite2 = DrumSprite::create("CyanSquare.png");
	drumSprite2->setPosition(Vec2(visibleSize.width * 0.38, visibleSize.height * 0.41));
	drumSprite2->setMusicFile(*XMLParseUtil::_musicPath[1]);
	drumSprite2->setScaleX(1.8 * 2);
	drumSprite2->setScaleY(1.45 * 2);
	drumSprite2->setOpacity(100);
	addChild(drumSprite2, 0);

	drumSprite2->RegistListener(_audioProfile);


	auto drumSprite3 = DrumSprite::create("CyanSquare.png");
	drumSprite3->setPosition(Vec2(visibleSize.width * 0.17, visibleSize.height * 0.41));
	drumSprite3->setMusicFile(*XMLParseUtil::_musicPath[2]);
	drumSprite3->setScaleX(2.4 * 2);
	drumSprite3->setScaleY(1.5 * 2);
	drumSprite3->setOpacity(100);
	addChild(drumSprite3, 0);

	drumSprite3->RegistListener(_audioProfile);


	auto drumSprite4 = DrumSprite::create("CyanSquare.png");
	drumSprite4->setPosition(Vec2(visibleSize.width * 0.50, visibleSize.height * 0.13));
	drumSprite4->setMusicFile(*XMLParseUtil::_musicPath[3]);
	drumSprite4->setScaleX(2.3 * 2);
	drumSprite4->setScaleY(1.3 * 2);
	drumSprite4->setOpacity(100);
	addChild(drumSprite4, 0);

	drumSprite4->RegistListener(_audioProfile);

	auto drumSprite5 = DrumSprite::create("CyanSquare.png");
	drumSprite5->setPosition(Vec2(visibleSize.width * 0.75, visibleSize.height * 0.20));
	drumSprite5->setMusicFile(*XMLParseUtil::_musicPath[4]);
	drumSprite5->setScaleX(2.8 * 2);
	drumSprite5->setScaleY(1.8 * 2);
	drumSprite5->setOpacity(100);
	addChild(drumSprite5, 0);

	drumSprite5->RegistListener(_audioProfile);

	auto drumSprite6 = DrumSprite::create("CyanSquare.png");
	drumSprite6->setPosition(Vec2(visibleSize.width * 0.59, visibleSize.height * 0.41));
	drumSprite6->setMusicFile(*XMLParseUtil::_musicPath[5]);
	drumSprite6->setScaleX(1.8 * 2);
	drumSprite6->setScaleY(1.45 * 2);
	drumSprite6->setOpacity(100);
	addChild(drumSprite6, 0);
	drumSprite6->RegistListener(_audioProfile);

	//top panel
	auto panelDrum = Sprite::create("CyanSquare.png");
	panelDrum->setPosition(visibleSize.width * 0.15, visibleSize.height * 0.9);
	panelDrum->setScale(1.6);
	addChild(panelDrum, 20);



	// scheduler test
	auto sche = DJScheduler::create();
	addChild(sche);

	//background music
	//XMLParseUtil::ParseLevel("level/level1.xml");
	//XMLParseUtil::PrintVec();

	sche->StartTimer();

	AudioEngine::preload(*XMLParseUtil::_bgmPath, [](bool isSuccess) {
		if (isSuccess)
		{
			//stateLabel->setString("status:load success");
			//log("load music/beat1.mp3  succeed!");
		}
		else
		{
			//stateLabel->setString("status:load fail");
			//log("load music/beat1.mp3  failed!");
		}
	});

	//_backId = AudioEngine::play2d(* XMLParseUtil::_bgmPath, false, 0.3f, &_audioProfile);
	//log("backid: %d", _backId);
	//note test
	// 	auto note = NoteSprite::create("note.png");
	// 	note->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
	// 	panel->addChild(note);
	// 	note->StartDrop();



	// score label
	char stringLabel[100];
	sprintf(stringLabel, "%d", _score);

	_scoreLabel = LabelTTF::create();
	_scoreLabel->setFontName("Marker Felt");
	_scoreLabel->setFontSize(48);
	_scoreLabel->setFontFillColor(Color3B(255, 0, 0));
	_scoreLabel->setString(stringLabel);
	addChild(_scoreLabel, 20);
	_scoreLabel->setPosition(Vec2(visibleSize.width *0.9, visibleSize.height * 0.9));

	//draw test
	auto draw = DrawNode::create();
	addChild(draw, 30);
	// draw a line
	draw->drawLine(Vec2(visibleSize.width *0.2, visibleSize.height *0.8), Vec2(visibleSize.width *0.2, visibleSize.height), Color4F(1.0, 0.0, 0.0, 0.5));
	draw->drawLine(Vec2(visibleSize.width *0.1, visibleSize.height *0.8), Vec2(visibleSize.width *0.1, visibleSize.height), Color4F(1.0, 0.0, 0.0, 0.5));
	draw->drawLine(Vec2(visibleSize.width *0.15, visibleSize.height *0.8), Vec2(visibleSize.width *0.15, visibleSize.height), Color4F(1.0, 0.0, 0.0, 0.5));

	// combo test
	_comboNode = ComboNode::create(10);
	_comboNode->setPosition(visibleSize.width * 0.5, visibleSize.height * 0.75);
	_comboNode->_label->setOpacity(0);
	//combo->RunAction();
	addChild(_comboNode, 30);


	//key board test
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
		char buf[100] = { 0 };
		log("Key %d was pressed!", (int)keyCode);


	};

	listener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event) {
		char buf[100] = { 0 };
		log("Key %d was released!", (int)keyCode);

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void MainGameScene::my_init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// background layer
	//auto back = LayerColor::create(Color4B(20, 30, 52, 255));

	auto back = Sprite::create("main/back.png");
	back->setPosition(visibleSize.width / 2, visibleSize.height / 2);

	addChild(back, 0);

	// drums

	Size src_location[8];
	Size dst_location[8];

	src_location[0].width = 490;
	src_location[0].height = 1080 - 395;     //drum_t1

	drum_t1 = Sprite::create("main/drum_t1.png");
	drum_t1->setPosition(src_location[0].width, src_location[0].height);

	//move = MoveBy::create(0.5f, Vec2(0, 1080));

	addChild(drum_t1, 10);
	//drum_t1->runAction(move);

	drum_t2 = Sprite::create("main/drum_t2.png");
	drum_t2->setPosition(1560, 1080 - 450 );

	addChild(drum_t2, 10);

	drum1 = Node::create();
	auto drum1_d = DrumSprite::create("main/drum1.png");
	drum1_d->setSelSprite("main/drum1_sel.png");
	drum1_d->setMusicFile(*XMLParseUtil::_musicPath[0]);
	drum1_d->setPosition(0, 0);

	auto drum1_t = Sprite::create("main/drum1_t.png");
	drum1_t->setPosition(2, -20);

	drum1->addChild(drum1_d, 20);
	drum1->addChild(drum1_t, 10);

	drum1->setPosition(475, 1080 - 840);

	addChild(drum1, 9);

	drum1_d->RegistListener(_audioProfile);

	//
	drum3 = Node::create();
	auto drum3_d = DrumSprite::create("main/drum3.png");
	drum3_d->setSelSprite("main/drum3_sel.png");
	drum3_d->setMusicFile(*XMLParseUtil::_musicPath[2]);
	drum3_d->setPosition(0, 0);

	auto drum3_t = Sprite::create("main/drum3_t.png");
	drum3_t->setPosition(8, -14);

	drum3->addChild(drum3_d, 20);
	drum3->addChild(drum3_t, 10);

	drum3->setPosition(335, 1080 - 635 );
	
	addChild(drum3, 10);

	drum3_d->RegistListener(_audioProfile);

	drum2 = Node::create();
	auto drum2_d = DrumSprite::create("main/drum2.png");
	drum2_d->setSelSprite("main/drum2_sel.png");
	drum2_d->setMusicFile(*XMLParseUtil::_musicPath[1]);
	drum2_d->setPosition(0, 0);

	auto drum2_t = Sprite::create("main/drum2_t.png");
	drum2_t->setPosition(12, -13);

	drum2->addChild(drum2_d, 20);
	drum2->addChild(drum2_t, 10);

	drum2->setPosition(730, 1080 - 640 );

	addChild(drum2, 11);

	drum2_d->RegistListener(_audioProfile);

	drum6 = Node::create();
	auto drum6_d = DrumSprite::create("main/drum6.png");
	drum6_d->setSelSprite("main/drum6_sel.png");
	drum6_d->setMusicFile(*XMLParseUtil::_musicPath[5]);

	drum6_d->setPosition(0, 0);

	auto drum6_t = Sprite::create("main/drum6_t.png");
	drum6_t->setPosition(-6, -18);

	drum6->addChild(drum6_d, 20);
	drum6->addChild(drum6_t, 10);

	drum6->setPosition(1130, 1080 - 640 );
	addChild(drum6, 11);

	drum6_d->RegistListener(_audioProfile);

	drum4 = Node::create();
	auto drum4_d = DrumSprite::create("main/drum4.png");
	drum4_d->setSelSprite("main/drum4_sel.png");
	drum4_d->setMusicFile(*XMLParseUtil::_musicPath[3]);

	drum4_d->setPosition(0, 0);
	

	auto drum4_t = Sprite::create("main/drum4_t.png");
	drum4_t->setPosition(0, 58);

	drum4->addChild(drum4_d, 20);
	drum4->addChild(drum4_t, 10);

	drum4->setPosition(930, 1080 - 950);

	addChild(drum4, 10);

	drum4_d->RegistListener(_audioProfile);

	drum5 = Node::create();
	auto drum5_d = DrumSprite::create("main/drum5.png");
	drum5_d->setSelSprite("main/drum5_sel.png");
	drum5_d->setMusicFile(*XMLParseUtil::_musicPath[4]);

	drum5_d->setPosition(0, 0);

	auto drum5_t = Sprite::create("main/drum5_t.png");
	drum5_t->setPosition(-15, -27);

	drum5->addChild(drum5_d, 20);
	drum5->addChild(drum5_t, 10);

	drum5->setPosition(1420, 1080 - 865 );
	addChild(drum5, 12);

	drum5_d->RegistListener(_audioProfile);
	//zhijia
	zhijia = Sprite::create("main/zhijia.png");
	zhijia->setPosition(990, 265);
	//zhijia->setOpacity(0);

	addChild(zhijia, 5);


	//  µÆ¹â
	light = Sprite::create("main/light.png");
	light->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//light->setOpacity(0);

	addChild(light, 31);

	


	//hud
	auto hud_t = Sprite::create("main/hud.png");
	hud_t->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//addChild(hud_t, 50);

	auto label = LabelTTF::create("PERFECT", "fonts/Duck-esa.ttf", 55);
	// 	label->setFontName("font/MF.otf");
	// 	label->setFontSize(30);
	label->setColor(Color3B(255, 0, 0));
	//label->setString("PERFECT ºÃ");
	label->setPosition(visibleSize.width / 2, visibleSize.height*0.95);
	//addChild(label);

	hud_layer = HUD::create();
	hud_layer->ignoreAnchorPointForPosition(true);
	hud_layer->setPosition(0, 1020);
	addChild(hud_layer, 50);


	//½¥±ä²ã
	gradient = Node::create();
	


	auto gradient_1 = LayerColor::create(Color4B(20, 30, 52, 255));
	gradient_1->changeWidthAndHeight(1920, 200);
	gradient_1->setTag(1);
	gradient_1->setPosition(0, 200);
	//gradient_1->setOpacity(0);
	auto gradient_2 = LayerGradient::create(Color4B(20, 30, 52, 255), Color4B(20, 30, 52, 0));
	gradient_2->changeWidthAndHeight(1920, 200);
	gradient_2->setPosition(0, 0);
	gradient_2->setTag(2);
	//gradient_2->setOpacity(0);
	gradient->addChild(gradient_1, 1);
	gradient->addChild(gradient_2, 0);
	gradient->setPosition(0, 1080 - 550);

	addChild(gradient, 30);


	//panel
	panelLayer = LayerColor::create(Color4B(255, 255, 255, 37));
	panelLayer->changeWidthAndHeight(1920, 220);
	panelLayer->setPosition(0 , 1080 - 330);
	//panelLayer->setScaleY(0.03);
	addChild(panelLayer, 40);

	//drum panel
	drum_panel = Sprite::create("main/drum_panel.png");
	drum_panel->setPosition(1920 * 0.1, 1080 - 220);
	//drum_panel->setOpacity(0);
	addChild(drum_panel, 45);



	auto delay = DelayTime::create(0.1f);
	move = MoveBy::create(0.4f, Vec2(0, 1080));
	move->retain();
	auto callfunc1 = CallFunc::create([this]() { drum_t1->runAction(move->clone()); });
	auto callfunc2 = CallFunc::create([this]() { drum_t2->runAction(move->clone()); });
	auto callfunc3 = CallFunc::create([this]() { drum2->runAction(move->clone()); });
	auto callfunc4 = CallFunc::create([this]() { drum6->runAction(move->clone()); });
	auto callfunc5 = CallFunc::create([this]() { drum3->runAction(move->clone()); });
	auto callfunc6 = CallFunc::create([this]() { drum4->runAction(move->clone()); });
	auto callfunc7 = CallFunc::create([this]() { drum1->runAction(move->clone()); });
	auto callfunc8 = CallFunc::create([this]() { drum5->runAction(move->clone()); });

	auto callfunc9 = CallFunc::create([this]() { zhijia->runAction(FadeIn::create(0.5)); });

	
	auto callfunc10 = CallFunc::create([this]() { 
		gradient->getChildByTag(1)->runAction(FadeIn::create(0.2f));
		gradient->getChildByTag(2)->runAction(FadeIn::create(0.2f));

		light->runAction(FadeIn::create(0.2f));

		auto callfunc11 = CallFunc::create([this]() { drum_panel->runAction(FadeIn::create(0.5)); });
		panelLayer->runAction(Sequence::create(MoveBy::create(1.0f, Vec2(1920, 0)), ScaleTo::create(0.5f, 1, 1), DelayTime::create(0.2f), callfunc11, nullptr));
	});

	

	auto seq = Sequence::create(delay, callfunc1, delay, callfunc2, delay, callfunc3, delay, callfunc4,
								delay, callfunc5, delay, callfunc6, delay, callfunc7, delay, callfunc8, 
		                        DelayTime::create(0.5f), callfunc9, callfunc10, nullptr);
	//this->runAction(seq);


	// scheduler test
	auto sche = DJScheduler::create();
	addChild(sche);

	sche->StartTimer();

	//audio profile
	_audioProfile.name = "DrumPanel";
	_audioProfile.maxInstances = 10;
	_audioProfile.minDelay = 0.05;

	AudioEngine::preload(*XMLParseUtil::_bgmPath, [](bool isSuccess) {
		if (isSuccess)
		{
			//stateLabel->setString("status:load success");
			//log("load music/beat1.mp3  succeed!");
		}
		else
		{
			//stateLabel->setString("status:load fail");
			//log("load music/beat1.mp3  failed!");
		}
	});
}

MainGameScene::~MainGameScene()
{
	move->release();
}

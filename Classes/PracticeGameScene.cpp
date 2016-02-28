#include "PracticeGameScene.h"
#include "MenuScene.h"
#include "DJScheduler.h"

#include "math.h"

#include "DrumSprite.h"

#include "XMLParseUtil.h"

#include "ToastSprite.h"

#include "HUD.h"

#include "ScoreUtil.h"
#include "PauseLayer.h"
#include "GuideArrow.h"
#include "GuideLabel.h"
#include "CommonUtil.h"

USING_NS_CC;
using namespace cocos2d::experimental;

PracticeGameScene::~PracticeGameScene()
{

}

cocos2d::Scene* PracticeGameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = PracticeGameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool PracticeGameScene::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//my_init_old();
	my_init();
	//drum_test();

	return true;
}

void PracticeGameScene::menuCallbackBack(cocos2d::Ref* pSender)
{
	auto pauseLayer = PauseLayer::createPause();
	pauseLayer->setPosition(0, 0);

	addChild(pauseLayer, 200);
	AudioEngine::pause(_backId);
	Director::getInstance()->pause();
}

void PracticeGameScene::my_init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//clear score
	ScoreUtil::Clear();

	//audio profile
	_audioProfile.name = "DrumPanel";
	_audioProfile.maxInstances = 10;
	_audioProfile.minDelay = 0.01;

	AudioEngine::preload(*XMLParseUtil::_bgmPath, [](bool isSuccess) {});

	AudioEngine::preload(*XMLParseUtil::_musicPath[0], [](bool isSuccess) {});
	AudioEngine::preload(*XMLParseUtil::_musicPath[1], [](bool isSuccess) {});
	AudioEngine::preload(*XMLParseUtil::_musicPath[2], [](bool isSuccess) {});
	AudioEngine::preload(*XMLParseUtil::_musicPath[3], [](bool isSuccess) {});
	AudioEngine::preload(*XMLParseUtil::_musicPath[4], [](bool isSuccess) {});
	AudioEngine::preload(*XMLParseUtil::_musicPath[5], [](bool isSuccess) {});
	// background layer
	//auto back = LayerColor::create(Color4B(20, 30, 52, 255));

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemFont::create("Back", CC_CALLBACK_1(PracticeGameScene::menuCallbackBack, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	closeItem->setScale(2);
	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	//this->addChild(menu, 100);


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
	drum_t2->setPosition(1560, 1080 - 450);

	addChild(drum_t2, 10);

	drum1 = Node::create();
	auto drum1_d = DrumSprite::create("main/drum1.png");
	drum1_d->_order = 9;
	drum1_d->setSelSprite("main/drum1_sel.png");
	drum1_d->setMusicFile(*XMLParseUtil::_musicPath[0]);
	drum1_d->setPosition(0, 0);
	drum1_d->setTag(1);

	auto drum1_t = Sprite::create("main/drum1_t.png");
	drum1_t->setPosition(2, -20);

	drum1->addChild(drum1_d, 20);
	drum1->addChild(drum1_t, 10);

	drum1->setPosition(475, 1080 - 840);
	drum1->setTag(1);
	addChild(drum1, 9);

	drum1_d->RegistListenerPractice(_audioProfile);

	//
	drum3 = Node::create();
	auto drum3_d = DrumSprite::create("main/drum3.png");
	drum3_d->_order = 10;
	drum3_d->_order += 50;
	drum3_d->setSelSprite("main/drum3_sel.png");
	drum3_d->setMusicFile(*XMLParseUtil::_musicPath[2]);
	drum3_d->setPosition(0, 0);
	drum3_d->setTag(1);

	auto drum3_t = Sprite::create("main/drum3_t.png");
	drum3_t->setPosition(8, -14);

	drum3->addChild(drum3_d, 20);
	drum3->addChild(drum3_t, 10);

	drum3->setPosition(335, 1080 - 635);
	drum3->setTag(3);
	addChild(drum3, 60);

	drum3_d->RegistListenerPractice(_audioProfile);

	drum2 = Node::create();
	auto drum2_d = DrumSprite::create("main/drum2.png");
	drum2_d->_order = 11;
	drum2_d->setSelSprite("main/drum2_sel.png");
	drum2_d->setMusicFile(*XMLParseUtil::_musicPath[1]);
	drum2_d->setPosition(0, 0);

	auto drum2_t = Sprite::create("main/drum2_t.png");
	drum2_t->setPosition(12, -13);

	drum2->addChild(drum2_d, 20);
	drum2->addChild(drum2_t, 10);

	drum2->setPosition(730, 1080 - 640);
	drum2->setTag(2);
	addChild(drum2, 11);

	drum2_d->RegistListenerPractice(_audioProfile);

	drum6 = Node::create();
	auto drum6_d = DrumSprite::create("main/drum6.png");
	drum6_d->_order = 11;
	drum6_d->setSelSprite("main/drum6_sel.png");
	drum6_d->setMusicFile(*XMLParseUtil::_musicPath[5]);

	drum6_d->setPosition(0, 0);

	auto drum6_t = Sprite::create("main/drum6_t.png");
	drum6_t->setPosition(-6, -18);

	drum6->addChild(drum6_d, 20);
	drum6->addChild(drum6_t, 10);

	drum6->setPosition(1130, 1080 - 640);
	drum6->setTag(6);
	addChild(drum6, 11);

	drum6_d->RegistListenerPractice(_audioProfile);

	drum4 = Node::create();
	auto drum4_d = DrumSprite::create("main/drum4.png");
	drum4_d->_order = 10;
	drum4_d->setTag(1);
	drum4_d->setSelSprite("main/drum4_sel.png");
	drum4_d->setMusicFile(*XMLParseUtil::_musicPath[3]);

	drum4_d->setPosition(0, 0);


	auto drum4_t = Sprite::create("main/drum4_t.png");
	drum4_t->setPosition(0, 58);

	drum4->addChild(drum4_d, 20);
	drum4->addChild(drum4_t, 10);

	drum4->setPosition(930, 1080 - 950);
	drum4->setTag(4);
	addChild(drum4, 10);

	drum4_d->RegistListenerPractice(_audioProfile);

	drum5 = Node::create();
	auto drum5_d = DrumSprite::create("main/drum5.png");
	drum5_d->_order = 12;
	drum5_d->setTag(1);
	drum5_d->setSelSprite("main/drum5_sel.png");
	drum5_d->setMusicFile(*XMLParseUtil::_musicPath[4]);

	drum5_d->setPosition(0, 0);

	auto drum5_t = Sprite::create("main/drum5_t.png");
	drum5_t->setPosition(-15, -27);

	drum5->addChild(drum5_d, 20);
	drum5->addChild(drum5_t, 10);

	drum5->setPosition(1420, 1080 - 865);
	drum5->setTag(5);
	addChild(drum5, 12);

	drum5_d->RegistListenerPractice(_audioProfile);
	//zhijia
	zhijia = Sprite::create("main/zhijia.png");
	zhijia->setPosition(990, 265);
	//zhijia->setOpacity(0);

	addChild(zhijia, 5);


	//  灯光
	light = Sprite::create("main/light.png");
	light->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//light->setOpacity(0);

	addChild(light, 35);



	//hud
	auto hud_t = Sprite::create("main/hud.png");
	hud_t->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	//addChild(hud_t, 50);

	auto label = LabelTTF::create("PERFECT", "fonts/Duck-esa.ttf", 55);
	// 	label->setFontName("font/MF.otf");
	// 	label->setFontSize(30);
	label->setColor(Color3B(255, 0, 0));
	//label->setString("PERFECT 好");
	label->setPosition(visibleSize.width / 2, visibleSize.height*0.95);
	//addChild(label);

	hud_layer = HUD::create();
	hud_layer->ignoreAnchorPointForPosition(true);
	hud_layer->setPosition(0, 1020);
	//addChild(hud_layer, 50);



	//渐变层
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
	panelLayer->setPosition(0, 1080 - 330);
	//panelLayer->setScaleY(0.03);
	addChild(panelLayer, 40);

	//drum panel
	drum_panel = Sprite::create("main/drum_panel.png");
	drum_panel->setPosition(1920 * 0.1, 1080 - 220);
	//drum_panel->setOpacity(0);
	addChild(drum_panel, 45);

	// guchui
	guchui = Sprite::create("main/guchui.png");
	guchui->setAnchorPoint(Vec2(1, 1));
	guchui->setPosition(280, 970);
	guchui->setRotation(10);
	addChild(guchui, 100);

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


	// back menu
	//auto backItem = MenuItemImage::create("main/pause.png", "main/pause_sel.png", [this](Ref* sender) {});

	auto backItem = MenuItemImage::create("main/pause.png", "main/pause_sel.png", CC_CALLBACK_1(PracticeGameScene::menuCallbackBack, this));
	backItem->setAnchorPoint(Vec2(1, 0));
	backItem->setPosition(1900, 20);

	auto backMenu = Menu::create(backItem, nullptr);
	backMenu->setPosition(Vec2::ZERO);

	addChild(backMenu, 100);

	//  pause test
	// 	auto pauseLayer = PauseLayer::create();
	// 	pauseLayer->setPosition(0, 0);
	// 	
	// 	addChild(pauseLayer, 200);
	
	
	//  mask test
	mask = LayerColor::create(Color4B(0, 0, 0, 180));
	mask->changeWidthAndHeight(1920, 750);
	addChild(mask, 40);


	//lights test
	lights = Lights::create();
	lights->setPosition(960, 650);
	addChild(lights, 120);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event) {
		char buf[100] = { 0 };
		//log("Key %d was pressed!", (int)keyCode);


	};

	listener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
		char buf[100] = { 0 };
		//log("Key %d was released!", (int)keyCode);
		if (keyCode == EventKeyboard::KeyCode::KEY_HOME)
		{
			//Director::getInstance()->replaceScene(ModeSelectScene::createScene());
			AudioEngine::stop(_backId);
		}

	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// scheduler test
	sche = DJScheduler::create();
	addChild(sche);


	_backId =  AudioEngine::play2d("guide/guide_loop2.mp3", true, XMLParseUtil::_vol, &_audioProfile);

	sche->StartPracticeTimer();

	arrow = GuideArrow::create("guide/arrow.png");
	arrow->setPosition(700, 400);
	addChild(arrow, 200);
	arrow->RunAction();

	//label test
	guideLabel = GuideLabel::create();
	guideLabel->setString("音符靠近圆圈时，击中对应的鼓");
	guideLabel->setFontSize(45);
	guideLabel->setPosition(960, 500);
	addChild(guideLabel, 200);

	guideLabel->RunAction();
	
	

}



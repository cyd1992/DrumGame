#include "JiesuanScene.h"

#include "MenuScene.h"
#include "ScoreUtil.h"
#include "MainGameScene.h"
#include "BandSelectScene.h"


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
	
	char t[100];
	//  label
	auto score = LabelTTF::create();
	sprintf(t, "%d", ScoreUtil::_score);
	score->setString(t);
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		score->setFontName("fonts/MF.ttf");
	else score->setFontName("goma block");
	score->setAnchorPoint(Vec2(1, 0));
	score->setFontSize(70);
	score->setPosition(1710, 800);
	addChild(score, 10);

	auto scoreLabel = LabelTTF::create();
	scoreLabel->setString("SCORE");
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		scoreLabel->setFontName("fonts/MF.ttf");
	else scoreLabel->setFontName("goma block");
	scoreLabel->setAnchorPoint(Vec2(1, 0));
	scoreLabel->setFontSize(70);
	scoreLabel->setPosition(1410, 800);
	addChild(scoreLabel, 10);

	auto combo = LabelTTF::create();
	sprintf(t, "%d", ScoreUtil::_maxCombo);
	combo->setString(t);
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		combo->setFontName("fonts/MF.ttf");
	else combo->setFontName("goma block");
	combo->setAnchorPoint(Vec2(1, 0));
	combo->setFontSize(70);
	combo->setPosition(1710, 650);
	addChild(combo, 10);

	auto comboLabel = LabelTTF::create();
	comboLabel->setString("MAX COMBO");
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		comboLabel->setFontName("fonts/MF.ttf");
	else comboLabel->setFontName("goma block");
	comboLabel->setAnchorPoint(Vec2(1, 0));
	comboLabel->setFontSize(70);
	comboLabel->setPosition(1410, 650);
	addChild(comboLabel, 10);

	auto perfect = LabelTTF::create();
	sprintf(t, "%d", ScoreUtil::_perfect);
	perfect->setString(t);
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		perfect->setFontName("fonts/MF.ttf");
	else perfect->setFontName("goma block");
	perfect->setAnchorPoint(Vec2(1, 0));
	perfect->setFontSize(70);
	perfect->setPosition(1710, 570);
	addChild(perfect, 10);

	auto perfectLabel = LabelTTF::create();
	perfectLabel->setString("PERFECT");
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		perfectLabel->setFontName("fonts/MF.ttf");
	else perfectLabel->setFontName("goma block");
	perfectLabel->setAnchorPoint(Vec2(1, 0));
	perfectLabel->setFontSize(70);
	perfectLabel->setPosition(1410, 570);
	addChild(perfectLabel, 10);

	auto great = LabelTTF::create();
	sprintf(t, "%d", ScoreUtil::_great);
	great->setString(t);
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		great->setFontName("fonts/MF.ttf");
	else great->setFontName("goma block");
	great->setAnchorPoint(Vec2(1, 0));
	great->setFontSize(70);
	great->setPosition(1710, 490);
	addChild(great, 10);

	auto greatLabel = LabelTTF::create();
	greatLabel->setString("GREAT");
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		greatLabel->setFontName("fonts/MF.ttf");
	else greatLabel->setFontName("goma block");
	greatLabel->setAnchorPoint(Vec2(1, 0));
	greatLabel->setFontSize(70);
	greatLabel->setPosition(1410, 490);
	addChild(greatLabel, 10);

	auto miss = LabelTTF::create();
	sprintf(t, "%d", ScoreUtil::_miss);
	miss->setString(t);
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		miss->setFontName("fonts/MF.ttf");
	else miss->setFontName("goma block");
	miss->setAnchorPoint(Vec2(1, 0));
	miss->setFontSize(70);
	miss->setPosition(1710, 410);
	addChild(miss, 10);

	auto missLabel = LabelTTF::create();
	missLabel->setString("MISS");
	if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		missLabel->setFontName("fonts/MF.ttf");
	else missLabel->setFontName("goma block");
	missLabel->setAnchorPoint(Vec2(1, 0));
	missLabel->setFontSize(70);
	missLabel->setPosition(1410, 410);
	addChild(missLabel, 10);

	
	// BUTTON
	auto item1 = MenuItemImage::create("jiesuan/restart.png", "jiesuan/restart_sel.png", [&](Ref *sender) {
		Director::getInstance()->replaceScene(MainGameScene::createScene());
	} );
	auto item2 = MenuItemImage::create("jiesuan/return.png", "jiesuan/return_sel.png", [&](Ref *sender) {
		Director::getInstance()->replaceScene(BandSelectScene::createScene());
	} );
	item1->setAnchorPoint(Vec2(1, 0));
	item2->setAnchorPoint(Vec2(1, 0));
	item1->setPosition(1200, 180);
	item2->setPosition(1920, 180);
	
	auto menu = Menu::create(item1, item2, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 10);
	return true;
}

void JiesuanScene::menuCallbackBack(Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::createScene());
}
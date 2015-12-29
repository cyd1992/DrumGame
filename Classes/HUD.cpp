#include "HUD.h"

USING_NS_CC;

HUD* HUD::create()
{
	HUD * ret = new (std::nothrow) HUD();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool HUD::init()
{
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	//perform
	_perform = LabelTTF::create("PERFECT", "goma block", 55);
	_perform->setColor(Color3B(255, 0, 0));
	_perform->setPosition(960, 0);
	_perform->setScaleX(0);
	addChild(_perform, 0);

	// combo const
	_comboConst = LabelTTF::create("COMBO", "goma block", 70);
	_comboConst->setColor(Color3B(255, 255, 255));
	_comboConst->setPosition(310, 10);
	addChild(_comboConst);

	//combo
	_combo = LabelTTF::create("55", "goma block", 110);
	_combo->setColor(Color3B(255, 255, 255));
	_combo->setPosition(100, 0);
	addChild(_combo);

	//score const
	_score = LabelTTF::create("     0", "goma block", 110);
	_score->setColor(Color3B(255, 255, 255));
	_score->setPosition(1890, -60);
	_score->setAnchorPoint(Vec2(1, 0));
	addChild(_score);

	return true;
}

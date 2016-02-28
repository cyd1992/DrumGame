#include "Lights.h"
USING_NS_CC;

Lights* Lights::create()
{
	Lights *node = new (std::nothrow) Lights();
	if (node && node->init())
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return nullptr;

}

bool Lights::init()
{
	if (!Node::init())
	{
		return false;
	}

	// add four lights
	for (int i = 0; i < 4; i++)
	{
		_light[i] = Sprite::create("guide/light.png");
		_light[i]->setPosition(-180 + i*120, 0);

		addChild(_light[i]);

	}

	return true;
}

void Lights::Clear()
{
	for (int i = 0; i < 4; i++)
	{
		_light[i]->setTexture("guide/light.png");
	}

	_curIndex = -1;
}


void Lights::Right()
{
	if (_curIndex < 3)
	{
		_curIndex++;
		_light[_curIndex]->setTexture("guide/light_green.png");
	}
}

void Lights::Wrong()
{
	if (_curIndex < 3)
	{
		_curIndex++;
		_light[_curIndex]->setTexture("guide/light_red.png");
	}

	auto delay = DelayTime::create(0.5);
	auto callfunc = CallFunc::create([this]() {
		Clear();
	});

	this->runAction(Sequence::create(delay, callfunc,nullptr));

	
}



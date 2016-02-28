#ifndef __LIGHTS_H__
#define __LIGHTS_H__

#include "cocos2d.h"

class Lights : public cocos2d::Node
{
public:
	static Lights* create();
	virtual bool init();

	cocos2d::Sprite* _light[4];

	void Clear();
	void Right();
	void Wrong();

	int _curIndex = -1;
};

#endif

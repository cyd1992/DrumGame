#ifndef __HUD_LAYER_H__
#define __HUD_LAYER_H__

#include "cocos2d.h"

class HUD : public cocos2d::Layer
{
public:
	static HUD* create();
	virtual bool init();

	cocos2d::LabelTTF* _perform;
	cocos2d::LabelTTF* _score;
	cocos2d::LabelTTF* _combo;
private:
	cocos2d::LabelTTF* _comboConst;
	cocos2d::LabelTTF* _scoreConst;
};


#endif

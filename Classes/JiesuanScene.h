#ifndef __JIESUAN_SCENE_H__
#define __JIESUAN_SCENE_H__

#include "cocos2d.h"

class JiesuanScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(JiesuanScene);

	void menuCallbackBack(cocos2d::Ref* sender);

};

#endif

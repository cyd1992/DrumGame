#ifndef __WELCOME_SCENE_H__
#define __WELCOME_SCENE_H__

#include "cocos2d.h"

class WelcomeScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(WelcomeScene);

	void menuCallback(cocos2d::Ref* sender);
};

#endif // __HELLOWORLD_SCENE_H__

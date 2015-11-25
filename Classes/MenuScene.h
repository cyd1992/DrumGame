#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MenuScene);

	void menuCallback(cocos2d::Ref* sender);
	void menuCallbackAudio(cocos2d::Ref* sender);
	void menuCallbackDisk(cocos2d::Ref* sender);
	void menuCallbackMain(cocos2d::Ref* sender);
};

#endif // __HELLOWORLD_SCENE_H__

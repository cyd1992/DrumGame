#ifndef __PRACTICE_SELECT_SCENE_H__
#define __PRACTICE_SELECT_SCENE_H__


#include "cocos2d.h"

class PracticeSelectScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(PracticeSelectScene);

	void menuCallbackBack(cocos2d::Ref* sender);
	void menuCallbackLevel1(cocos2d::Ref* sender);
	void menuCallbackLevel2(cocos2d::Ref* sender);
	void menuCallbackLevel3(cocos2d::Ref* sender);



};


#endif
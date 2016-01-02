#ifndef __BAND_SELECT_SCENE_H__
#define __BAND_SELECT_SCENE_H__

#include "cocos2d.h"

class BandSelectScene : public cocos2d::Layer
{
public:
	BandSelectScene();

	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	void my_init_old();
	void my_init();

	// implement the "static create()" method manually
	CREATE_FUNC(BandSelectScene);

	void menuCallbackBack(cocos2d::Ref* sender);
	void menuCallbackLevel1(cocos2d::Ref* sender);
	void menuCallbackLevel2(cocos2d::Ref* sender);
	void menuCallbackLevel3(cocos2d::Ref* sender);


	void CallbackRight(cocos2d::Ref* sender);
	void CallbackLeft(cocos2d::Ref* sender);

private:
	int _curIndex = 0;
	int _maxItem = 3;
	cocos2d::Node* _bandItem[3];
	const std::string _title[3] = {"guanghuisuiyue","blabla","blabla"};
	const std::string _musicFile[3] = { "level/level_sample_1.xml","level/level_sample_1.xml","level/level_sample_1.xml" };
	cocos2d::Node* createItem(int index);
};




#endif

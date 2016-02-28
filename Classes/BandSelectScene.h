#ifndef __BAND_SELECT_SCENE_H__
#define __BAND_SELECT_SCENE_H__

#include "cocos2d.h"

#include "CommonUtil.h"

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
	int _maxItem = 4;
	cocos2d::Node* _bandItem[4];
	const std::string _title[4] = {"光辉岁月","rolling in the deep","练习曲一","练习曲二"};
	const std::string _musicFile[4] = { "level/level_sample_1.xml","level/level2/level2.xml","practice/practice4/practice4.xml","level/level3/level3.xml"};
	const std::string _thumbFile[4] = { "band/thumb1.png","band/rolling.png","band/practice.png","band/practice.png" };

	cocos2d::Node* createItem(int index);
};



#endif

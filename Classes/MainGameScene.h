#ifndef __MAIN_GAME_SCENE_H__
#define __MAIN_GAME_SCENE_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

#include "ComboNode.h"

class MainGameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCallbackBack(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MainGameScene);

	cocos2d::LabelTTF* _scoreLabel;
	int _score = 0;
	int _curTag = 100;
	int _combo = 0;

	int _backId;
	cocos2d::experimental::AudioProfile _audioProfile;

	ComboNode* _comboNode;

};

#endif

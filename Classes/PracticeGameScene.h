#ifndef __PRACTICE_GAME_SCENE_H__
#define __PRACTICE_GAME_SCENE_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

#include "ComboNode.h"

#include "ToastSprite.h"
#include "HUD.h"
#include "Lights.h"
#include "GuideArrow.h"
#include "GuideLabel.h"

#include "DJScheduler.h"

class PracticeGameScene : public cocos2d::Layer
{
public:
	~PracticeGameScene();

	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCallbackBack(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(PracticeGameScene);

	cocos2d::LabelTTF* _scoreLabel;
	int _score = 0;
	int _curTag = 100;
	int _curTag2 = 100;

	int _combo = 0;

	int _backId;
	cocos2d::experimental::AudioProfile _audioProfile;

	ComboNode* _comboNode;

	ToastSprite* _toastSprite;
	HUD* hud_layer;

	cocos2d::Sprite* guchui;
	cocos2d::Sprite* drum_panel;

	cocos2d::LayerColor* mask;
	Lights* lights;

	GuideArrow* arrow;
	GuideLabel* guideLabel;

	int guide_index = 0;

	DJScheduler* sche;

	void my_init();

	cocos2d::Node* drum1, *drum2, *drum3, *drum4, *drum5, *drum6;
	cocos2d::Sprite* drum_t1, *drum_t2;
	cocos2d::Sprite* zhijia;

	cocos2d::MoveBy* move;
	cocos2d::Node* gradient;
	cocos2d::LayerColor* panelLayer;

	cocos2d::Sprite* light;


};


#endif

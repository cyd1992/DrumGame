#ifndef __MAIN_GAME_SCENE_H__
#define __MAIN_GAME_SCENE_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

#include "ComboNode.h"

#include "ToastSprite.h"
#include "HUD.h"
class MainGameScene : public cocos2d::Layer
{
public:
	~MainGameScene();

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

	ToastSprite* _toastSprite;
	HUD* hud_layer;

private:
	void my_init_old();
	void my_init();
	void drum_test();

	cocos2d::EventListenerTouchOneByOne* getListener(std::string file);


	cocos2d::Node* drum1, *drum2, *drum3, *drum4, *drum5, *drum6 ;
	cocos2d::Sprite* drum_t1, *drum_t2;
	cocos2d::Sprite* zhijia;

	cocos2d::MoveBy* move;
	cocos2d::Node* gradient;
	cocos2d::LayerColor* panelLayer;
	cocos2d::Sprite* drum_panel;
	cocos2d::Sprite* light;


};

#endif

#ifndef __BAND_SELECT_SCENE_H__
#define __BAND_SELECT_SCENE_H__

#include "cocos2d.h"
#include "MainGameScene.h"

class ScoreUtil
{
public:
	static void SetScore(float dist , MainGameScene* scene );

private:
	static void SetPerform(MainGameScene* scene, std::string s, cocos2d::Color3B c);
};

#endif

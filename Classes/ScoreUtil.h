#ifndef __SCORE_UTIL_H__
#define __SCORE_UTIL_H__

#include "cocos2d.h"
#include "MainGameScene.h"

class ScoreUtil
{
public:
	static void SetScore(float dist , MainGameScene* scene );
	static void Clear();

	static int _score ;
	static int _perfect;
	static int _great;
	static int _miss;
	static int _maxCombo;
private:
	static void SetPerform(MainGameScene* scene, std::string s, cocos2d::Color3B c);
};

#endif

#include "ScoreUtil.h"

#include "NoteNode.h"
#include "CommonUtil.h"

USING_NS_CC;

int ScoreUtil::_score = 0;
int ScoreUtil::_perfect = 0;
int ScoreUtil::_great = 0;
int ScoreUtil::_miss = 0;
int ScoreUtil::_maxCombo = 0;

void ScoreUtil::SetScore(float dist, MainGameScene* scene)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();


	if (dist < 0) dist = dist * -1;
	log("dist: %f", dist);
	if (dist < 120 && dist > -40)
	{
		//scene->_curTag++;
		int type = 2;
		scene->_combo++;
		if (_maxCombo < scene->_combo) _maxCombo = scene->_combo;

		int score_temp = 10;

		if (dist < 60 )
		{
			score_temp = 100;
			type = 0;
			_perfect++;
		}
		else 
		{
			score_temp = 70;
			type = 1;
			_great++;
		}

		float combo_factor = 1;

		if (scene->_combo >= 10) combo_factor = 1.2;
		if (scene->_combo >= 30) combo_factor = 1.5;

		scene->_score += score_temp * combo_factor;

		//toast

		char t[100];
		sprintf(t, "%d", scene->_score);
		scene->hud_layer->_score->setString(t);

		char t2[10];
		sprintf(t2, "%d", scene->_combo);
		scene->hud_layer->_combo->setString(t2);

		switch (type)
		{
		case 0:SetPerform(scene, "PERFECT", Color3B(191, 56, 142));break;
		case 1:SetPerform(scene, "GREAT", Color3B(0, 125, 197)); break;
		case 2:SetPerform(scene, "NICE", Color3B(0, 163, 89)); break;
		case 3:SetPerform(scene, "NICE", Color3B(0, 163, 89)); break;
		default:
			break;
		}

		auto note = (NoteNode*)(scene->getChildByTag(scene->_curTag));
		note->isKilled = true;

		note->stopAllActions();
		note->removeFromParentAndCleanup(true);

		//add particle
		auto p = CommonUtil::createParticle();
		p->setPosition(1920 * 0.1, 860);
		scene->addChild(p, 59);
		
		scene->_curTag++;
		

	}
	else
	{
		scene->_combo = 0;
		_miss++;
	}

}

void ScoreUtil::Clear()
{
	_score = 0;
	_perfect = 0;
	_great = 0;
	_miss = 0;
	_maxCombo = 0;
}

void ScoreUtil::SetPerform(MainGameScene* scene, std::string s, Color3B c)
{
	scene->hud_layer->_perform->stopAllActions();
	scene->hud_layer->_perform->setString(s);
	scene->hud_layer->_perform->setScaleX(0);
	scene->hud_layer->_perform->setColor(c);
	scene->hud_layer->_perform->runAction(ScaleTo::create(0.1f, 1, 1));
}


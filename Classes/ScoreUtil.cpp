#include "ScoreUtil.h"

#include "NoteNode.h"

USING_NS_CC;

void ScoreUtil::SetScore(float dist, MainGameScene* scene)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();


	if (dist < 0) dist = dist * -1;
	log("dist: %f", dist);
	if (dist <= 100)
	{
		//scene->_curTag++;
		int type = 2;
		scene->_combo++;

		int score_temp = 10;

		if (dist < 50)
		{
			score_temp = 100;
			type = 0;
		}
		else if(dist < 70)
		{
			score_temp = 50;
			type = 1;
		}

		float combo_factor = 1;

		if (scene->_combo >= 10) combo_factor = 1.2;
		if (scene->_combo >= 50) combo_factor = 1.5;

		scene->_score += score_temp * combo_factor;

		//toast
		if (scene->_toastSprite != nullptr)
		{
			scene->_toastSprite->stopAllActions();
			scene->_toastSprite->removeFromParentAndCleanup(true);
		}

		scene->_toastSprite = ToastSprite::create(type);
		scene->_toastSprite->setPosition(visibleSize.width *0.5, visibleSize.height *0.7);
		scene->_toastSprite->setOpacity(0);
		scene->addChild(scene->_toastSprite, 30);
		scene->_toastSprite->RunAction();

		char t[100];
		sprintf(t, "%d", scene->_score);
		scene->_scoreLabel->setString(t);

		char t2[10];
		sprintf(t2, "combo x%d", scene->_combo);
		scene->_comboNode->stopAllActions();
		scene->_comboNode->_label->setOpacity(0);
		scene->_comboNode->_label->setString(t2);

		scene->_comboNode->RunAction();

		((NoteNode*)(scene->getChildByTag(scene->_curTag)))->isKilled = true;

		scene->_curTag++;
		

	}
	else
	{
		scene->_combo = 0;
	}

}


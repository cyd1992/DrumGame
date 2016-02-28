#include "ActionUtil.h"
#include "CommonUtil.h"
#include "DrumSprite.h"
USING_NS_CC;

void ActionUtil::Switch(PracticeGameScene* scene, int index)
{

	if (index == 1)
	{

		scene->guideLabel->setString("good!");
		scene->guideLabel->RunAction();


		//scene->sche->isUpdate = false;

		// remove current drops
		int t = scene->sche->type_table[0];

		scene->removeChildByTag(t*10 +1);
		scene->removeChildByTag(t * 10 +2);
		scene->removeChildByTag(t * 10 +3);
		scene->removeChildByTag(t * 10 +4);

		scene->drum3->setZOrder(10);
		auto sprite3 = (DrumSprite*)(scene->drum3->getChildByTag(1));
		sprite3->_order = 10;

		scene->drum1->setZOrder(60);
		auto sprite1 = (DrumSprite*)(scene->drum1->getChildByTag(1));
		sprite1->_order = 60;

		scene->lights->Clear();

		scene->sche->_curIndex = index;
		scene->sche->isUpdate = true;
		
		scene->arrow->setPosition(800, 250);
	}
	if (index == 2)
	{

		scene->guideLabel->setString("good!");
		scene->guideLabel->RunAction();


		//scene->sche->isUpdate = false;

		// remove current drops
		int t = scene->sche->type_table[1];

		scene->removeChildByTag(t * 10 + 1);
		scene->removeChildByTag(t * 10 + 2);
		scene->removeChildByTag(t * 10 + 3);
		scene->removeChildByTag(t * 10 + 4);

		scene->drum1->setZOrder(10);
		auto sprite1 = (DrumSprite*)(scene->drum1->getChildByTag(1));
		sprite1->_order = 10;

		scene->drum4->setZOrder(60);
		auto sprite4 = (DrumSprite*)(scene->drum4->getChildByTag(1));
		sprite4->_order = 60;

		scene->lights->Clear();

		scene->sche->_curIndex = index;
		scene->sche->isUpdate = true;

		scene->arrow->setPosition(1230, 150);
	}
	if (index == 3)
	{

		scene->guideLabel->setString("good!");
		scene->guideLabel->RunAction();


		//scene->sche->isUpdate = false;

		// remove current drops
		int t = scene->sche->type_table[1];

		scene->removeChildByTag(t * 10 + 1);
		scene->removeChildByTag(t * 10 + 2);
		scene->removeChildByTag(t * 10 + 3);
		scene->removeChildByTag(t * 10 + 4);

		scene->drum4->setZOrder(10);
		auto sprite4 = (DrumSprite*)(scene->drum4->getChildByTag(1));
		sprite4->_order = 10;

		scene->drum5->setZOrder(60);
		auto sprite5 = (DrumSprite*)(scene->drum5->getChildByTag(1));
		sprite5->_order = 60;

		scene->lights->Clear();

		scene->sche->_curIndex = index;
		scene->sche->isUpdate = true;

		scene->arrow->setPosition(1750, 150);
	}
	if (index == 4)
	{
		// over
		scene->drum5->setZOrder(10);
		auto sprite5 = (DrumSprite*)(scene->drum5->getChildByTag(1));
		sprite5->_order = 10;
		
		scene->guideLabel->setFontSize(80);
		scene->guideLabel->setString("恭喜！您已经成功完成新手引导");

		scene->mask->removeFromParentAndCleanup(true);

		scene->sche->isOver = true;
	}
	
}

void ActionUtil::Stay(PracticeGameScene* scene, int index)
{
	scene->guideLabel->setString("Miss! Let's do it again");
	scene->guideLabel->RunAction();

	int t = scene->sche->type_table[index];

	scene->removeChildByTag(t * 10 + 1);
	scene->removeChildByTag(t * 10 + 2);
	scene->removeChildByTag(t * 10 + 3);
	scene->removeChildByTag(t * 10 + 4);

	scene->sche->isUpdate = true;

}

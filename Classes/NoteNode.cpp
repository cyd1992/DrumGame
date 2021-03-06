#include "NoteNode.h"
#include "MainGameScene.h"
#include "ScoreUtil.h"
#include "PracticeGameScene.h"
#include "ActionUtil.h"

USING_NS_CC;

NoteNode* NoteNode::create(int type ,int note_tag)
{
	NoteNode *node = new (std::nothrow) NoteNode();
	if (node && node->init(type,note_tag))
	{
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
	return nullptr;
}

bool NoteNode::init(int type,int note_tag)
{
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	std::string file;
	switch (type)
	{
	case 1: file = "main/drum_panel1.png"; break;
	case 2: file = "main/drum_panel6.png"; break;
	case 3: file = "main/drum_panel3.png"; break;
	case 4: file = "main/drum_panel4.png"; break;
	case 5: file = "main/drum_panel5.png"; break;
	case 6: file = "main/drum_panel6.png"; break;
	default:
		break;
	}

	auto sprite = Sprite::create(file);
	addChild(sprite);

	char t[100];
	sprintf(t, "%d", note_tag);

	auto tagLabel = LabelTTF::create();
	tagLabel->setFontName("Marker Felt");
	tagLabel->setFontSize(48);
	tagLabel->setString(t);
	//addChild(tagLabel);

	return true;
}

void NoteNode::StartDrop()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float speed = 0.65;
	// 	auto move1 = MoveBy::create(1.5, Vec2(0, -1 * visibleSize.height));
	// 	auto move2 = MoveBy::create(0.5, Vec2(0, -1 * visibleSize.height / 3));

	auto move1 = MoveBy::create( (2.7  ) * speed, Vec2(-1 * (1920), 0));
	auto callfunc1 = CallFunc::create([this]() {
		//log("remove!");
		//this->removeFromParentAndCleanup(true);
		auto scene = (MainGameScene*)(this->getParent());

		//if(this->getTag() >= scene->_curTag)
		//	scene->_curTag = this->getTag();
		auto last = (NoteNode*)(scene->getChildByTag(scene->_curTag));
		if (last != NULL)
		{
			if(last->isKilled || last->isOver) scene->_curTag = this->getTag();
			//else scene->_curTag2 = this->getTag();
		}

		//if auto   play music

	});
	auto move2 = MoveBy::create( (0.3 - 0.028125*3) * speed, Vec2(-1 * (1920 * 0.1 -60), 0));

	auto callfunc2 = CallFunc::create([this]() {
		//log("remove!");
		//this->removeFromParentAndCleanup(true);
// 		auto scene = (MainGameScene*)(this->getParent());
// 		scene->_curTag = this->getTag();
		//if auto  play music

	});

	auto move3 = MoveBy::create((0.3 + 0.028125*3)* speed, Vec2(-1 * (1920 *0.1 +60), 0));

	auto callfunc3 = CallFunc::create([this]() {
		//log("remove!");
		//
		this->isOver = true;
		auto scene = (MainGameScene*)(this->getParent());

		scene->_curTag = this->getTag() + 1;
		if (!this->isKilled)
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();

			
			scene->_combo = 0;
			ScoreUtil::_miss++;

			scene->hud_layer->_combo->setString("0");
			
			scene->hud_layer->_perform->stopAllActions();
			scene->hud_layer->_perform->setString("MISS");
			scene->hud_layer->_perform->setScaleX(0);
			scene->hud_layer->_perform->setColor(Color3B(255, 0, 0));
			scene->hud_layer->_perform->runAction(ScaleTo::create(0.1f, 1, 1));
			//scene->hud_layer->_perform->setScaleX(0);

			//toast
// 			if (scene->_toastSprite != nullptr)
// 			{
// 				scene->_toastSprite->stopAllActions();
// 				scene->_toastSprite->removeFromParentAndCleanup(true);
// 			}
// 
// 			scene->_toastSprite = ToastSprite::create(4);
// 			scene->_toastSprite->setPosition(visibleSize.width *0.5, visibleSize.height *0.7);
// 			scene->_toastSprite->setOpacity(0);
// 			scene->addChild(scene->_toastSprite, 30);
// 			scene->_toastSprite->RunAction();



		}
	});

	auto move4 = MoveBy::create(1, Vec2(-1 * 1920 / 3, 0));
	auto callfunc4 = CallFunc::create([this]() {
		//log("remove!");
		this->removeFromParentAndCleanup(true);
	});

	auto seq = Sequence::create(DelayTime::create(3*(1-speed)),move1, callfunc1, move2, callfunc2, move3, callfunc3, move4, callfunc4, NULL);

	this->runAction(seq);


}

void NoteNode::StartDropPractice()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float speed = 0.65;

	int t = this->getTag() % 10 - 1;

	// 	auto move1 = MoveBy::create(1.5, Vec2(0, -1 * visibleSize.height));
	// 	auto move2 = MoveBy::create(0.5, Vec2(0, -1 * visibleSize.height / 3));

	auto move1 = MoveBy::create(2.7 * speed + 0.75 * t, Vec2(-1 * (1920 + 1920.0*0.75*t / (3 * speed)), 0));
	auto callfunc1 = CallFunc::create([this]() {
		auto scene = (MainGameScene*)(this->getParent());
		scene->_curTag = this->getTag();

	});
	auto move2 = MoveBy::create(0.3 * speed, Vec2(-1 * 1920 * 0.1, 0));

	auto callfunc2 = CallFunc::create([this]() {



	});

	auto move3 = MoveBy::create(0.3 * speed, Vec2(-1 * 1920 *0.1, 0));

	auto callfunc3 = CallFunc::create([this]() {
		//log("remove!");
		//


		auto scene = (PracticeGameScene*)(this->getParent());
		scene->_curTag = 0;

		scene->lights->Wrong();
		ActionUtil::Stay(scene, scene->guide_index);
	});

	auto move4 = MoveBy::create(1, Vec2(-1 * 1920 / 3, 0));
	auto callfunc4 = CallFunc::create([this]() {
		log("remove!");
		this->removeFromParentAndCleanup(true);
	});

	auto seq = Sequence::create(DelayTime::create(3 * (1 - speed)), move1, callfunc1, move2, callfunc2, move3, callfunc3, move4, callfunc4, NULL);

	this->runAction(seq);
}


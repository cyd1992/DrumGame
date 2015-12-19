#include "NoteNode.h"
#include "MainGameScene.h"

USING_NS_CC;

NoteNode* NoteNode::create(int note_tag)
{
	NoteNode *node = new (std::nothrow) NoteNode();
	if (node && node->init(note_tag))
	{
		node->autorelease();

		return node;
	}
	CC_SAFE_DELETE(node);
	return nullptr;
}

bool NoteNode::init(int note_tag)
{
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	auto sprite = Sprite::create("note.png");
	addChild(sprite);

	char t[100];
	sprintf(t, "%d", note_tag);

	auto tagLabel = LabelTTF::create();
	tagLabel->setFontName("Marker Felt");
	tagLabel->setFontSize(48);
	tagLabel->setString(t);
	addChild(tagLabel);

	return true;
}

void NoteNode::StartDrop()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// 	auto move1 = MoveBy::create(1.5, Vec2(0, -1 * visibleSize.height));
	// 	auto move2 = MoveBy::create(0.5, Vec2(0, -1 * visibleSize.height / 3));

	auto move1 = MoveBy::create(2.7, Vec2(-1 * visibleSize.width, 0));
	auto callfunc1 = CallFunc::create([this]() {
		//log("remove!");
		//this->removeFromParentAndCleanup(true);
		auto scene = (MainGameScene*)(this->getParent());
		scene->_curTag = this->getTag();
		//if auto   play music

	});
	auto move2 = MoveBy::create(0.3, Vec2(-1 * visibleSize.width * 0.1, 0));

	auto callfunc2 = CallFunc::create([this]() {
		//log("remove!");
		//this->removeFromParentAndCleanup(true);
// 		auto scene = (MainGameScene*)(this->getParent());
// 		scene->_curTag = this->getTag();
		//if auto   play music

	});

	auto move3 = MoveBy::create(0.3, Vec2(-1 * visibleSize.width *0.1, 0));

	auto callfunc3 = CallFunc::create([this]() {
		//log("remove!");
		//
		if (!this->isKilled)
		{
			Size visibleSize = Director::getInstance()->getVisibleSize();

			auto scene = (MainGameScene*)(this->getParent());
			scene->_combo = 0;
			
			//toast
			if (scene->_toastSprite != nullptr)
			{
				scene->_toastSprite->stopAllActions();
				scene->_toastSprite->removeFromParentAndCleanup(true);
			}

			scene->_toastSprite = ToastSprite::create(4);
			scene->_toastSprite->setPosition(visibleSize.width *0.5, visibleSize.height *0.7);
			scene->_toastSprite->setOpacity(0);
			scene->addChild(scene->_toastSprite, 30);
			scene->_toastSprite->RunAction();
		}
	});

	auto move4 = MoveBy::create(1, Vec2(-1 * visibleSize.width / 3, 0));
	auto callfunc4 = CallFunc::create([this]() {
		//log("remove!");
		this->removeFromParentAndCleanup(true);
	});

	auto seq = Sequence::create(move1, callfunc1, move2, callfunc2, move3, callfunc3, move4, callfunc4, NULL);

	this->runAction(seq);
}


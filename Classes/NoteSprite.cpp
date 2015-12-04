#include "NoteSprite.h"

#include "MainGameScene.h"
USING_NS_CC;

NoteSprite* NoteSprite::create(const std::string& filename)
{
	NoteSprite *sprite = new (std::nothrow) NoteSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();

		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


void NoteSprite::StartDrop()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

// 	auto move1 = MoveBy::create(1.5, Vec2(0, -1 * visibleSize.height));
// 	auto move2 = MoveBy::create(0.5, Vec2(0, -1 * visibleSize.height / 3));

	auto move1 = MoveBy::create(3, Vec2(-1 * visibleSize.width, 0));
	auto callfunc1 = CallFunc::create([this]() {
		//log("remove!");
		//this->removeFromParentAndCleanup(true);
		auto scene = (MainGameScene*)(this->getParent());
		scene->_curTag = this->getTag();
		//if auto   play music

	});
	auto move2 = MoveBy::create(1, Vec2(-1 * visibleSize.width/3, 0));
	auto callfunc2 = CallFunc::create([this]() {
		//log("remove!");
		this->removeFromParentAndCleanup(true);
	});

	auto seq = Sequence::create(move1,callfunc1, move2, callfunc2, NULL);

	this->runAction(seq);
}
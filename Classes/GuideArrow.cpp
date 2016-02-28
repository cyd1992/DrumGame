#include "GuideArrow.h"

USING_NS_CC;

GuideArrow* GuideArrow::create(const std::string& filename)
{
	GuideArrow *sprite = new (std::nothrow) GuideArrow();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();

		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void GuideArrow::RunAction()
{
	auto move = MoveBy::create(0.75f, Vec2(-20, 0));
	auto callfunc = CallFunc::create([this]() {
		this->setPosition(this->getPosition() + Vec2(20, 0));
	});

	this->runAction(RepeatForever::create(Sequence::create(move, callfunc, nullptr)));
}




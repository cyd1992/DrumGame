#include "ToastSprite.h"
USING_NS_CC;

ToastSprite* ToastSprite::create(int type)
{
	std::string filename;
	switch (type)
	{
		case 0:filename = "perfect.png";break;
		case 1:filename = "great.png"; break;
		case 2:filename = "nice.png"; break;
		case 3:filename = "nice.png"; break;
		case 4:filename = "miss.png"; break;
	default:
		break;
	}

	ToastSprite *sprite = new (std::nothrow) ToastSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->_type = type;
		sprite->autorelease();

		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void ToastSprite::RunAction()
{
	auto fadein = FadeIn::create(0.5);

	this->runAction(Sequence::create(fadein, nullptr));
}


#include "ToastSprite.h"
USING_NS_CC;

ToastSprite* ToastSprite::create(const std::string& filename)
{
	ToastSprite *sprite = new (std::nothrow) ToastSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();


		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


#include "CommonUtil.h"

USING_NS_CC;

cocos2d::ParticleFlower* CommonUtil::createParticle()
{
	auto _emitter = ParticleFlower::create();
	_emitter->retain();
	_emitter->setDuration(0.05f);
	_emitter->setLife(0.1f);
	_emitter->setTotalParticles(40);
	//_emitter->set
	_emitter->setStartSize(40);
	_emitter->setEndSize(0);
	_emitter->setEmissionRate(20000);
	_emitter->setColor(Color3B(253, 245, 92));
	_emitter->setStartColor(Color4F(253, 245, 92, 255));

	_emitter->setTexture(Director::getInstance()->getTextureCache()->addImage("stars.png"));
	_emitter->setAutoRemoveOnFinish(true);

	return _emitter;
}

void CommonUtil::WStrToUTF8(std::string& dest, const std::string& src) {
	dest.clear();

	for (size_t i = 0; i < src.size(); i++) {
		wchar_t w = src[i];
		if (w <= 0x7f)
			dest.push_back((char)w);
		else if (w <= 0x7ff)
		{
			dest.push_back(0xc0 | ((w >> 6) & 0x1f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else if (w <= 0xffff)
		{
			dest.push_back(0xe0 | ((w >> 12) & 0x0f));
			dest.push_back(0x80 | ((w >> 6) & 0x3f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else if (sizeof(wchar_t) > 2 && w <= 0x10ffff)
		{
			dest.push_back(0xf0 | ((w >> 18) & 0x07)); // wchar_t 4-bytes situation  
			dest.push_back(0x80 | ((w >> 12) & 0x3f));
			dest.push_back(0x80 | ((w >> 6) & 0x3f));
			dest.push_back(0x80 | (w & 0x3f));
		}
		else
			dest.push_back('?');
	}
}

std::string CommonUtil::WStrToUTF8(const std::string& str)
{
	std::string result;
	WStrToUTF8(result, str);
	return result;

}




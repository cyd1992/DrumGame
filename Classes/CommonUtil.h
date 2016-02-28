#ifndef __COMMON_UTIL_H__
#define __COMMON_UTIL_H__

#include "cocos2d.h"

class CommonUtil
{
public:
	static cocos2d::ParticleFlower* createParticle();
	static void WStrToUTF8(std::string& dest, const std::string& src);
	static std::string WStrToUTF8(const std::string& str);
};


#endif

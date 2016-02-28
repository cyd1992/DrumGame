#ifndef __GUIDE_ARROW_H__
#define __GUIDE_ARROW_H__

#include "cocos2d.h"

class GuideArrow : public cocos2d::Sprite
{
public:
	static GuideArrow* create(const std::string& filename);
	
	void RunAction();

};
#endif

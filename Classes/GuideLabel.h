#ifndef __GUIDE_LABEL_H__
#define __GUIDE_LABEL_H__

#include "cocos2d.h"

class GuideLabel: public cocos2d::LabelTTF
{
public:
	//static GuideLabel* create(const std::string& filename);
	CREATE_FUNC(GuideLabel);
	void RunAction();

};



#endif

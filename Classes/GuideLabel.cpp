#include "GuideLabel.h"
#include "CommonUtil.h"
USING_NS_CC;

void GuideLabel::RunAction()
{
	this->setOpacity(0);

	auto callfunc = CallFunc::create([this](){ 
		this->setString("音符靠近圆圈时，击中对应的鼓");
	});
	this->runAction(Sequence::create(FadeIn::create(0.5),DelayTime::create(0.3f),callfunc, nullptr));


}





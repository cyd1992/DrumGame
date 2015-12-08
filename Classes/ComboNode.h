#ifndef  _COMBO_NODE_H_
#define  _COMBO_NODE_H_

#include "cocos2d.h"

class ComboNode : public cocos2d::Node
{
public:


	static ComboNode* create(int combo);

	virtual bool init(int combo);

	cocos2d::LabelTTF* _label;

	void RunAction();

};


#endif

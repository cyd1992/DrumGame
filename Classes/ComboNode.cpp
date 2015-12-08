#include "ComboNode.h"

USING_NS_CC;

ComboNode* ComboNode::create(int combo)
{
	ComboNode *node = new (std::nothrow) ComboNode();
	if (node && node->init(combo))
	{
		node->autorelease();

		return node;
	}
	CC_SAFE_DELETE(node);
	return nullptr;
}

bool ComboNode::init(int combo)
{
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	char t[100];
	sprintf(t, "combo x%d", combo);

	_label = LabelTTF::create();
	_label->setFontName("Marker Felt");
	_label->setFontSize(30);
	_label->setColor(Color3B(255, 0, 0));
	_label->setString(t);
	addChild(_label);
	return true;
}

void ComboNode::RunAction()
{
	auto fadein = FadeIn::create(0.5);

	_label->runAction(Sequence::create(fadein,nullptr));

}


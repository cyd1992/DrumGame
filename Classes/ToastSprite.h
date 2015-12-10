#ifndef  _TOAST_SPRITE_H_
#define  _TOAST_SPRITE_H_

#include "cocos2d.h"

class ToastSprite : public cocos2d::Sprite
{
public:
	//   0    perfect
	//   1    great
	//   2    nice
	//   3    bad
	//   4    miss
	int _type = 0;

	// rewrite
	static ToastSprite* create(int type);

	void RunAction();
	
};


#endif

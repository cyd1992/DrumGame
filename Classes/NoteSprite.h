#ifndef  _NOTE_SPRITE_H_
#define  _NOTE_SPRITE_H_

#include "cocos2d.h"

class NoteSprite : public cocos2d::Sprite
{
public:

	int _id = 6;
	int _auto = 0;
	int _type;

	static NoteSprite* create(const std::string& filename);

	void StartDrop();

};

#endif

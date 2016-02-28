#ifndef  _NOTE_NODE_H_
#define  _NOTE_NODE_H_

#include "cocos2d.h"

class NoteNode : public cocos2d::Node
{
public:

	int _noteTag;
	int _auto = 0;
	int _type;

	bool isKilled = false;
	bool isOver = false;

	static NoteNode* create(int type, int note_tag);

	virtual bool init(int type,int note_tag);

	void StartDrop();
	void StartDropPractice();
};


#endif

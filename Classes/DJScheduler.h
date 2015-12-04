#ifndef __DJ_SCHEDULER_H__
#define __DJ_SCHEDULER_H__

#include "cocos2d.h"
#include "NoteInfo.h"

class DJScheduler : public cocos2d::Node
{
public:
	static DJScheduler* create();
	int _id = 0;
	NoteInfo _note;

	float _time = 0.0f;

	void StartTimer();

	void callback1(float dt);

};


#endif

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
	float t = 2.8f;

	void StartTimer();
	void StartPracticeTimer();

	void callback1(float dt);
	void callback2(float dt);

	void callbackPractice(float dt);
	float abs(float f);

	void createDrops(int type);

	bool isUpdate = true;
	int _curIndex = 0;
	int type_table[4] = { 3,1,4,5 };

	bool isOver = false;

};


#endif

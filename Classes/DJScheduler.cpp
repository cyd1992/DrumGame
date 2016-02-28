#include "DJScheduler.h"
#include "XMLParseUtil.h"
#include "NoteInfo.h"

#include "NoteSprite.h"
#include "NoteNode.h"
#include <math.h>

#include "MainGameScene.h"

#include "JiesuanScene.h"
#include "ScoreUtil.h"
#include "PracticeGameScene.h"
#include "PauseLayer.h"
USING_NS_CC;
using namespace cocos2d::experimental;
//float DJScheduler::_time = -3.0f;
//int DJScheduler::_id = 0;


void DJScheduler::callback1(float dt)
{


	if(_id<XMLParseUtil::_vec.size())
	_note = (NoteInfo)XMLParseUtil::_vec.at(_id);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//CCLOG("time: %f",_time);
	float time_temp = _time - 3.0f;

	//log("time_temp: %f  time:%f", time_temp,_time);
	if (time_temp < 0.01  &&  time_temp >-0.01)
	{
		//play back
		auto scene = (MainGameScene*)this->getParent();
		scene->_backId = AudioEngine::play2d(*XMLParseUtil::_bgmPath, false, 0.3f, &scene->_audioProfile);
		//log("time_temp: %f", time_temp);
	}else if ( time_temp < XMLParseUtil::_total )
	{
		float note_time = _note._time;
		float pre_time = time_temp + 3.0f;
		if (abs(note_time - pre_time) < 0.01)
		{
			//drumpane's tag is 101;
			//Layer* panel = (Layer*)(this->getParent());

			//note test
			auto noteSprite = NoteNode::create(_note._type,_id);

// 			if(_note._index == 0) noteSprite->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
// 			else if(_note._index == 1) noteSprite->setPosition(visibleSize.width *0.3, visibleSize.height *1.2);

			noteSprite->setPosition(visibleSize.width *1.20, visibleSize.height * 0.9);
			noteSprite->setScale(2);
			noteSprite->setScaleX(0.7);
			if (_note._type == 1)
			{
				noteSprite->setScale(1);
				noteSprite->setScaleX(0.8);
			}
			if (_note._type == 2 || _note._type == 6)
			{

			}

			//noteSprite->setOpacity(100);
			//panel->addChild(noteSprite);
			noteSprite->setTag(100 + _id);
			this->getParent()->addChild(noteSprite, 20);
			noteSprite->StartDrop();

			_id++;

		}


		
		//CCLOG("dt: %f    time: %f", dt,_time);
	}
	else
	{
		log("end!");
		AudioEngine::stop(( (MainGameScene*)this->getParent())->_backId);
		Director::getInstance()->replaceScene(JiesuanScene::createScene());
	}

	_time += dt;
}

void DJScheduler::callback2(float dt)
{
	if (_id < XMLParseUtil::_vec.size())
		_note = (NoteInfo)XMLParseUtil::_vec.at(_id);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//CCLOG("time: %f",_time);
	float time_temp = _time - 3.0f;

	//log("time_temp: %f  time:%f", time_temp,_time);
	if (time_temp < 0.01  &&  time_temp >-0.01)
	{
		//play back
		auto scene = (MainGameScene*)this->getParent();
		scene->_backId = AudioEngine::play2d(*XMLParseUtil::_bgmPath, false, XMLParseUtil::_vol, &scene->_audioProfile);
		//log("time_temp: %f", time_temp);
	}
	else if (time_temp < XMLParseUtil::_total)
	{
		float note_time = _note._time;
		float pre_time = time_temp + 3.0f;
		if (abs(note_time - pre_time) < 0.01)
		{
			//drumpane's tag is 101;
			//Layer* panel = (Layer*)(this->getParent());

			//note test
			auto noteSprite = NoteNode::create(_note._type,_id);
			noteSprite->_type = _note._type;

			float speed = 0.65f;
			// 			if(_note._index == 0) noteSprite->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
			// 			else if(_note._index == 1) noteSprite->setPosition(visibleSize.width *0.3, visibleSize.height *1.2);

			noteSprite->setPosition(1920.0 *1.2 + 70 + 1920.0*_note._feedback/(3*speed), 860);
// 			noteSprite->setScale(2);
// 			noteSprite->setScaleX(0.7);
			if (_note._type == 1 || _note._type == 5)
			{
				noteSprite->setScale(0.8);

			}

			if (_note._type == 2 || _note._type == 6)
			{
				noteSprite->setScale(0.6);
			}

			//noteSprite->setOpacity(100);
			//panel->addChild(noteSprite);
			noteSprite->setTag(100 + _id);
			this->getParent()->addChild(noteSprite, 60);
			noteSprite->StartDrop();

			_id++;

		}



		//CCLOG("dt: %f    time: %f", dt,_time);
	}
	else
	{
		log("end!");
		
		ScoreUtil::_score = ((MainGameScene*)this->getParent())->_score;
		AudioEngine::stop(((MainGameScene*)this->getParent())->_backId);
		Director::getInstance()->replaceScene(JiesuanScene::createScene());
	}

	_time += dt;
}


void DJScheduler::callbackPractice(float dt)
{
	//if (_time <9.001 && _time >8.999)
	//t = 6.0;
	if(_time <(t + 0.001) && _time>(t-0.001) )
	{

		// add four node

		createDrops(_curIndex);

		t += 3.0;

		if (isOver)
		{
			auto scene = (PracticeGameScene*)(this->getParent());

			auto pauseLayer = PauseLayer::createPause();
			pauseLayer->setPosition(0, 0);

			scene->addChild(pauseLayer, 200);
			AudioEngine::pause(scene->_backId);
			Director::getInstance()->pause();

			isOver = false;
		}
	}

	_time += dt;
}


void DJScheduler::createDrops(int type)
{
	type = type_table[type];

	if (isUpdate) {
		float speed = 0.65f;
		float feedback = 0;
		auto noteSprite1 = NoteNode::create(type, 0);
		noteSprite1->setPosition(1920 * 1.2 - feedback, 860);
		noteSprite1->_type = type;
		noteSprite1->setTag(type*10 +1);
		this->getParent()->addChild(noteSprite1, 60);
		noteSprite1->StartDropPractice();

		auto noteSprite2 = NoteNode::create(type, 0);
		noteSprite2->setPosition(1920 * 1.2 + 1920.0*0.75 / (3 * speed) - feedback, 860);
		noteSprite2->_type = type;
		noteSprite2->setTag(type * 10 +2 );
		this->getParent()->addChild(noteSprite2, 60);
		noteSprite2->StartDropPractice();

		auto noteSprite3 = NoteNode::create(type, 0);
		noteSprite3->setPosition(1920 * 1.2 + 1920.0*0.75 * 2 / (3 * speed) - feedback, 860);
		noteSprite3->_type = type;
		noteSprite3->setTag(type*10 +3);
		this->getParent()->addChild(noteSprite3, 60);
		noteSprite3->StartDropPractice();

		auto noteSprite4 = NoteNode::create(type, 0);
		noteSprite4->setPosition(1920 * 1.2 + 1920.0*0.75 * 3 / (3 * speed) - feedback, 860);
		noteSprite4->_type = type;
		noteSprite4->setTag(type * 10 +4);
		this->getParent()->addChild(noteSprite4, 60);
		noteSprite4->StartDropPractice();

		isUpdate = false;
	}
	
}



void DJScheduler::StartTimer()
{
	schedule(CC_SCHEDULE_SELECTOR(DJScheduler::callback2), 0.1f);
}

void DJScheduler::StartPracticeTimer()
{
	schedule(CC_SCHEDULE_SELECTOR(DJScheduler::callbackPractice), 0.2f);
}

DJScheduler* DJScheduler::create()
{
	DJScheduler * ret = new (std::nothrow) DJScheduler();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

float DJScheduler::abs(float f)
{
	return f > 0 ? f : (-1.0*f);
}





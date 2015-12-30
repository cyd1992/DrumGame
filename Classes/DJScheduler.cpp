#include "DJScheduler.h"
#include "XMLParseUtil.h"
#include "NoteInfo.h"

#include "NoteSprite.h"
#include "NoteNode.h"
#include <math.h>

#include "MainGameScene.h"

#include "JiesuanScene.h"
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
				noteSprite->setScaleX(0.7);
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
		scene->_backId = AudioEngine::play2d(*XMLParseUtil::_bgmPath, false, 0.3f, &scene->_audioProfile);
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

			// 			if(_note._index == 0) noteSprite->setPosition(visibleSize.width *0.17, visibleSize.height *1.2);
			// 			else if(_note._index == 1) noteSprite->setPosition(visibleSize.width *0.3, visibleSize.height *1.2);

			noteSprite->setPosition(visibleSize.width *1.15, 860);
// 			noteSprite->setScale(2);
// 			noteSprite->setScaleX(0.7);
			if (_note._type == 1)
			{
				noteSprite->setScale(0.8);

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
		AudioEngine::stop(((MainGameScene*)this->getParent())->_backId);
		Director::getInstance()->replaceScene(JiesuanScene::createScene());
	}

	_time += dt;
}

void DJScheduler::StartTimer()
{
	schedule(CC_SCHEDULE_SELECTOR(DJScheduler::callback2), 0.1f);
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




#include "DrumSprite.h"

#include "MainGameScene.h"

#include "ScoreUtil.h"
#include "PracticeGameScene.h"
#include "NoteNode.h"

#include "ActionUtil.h"
#include "CommonUtil.h"

USING_NS_CC;
using namespace cocos2d::experimental;

DrumSprite::DrumSprite()
{
	_musicFile = new std::string(100, 0);
	_selSprite = new std::string(100, 0);
	_sprite =  new std::string(100, 0);
}

DrumSprite::~DrumSprite()
{
	delete _musicFile;
	delete _selSprite;
	delete _sprite;
}

DrumSprite* DrumSprite::create(const std::string& filename)
{
	DrumSprite *sprite = new (std::nothrow) DrumSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sprite->_sprite->assign(filename);
		//sprite->_id = 7;
		//sprite->musicFile = new std::string("music/t1.mp3");
		//log("%d", sprite->_id);///////////////////////////////////////////////
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;

}

void DrumSprite::setMusicFile(const std::string& musicFile)
{

	this->_musicFile->assign(musicFile);// = new std::string(musicFile);
										//this->musicFile = musicFile;

}



void DrumSprite::setSelSprite(const std::string& selFile)
{
	_selSprite->assign(selFile);
}


void DrumSprite::RegistListener(cocos2d::experimental::AudioProfile& _audioProfile)
{
	// Make sprite1 touchable
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//log("touched!");

		if (rect.containsPoint(locationInNode))
		{
			
			

			//log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			//target->setOpacity(180);


			//log("%s",this->_musicFile);
			//log(musicFile->_string) ;
			_id = AudioEngine::play2d(this->_musicFile->c_str(), false, 1.0f, &_audioProfile);
			int id = _id;
			//log("_idBack: %d", _id);
			// 			if (id != AudioEngine::INVALID_AUDIO_ID) {
			// 				log("--");
			// 			}
			//}
			this->setTexture(_selSprite->c_str());
			this->getParent()->setZOrder(60);

			auto scene = (MainGameScene*)(this->getParent()->getParent());

			scene->guchui->setRotation(0);//runAction(RotateTo::create(0.1f, 0));

			scene->drum_panel->setPosition(scene->drum_panel->getPosition() + Vec2(4,-4));

			Size visibleSize = Director::getInstance()->getVisibleSize();
			//score 
			
			auto note = (NoteNode*)scene->getChildByTag(scene->_curTag);
			if (note != nullptr) {
				if (this->getParent()->getTag() == note->_type)
				{
					float dist = note->getPositionX() - visibleSize.width * 0.1;					
					ScoreUtil::SetScore(dist, scene);
				}
// 				else
// 				{
// 					auto note = (NoteNode*)scene->getChildByTag(scene->_curTag2);
// 					if (note != nullptr) {
// 						if (this->getParent()->getTag() == note->_type)
// 						{
// 							float dist = note->getPositionX() - visibleSize.width * 0.1;
// 							ScoreUtil::SetScore(dist, scene);
// 						}
// 					}
// 				}
				

			}
			

			return true;
		}

		return false;
	};

	listener1->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		this->setTexture(_sprite->c_str());
		this->getParent()->setZOrder(this->_order);
		//this->setSpriteFrame(SpriteFrame::create("main/drum4.png", Rect(0, 0, 417, 242)));

		auto scene = (MainGameScene*)(this->getParent()->getParent());
		scene->guchui->setRotation(10);
		scene->drum_panel->setPosition(scene->drum_panel->getPosition() + Vec2(-4, 4));
		// 		log("sprite onTouchesEnded.. ");
		//target->setOpacity(255);

		//auto temp = static_cast<AudioTestScene*>(target->getParent());


		//log("moved!");
	};

	listener1->retain();

	(this->getParent()->getParent())->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);


}

void DrumSprite::RegistListenerPractice(cocos2d::experimental::AudioProfile& _audioProfile)
{
	// Make sprite1 touchable
	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		//log("touched!");

		if (rect.containsPoint(locationInNode))
		{

			//log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
			//target->setOpacity(180);


			//log("%s",this->_musicFile);
			//log(musicFile->_string) ;
			_id = AudioEngine::play2d(this->_musicFile->c_str(), false, 1.0f, &_audioProfile);
			int id = _id;
			//log("_idBack: %d", _id);
			// 			if (id != AudioEngine::INVALID_AUDIO_ID) {
			// 				log("--");
			// 			}
			//}
			this->setTexture(_selSprite->c_str());
			this->getParent()->setZOrder(60);

			auto scene = (PracticeGameScene*)(this->getParent()->getParent());

			scene->guchui->setRotation(0);//runAction(RotateTo::create(0.1f, 0));

			scene->drum_panel->setPosition(scene->drum_panel->getPosition() + Vec2(4, -4));

			Size visibleSize = Director::getInstance()->getVisibleSize();
			//score 

			auto note = (NoteNode*)scene->getChildByTag(scene->_curTag);
			if (note != nullptr) {
				if (this->getParent()->getTag() == note->_type)
				{
					float dist = note->getPositionX() - visibleSize.width * 0.1;
					if (dist<150 && dist >-100)
					{
						auto note = (NoteNode*)(scene->getChildByTag(scene->_curTag));
						note->isKilled = true;

						note->stopAllActions();
						note->removeFromParentAndCleanup(true);

						//add particle
						auto p = CommonUtil::createParticle();
						p->setPosition(1920 * 0.1, 860);
						scene->addChild(p, 59);


						scene->lights->Right();
						if (scene->lights->_curIndex == 3)
						{
							scene->guide_index++;
							ActionUtil::Switch(scene, scene->guide_index);
						}
					}
				}
				else
				{
					scene->lights->Wrong();
					ActionUtil::Stay(scene, scene->guide_index);
				}
				


			}


			return true;
		}

		return false;
	};

	listener1->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		this->setTexture(_sprite->c_str());
		this->getParent()->setZOrder(this->_order);
		//this->setSpriteFrame(SpriteFrame::create("main/drum4.png", Rect(0, 0, 417, 242)));

		auto scene = (MainGameScene*)(this->getParent()->getParent());
		scene->guchui->setRotation(10);
		scene->drum_panel->setPosition(scene->drum_panel->getPosition() + Vec2(-4, 4));
		// 		log("sprite onTouchesEnded.. ");
		//target->setOpacity(255);

		//auto temp = static_cast<AudioTestScene*>(target->getParent());


		//log("moved!");
	};

	listener1->retain();

	(this->getParent()->getParent())->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);
}

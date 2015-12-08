#include "DrumSprite.h"

#include "MainGameScene.h"



USING_NS_CC;
using namespace cocos2d::experimental;

DrumSprite::DrumSprite()
{
	_musicFile = new std::string(100, 0);
}

DrumSprite::~DrumSprite()
{
	delete _musicFile;
}

DrumSprite* DrumSprite::create(const std::string& filename)
{
	DrumSprite *sprite = new (std::nothrow) DrumSprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		//sprite->_id = 7;
		//sprite->musicFile = new std::string("music/t1.mp3");
		//log("%d", sprite->_id);
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
			//auto temp =  static_cast<AudioTestScene*>(target->getParent());

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


			Size visibleSize = Director::getInstance()->getVisibleSize();
			//score
			auto scene = (MainGameScene*)(this->getParent());
			auto note = scene->getChildByTag(scene->_curTag);
			float dist = note->getPositionX() - visibleSize.width * 0.15;

			if (dist < 0) dist =  dist * -1;
			log("dist: %f", dist);
			if (dist <= 50)
			{
				scene->_combo++;

				scene->_score += 100;
				char t[100];
				sprintf(t, "%d", scene->_score);
				scene->_scoreLabel->setString(t);	


				char t2[10];
				sprintf(t2, "combo x%d", scene->_combo);
				scene->_comboNode->stopAllActions();
				scene->_comboNode->_label->setOpacity(0);
				scene->_comboNode->_label->setString(t2);

				scene->_comboNode->RunAction();
				
				
			}
			else
			{
				scene->_combo = 0;
			}

			return true;
		}

		return false;
	};

	listener1->onTouchEnded = [&](Touch* touch, Event* event) {
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		// 		log("sprite onTouchesEnded.. ");
		//target->setOpacity(255);

		//auto temp = static_cast<AudioTestScene*>(target->getParent());

		//AudioEngine::stop(_id);
		// 		if (target == sprite2)
		// 		{
		// 			containerForSprite1->setLocalZOrder(100);
		// 		}
		// 		else if (target == sprite1)
		// 		{
		// 			containerForSprite1->setLocalZOrder(0);
		// 		}

		//log("moved!");
	};

	listener1->retain();

	(this->getParent())->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);


}
#include "DrumSprite.h"

#include "MainGameScene.h"

#include "ScoreUtil.h"

#include "NoteNode.h"

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
			
			//this->setSpriteFrame(SpriteFrame::create("main/drum4_sel.png", Rect(0, 0, 457, 282)));
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
			this->setTexture(_selSprite->c_str());
			this->getParent()->setZOrder(60);

			Size visibleSize = Director::getInstance()->getVisibleSize();
			//score 
			auto scene = (MainGameScene*)(this->getParent()->getParent());
			auto note = (NoteNode*)scene->getChildByTag(scene->_curTag);
			if (note != nullptr) {

				float dist = note->getPositionX() - visibleSize.width * 0.1;
				if (this->getParent()->getTag() == note->_type)
				{
					ScoreUtil::SetScore(dist, scene);
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

	(this->getParent()->getParent())->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener1, this);


}
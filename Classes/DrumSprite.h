#ifndef  _DRUM_SPRITE_H_
#define  _DRUM_SPRITE_H_

#include "cocos2d.h"

#include "audio/include/AudioEngine.h"

#include <string>

class DrumSprite : public cocos2d::Sprite
{
public:
	DrumSprite();
	virtual ~DrumSprite();

	int _id = 6;
	int _order;

	static DrumSprite* create(const std::string& filename);

	static cocos2d::experimental::AudioProfile _audioProfile;

	void setMusicFile(const std::string& musicFile);
	void setSelSprite(const std::string& selFile);
	void RegistListener(cocos2d::experimental::AudioProfile& _audioProfile);

	std::string* _sprite;
	std::string* _musicFile;
	std::string* _selSprite;

};


#endif

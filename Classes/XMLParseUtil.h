#ifndef __XML_PARSER_UTIL_H__
#define __XML_PARSER_UTIL_H__

#include "cocos2d.h"

#include "NoteInfo.h"

class XMLParseUtil
{
public:
	~XMLParseUtil();

	static void ParseLevel(const char* file);

	//static cocos2d::Vector<NoteInfo> _vec;
	static float _total;
	static float _vol;
	static std::vector<NoteInfo> _vec;
	static std::string * _musicPath[10];
	static std::string * _bgmPath;


	static void PrintVec();
};





#endif

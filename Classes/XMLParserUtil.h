#ifndef __XML_PARSER_UTIL_H__
#define __XML_PARSER_UTIL_H__

#include "cocos2d.h"

#include "NoteInfo.h"

class XMLParseUtil
{
public:
	static void ParseLevel(const char* file);

	//static cocos2d::Vector<NoteInfo> _vec;
	static std::vector<NoteInfo> _vec;

	static void PrintVec();
};





#endif

#include "XMLParserUtil.h"

#include "cocos-ext.h"
#include "tinyxml2/tinyxml2.h"
#include <vector>

USING_NS_CC;
//using namespace tinyxml2;

std::vector<NoteInfo> XMLParseUtil::_vec;
std::string * XMLParseUtil::_musicPath[10] = { new std::string(),new std::string(),new std::string(),new std::string(),new std::string(),new std::string(),new std::string(),new std::string(),new std::string(),new std::string() };
std::string * XMLParseUtil::_bgmPath = new std::string();


XMLParseUtil::~XMLParseUtil()
{
	delete _bgmPath;
	delete[] _musicPath;
}

void XMLParseUtil::ParseLevel(const char* file)
{
// 	const char* file_path = FileUtils::getInstance()->fullPathForFilename("test.xml").c_str();
// 	log("external file path: %s", file_path);
	

	//first clear vec
	_vec.clear();


	//create XMLDocument
	tinyxml2::XMLDocument* myDocument = new tinyxml2::XMLDocument();
	myDocument->LoadFile(file);

	//get root node  level
	tinyxml2::XMLElement* rootElement = myDocument->RootElement();

	//get bgm node
	tinyxml2::XMLElement* bgmElement = rootElement->FirstChildElement();

	delete _bgmPath;
	_bgmPath = new std::string(bgmElement->GetText());

	//log("%s", rootElement->GetText());

	//   track
	tinyxml2::XMLElement* trackElement = bgmElement->NextSiblingElement();

		tinyxml2::XMLElement* element = trackElement->FirstChildElement();
		int i = 0;
		while (element)
		{
			log("message: %s", element->GetText());

			delete _musicPath[i];
			_musicPath[i] = new std::string(element->GetText());
			i++;

			element = element->NextSiblingElement();
		}

//	while (trackElement)
//	{
// 		tinyxml2::XMLElement* element = drumElement->FirstChildElement();
// 		while (element)
// 		{
// 			log("message: %s", element->GetText());
// 
// 			element = element->NextSiblingElement();
// 		}
// 
// 		drumElement = drumElement->NextSiblingElement();
//	}

	//   total
	tinyxml2::XMLElement* totalElement = trackElement->NextSiblingElement();

	log("total: %s", totalElement->GetText());

	//  note-list
	tinyxml2::XMLElement* noteElement = totalElement->NextSiblingElement();

	//note
	noteElement = noteElement->FirstChildElement();

	while (noteElement)
	{
		tinyxml2::XMLElement* element = noteElement->FirstChildElement();
		NoteInfo note;
		log(noteElement->Value());
		while (element)
		{
			

			if (strcmp(element->Value(), "id") == 0)
			{
				//log("id = %s", element->GetText());
				note._id = atoi(element->GetText());
				log("id = %d", note._id);
			}
			else if(strcmp(element->Value(), "time") == 0)
			{
				note._time = atof(element->GetText());
				log("time = %f", note._time);
			}
			else if (strcmp(element->Value(), "type") == 0)
			{
				note._type = atoi(element->GetText());
				log("type = %d", note._type);
			}	
			else if (strcmp(element->Value(), "auto") == 0)
			{
				note._auto = atoi(element->GetText());
				log("type = %d", note._auto);
			}
			element = element->NextSiblingElement();
		}
		_vec.push_back(note);

		noteElement = noteElement->NextSiblingElement();
	}

	PrintVec();
	//

}

void XMLParseUtil::PrintVec()
{
	log("size: %d", _vec.size());

	//print musicPath
	for (int i = 0; i < 6; i++)
	{
		log("src%d : %s",i, _musicPath[i]->c_str());
	}

	for (auto& e : _vec)
	{
 		log("id:%d  time:%f ", e._id,e._time);
// 		log("panel:%d  type:%d  index:%d", e._panel, e._type, e._index);
	}

}

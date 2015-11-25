#include "XMLParserUtil.h"

#include "cocos-ext.h"
#include "tinyxml2/tinyxml2.h"
#include <vector>

USING_NS_CC;
//using namespace tinyxml2;

std::vector<NoteInfo> XMLParseUtil::_vec;

void XMLParseUtil::ParseLevel(const char* file)
{
// 	const char* file_path = FileUtils::getInstance()->fullPathForFilename("test.xml").c_str();
// 	log("external file path: %s", file_path);
	//create XMLDocument
	tinyxml2::XMLDocument* myDocument = new tinyxml2::XMLDocument();
	myDocument->LoadFile(file);

	//get root node  level
	tinyxml2::XMLElement* rootElement = myDocument->RootElement();

	//log("%s", rootElement->GetText());

	//   track
	tinyxml2::XMLElement* trackElement = rootElement->FirstChildElement();

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
	for (auto& e : _vec)
	{
// 		log("id:%d  time:%f  track:%d", e._id,e._time,e._track);
// 		log("panel:%d  type:%d  index:%d", e._panel, e._type, e._index);
	}

}

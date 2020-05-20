
#include <string>
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/rapidjson.h"

//This is a document parser
//the goal of the parser is to iterate through a json object to pull out the relevant data
//It should pull out a list of the authors, the title, and each word within the text and abstract
//It then passes the relevant data to an indexer which takes the data and stores it

//This uses the rapidjson library extensively

#include "unordered_map"
class DocumentParser{
    private:

        //The Document Currently Being Parsed
        std::string currentDoc;

        void parseBodyText(rapidjson::Value&);

        void parseBodyBlock(rapidjson::Value&,std::unordered_map<std::string,int> &);

    public:
        //Constructors
        DocumentParser();
        DocumentParser(std::string);
        DocumentParser(DocumentParser&);

        ~DocumentParser();

        std::string getCurrentDoc();

        void setCurrentDoc(std::string);

        void parseDoc();


};
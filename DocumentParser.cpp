#include "DocumentParser.h"

#include <iostream>
#include "fstream"
#include <string>
#include "lib/rapidjson/filereadstream.h"
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/istreamwrapper.h"

DocumentParser::DocumentParser(){
    currentDoc="";
}

DocumentParser::DocumentParser(std::string newDoc){
    currentDoc = newDoc;
}

DocumentParser::~DocumentParser(){

}

std::string DocumentParser::getCurrentDoc(){
    return currentDoc;
}

void DocumentParser::setCurrentDoc(std::string newDoc){
    currentDoc = newDoc;
}

void DocumentParser::outputDoc(){
    std::ifstream input(currentDoc);

    rapidjson::Document doc;
    rapidjson::IStreamWrapper inputWrapper(input);
    
    
    doc.ParseStream(inputWrapper);

    if(doc.HasParseError()){
        std::cout << "Parse Error" << std::endl;
    }

    if(doc["metadata"].HasMember("title")){
        std::cout << doc["metadata"]["title"].GetString() << std::endl;
    }
}
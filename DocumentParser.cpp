#include "DocumentParser.h"

#include <iostream>
#include "fstream"
#include <string>
#include "lib/rapidjson/filereadstream.h"
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/istreamwrapper.h"
#include "unordered_map"
#include "utility"

DocumentParser::DocumentParser(){
    currentDoc="";
}

DocumentParser::DocumentParser(std::string newDoc){
    currentDoc = newDoc;
}

DocumentParser::~DocumentParser(){

}

DocumentParser::DocumentParser(DocumentParser & cpy) {
    this->currentDoc = cpy.currentDoc;
}


std::string DocumentParser::getCurrentDoc(){
    return currentDoc;
}

void DocumentParser::setCurrentDoc(std::string newDoc){
    currentDoc = newDoc;
}

void DocumentParser::parseDoc(){
    std::ifstream input(currentDoc);

    rapidjson::Document doc;
    rapidjson::IStreamWrapper inputWrapper(input);
    
    
    doc.ParseStream(inputWrapper);

    if(doc.HasParseError()){
        std::cout << "Parse Error" << std::endl;
    }

    rapidjson::Value& bodyText = doc["body_text"];

    parseBodyText(bodyText);
}


void DocumentParser::parseBodyText(rapidjson::Value & bodyText) {
    for(rapidjson::SizeType i = 0; i < bodyText.Size(); i++){
        parseBodyBlock(bodyText[i]["text"]);
    }
}

void DocumentParser::parseBodyBlock(rapidjson::Value& text){

    //Converting Block into a string
    std::string block = text.GetString();

    //Creating a Map of words to the amount of times it appears
    std::unordered_map<std::string,int> wordMap;

    //The Current Word
    std::string currWord= "";

    for(char letter : block){
        if(letter == ' '){
            //If the word is not empty
            if(currWord.compare("") == 0){

            }else{ //If there is a word

                //Removing punctuation from front
                while(ispunct(*currWord.begin())!=0){
                    currWord.erase(0,1);
                }

                //Removing punctuation from back
                while(ispunct(currWord[currWord.size()-1])!=0){
                    currWord.pop_back();
                }

                if(wordMap.find(currWord)!=wordMap.end()){
                    //Increment appearence count and reset word
                    wordMap[currWord]++;
                    currWord="";
                }else{
                    //Add Word to map and reset word
                    wordMap.insert(std::pair<std::string,int>(currWord,1));
                    currWord="";
                }
            }
        }else{
            //add next letter
            currWord+=letter;
        }
    }

    for(auto iter = wordMap.begin(); iter!=wordMap.end();iter++){
        std::cout << iter->first << " " << iter->second << std::endl;
    }

}



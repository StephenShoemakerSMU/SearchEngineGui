#include "DocumentParser.h"

#include <iostream>
#include "fstream"
#include <string>
#include "lib/rapidjson/filereadstream.h"
#include "lib/rapidjson/document.h"
#include "lib/rapidjson/istreamwrapper.h"
#include "unordered_map"
#include "utility"
#include "porter2_stemmerWrapper.h"
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



    parseBodyText(doc);
}


void DocumentParser::parseBodyText(rapidjson::Value & doc) {
    //Total Map of words and how much they appear
    std::unordered_map<std::string,int> totalMap;

    parseBodyBlock(doc["metadata"]["title"],totalMap);
    parseBodyBlock(doc["abstract"][0]["text"],totalMap);

    for(rapidjson::SizeType i = 0; i < doc["body_text"].Size(); i++){

        parseBodyBlock(doc["body_text"][i]["text"],totalMap);

    }

    for(auto iter = totalMap.begin(); iter !=totalMap.end(); iter++){
        std::cout << iter->first << " " << iter->second<< std::endl;
    }


}

void DocumentParser::parseBodyBlock(rapidjson::Value& text, std::unordered_map<std::string,int>& wordMap){

    //Converting Block into a string
    std::string block = text.GetString();


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
                while(ispunct(currWord.size()>1 && currWord[currWord.size()-1])!=0){
                    currWord.pop_back();
                }

                //Making sure word is still a word
                if(currWord.size()!=0) {

                    //Stemming word
                    currWord = porter2_stemmerWrapper::stem(currWord);

                    if (wordMap.find(currWord) != wordMap.end()) {
                        //Increment appearence count and reset word
                        wordMap[currWord]++;
                        currWord = "";
                    } else {
                        //Add Word to map and reset word
                        wordMap.insert(std::pair<std::string, int>(currWord, 1));
                        currWord = "";
                    }
                }
            }
        }else{
            //add next letter
            currWord+=letter;
        }
    }
}



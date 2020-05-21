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
    currentDocLength = 0;
    wordIndex=nullptr;
    loadStopWords();
}

DocumentParser::DocumentParser(std::string newDoc){
    currentDoc = newDoc;
    currentDocLength = 0;
    wordIndex=nullptr;
    loadStopWords();
}

DocumentParser::~DocumentParser(){

}

DocumentParser::DocumentParser(DocumentParser & cpy) {
    this->currentDoc = cpy.currentDoc;
    this->currentDocLength = cpy.currentDocLength;
    wordIndex = cpy.wordIndex;
    loadStopWords();
}


std::string DocumentParser::getCurrentDoc(){
    return currentDoc;
}

void DocumentParser::setCurrentDoc(std::string newDoc){
    currentDoc = newDoc;
    currentDocLength=0;
}

void DocumentParser::parseDoc(){
    std::ifstream input(currentDoc);

    rapidjson::Document doc;
    rapidjson::IStreamWrapper inputWrapper(input);
    
    
    doc.ParseStream(inputWrapper);

    if(doc.HasParseError()){
        std::cout << currentDoc << std::endl;
        std::cout << "Parse Error" << std::endl;
    }else{
        parseBodyText(doc);
    }




}


void DocumentParser::parseBodyText(rapidjson::Value & doc) {
    //Total Map of words and how much they appear
    std::unordered_map<std::string,int> totalMap;

    //Parsing abstract and title
    if(doc.HasMember("metadata") && doc["metadata"].HasMember("title")) {
        docTitle = doc["metadata"]["title"].GetString();
        parseBodyBlock(doc["metadata"]["title"], totalMap);
    }

    //Essentially being super duper sure abstract exists
    if(doc.HasMember("abstract") && doc["abstract"].IsArray()&& doc["abstract"].Size()!=0 && doc["abstract"][0].HasMember("text")) {
        parseBodyBlock(doc["abstract"][0]["text"], totalMap);
    }

    for(rapidjson::SizeType i = 0; i < doc["body_text"].Size(); i++){

        parseBodyBlock(doc["body_text"][i]["text"],totalMap);

    }

    Document* currDoc = new Document(docTitle,currentDoc,currentDocLength);
    currDoc->addWordMap(totalMap);
    docIdex->addDoc(currDoc);

    for(auto iter = totalMap.begin(); iter !=totalMap.end();iter++){
        wordIndex->addEntry(iter->first,currDoc);
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
                    if(stopWords.find(currWord)==stopWords.end()) {
                        if (wordMap.find(currWord) != wordMap.end()) {
                            //Increment appearence count and reset word
                            wordMap[currWord]++;

                        } else {
                            //Add Word to map and reset word
                            wordMap.insert(std::pair<std::string, int>(currWord, 1));

                        }
                    }
                }
                currWord = "";
            }
        }else{
            //add next letter
            currentDocLength++;
            currWord+=letter;
        }
    }
}

void DocumentParser::loadStopWords() {
    std::ifstream stopWordsFile("../lib/StopWords.txt");
    std::string line;
    while(stopWordsFile.good()){
        getline(stopWordsFile,line);
        stopWords.insert(line);
    }
}

void DocumentParser::setIndex(WordIndex * index) {
    wordIndex = index;
}

void DocumentParser::setDocIndex(DocumentIndex * newIndex) {
    this->docIdex = newIndex;
}



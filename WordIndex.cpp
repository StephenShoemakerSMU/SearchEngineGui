//
// Created by stephenshoemaker on 5/20/20.
//

#include "WordIndex.h"

WordIndex::WordIndex() {

}

WordIndex::WordIndex(WordIndex & cpy) {
    for(auto iter = wordMap.begin(); iter!=wordMap.end(); iter++){
        delete iter->second;
    }
    this->wordMap.clear();
    for(auto iter = cpy.wordMap.begin(); iter !=cpy.wordMap.end();iter++){
        std::string string = iter->first;
        Word* word = new Word(*iter->second);
        wordMap.insert(std::pair<std::string,Word*>(string,word));
    }
}

WordIndex::~WordIndex() {
    for(auto iter = wordMap.begin(); iter!=wordMap.end(); iter++){
        delete iter->second;
    }
}

WordIndex& WordIndex::operator=(const WordIndex &cpy) {
    for(auto iter = wordMap.begin(); iter!=wordMap.end(); iter++){
        delete iter->second;
    }
    for(auto iter = cpy.wordMap.begin(); iter !=cpy.wordMap.end();iter++){
        std::string string = iter->first;
        Word* word = new Word(*iter->second);
        wordMap.insert(std::pair<std::string,Word*>(string,word));
    }

    return *this;
}

void WordIndex::addDoc(std::string word, std::string title, std::string path, float frequency) {
    auto wordIter = wordMap.find(word);
    Document currDoc;
    currDoc.setPath(path);
    currDoc.setTitle(title);
    if(wordIter!=wordMap.end()){
        wordIter->second->frequency.insert(std::pair<Document,float>(currDoc,frequency));
    }else{
        wordMap.insert(std::pair<std::string,Word*>(word,new Word(word)));
        wordMap.find(word)->second->frequency.insert(std::pair<Document,float>(currDoc,frequency));
    }
}

WordIndex::Word::Word() {

}

WordIndex::Word::Word(WordIndex::Word & cpy) {
    this->frequency.clear();

    for(auto iter = cpy.frequency.begin(); iter != cpy.frequency.end();iter++){
        Document newDoc = iter->first;
        this->frequency.insert(std::pair<Document,float>(newDoc,iter->second));
    }

}

WordIndex::Word::~Word() {

}

WordIndex::Word& WordIndex::Word::operator=(const WordIndex::Word & cpy) {
    this->frequency.clear();

    for(auto iter = cpy.frequency.begin(); iter != cpy.frequency.end();iter++){
        Document newDoc = iter->first;
        this->frequency.insert(std::pair<Document,float>(newDoc,iter->second));
    }

    return *this;
}

WordIndex::Word::Word(std::string text) {
    this->text = text;
}

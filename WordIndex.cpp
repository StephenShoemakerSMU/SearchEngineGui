//
// Created by stephenshoemaker on 5/20/20.
//

#include "WordIndex.h"

WordIndex::WordIndex() {

}

//Copy Constructor
//Deletes the word map and copys the other users
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

//Deletes the words to avoid memory leaks
WordIndex::~WordIndex() {
    for(auto iter = wordMap.begin(); iter!=wordMap.end(); iter++){
        delete iter->second;
    }
}

//Same as copy constructor but returns a reference
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

//If the word is in the map, add the Document to the map
//If the word is not in the map, add the Word, then the Document
void WordIndex::addEntry(std::string word, std::string doc, std::string path, float frequency) {
    auto wordIter = wordMap.find(word);
    Document currDoc;
    currDoc.setPath(path);
    currDoc.setTitle(doc);
    if(wordIter!=wordMap.end()){
        wordIter->second->frequency.insert(std::pair<Document,float>(currDoc,frequency));
    }else{
        wordMap.insert(std::pair<std::string,Word*>(word,new Word(word)));
        wordMap.find(word)->second->frequency.insert(std::pair<Document,float>(currDoc,frequency));
    }
}

WordIndex::Word::Word() {

}

//Copys every doc and frequency into the word
WordIndex::Word::Word(WordIndex::Word & cpy) {
    this->frequency.clear();

    for(auto iter = cpy.frequency.begin(); iter != cpy.frequency.end();iter++){
        Document newDoc = iter->first;
        this->frequency.insert(std::pair<Document,float>(newDoc,iter->second));
    }

}

WordIndex::Word::~Word() {

}
//Copies the word and copies the requency
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

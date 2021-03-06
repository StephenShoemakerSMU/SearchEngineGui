//
// Created by stephenshoemaker on 5/20/20.
//

#include "WordIndex.h"
#include "fstream"
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

void WordIndex::addEntry(std::string word, Document *doc) {
    auto wordIter = wordMap.find(word);
    if(wordIter!=wordMap.end()) {
        wordIter->second->docMap.insert(std::pair<std::string,Document*>(doc->getPath(),doc));
    }else{
        wordMap.insert(std::pair<std::string,Word*>(word,new Word(word)));
        wordMap.find(word)->second->docMap.insert(std::pair<std::string,Document*>(doc->getPath(),doc));
    }

}

WordIndex::Word &WordIndex::getWord(std::string word) {
    return *(wordMap.find(word)->second);
}

void WordIndex::saveIndex(std::string path) {
    for(auto index = wordMap.begin();index!=wordMap.end();index++){
        std::string output = path + "/" + index->second->text+ ".txt";
        std::ofstream file(output);
        file << index->second->getPersistentIndex();
        file.close();
    }
}

void WordIndex::loadWord(std::string path) {
    std::ifstream wordFile(path);

}


WordIndex::Word::Word() {

}

//Copys every doc and frequency into the word
WordIndex::Word::Word(WordIndex::Word & cpy) {
    this->docMap.clear();
    this->text = cpy.text;
    for(auto iter = cpy.docMap.begin(); iter != cpy.docMap.end();iter++){

        this->docMap.insert(std::pair<std::string,Document*>(iter->first,iter->second));
    }

}

WordIndex::Word::~Word() {

}

//Copies the word and copies the frequency
WordIndex::Word& WordIndex::Word::operator=(const WordIndex::Word & cpy) {
    this->docMap.clear();

    for(auto iter = cpy.docMap.begin(); iter != cpy.docMap.end();iter++){

        this->docMap.insert(std::pair<std::string,Document*>(iter->first,iter->second));
    }

    return *this;
}

WordIndex::Word::Word(std::string text) {
    this->text = text;
}

std::string WordIndex::Word::getPersistentIndex(){
    std::string output = "";
    for(auto iter = docMap.begin(); iter!=docMap.end();iter++){
        output+=iter->second->getTitle() + ".txt" + "\n";
    }
    return output;
}

//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_DOCUMENT_H
#define SEARCHENGINE_DOCUMENT_H


#include <string>
#include <unordered_map>
#include "lib/rapidjson/document.h"
//Document Class
//Stores All Relevant Info for a document
class Document {
    private:
        std::string title;
        std::string path;
        int length;

        std::unordered_map<std::string, int> wordMap;
    public:
        Document(std::string, std::string,int);
        Document();
        Document(const Document&);
        ~Document();

        Document& operator=(const Document&);

        std::string getTitle();
        std::string getPath();
        int getLength();

        int getWordFrequency(std::string);

        void setTitle(std::string);
        void setPath(std::string);

        std::string getJson();

        void loadDoc(std::string);

        void addWord(std::string,int);

        void addWordMap(std::unordered_map<std::string,int>&);

        bool operator<(const Document&) const ;
};


#endif //SEARCHENGINE_DOCUMENT_H

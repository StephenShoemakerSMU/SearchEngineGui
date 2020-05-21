//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_DOCUMENT_H
#define SEARCHENGINE_DOCUMENT_H


#include <string>
#include <unordered_map>

//Document Class
//Stores All Relevant Info for a document
class Document {
    private:
        std::string title;
        std::string path;

        std::unordered_map<std::string, int> wordMap;
    public:
        Document(std::string, std::string);
        Document();
        Document(const Document&);
        ~Document();

        Document& operator=(const Document&);

        std::string getTitle();
        std::string getPath();

        void setTitle(std::string);
        void setPath(std::string);

        void addWordMap(std::unordered_map<std::string,int>&);

        bool operator<(const Document&) const ;
};


#endif //SEARCHENGINE_DOCUMENT_H

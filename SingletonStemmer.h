//
// Created by stephenshoemaker on 5/20/20.
//

#ifndef SEARCHENGINE_SINGLETONSTEMMER_H
#define SEARCHENGINE_SINGLETONSTEMMER_H

#include "lib/porter2_stemmer/porter2_stemmer.h"
#include "unordered_map"
#include "utility"
//Singleton Stemmer Map
//
class SingletonStemmer {
    private:
        std::unordered_map<std::string,std::string> stemMap;
    public:
        std::string stem(std::string);
};


#endif //SEARCHENGINE_SINGLETONSTEMMER_H

//
// Created by stephenshoemaker on 5/20/20.
//

#include "SingletonStemmer.h"

std::string SingletonStemmer::stem(std::string input) {
    if(stemMap.find(input) != stemMap.end()){
        return stemMap.find(input)->second;
    } else{
        std::string original = input;
        Porter2Stemmer::trim(input);
        Porter2Stemmer::stem(input);
        stemMap.insert(std::pair<std::string,std::string>(original,input));
        return input;
    }
}

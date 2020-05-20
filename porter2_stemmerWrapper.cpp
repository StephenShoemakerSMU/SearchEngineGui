//
// Created by stephenshoemaker on 5/20/20.
//

#include "porter2_stemmerWrapper.h"

std::string porter2_stemmerWrapper::stem(std::string input) {
    return porter2_stemmerWrapper::stemmer->stem(input);
}

SingletonStemmer* porter2_stemmerWrapper::stemmer = new SingletonStemmer();
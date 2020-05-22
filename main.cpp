#include <iostream>

#include "SearchEngine.h"
#define CATCH_CONFIG_RUNNER
#include "lib/catch.hpp"
int main(int argc, char *argv[])
{
    int result = Catch::Session().run( argc, argv );

    SearchEngine searchEngine;
    searchEngine.parseDirectory("../Corpus");
    searchEngine.saveDocumentIndex("../Persistent/Documents");
    searchEngine.saveWordIndex("../Persistent/Words");

}
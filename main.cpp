#include <iostream>
#include "DocumentParser.h"
int main(int argc, char *argv[])
{
	DocumentParser* parser = new DocumentParser("../Corpus/0a00a6df208e068e7aa369fb94641434ea0e6070.json");
	parser->parseDoc();
	delete parser;
}
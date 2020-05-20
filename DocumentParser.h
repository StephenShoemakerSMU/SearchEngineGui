
#include <string>
class DocumentParser{
    private:
        std::string currentDoc;

    public:
        
        DocumentParser();
        DocumentParser(std::string);

        ~DocumentParser();

        DocumentParser(DocumentParser&);

        std::string getCurrentDoc();

        void setCurrentDoc(std::string);

        void outputDoc();

};
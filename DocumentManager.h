#ifndef DOCUMENTMANAGER
#define DOCUMENTMANAGER
#include <string>
#include <unordered_set>
#include <unordered_map>

struct Document {
    std::string name;
    int license_limit;
    int id;
    std::unordered_set<int> licenses_used;

    Document() {}
    Document(std::string name, int id, int license_limit)
        : name(name), id(id), license_limit(license_limit) {}
};

class DocumentManager {
private:
    std::unordered_set<int> patrons; // could be made into a map in order to add more patron info
    std::unordered_map<int, Document> documents; // key: id , value: Document
    std::unordered_map<std::string, int> docIDLookup; // O(strlen) insertion (hashing func) and hence comparable to a trie

public:
    void addDocument(std::string name, int id, int license_limit);

    void addPatron(int patronID);

    int search(std::string name); // returns docid if name is in the document collection or 0 if the name is not in the collection

    bool borrowDocument(int docid, int patronID);  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

    void returnDocument(int docid, int patronID);
};

#endif // DOCUMENTMANAGER
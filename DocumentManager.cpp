#include "DocumentManager.h"


void DocumentManager::addDocument(std::string name, int id, int license_limit){
    // check if id is already in use ? should return bool for successful addition check
    if (this->documents.find(id) == this->documents.end()){
        // add document to documents map;
        documents.insert({id, Document(name, id, license_limit)});
        // O(strlen) insertion (hashing func) and hence comparable to a trie
        // for searching for document
        docIDLookup.insert({name, id});
    }
}

void DocumentManager::addPatron(int patronID){
    if (this->patrons.find(patronID) == this->patrons.end()){
        // if patrons had more data/ values use a patron struct
        patrons.insert(patronID);
    }
}

// returns docid if name is in the document collection or 0 if the name is not in the collection
int DocumentManager::search(std::string name){
    if (this->docIDLookup.find(name) == this->docIDLookup.end())
        return 0;
    
    return this->docIDLookup[name];
} 

// returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)
bool DocumentManager::borrowDocument(int docid, int patronID){
    if (this->documents.find(docid) == this->documents.end())
        return false;

    if (this->documents[docid].licenses_used.size() + 1 > this->documents[docid].license_limit){
        return false;
    }
    
    this->documents[docid].licenses_used.insert(patronID);
    return true;

}

void DocumentManager::returnDocument(int docid, int patronID){
    if (this->documents.find(docid) == this->documents.end())
        return;

    if (this->documents[docid].licenses_used.size() == 0 || 
        this->documents[docid].licenses_used.find(patronID) == this->documents[docid].licenses_used.end()){
        return;
    }
    
    this->documents[docid].licenses_used.erase(patronID);
}
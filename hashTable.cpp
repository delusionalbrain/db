#include <string>
using namespace std;

struct Node{
    string key;
    string value;
    Node *next;

    Node(const string& a, const string& b, Node* n = nullptr){
        key = a;
        value = b;
        next = n;
    }
};

class hashTable{
    int cap;
    int numberKeys;
    Node **bucket;
    
    public:
    hashTable(){
        cap = 16;
        numberKeys = 0;
        bucket = new Node*[cap];
        for (int i = 0; i < cap;i++){
            bucket[i] = nullptr;
        }
    };

    int hashFunction(const string &key){
        unsigned int h = 5381;
        for (char c : key){
            h = (h * 33) + (int)c;
        }
        return h % cap;
    }

    
};


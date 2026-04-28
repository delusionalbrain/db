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
    
    void set(const string& key, const string& value){
        int hash = hashFunction(key);
        Node *head = bucket[hash];
        if(head==nullptr) {
            bucket[hash]= new Node(key, value);
            numberKeys++;
            return;
        }
        while (head != nullptr){
            if (head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        bucket[hash] = new Node(key, value);
        numberKeys++;
    }

    string get(const string& key){
        int hash = hashFunction(key);
        Node* head = bucket[hash];
        if(head==nullptr){
            return "No such key found";
        }else{
            while(head!=nullptr){
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }
            return "No such key found";
        }
    }

    string dlt(const string& key){
        int hash = hashFunction(key);
        Node* head = bucket[hash];
        if(head==nullptr){
            return "No such key found";
        }else{
            if(bucket[hash]->key==key){
                bucket[hash] = head->next;
                delete head;
                numberKeys--;
                return "Deleted successfully";
            }
            Node *prev = head;
            head = head->next;
            while (head != nullptr)
            {
                if(head->key == key){
                    prev->next = head->next;
                    numberKeys--;
                    delete head;
                    return "Deleted successfully";
                }
                prev = head;
                head = head->next;
            }
            return "No such key found";
        }
    }

    bool exist(const string& key){
        int hash = hashFunction(key);
        Node* head = bucket[hash];
        if(head==nullptr){
            return false;
        }else{
            while(head!=nullptr){
                if(head->key == key){
                    return true;
                }
                head = head->next;
            }
            return false;
        }
    }
};


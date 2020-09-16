#include "headers.h"

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(hash.count(key)){
            auto temp = hash[key];
            moveToFront(temp);
            return temp->val;
            
        }else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) {

        if (hash.count(key))
        {
            auto temp = hash[key];
            temp->val = value;
            moveToFront(temp);
        }
        
        if(size == capacity){
            if(size ==1){
                hash.erase(head->key);
                delete head;
                head = nullptr;
                end = nullptr;  
            }else{
                auto temp = end;
                if(end->prev) end = end->prev;
                end->next = nullptr;
                temp->prev = nullptr;
                hash.erase(temp->key);
                delete temp;
            }

            size--;
            
        }

        if(head == nullptr){
            head = new ListNode(key,value);
            hash[key] = head;
            end = head;
            size++;
        }else{
            auto temp = new ListNode(key,value);
            hash[key] = temp;
            temp->next = head;
            head->prev = temp;
            head = temp;
            size++;
        }
    }
private:
    int capacity;
    int size;
    struct ListNode
    {
        int val;
        int key;
        ListNode* prev;
        ListNode* next;
        ListNode(int key, int val):key(key),val(val){
            prev = nullptr;
            next = nullptr;
        }
    };
    void moveToFront(ListNode* node){
        if(size ==1) return;
        if(node == head) return;
        if(node == end){
            end = node->prev;
        }
        node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;
        head->prev = node;
        node->next = head;
        node->prev=nullptr;
        head = node;
    }
    
    std::map<int,ListNode*> hash;
    ListNode* head;
    ListNode* end;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
     LRUCache* obj = new LRUCache(1);
    // std::cout <<  obj->get(1) << std::endl;
     obj->put(2,1);
     std::cout <<  obj->get(2) << std::endl;
     obj->put(3,2);
    //  obj->put(4,5);
    //  obj->put(3,6);
    std::cout <<  obj->get(2) << std::endl;
    std::cout <<  obj->get(3) << std::endl;
    return 0;
}

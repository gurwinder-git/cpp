#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int key;
    int val;
    Node *next;
    Node *previous;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->previous = NULL;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;
    int capacity;

    void insertFirst(Node *&n)
    {
        n->next = head->next;
        n->next->previous = n;
        head->next = n;
        n->previous = head;
    }

    void rearrange(Node *&n)
    {
        n->previous->next = n->next;
        n->next->previous = n->previous;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->previous = head;
    }

    int get(int key)
    {
        unordered_map<int, Node *>::iterator itr = mp.find(key);
        if (itr != mp.end())
        {
            rearrange(itr->second);
            insertFirst(itr->second);
            return itr->second->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        unordered_map<int, Node *>::iterator itr = mp.find(key);
        // if key's node not exist
        if (itr == mp.end())
        {
            Node *newNode = new Node(key, value);
            insertFirst(newNode);
            mp[key] = newNode;
        }
        else // if key's node exist
        {
            itr->second->val = value;
            rearrange(itr->second);
            insertFirst(itr->second);
        }

        if (mp.size() > capacity)
        {
            // delete tail node
            Node *t = tail->previous;
            int keyToBeDelete = t->key;
            mp.erase(keyToBeDelete);
            rearrange(t);
            delete t;
        }
    }
};

int main()
{
    LRUCache lru(3);

    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    cout << lru.get(1) << "  ";
    lru.put(4, 40);
    cout << lru.get(2) << "  ";
    cout << lru.get(3) << "  ";
    cout << lru.get(4) << "  ";

    return 0;
}
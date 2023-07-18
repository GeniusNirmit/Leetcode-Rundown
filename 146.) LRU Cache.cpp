class LRUCache {
public:
    struct ListNode {
        ListNode* next = NULL;
        ListNode* prev = NULL;
        pair<int, int> data;
        ListNode(int key, int value) {
            data = { key, value};
        }
    };

    unordered_map<int, ListNode*> mp;
    int capacity;
    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }

    void deleteNode(int key) {
        ListNode* current = mp[key];
        ListNode* prev = current->prev;
        ListNode* next = current->next;

        prev->next = next;
        next->prev = prev;
        mp.erase(key);
    }

    void insertNode(int key, int value) {
        ListNode* temp = new ListNode(key, value);
        ListNode* nextHead = head->next;

        head->next = temp;
        temp->prev = head;
        temp->next = nextHead;
        nextHead->prev = temp;
        mp[key] = temp;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            int value = mp[key]->data.second;
            deleteNode(key);
            insertNode(key, value);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
            deleteNode(key);

        if(mp.size() >= capacity)
            deleteNode(tail->prev->data.first);
        insertNode(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
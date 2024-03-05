class LRUCache {
public:
    // initializing Doubly linked list
    class node {
    public:
        int key;
        int val;
        node* next = NULL;
        node* prev = NULL;

        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int size;
    map<int, node*> store;

    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(store.find(key)!=store.end()){
            int val = store[key]->val;
            node* leftnode = store[key]->prev;
            node* rightnode = store[key]->next;
            leftnode->next = rightnode;
            rightnode->prev= leftnode;
            node* newNode = new node(key, val);
            node* lastNode = head->next;
            newNode->next = lastNode;
            newNode->prev = head;
            head->next = newNode;
            lastNode->prev = newNode;
            store[key] = newNode;
            return val;
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        if (store.find(key) != store.end()) {
            node* leftnode = store[key]->prev;
            node* rightnode = store[key]->next;
            leftnode->next = rightnode;
            rightnode->prev = leftnode;
            node* newNode = new node(key, value);
            node* lastNode = head->next;
            newNode->next = lastNode;
            newNode->prev = head;
            head->next = newNode;
            lastNode->prev = newNode;
            store[key] = newNode;
        } else {
            if (store.size() == size) {
                node* lruNode = tail->prev;
                int lruKey = lruNode->key;
                node* leftnode = lruNode->prev;
                node* rightnode = lruNode->next;
                leftnode->next = rightnode;
                rightnode->prev = leftnode;
                store.erase(lruKey);
                node* newNode = new node(key, value);
                node* lastNode = head->next;
                newNode->next = lastNode;
                newNode->prev = head;
                head->next = newNode;
                lastNode->prev = newNode;
                store[key] = newNode;
            } else {
                node* newNode = new node(key, value);
                node* lastNode = head->next;
                newNode->next = lastNode;
                newNode->prev = head;
                head->next = newNode;
                lastNode->prev = newNode;
                store[key] = newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
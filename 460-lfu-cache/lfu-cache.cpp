struct Node {
    int key, val, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* frontNode = head->next;
        frontNode->prev = node;
        node->next = frontNode;
        node->prev = head;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* deletePrev = node->prev;
        Node* deleteNext = node->next;
        deletePrev->next = deleteNext;
        deleteNext->prev = deletePrev;
        size--;
    }
};
class LFUCache {
    map<int, Node*> store;
    map<int, List*> freqList;
    int curSize;
    int maxSizeCache;
    int minFreq;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        curSize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node* node) {
        store.erase(node->key);
        freqList[node->cnt]->removeNode(node);

        if (node->cnt == minFreq && freqList[node->cnt]->size == 0) {
            minFreq++;
        }

        List* higherOrderList = new List();
        if (freqList.find(node->cnt + 1) != freqList.end()) {
            higherOrderList = freqList[node->cnt + 1];
        }

        node->cnt += 1;
        higherOrderList->addFront(node);
        freqList[node->cnt] = higherOrderList;
        store[node->key] = node;
    }

    int get(int key) {
        if(store.find(key)!=store.end()){
            Node* node = store[key];
            updateFreqListMap(node);
            return node->val;
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }

        if (store.find(key) != store.end()) {
            Node* node = store[key];
            node->val = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List* list = freqList[minFreq];
                store.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }

            minFreq = 1;
            Node* newNode = new Node(key, value);

            List* list = new List();
            if (freqList.find(minFreq) != freqList.end()) {
                list = freqList[minFreq];
            }
            list->addFront(newNode);
            freqList[minFreq] = list;
            store[key] = newNode;
            curSize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
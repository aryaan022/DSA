class MyHashMap {
    
    class Node {
    public:
        int key;
        int value;
        Node* next;

        Node(int k, int v) {
            key=k;
            value=v;
            next=NULL;
        }
    };
    int ts;
    int cs;
    vector<Node*> table;

    int hashFunction(int key) {
        return key % ts;
    }

    void rehash() {
        vector<Node*> oldTable = table;
        int oldSize = ts;

        ts = 2 * ts;
        table = vector<Node*>(ts, NULL);

        cs = 0;

        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];

            while (temp != NULL) {
                put(temp->key, temp->value);

                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }

public:
    MyHashMap() {
        ts = 10;
        cs = 0;
        table=vector<Node*>(ts, NULL);
    }

    void put(int key, int value) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        // key already exists → update value
        while (temp != NULL) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        // insert new node
        Node* newNode = new Node(key, value);
        newNode->next = table[idx];
        table[idx] = newNode;
        cs++;
        double loadFactor = cs / (double)ts;
        if (loadFactor > 1.0) {
            rehash();
        }
    }

    int get(int key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];

        while (temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }

        return -1;
    }

    void remove(int key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {

                if (prev == NULL) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }

                delete temp;
                cs--;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
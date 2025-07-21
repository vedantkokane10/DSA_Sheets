// Question = Leetcode - 146

class Node{
    public:
    int key,value;
    Node *next;
    Node *prev;
    Node(int key,int value){
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

Node *start = new Node(-1,-1);
Node *last = new Node(-1,-1);
unordered_map<int,Node*> mp;
int size;
LRUCache(int capacity) {
    size = capacity;
    start->next = last;
    last->prev = start;
}

void addNode(Node *newNode){
    Node *temp = start->next;
    newNode->next = temp;
    newNode->prev = start;
    temp->prev = newNode;
    start->next = newNode;
}

void deleteNode(Node *node){
    Node *nodePrev = node->prev;
    Node *nodeNext = node->next;
    nodePrev->next = nodeNext;
    nodeNext->prev = nodePrev;
    delete node;
}

int get(int key) {
    if(mp.find(key) != mp.end()){
        Node *current = mp[key];
        int value = current->value;
        deleteNode(current);
        mp.erase(key);
        Node *newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
        return value;
    }
    return -1;
}

void put(int key, int value) {
    if(mp.find(key) != mp.end()){
        Node *current = mp[key];
        deleteNode(current);
        mp.erase(key);
        Node *newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
        return;
    }
    if(mp.size() == size){
        Node *leastUsedNode = last->prev;
        mp.erase(leastUsedNode->key);
        deleteNode(leastUsedNode);
        Node *newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
    }
    else{
        Node *newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
    }
}
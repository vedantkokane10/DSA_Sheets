// Question = Leetcode - 138


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void addNode(Node* &start, Node* &last, Node* &newNode){
    if(start == NULL){
        start = newNode;
        last = start;
    }
    else{
        last->next = newNode;
        last = last->next;
    }
}
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> mp;
    Node* start = NULL;
    Node* last = NULL;
    Node* temp = head;
    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        mp[temp] = newNode;
        addNode(start,last,newNode);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        Node* randomNode = temp->random;
        Node* newNode = mp[temp];
        newNode->random = mp[randomNode];
        temp = temp->next;
    }

    return start;

}
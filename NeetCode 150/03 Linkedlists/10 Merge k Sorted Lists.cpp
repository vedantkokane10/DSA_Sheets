// Question = Leetcode - 23

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void addNode(ListNode* &start, ListNode* &last, ListNode* &newNode){
    if(start == NULL){
        start = newNode;
        last = start;
    }
    else{
        last->next = newNode;
        last = last->next;
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    priority_queue<int, vector<int>, greater<int>> p1;
    for(int i=0;i<k;i++){
        ListNode* temp = lists[i];
        while(temp != NULL){
            p1.push(temp->val);
            temp = temp->next;
        }
    }
    ListNode* start = NULL;
    ListNode* last = NULL;
    while(!p1.empty()){
        ListNode* newNode = new ListNode(p1.top());
        p1.pop();
        addNode(start,last,newNode);
    }

    return start;
}
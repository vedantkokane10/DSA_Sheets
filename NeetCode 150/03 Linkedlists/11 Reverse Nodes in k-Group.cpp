// Question = Leetcode - 25

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* &head) {
    ListNode* current = head;
    ListNode* prevNode = NULL;
    ListNode* nextNode = NULL;
    while(current != NULL){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    return prevNode;
}

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

ListNode* reverseKGroup(ListNode* head, int k) {
    vector<pair<ListNode*, int>> arr;
    ListNode* temp = head;
    while(temp != NULL){
        ListNode* last = temp;
        int cnt = 1;
        while(last->next != NULL && cnt < k){
            last = last->next;
            cnt++;
        }
        arr.push_back({temp,cnt});
        if(cnt < k || last == NULL){
            break;
        }
        
        ListNode* newStart = last->next;

        last->next = NULL;
        temp = newStart;
    }
    for(int i=0;i<arr.size();i++){
        if(arr[i].second == k){
            cout<<arr[i].first->val<<" "<<arr[i].second<<endl;
            arr[i].first = reverse(arr[i].first);
        }
    }

    ListNode* start = NULL;
    ListNode* last = NULL;

    for(int i=0;i<arr.size();i++){
        ListNode* tempNode = arr[i].first;
        while(tempNode != NULL){
            addNode(start,last,tempNode);
            tempNode = tempNode->next;
        }
    }

    return start;

}
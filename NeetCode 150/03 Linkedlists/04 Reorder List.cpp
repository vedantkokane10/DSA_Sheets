// Question = Leetcode - 143

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
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

void reorderList(ListNode* head) {
    // find mid
    // break it in 2 parts based on mid
    // reverse 2nd part
    // merge 1st and 2nd part
    if(head == NULL || head->next == NULL){
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* middle = slow->next;
    slow->next = NULL;
    ListNode* prev = reverseList(middle);
    
    ListNode* temp = head;

    while(prev != NULL){
        ListNode* nextNode = temp->next;
        ListNode* prevNextNode = prev->next;
        temp->next = prev;
        prev->next = nextNode;
        temp = nextNode;
        prev = prevNextNode;
    }

}
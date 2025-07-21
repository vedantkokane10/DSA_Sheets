// Question = Leetcode - 19

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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* reverse = reverseList(head);
    ListNode* reversehead = reverse;
    int cnt = 1;
    if(n == 1){
        if(reverse->next != NULL){
            reverse = reverse->next;
        }
        else{
            return NULL;
        }
        head = reverseList(reverse);
        return head;
    }   
    while(reverse != NULL){
        if(cnt+1 == n){
            reverse->next = reverse->next->next;
            break;
        }
        cnt++;
        reverse = reverse->next;
    }
    head = reverseList(reversehead);
    return head;
}
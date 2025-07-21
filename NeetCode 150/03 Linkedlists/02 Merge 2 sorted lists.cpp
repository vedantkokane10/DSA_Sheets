// Question = Leetcode - 21

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* first = list1;
    ListNode* second = list2;
    ListNode* start = NULL;
    ListNode* last = NULL;

    while(first != NULL && second != NULL){
        ListNode* temp;
        if(first->val <=  second->val){
            temp = new ListNode(first->val);
            first = first->next;
        }
        else{
            temp = new ListNode(second->val);
            second = second->next;
        }

        if(start == NULL){
            start = temp;
            last = start;
        }
        else{
            last->next = temp;
            last = last->next;
        }

    }

    while(first != NULL){
        ListNode * temp = new ListNode(first->val);
        first = first->next;
        if(start == NULL){
            start = temp;
            last = start;
        }
        else{
            last->next = temp;
            last = last->next;
        }
    }

    while(second != NULL){
        ListNode* temp = new ListNode(second->val);
        second = second->next;
        if(start == NULL){
            start = temp;
            last = start;
        }
        else{
            last->next = temp;
            last = last->next;
        }
    }


    return start;
}
// Question = Leetcode - 2

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addNode(int value, ListNode* &start, ListNode* &last){
    ListNode* temp = new ListNode(value);
    if(start == NULL){
        start = temp;
        last = start;
    }
    else{
        last->next = temp;
        last = last->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* start = NULL;
    ListNode* last = NULL;
    int carry = 0;
    while(l1 != NULL && l2 != NULL){
        int value = l1->val + l2->val + carry;
        if(value >= 10){
            value = value % 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        addNode(value,start,last);
        l1 = l1->next;
        l2 = l2->next;
        
    }

    while(l1 != NULL){
        int value = l1->val + carry;
        if(value >= 10){
            value = value % 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        addNode(value,start,last);
        l1 = l1->next;
    }
    while(l2 != NULL){
        int value = l2->val + carry;
        if(value >= 10){
            value = value % 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        addNode(value,start,last);
        l2 = l2->next;
    }
    if(carry){
        addNode(carry,start,last);
    }
    return start;
}
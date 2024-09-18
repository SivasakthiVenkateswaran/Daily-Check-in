


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        struct ListNode* dummyLess = new ListNode(0); 
        struct ListNode* dummyGreat = new ListNode(0); 
        struct ListNode* less = dummyLess; 
        struct ListNode* great = dummyGreat; 
        struct ListNode* temp = head; 

        while(temp) {
            if(temp->val >= x) {
                great->next = temp; 
                great = great->next; 
            } 
            else {
                less->next = temp; 
                less = less->next; 
            }
            temp = temp->next; 
        }

        great->next = NULL; 
        less->next = dummyGreat->next; 
        return dummyLess->next; 
    }
};
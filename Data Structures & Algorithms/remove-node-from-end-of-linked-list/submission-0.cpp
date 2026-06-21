/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution{

public:
    ListNode* removeNthFromEnd(ListNode* head,int n){
       ListNode dummy(0);
       dummy.next = head;
       ListNode* left = &dummy;
       ListNode* right = &dummy;
       // Move right pointer n+1 step ahead
       for(int i=0;i<=n;i++){
        right = right->next;
       }
       // Move both pointers
       while( right!= nullptr){
        left = left->next;
        right = right->next;
       }
       // Remove target nodes
       ListNode* temp = left->next;
       left->next = left->next->next;
       delete temp;
       return dummy.next;
    }
};
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy Node
        ListNode* dummy = new ListNode(0);
        // Tail pointer
        ListNode* tail = dummy;
        // Compare both linked list
        while(list1!= nullptr && list2!= nullptr){
            if(list1->val < list2->val){
                tail->next = list1;
                list1  = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            //Move tail forward
            tail = tail->next;
        }
        //if list1 has remaining nodes
        if(list1!= nullptr){
            tail->next = list1;
        }
        //If list2 still has remaining nodes
        if(list2!=nullptr){
            tail->next = list2;
        }
        // Return merge list
        return dummy->next;
    }
};

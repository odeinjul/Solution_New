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
    ListNode* reverseList(ListNode* head) {
        ListNode *ans,*temp,*last;
        if(head == NULL) return NULL;
        temp = head -> next;
        head -> next = NULL;
        ans = head;
        head = temp;
        while(head != NULL){
            temp = head -> next;
            head -> next = ans;
            ans = head;
            head = temp;
        }
        //head -> next 
        return ans;
    }
};
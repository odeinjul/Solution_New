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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first, *second, *third;
        int n0 = n,l=0;
        first = head; second = head;
        for(;n0>=1 && first -> next != NULL;n0--){
            l++;
            first = first -> next;
        }
        while(first -> next != NULL){
            second = second -> next;
            l++;
            first = first -> next;
        }
        if(n == 1){
            second -> next = NULL;
            if(second == first){
                return second -> next;
            }
            return head;
        }
        else{
            if(second == head && l+1 == n){
                return second -> next;
            }
            second -> next = second -> next ->next; 
            return head;
        }
    }
};
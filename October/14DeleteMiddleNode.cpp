// Problem Link : https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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
    ListNode* deleteMiddle(ListNode* head) {

        int count = 0;

        ListNode* node = head;

        while(node!=NULL){
            node = node->next;
            count++;
        }

        if(count == 1)
            return NULL;
        

        int half = count/2;

        int i=0;
        node = head;
        while(i<half-1){
            node = node->next;
            i++;
        }

        node->next = node->next->next;

        return head;
        
    }
};
// Problem Link : https://leetcode.com/problems/palindrome-linked-list/


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
    bool isPalindrome(ListNode* head) {
        
        vector<int> result;
        
        ListNode* curr = head;
        
        while(curr!=NULL)
        {
            result.push_back(curr->val);
            curr=curr->next;
        }
        
        int n = result.size();
        
        for(int i=0; i<n/2; i++)
        {
            if(result[i] != result[n-1-i])
                return false;
        }
        
        return true;
    }
};
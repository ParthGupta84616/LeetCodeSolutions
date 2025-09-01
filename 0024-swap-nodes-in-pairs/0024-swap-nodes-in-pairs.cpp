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
    ListNode* swapPairs(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
        ListNode* newHead = head->next;
        ListNode* prev = NULL;
        ListNode* prevNode = NULL;


        while (head && head -> next) {
            prev = head;
            head = head->next;
            prev->next = head->next;
            head-> next = prev;
            if(prevNode){
                prevNode->next = head; 
            }
            head = prev->next;
            prevNode = prev;
        }
        return newHead;
    }
};
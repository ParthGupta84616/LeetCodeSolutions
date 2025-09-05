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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* stHead = head;
        ListNode* whileHead = head;
        int size = 0;
        while (stHead) {
            size++;
            st.push(stHead);
            stHead = stHead->next;
        }
        int n = size / 2;
        while (n--) {
            ListNode* nextNode = whileHead->next;
            whileHead->next = st.top();
            st.pop();
            whileHead->next->next = nextNode;
            whileHead = nextNode;
        }
        if (whileHead) {
            whileHead->next = nullptr;
        }
    }
};
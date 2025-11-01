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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        ListNode* temp = head;
        while(temp->next != NULL){
            if(st.find(temp->next->val) != st.end()){
                if(temp->next->next){
                    temp->next  = temp->next->next;
                }else{
                    temp->next = NULL;
                }
            }else{
                temp = temp->next;
            }
        }
        if(st.find(head->val) != st.end()){
            if(head->next){
                return head->next;
            }else{
                return NULL;
            }
        }

        return head;
    }
};
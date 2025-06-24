class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> ia;
        ListNode* h = head;
        while (h) {
            ia.push_back(h->val);
            h = h->next;
        }
        sort(ia.begin(), ia.end());
        h = head;
        for (int i = 0; i < ia.size(); i++) {
            h->val = ia[i];
            h = h->next;
        }
        return head;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        int ents = getNodeSize(head);
        vector<int> iva(ents, 0);
        traverseNodes(head, iva);
        vector<int> iva_save(iva);
        int revindex = ents - 1;
        ListNode* lnp = head;
        for (int i = 0; i < ents; i++) {
            lnp->val = iva[revindex--];
            lnp = lnp->next;
        }
        return head;
    }
private:
    int getNodeSize(ListNode* h) {
        int ents = 0;
        while (h != nullptr) {
            ents++;
            h = h->next;
        }
        return ents;
    }
    void traverseNodes(ListNode* h, vector<int>& iva)
    {
        int ents = 0;
        for (int i = 0; h != nullptr; h = h->next, i++) {
            iva[i] = h->val;
        }
    }
};
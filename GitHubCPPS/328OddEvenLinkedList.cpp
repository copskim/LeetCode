class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        int ents = getNodeSize(head);
        vector<int> iva(ents, 0);
        vector<int*> ivp(ents, nullptr);
        traverseNodes(head, iva, ivp);
        vector<int> iva_save(iva);
        for (int i = 1; i < ents; i++) {
            int to_index;
            if (i % 2) { //even index
                to_index = ents / 2 + i / 2;
                if (ents % 2) to_index++;
            }
            else { //odd index
                to_index = i / 2;
            }
            *ivp[to_index] = iva[i];
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
    void traverseNodes(ListNode* h, vector<int>& iva, vector<int*>& ivp)
    {
        int ents = 0;
        for (int i = 0; h != nullptr; h = h->next, i++) {
            iva[i] = h->val;
            ivp[i] = &h->val;
        }
    }
};
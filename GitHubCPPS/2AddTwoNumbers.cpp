
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ln1 = l1, * ln2 = l2;
        ListNode* result = new ListNode();
        ListNode* r = result;
        int carry = 0;
        while (1) {
            int sum = 0;
            if (ln1) sum += ln1->val;
            if (ln2) sum += ln2->val;
            sum += carry;
            if (sum >= 10) {
                carry = 1;
                sum %= 10;
            }
            else carry = 0;
            r->val = sum;
            if (ln1) ln1 = ln1->next;
            if (ln2) ln2 = ln2->next;
            if (ln1 || ln2) r->next = new ListNode();
            else {
                if (carry) r->next = new ListNode(carry);
                else break;
            }
            r = r->next;
        }
        return result;
    }
};
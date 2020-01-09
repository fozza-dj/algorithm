class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        int len1=0, len2=0;
        ListNode* p1 = l1;
        while(p1){
            len1++;
            p1 = p1->next;
        }
        ListNode* p2 = l2;
        while(p2){
            len2++;
            p2 = p2->next;
        }

        //compare length of two lists
        p1 = l1;
        p2 = l2;
        int carry = 0;

        if(len1 >= len2){
            for(int i=0; i<len2; i++){
                int x = p1->val + p2->val + carry;
                if(x > 9){
                    x %= 10;
                    carry = 1;
                }
                else
                    carry = 0;
                p1 ->val = x;
                p1 = p1->next;
                p2 = p2->next;
            }
            if(carry == 1){
                if(p1 == NULL){
                    ListNode* node = new ListNode(1);
                    p1 = l1;
                    while(p1->next)
                        p1 = p1->next;
                    p1->next = node;
                }
                else{
                    while(p1){
                        if(p1->val < 9){
                            p1->val++;
                            break;
                        }
                        else{
                            if(p1->next){
                                p1->val = 0;
                                p1 = p1->next;
                            }
                            else{
                                ListNode* node = new ListNode(1);
                                p1->val = 0;
                                p1->next = node;
                                break;
                            }
                        }
                    }
                }
            }
            return l1;
        }
        else{
            for(int i=0; i<len1; i++){
                int x = p1->val + p2->val + carry;
                if(x > 9){
                    x %= 10;
                    carry = 1;
                }
                else
                    carry = 0;
                p2->val = x;
                p1 = p1->next;
                p2 = p2->next;
            }
            if(carry == 1){
                while(p2){
                    if(p2->val < 9){
                        p2->val++;
                        break;
                    }
                    else{
                        if(p2->next){
                            p2->val = 0;
                            p2 = p2->next;
                        }
                        else{
                            ListNode* node = new ListNode(1);
                            p2->val = 0;
                            p2->next = node;
                            break;
                        }
                    }
                }
            }
            return l2;
        }
    }
};
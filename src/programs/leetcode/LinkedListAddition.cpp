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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* output = new ListNode;
        ListNode* orig = output;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int curSum = 0;
        while(cur1 != nullptr && cur2 != nullptr){
            curSum += cur1->val + cur2->val;
            output->val = curSum % 10;
            cur1= cur1->next;
            cur2= cur2->next;
            if(curSum > 9){
                curSum /= 10;
            }else{
                curSum = 0;
            }
            if(cur1 != nullptr || cur2 != nullptr || curSum > 0){
              output->next = new ListNode(curSum);
              output = output->next;
            }
        }
        ListNode* rem = nullptr;
            if(cur1 != nullptr)
                rem = cur1;
            else if (cur2 != nullptr)
                rem = cur2;
        
        curSum = output->val;
        
        while(rem != nullptr){
            curSum += rem->val;
            output->val = curSum % 10;
            if(curSum > 9){
                curSum /= 10;
            }else{
                curSum = 0;
            }
            rem = rem->next;
            if(rem != nullptr || curSum > 0){
              output->next = new ListNode(curSum);
              output = output->next;
            }
        }
        return orig;
    }
    
};

int main(){
    
}
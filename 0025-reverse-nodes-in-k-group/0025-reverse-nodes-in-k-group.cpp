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
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp && k>0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // temp:	Head of the current sub-group to be reversed.
    // kThNode:	Tail of the current sub-group before reversal (becomes new head of group after reversal).
    // nextNode: Remembers where the unvisited portion of the list starts before breaking connections.
    // prevLast: Tail of the previously reversed sub-group; used to link groups together.
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = nullptr;
        while(temp){
            ListNode* kthnode = getKthNode(temp, k);

            // not enough elements to make the group of k elements
            if(kthnode == nullptr){
                if(prevLast){
                    prevLast->next = temp;
                    break;
                }
            }

            ListNode* nextNode = kthnode->next;
            kthnode->next = nullptr;
            reverseLL(temp);
            // this is the condition of finding the first group to update the head to the initial node 
            if(temp == head){
                head = kthnode;
            }
            else{
                prevLast->next = kthnode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
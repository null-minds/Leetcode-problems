/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertCopyNode(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* nextNode = temp->next;
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = nextNode;

            temp = nextNode;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* copyNode = temp->next;
            if(temp->random != nullptr){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = nullptr;
            }

            temp = temp->next->next;
        }
    }

    Node* deepCopyLL(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* t = dummy;

        while(temp != nullptr){
            // connection only copied nodes
            t->next = temp->next;
            t = t->next;

            // connecting only original list's nodes
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) {
        insertCopyNode(head);
        connectRandomPointers(head);
        return deepCopyLL(head);
    }
};
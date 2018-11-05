/*          QUESTION
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.
Return a deep copy of the list.

Example:
Given list
   1 -> 2 -> 3
with random pointers going from
  1 -> 3
  2 -> 1
  3 -> 1

You should return a deep copy of the list. The returned answer should not contain the same node as the original list, 
but a copy of them. The pointers in the returned list should not link to any node in the original input list.
*/
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    if(A == NULL) return NULL;
    
    map<RandomListNode*, RandomListNode*> m;
    RandomListNode* curr = A->next;
    RandomListNode* newHead = new RandomListNode(A->label); 
    m[A] = newHead;
    RandomListNode* prevNode = newHead;
    
    while(curr) // New List created with next pointers
    {   RandomListNode* newNode = new RandomListNode(curr->label);
        m[curr] = newNode;
        prevNode->next = newNode;
        prevNode = newNode;
        curr = curr->next;
    }
    curr = A;
    while(curr)
    {
        RandomListNode* randomNode = curr->random;  
        RandomListNode* temp = m[curr];
        temp->random = m[randomNode];
        curr = curr->next;
    }
    return newHead;
}

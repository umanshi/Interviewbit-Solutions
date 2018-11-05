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

struct ListNode{
	int val;
	ListNode* next;
};
/*
  minus each of node in first half with the symmetric one in the second half
*/
ListNode* minusSymmetricNode(ListNode* head)
{
	if(head == NULL) return NULL;
	if(head->next == NULL){
		head->val = 0;
		return head;
	}
//Step 1: use fast and slow pointer to break the list up at the (n + 1)/2 node
	ListNode* pFast = head->next, *pSlow = head;
	while(true){
		if(pFast == NULL) break;//now pSlow points to the last node of the first half
								//and length of first half = length of second half + 1
		if(pFast->next == NULL) break;//now pSlow points to the last node of the first half
									  //and length of first half = length of second half
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	//if total length is odd, we set middle node' value to zero!!!
	if(pFast == NULL) pSlow->val = 0;
	//now slow->next is the head of second half
	ListNode* pSecondHalf = pSlow->next;
	pSlow->next = NULL;
//Step 2: reverse second half and use it as subtrahend
	pSecondHalf = reverseList(pSecondHalf);
//Step 3: minus each node of first half with each node of reverse of second half
	minus(head, pSecondHalf);
//Step 4: reverse the second half and connect it to the first half's end
	pSlow->next = reverseList(pSecondHalf);

	return head;
}
ListNode* reverseList(ListNode* head)//reverse the list and return the new head
{
	if(head == NULL || head->next == NULL) return head;

	ListNode *pre = NULL, *next = NULL;
	for(; head != NULL; head = next){
		next = head->next;
		head->next = pre;
		pre = head;
	}
	return pre;
}
void minus(ListNode* minuend, ListNode* subtrahend)//minus each of minuend by each of subtrahend
{
	while(minuend != NULL && subtrahend != NULL){
		minuend->val -= subtrahend->val;
		minuend = minuend->next;
		subtrahend = subtrahend->next;
	}
}
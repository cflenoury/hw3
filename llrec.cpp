#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

	if(head->val <= pivot){
		smaller = head;
		head = head->next;
		if(head == nullptr){
			larger = nullptr;
			return;
		}else{
			llpivot(head, smaller->next, larger, pivot);
		}
		
	}else{
		larger = head;
		head = head->next;
		if(head == nullptr){
			smaller = nullptr;
			return;
		}else{
		llpivot(head, smaller, larger->next, pivot);
		}
	}
}

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int data;
	struct ListNode *next;
};

void ListLength(struct ListNode *head) {
	struct ListNode *current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		printf("%d ", current->data);
		current = current->next;
	}
	printf("ÃÑ°è¼ö:%d\n", count);
}

void InsertList(struct ListNode **head, int data, int position) {
	int k = 1;
	struct ListNode *p, *q=0, *newNode;
	newNode = (ListNode *)malloc(sizeof(struct ListNode));

	if (!newNode) {
		printf("Memory Error\n");
		return;
	}

	newNode->data = data;
	p = *head;

	if (position == 1) {
		newNode->next = p;
		*head = newNode;
	}
	else {
		while (p != NULL && (k < position)) {
			k++;
			q=p;
			p=p->next;
		}
		q->next = newNode;
		newNode->next = p;
	}

}

int main(void) {
	struct ListNode *list1 = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *list2 = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *list3 = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *list4 = (ListNode *)malloc(sizeof(struct ListNode));
	
	list1->data = 1;
	list1->next = list2;

	list2->data = 2;
	list2->next = list3;

	list3->data = 3;
	list3->next = list4;
	
	list4->data = 4;
	list4->next = NULL;


	ListLength(list1);
	InsertList(&list1, 5, 1);
	ListLength(list1);
}
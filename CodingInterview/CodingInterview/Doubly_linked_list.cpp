#include <stdio.h>
#include <stdlib.h>

struct DLNode {
	int data;
	struct DLNode *next;
	struct DLNode *prev;
};

void ListLength(struct DLNode *head) {
	struct DLNode *current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		printf("%d ", current->data);
		current = current->next;
	}
	printf("ÃÑ°è¼ö:%d\n", count);
}

void DLLNodeInsert(DLNode **head, int data, int position) {
	int k = 1;
	struct DLNode *temp, *newNode;

	newNode = (struct DLNode*)malloc(sizeof(struct DLNode));
	if (!newNode) {
		printf("Memory Error");
		return;
	}

	newNode->data = data;
	if (position == 1) {
		newNode->next = *head;
		newNode->prev = NULL; if (*head)
			(*head)->prev = newNode; *head = newNode;
	}
	else {
		temp = *head;
		while ((k < position) && temp->next != NULL) {
			temp = temp->next;
			k++;
		}
		if (k != position) { printf("Desired position does not exist\n"); }
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next)
			temp->next->prev = newNode;
		temp->next = newNode;
	}
	return;
}

int main(void) {
	struct DLNode *list1 = (struct DLNode *)malloc(sizeof(struct DLNode));
	struct DLNode *list2 = (struct DLNode *)malloc(sizeof(struct DLNode));
	struct DLNode *list3 = (struct DLNode *)malloc(sizeof(struct DLNode));
	struct DLNode *list4 = (struct DLNode *)malloc(sizeof(struct DLNode));

	list1->data = 1;
	list1->prev = NULL;
	list1->next = list2;

	list2->data = 2;
	list1->prev = list1;
	list2->next = list3;

	list3->data = 3;
	list1->prev = list2;
	list3->next = list4;

	list4->data = 4;
	list1->prev = list3;
	list4->next = NULL;

	ListLength(list1);
	DLLNodeInsert(&list1, 5, 1);
	ListLength(list1);
}
#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int data;
	struct Stack *next;
};

struct Stack * CreateStack() {	return NULL; }

void Push(struct Stack **top, int data) {
	struct Stack *temp;
	temp = malloc(sizeof(struct Stack));
	if (!temp) 
		return NULL;
	
	temp->data = data;
	temp->next = *top;
	*top = temp;
}

int IsEmptyStack(struct Stack *top) {
	return top == NULL;
}

int Pop(struct Stack **top) {
	int data;
	struct Stack *temp; 
	if (IsEmptyStack(top))
		return INT_MIN;

	temp = *top;
	*top = temp->next;
	data = temp->data;
	free(temp);
	return data;
}

int Top(struct Stack *top) {
	if (IsEmptyStack(top)) {
		return INT_MIN;
	}
	return top->next->data;
}

void DeleteStack(struct Stack **top) {
	struct Stack *temp, *p;
	p = *top;
	while (p->next) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
	free(p);
}

int main(void) {

	printf("a");
}
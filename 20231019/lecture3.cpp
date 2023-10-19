#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	int data;
	struct _NODE* link;
}NODE;

void print_list(NODE* head) {
	NODE* p = head->link;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

void insert_node_last(NODE* head, int data) {
	NODE* p = head;
	while (p->link != NULL) {
		p = p->link;
	}
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->link = p->link;
	p->link = new_node;
}

void insert_node_first(NODE* head, int data) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = data;
	new_node->link = head->link;
	head->link = new_node;
}
void delete_node_first(NODE* head) {
	NODE* p = head->link->link;
	free(head->link);
	head->link = p;
}
void delete_node_last(NODE* head) {
	NODE* p = head->link;
	NODE* p_prev = head;
	while (p->link != NULL) {
		p = p->link;
		p_prev = p_prev->link;
	}
	free(p);
	p_prev->link = NULL;
}
int main() {
	NODE* head = (NODE*)malloc(sizeof(NODE));
	head->link = NULL;

	NODE* n1 = (NODE*)malloc(sizeof(NODE));
	n1->data = 1;
	n1->link = head->link;
	head->link = n1;

	NODE* n2 = (NODE*)malloc(sizeof(NODE));
	n2->data = 2;
	n2->link = n1->link;
	n1->link = n2;

	NODE* n3 = (NODE*)malloc(sizeof(NODE));
	n3->data = 3;
	n3->link = n2->link;
	n2->link = n3;

	print_list(head);

	insert_node_last(head, 4);
	insert_node_last(head, 5);
	insert_node_last(head, 6);
	print_list(head);

	insert_node_first(head, 6);
	print_list(head);

	delete_node_first(head);
	print_list(head);

	delete_node_last(head);
	print_list(head);

	return 0;
}
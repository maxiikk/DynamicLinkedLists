#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node {
	struct node *prev;
	int value;
	struct node *next;
};

typedef struct node node_t;

void printlist (node_t *head){
	node_t *temp = head;
	while (temp != NULL){
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

void *insert_after_node (node_t *node_to_insert_after, node_t *node_to_insert){
	node_to_insert->next = node_to_insert_after->next;
	node_to_insert_after->next = node_to_insert;
}


node_t *insert_to_head (node_t *head, node_t *node_to_insert){
	node_to_insert->next = head;
	return node_to_insert;
}

node_t *create_new_node (int value){
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

node_t *find_node (node_t *head, int value){
	node_t *temp = head;
	while (temp != NULL){
		if (temp->value == value) return temp;
		temp = temp->next;
	}
	return NULL;
}
void ask_what_to_find (node_t *head){
	printf("\nWhat number are you looking for?\n");
	int a;
	scanf("%i", &a);
	node_t *temp = find_node(head, a);
	if (temp == NULL){
		printf("Not found\n");
	}
	else {
		printf("The node with the number %i is located at %p\n", temp->value, temp);
	}
	
}

node_t *ask_what_node (node_t *head){
	printf("\nWhat number are you looking for?\n");
	int a;
	scanf("%i", &a);
	node_t *temp = find_node(head, a);
	if (temp == NULL){
		printf("Not found\n");
	}
	else {
		printf("The node with the number %i is located at %p\n", temp->value, temp);
	}
	return temp;
}
int main(int argc, char *argv[]) {
	node_t *head = NULL;
	node_t *temp;
	
	for (int i = 1; i <= 25; i++){
		temp = create_new_node(i);
		temp->next = head;
		head = temp;
	}
	
	ask_what_to_find(head);
	
	insert_after_node (ask_what_node(head), create_new_node(90));
	
	printlist(head);
	return 0;
}
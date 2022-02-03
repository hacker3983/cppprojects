#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node {
	int val;
	struct linked_list_node* next;
} node_t;

typedef struct linked_list {
	node_t* list;
	size_t size;
} list_t, MyLinkedList;

node_t* node_create() {
	node_t* new_node = calloc(1, sizeof(node_t));
	return new_node;
}

list_t* myLinkedListCreate() {
	list_t* new_list = calloc(1, sizeof(list_t));
	return new_list;
}

int myLinkedListGet(list_t* list, int index) {
	int i=0;
	node_t* ref = list->list;
	while(ref != NULL) {
		if(i == index) {
			return ref->val;
		}
		i++; ref = ref->next;
	}
	return -1;
}

void myLinkedListAddAtHead(list_t* list, int val) {
	if(list == NULL) {
		return;
	}
	node_t* new_node = node_create();
	new_node->val = val;
	if(list->list == NULL) {
		list->list = new_node;
		list->size++;
		return;
	}
	new_node->next = list->list;
	list->list = new_node;
	list->size++;
}

void myLinkedListAddAtTail(list_t* list, int val) {
	if(list == NULL) {
		return;
	}
	if(list->size == 0) {
		myLinkedListAddAtHead(list, val);
		return;
	}
	node_t* ref = list->list;
	while(ref->next != NULL) {
		ref = ref->next;
	}
	node_t* new_node = node_create();
	new_node->val = val;
	ref->next = new_node;
	list->size++;
}

void myLinkedListAddAtIndex(list_t* list, int index, int val) {
	if(list == NULL) {
		return;
	} else if(index > list->size) {
		return;
	} else if(list->size == 0 || index == 0) {
		myLinkedListAddAtHead(list, val);
		return;
	} else if(index == list->size) {
		myLinkedListAddAtTail(list, val);
		return;
	}
	int i=0;
	node_t* ref = list->list;
	while(ref != NULL) {
		if(i == index-1 && ref->next != NULL) {
			node_t* next = ref->next, *new_node = node_create();
			new_node->val = val;
			new_node->next = next;
			ref->next = new_node;
			list->size++;
			return;
		}
		i++; ref = ref->next;
	}
}

void myLinkedListDeleteAtIndex(list_t* list, int index) {
	if(list == NULL) {
		return;
	}
	if(list->list == NULL) {
		return;
	}
	if(list->size == 0) {
		return;
	}
	if(index == 0) {
		node_t* next = list->list->next;
		free(list->list); list->list = NULL;
		if(next != NULL) {
			list->list = next;
		}
		list->size--;
		return;
	}
	int i=0;
	node_t* ref = list->list;
	while(ref != NULL) {
		if(i == index-1 && ref->next != NULL) {
			node_t* next = ref->next->next;
			free(ref->next);
			ref->next = next;
			list->size--;
			return;
		}
		i++; ref = ref->next;
	}
}

void myLinkedListPrint(list_t* list) {
	node_t* ref = list->list;
	printf("[");
	while(ref != NULL) {
		printf("%d", ref->val);
		if(ref->next != NULL) {
			printf(", ");
		}
		ref = ref->next;
	}
	printf("]\n");
}

void myLinkedListFree(list_t* list) {
	while(list->list != NULL) {
		node_t* next = list->list->next;
		free(list->list);
		list->list = next;
	}
	free(list);
}

int main() {
	int val = 0;
	list_t* obj = myLinkedListCreate();
	myLinkedListAddAtIndex(obj, 1, 0);
	myLinkedListPrint(obj);
	myLinkedListFree(obj);
	return 0;
}

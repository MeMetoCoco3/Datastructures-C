#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct DoublyNode {
  struct DoublyNode* prev;
  struct DoublyNode* next;
  int data;
};

struct Branch{
  struct Branch* l;
  struct Branch* r;
  int data;
};

// Linked List
struct Node* createHead(int value){
  struct Node* head = malloc(sizeof(struct Node));
  if (head == NULL){
    exit(1);
  }
  head->data = value;
  head->next = NULL;
  return head;
}

int addToSort(struct Node** head, int value){
  struct Node* newNode = malloc(sizeof(struct Node));
  if (newNode == NULL){
    exit(1);
  }
  newNode->data = value;
  newNode->next = NULL;


  if (*head == NULL || value < (*head)->data){
    newNode->next = *head;
    *head = newNode;
    return 0;
  }

  struct Node* last = *head;

  while (last->next != NULL && last->next->data < value){
    last = last->next;
  }

  newNode->next = last->next;
  last->next = newNode;

  return 0;
}

void addToNode(struct Node** head, int value){
  struct Node* newNode = malloc(sizeof(struct Node));
  if (newNode == NULL){
    exit(1);
  newNode->data = value;
  newNode->next = NULL;
  struct Node* last = *head;
  while (last->next != NULL){
    last = last->next;
  }
  last->next = newNode;
  }
}

void deleteNode(struct Node** head, int index){
  if (*head == NULL){
    printf("Empty list");
    exit(1);
  }

  struct Node* temp = *head;
  if (index == 0){
    *head = temp->next;
    free(temp);
    exit(1);
  }

  for(int i = 0; i < index - 1; i++){
    if (temp == NULL) {
      printf("Out of index.");
      exit(1);
    }
    temp = temp->next;
  }

  struct Node* next = temp->next->next;
  free(temp->next);
  temp->next = next;
}

// Stack
int pop(struct Node** head){
  if (*head == NULL){
      printf("Empty Stack");
      return 1;
    }

  struct Node* temp = *head;
  if(temp->next == NULL){
    int return_value = temp->data;
    free(temp);
    *head = NULL;
    return return_value;
  }

  while(temp->next->next != NULL){
    temp = temp->next;
  }
  int return_value = temp->next->data;
  // When you free memory you dont erase the data, just allow the system to use
  // the memory, but the pointer, still exists and still points to the same 
  // memory location.
  free(temp->next);
  temp->next = NULL;

  return return_value;
}

void push(struct Node** head, int value){
  if (*head == NULL){
      printf("Empty");
      exit(1);
  }
  struct Node* temp = *head;

  while(temp->next != NULL){
    temp = temp->next;
  }
  
  struct Node* newNode = malloc(sizeof(struct Node));
  
  newNode->data = value;
  newNode->next = NULL;

  temp->next = newNode;
}

// Queue
void enqueue(struct Node** head, int value){
  push(head, value);
}

int dequeue(struct Node** head){
  if (*head == NULL){
      printf("Initialize stack\n");
      return 1;
  }
  
  struct Node* temp = *head;
  int return_value = temp->data;

  *head = temp->next;
  free(temp);
  return return_value;
}

// Doubly Linked List
struct DoublyNode* createDHead(int value){
  struct DoublyNode* head = malloc(sizeof(struct DoublyNode));
  if (head == NULL){
    exit(1);
  }
  head->data = value;
  head->prev, head->next = NULL;
  return head;
}

void addToDNodeTail(struct DoublyNode** head, int value){
  struct DoublyNode* newNode = malloc(sizeof(struct DoublyNode));
  if (newNode == NULL){
    exit(1);
  }
  newNode->data = value;
  newNode->next = NULL;

  struct DoublyNode* temp = *head;
  while (temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

void addToDNodeHead(struct DoublyNode** head, int value){
  struct DoublyNode* newNode = malloc(sizeof(struct DoublyNode));
  if (newNode == NULL){
    exit(1);
  }
  newNode->data = value;
  newNode->prev = NULL;
  newNode->next = *head;
  (*head)->prev = newNode;
  *head = newNode;
}

// TREE

struct Branch* getBranchHead(int data){
  struct Branch* head = malloc(sizeof(struct Branch));
  if (head == NULL){
    exit(1);
  }
  
  head->data = data;
  head->l, head->r = NULL;
  return head;
}

void addLeafToBranch(struct Branch** tree,int data){
  struct Branch* newBranch = malloc(sizeof(struct Branch));
  if (newBranch == NULL){
    exit(1);
  }
  
  newBranch->data = data;
  
  struct Branch* head = *tree;
  
  while(1){
    if (head->data < data){
      head = head->r;
    } else if(head->data > data){

    }
    if (head == NULL){

    }
  }




}


// Others
void display(struct Node* head){
  struct Node* current = head;
  
  if(current == NULL){
    printf("NO DATA.\n");
    exit(1);
  }
  while(current != NULL){
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void displayDF(struct DoublyNode* head){
  struct DoublyNode* current = head;
  
  if(current == NULL){
    printf("NO DATA.\n");
    exit(1);
  }
  while(current != NULL){
    printf("%d->", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void displayDB(struct DoublyNode* head){
  struct DoublyNode* current = head;
  
  if(current == NULL){
    printf("NO DATA.\n");
    exit(1);
  }

  while(current->next != NULL){
    current = current->next;
  }
  
  while(current != NULL){
    printf("%d<-", current->data);
    current = current->prev;
  }
  printf("NULL\n");
}


int length(struct Node* head){
  if(head == NULL){
    return 0;
  }
  int length = 0;
  while(head != NULL){
    ++length;
    head = head->next;
  }
  return length;
}

int lengthD(struct DoublyNode* head){
  if(head == NULL){
    return 0;
  }
  int length = 0;
  while(head != NULL){
    ++length;
    head = head->next;
  }
  return length;
}

int main(){
  /*
  struct Node* head = createHead(88);
  addToNode(&head, 10);
  addToNode(&head, 20);
  addToNode(&head, 30);
  addToNode(&head, 40);

  display (head);
  printf("%d\n", length(head));


  deleteNode(&head, 3);
  display(head);
  printf("%d\n", length(head));
  int popped = pop(&head);

  printf("\n\nPopped: %d\n", popped);
  display(head);
  enqueue(&head, 245);
  display(head);
  
  struct Node* queue = createHead(145);
  dequeue(&queue);
  dequeue(&queue);

  struct DoublyNode* headD = createDHead(60);
  addToDNodeTail(&headD, 80);
  addToDNodeTail(&headD, 90);
  addToDNodeTail(&headD, 100);

  addToDNodeHead(&headD, 1);

  displayDF(headD);
  displayDB(headD);
  printf("%d\n", lengthD(headD));
  */


  struct Node* head = createHead(88);
  addToSort(&head, 10);
  addToSort(&head, 300);
  addToSort(&head, 14);
  addToSort(&head, 360);
  addToSort(&head, 13);
  addToSort(&head, 2200);

  display (head);
  printf("%d\n", length(head));

  return 0;
}

#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
	int data;
	struct node* link;
};
struct Llist{
	struct node* head;
};
struct node* getnode(int val){
	struct node* temp;
	temp = (struct node*) malloc (sizeof(struct node));
	temp -> data = val;
	temp -> link = NULL;
	count++;
	return temp;
}
void print(struct Llist* L){
	struct node* temp = L -> head;
	printf("\nList is :");
	if(L -> head == NULL){
		printf("Empty\n");
		return;
	}
	while(temp -> link != L -> head){
		printf("%d->",temp -> data);
		temp = temp ->link;
	}
	printf("%d--^\n",temp -> data);
}
void insertFront(struct Llist* L, int x){
	struct node* newnode = getnode(x);
	struct node* current = L -> head;
	struct node* previous = L -> head;
	if(L -> head == NULL){
		L -> head = newnode;
		newnode -> link = newnode;
		return;
	}
	while(current -> link != L -> head){
		current = current -> link;
	}
	newnode -> link = L -> head;
	current -> link = newnode;
	L -> head = newnode;		
}
void insertRear(struct Llist *L, int x){
	struct node* newnode = getnode(x);
	struct node* current = L -> head;
	//struct node* previous = L -> head;
	if(L -> head == NULL){
		L -> head = newnode;
		newnode -> link = newnode;
		return;
	}
	else{
		while(current -> link != L -> head){
			current = current -> link;
		}
		newnode -> link = current -> link;
		current -> link = newnode;
	}
}
void deleteRear(struct Llist* L){
	struct node* current = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL){
		printf("List is Empty\n");
		return;
	}
	else if(current -> link == L -> head){
			free(current);
			L -> head = NULL;
			printf("Now its empty\n");
			return;
	}
	else{
		while(current -> link != L -> head){
			previous = current;
			current = current -> link;
		}
		previous -> link = current -> link;
		free(current);
	}
}
void deleteFront(struct Llist* L){
	struct node* current = L -> head;
	struct node* previous = L -> head;
	if(L -> head == NULL){
		printf("List is empty\n");
		return;
	}
	else if(current -> link == L ->head){
		free(current);
		L -> head = NULL;
		return;
	}
	else{
		while(current -> link != L -> head){
			current = current -> link;
		}
		current -> link = L -> head -> link;
		L -> head = L -> head ->link;
		free(previous);
	}
}
// void insertByOrder(struct Llist* L,int x){
// 	struct node* newnode = getnode(x);
// 	struct node* current = L -> head;
// 	struct node* start = L -> head;
// 	struct node* previous = NULL;
// 	if(L -> head == NULL){
// 		L -> head = newnode;
// 		newnode -> link = newnode;
// 		return;
// 	}
// 			if(x <= L -> head -> data){
// 				newnode -> link = start;
// 				L -> head = newnode;
// 				while(current -> link != L -> head){
// 					current = current -> link;
// 				}
// 				current -> link = newnode;
// 				return;
// 			}
			
// 			else
// 			while(current -> link != L -> head && current -> data <= x){
// 				previous = current;
// 				current -> link = current;
// 				}
// 			if(current -> link == L ->head ){
// 							newnode -> link = start;
// 							current -> link = newnode;
// 							return;
// 						}
// 			newnode -> link = current;
// 			previous -> link = newnode;
// }
void insertByOrder(struct Llist* L, int x) {
    struct node* newnode = getnode(x);
    struct node* current = L->head;
    struct node* start = L->head;
    struct node* previous = NULL;

    if (L->head == NULL) {
        L->head = newnode;
        newnode->link = newnode;
        return;
    }

    if (x <= L->head->data) {
        newnode->link = start;
        L->head = newnode;
        while (current->link != L->head) {
            current = current->link;
        }
        current->link = newnode;
        return;
    }
	else {
        while (current->link != L->head && current->data <= x) {
            previous = current;
            current = current->link;
        }
        if (current->link == L->head) {
            newnode->link = start;
            current->link = newnode;
        } 
		else
		 {
            newnode->link = current;
            previous->link = newnode;
        }
    }
}
void searchByKey(struct Llist* L, int key){
	int pos = 1;
	struct node* current = L -> head;
	struct node* start = L -> head;
	if(L -> head == NULL){
		return;
	}
	else{
			while(current -> data != key && current -> link != start){
				current = current ->link;
				pos++;
			}
			if(current -> data == key && current -> link != start){
				printf("\n%d is found at Position %d",key,pos);
				return;
			}
			if(current -> data != key && current -> link == start){
				printf("\n %d is not present in List",key);
				return;
			}
	}
}
void searchByPosition(struct Llist* L , int spos){
//Not working for Last Position
	int pos = 1;
	struct node* current = L -> head;
	if(L -> head == NULL){
		return;
	}
	if(L -> head != NULL && spos <= count){
		while(spos > pos && current -> link != L -> head){
			pos++;
			current = current -> link;
		}
		if(spos == pos && current -> link != L -> head){
			printf("The element found at %d is %d",pos,current -> data);
			return;
		}
		if(spos != pos && current ->link == L -> head){
			printf("\n%d is not a valid position",spos);
			return;
		}
	}
}
void insertByPosition(struct Llist* L, int x, int spos){
//100% No problem	
	int pos = 1;
	struct node* newnode = getnode(x);
	struct node* current = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL && spos == 1){
		L -> head = newnode;
		newnode -> link = newnode;
		return;
	}
	if(L -> head == NULL && spos != 1){
		printf("List is Empty and Invalid position\n");
		return;
	}
	if(L -> head != NULL && spos <= count){
		if(spos == 1){
			newnode -> link = current;
			while(current -> link != L -> head){
				current = current -> link;
			}
			current -> link = newnode;
			L -> head = newnode;
			return;

		}
		while(current -> link != L -> head && spos != pos){
			previous = current;
			current = current -> link;
			pos++;
		}
		if(current -> link == L -> head && spos == pos + 1){
			newnode -> link = L -> head;
			current -> link = newnode;
			return;
		}
		previous -> link = newnode;
		newnode ->link = current; 
	}
	else{
		printf("Invalid position\n");
	}
}
void deleteByPosition(struct Llist* L, int spos){
	int pos = 1;
	struct node* current = L -> head;
	struct node* start = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL){
		return;
	}
	if(L -> head != NULL && spos <= count){
		if(spos == 1 && current -> link == L -> head){
			current -> link == NULL;
			free(current);
			L ->head = NULL;
			return;
		}
		if(spos == 1 && current -> link != L -> head){
			L -> head = start -> link;
			while(current -> link != start){
				current = current -> link;
			}
			current -> link = L -> head;
			start -> link = NULL;
			free(start);
			return;
		}
		while(pos != spos && current ->link != L ->head){
			previous = current;
			current = current -> link;
			pos++;
		}
		if(pos == spos && current -> link != L -> head){
			previous -> link = current -> link;
			current -> link = NULL;
			free(current);
			return;
		}
		if(pos == spos && current -> link == L -> head){
			previous -> link = L -> head;
			current -> link = NULL;
			free(current);
			return;
		}
	}
	else{
		printf("%d is invalid position\n",spos);
	}
}
void deleteByKey(struct Llist* L, int ele){
	struct node* current = L -> head;
	struct node* start = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL){
		return;
	}
	if(L -> head != NULL){
		if(current -> link == L -> head && current -> data == ele){
			L -> head = NULL;
			current -> link = NULL;
			free(current);
			return;
		}
		if(current -> link == L -> head && current -> data != ele){
			printf("%d is not found\n",ele);
			return;
		}
		while(current -> data != ele && current -> link != L -> head){
			previous = current; 
			current = current -> link;
		}
		if(current -> data == ele && previous == NULL){
			while(current -> link != L -> head){
				current = current -> link;
			}
			current -> link = start -> link;
			L-> head = start -> link;
			start -> link = NULL;
			free(start);
			return;
		}
		if(current -> data ==  ele && current -> link == L -> head){
			previous -> link = L -> head;
			current -> link = NULL;
			free(current);
			return;
		}
		if(current -> data == ele && current -> link != L -> head){
		previous -> link = current -> link;
		current -> link = NULL;
		free(current);
		return;
		}
		printf("%d not found",ele);
		return;
	}
}
void main(){
	struct Llist* L;
	L = (struct Llist*) malloc (sizeof(struct Llist));
	printf("\n==========\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert by Order(Starting )\n6.Insert by position\n7.Delete by positon\n8.Delete by key\n9.Search by key\n10.Search by Position(Last Position)\n11.Print\n-1.Exit\n==========\n");
	int choice,ele,spos;
	do{
	printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: printf("Enter the element: ");
				scanf("%d",&ele);
				insertFront(L,ele);
				print(L);
				break;
		case 2: printf("Enter the element: ");
				scanf("%d",&ele);
				insertRear(L,ele);
				print(L);
				break;
		case 3: deleteFront(L);
				print(L);
				break;
		case 4: deleteRear(L);
				print(L);
				break;
		case 5: printf("Enter the element:");
				scanf("%d",&ele);
				insertByOrder(L,ele);
				print(L);
				break;
		case 6: printf("Enter the element:");
				scanf("%d",&ele);
				printf("Enter the Positon:");
				scanf("%d",&spos);
				insertByPosition(L,ele,spos);
				print(L);
				break;
		case 7: printf("Enter the position: ");
				scanf("%d",&spos);
				deleteByPosition(L,spos);
				print(L);
				break;
		case 8: printf("Enter the Key:");
				scanf("%d",&ele);
				deleteByKey(L,ele);
				print(L);
				break;
		case 9: printf("Enter the element:");
				scanf("%d",&ele);
				searchByKey(L,ele);
				//print(L);
				break;
		case 10: printf("Enter the Positon:");
				scanf("%d",&ele);
				searchByPosition(L,ele);
				//print(L);
				break;
		case 11: print(L);
				 break;
		case -1: printf("Thank You\n");
				exit(0);			
		}
	}while(choice != -1);
	free(L);
}

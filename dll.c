#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
	int data;
	struct node* llink;
    struct node* rlink;
};
struct Llist{
	struct node* head;
};
struct node* getnode(int val){
	struct node* temp;
	temp = (struct node*) malloc (sizeof(struct node));
	temp -> data = val;
	temp -> llink = NULL;
	temp -> rlink = NULL;
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
	while(temp -> rlink != NULL){
		printf("%d<-->",temp -> data);
		temp = temp ->rlink;
	}
	printf("%d-->NULL\n",temp -> data);
}
 void insertFront(struct Llist* L, int x){
 	struct node* newnode = getnode(x);
	struct node* current = L -> head;
	struct node* previous = L -> head;
	if(L -> head == NULL){
		L -> head = newnode;
		return;
	}
    newnode -> rlink = current;
    current -> llink = newnode;
    L -> head = newnode;
    return; 		
}
void insertRear(struct Llist *L, int x){
	struct node* newnode = getnode(x);
	struct node* current = L -> head;
	struct node* previous = L -> head;
	if(L -> head == NULL){
		L -> head = newnode;
		return;
	}
	else{
		while(current -> rlink != NULL){
			current = current -> rlink;
		}
		current -> rlink = newnode;
        newnode -> llink = current;	
        return;
	}
}
void deleteRear(struct Llist* L){
	struct node* current = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL){
		printf("List is Empty\n");
		return;
	}
	else
        if(current -> rlink == NULL){
            L -> head = NULL;
            free(current);
            return;
        }
		while(current -> rlink != NULL){
			previous = current;
			current = current -> rlink;
		}
		previous -> rlink = NULL;
		free(current);
	}
void deleteFront(struct Llist* L){
	struct node* current = L -> head;
	struct node* previous = L -> head;
	if(L -> head == NULL){
		printf("List is empty\n");
		return;
	}
	else 
    {
        if(current -> rlink == NULL){
		L -> head = NULL;
        free(current);
		return;
	    }
	    else{
            L -> head = current -> rlink;
            current -> rlink -> llink = NULL;
            return;
	    }
    }
}
void insertByOrder(struct Llist*  L, int val){
    struct node* newnode = getnode(val);
    struct node* current = L -> head;
    struct node* previous = NULL;
    if(L -> head == NULL){
        L -> head = newnode;
        return;
    }
    else{
        if(current -> rlink == NULL && current -> data >= val){
            newnode -> rlink = current;
            current -> llink = newnode;
            L ->head = newnode;
            return;
        }
        if(current -> rlink != NULL && current -> data >= val){
            newnode -> rlink = current;
            current -> llink = newnode;
            L ->head = newnode;
            return;
        }
        while(current -> data < val && current -> rlink != NULL){
            previous = current;
            current = current -> rlink;
        }
        if(current -> data < val && current -> rlink == NULL){
            current -> rlink = newnode;
            newnode -> llink = current;
            return; 
        }
        previous -> rlink = newnode;
        newnode -> rlink = current;
        current -> llink = newnode;
        newnode -> llink = previous;
    }
}
void searchByKey(struct Llist* L, int key){
	int pos = 1;
	struct node* current = L -> head;
	if(L -> head == NULL){
		return;
	}
    else{
        if(pos <= count){
        if(current -> rlink == NULL && current -> data == key){
            printf("%d is found at %d\n",key,pos);
            return;
        }
        if(current -> rlink == NULL && current -> data != key){
            printf("%d is not in the List\n",key);
            return;
        }
        while(current -> data != key && current -> rlink != NULL){
            current = current -> rlink;
            pos++;
        }
        if(current -> data == key){
            printf("%d is found at %d position\n",key,pos);
            return;
        }
        if(current -> data != key && current -> rlink == NULL){
            printf("\n%d is not in the List\n",key);
            return;
        }
        }
        else{
            printf("\n%d is not in the List\n",key);
            return;
        }
    }
}
void searchByPosition(struct Llist* L , int spos){
    int pos = 1;
    struct node* previous = NULL;
	struct node* current = L -> head;
	if(L -> head == NULL){
		return;
	}
    else{
        if(spos <= count && spos > 0){
		
        if(current -> rlink == NULL && spos == pos){
            printf("%d is found at %d\n",current->data,pos);
            return;
        }
        if(current -> rlink == NULL && spos != pos){
            printf("%d position is out of list\n",spos);
            return;
        }
        while(spos > pos && current -> rlink != NULL){
            current = current -> rlink;
            pos++;
        }
        if(spos == pos && current -> rlink == NULL){
            printf("%d is found at %d position\n",current -> data,pos);
            return;
        }
        if(spos == pos && current -> rlink != NULL){
            printf("%d is found at %d",current -> data,pos);
            return;
        }
        }
        else{
            printf("\n%d position is out of list\n",spos);
            return;
        }
    }

}
void insertByPosition(struct Llist* L, int x, int spos){
	int pos = 1;
	struct node* newnode = getnode(x);
	struct node* current = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL && spos == 1){
		L -> head = newnode;
		return;
	}

	if(L -> head == NULL && spos != 1){
		printf("List is Empty and Invalid position\n");
		return;
	}
	if(L -> head != NULL && spos <= count){
		if(spos == 0){
			printf("0 is invalid position\n");
			return;
		}
		if(spos == 1){
			L -> head = newnode;
			newnode -> rlink = current;
			return;
		}

		while(current -> rlink != NULL && spos != pos){
			previous = current;
			current = current -> rlink;
			pos++;
		}
		if(current -> rlink == NULL && spos == pos + 1){
			newnode -> llink = current;
			current -> rlink = newnode;
			return;
		}
		previous -> rlink = newnode;
		newnode ->rlink = current;
		current -> llink = newnode;
		newnode -> llink = previous; 
	}
	else{
		printf("Invalid position\n");
		return;
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
	if(spos <= count && spos > count){
		if(spos == 1 && current -> rlink == NULL){
			free(current);
			L ->head = NULL;
			return;
		}
		if(spos == 1 && current -> rlink != NULL){
			L -> head = current -> rlink;
			free(current);
			return;
		}
		while(pos != spos && current ->rlink != NULL){
			previous = current;
			current = current -> rlink;
			pos++;
		}
		if(pos == spos && current -> rlink != NULL){
			previous -> rlink = current -> rlink;
			current -> rlink -> llink = previous;
			free(current);
			return;
		}
		if(pos == spos && current -> rlink == NULL){
			previous -> rlink = NULL;
			current -> llink = NULL;
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
		if(current -> rlink == NULL && current -> data == ele){
			L -> head = NULL;
			current -> rlink = NULL;
			free(current);
			return;
		}
		if(current -> rlink == NULL && current -> data != ele){
			printf("%d is not found\n",ele);
			return;
		}
		if(current -> rlink != NULL && current -> data == ele){
			L -> head = current -> rlink;
			current -> rlink -> llink = NULL;
			free(current);
			return;
		}
		while(current -> data != ele && current -> rlink != NULL){
			previous = current; 
			current = current -> rlink;
		}
		if(current -> data ==  ele && current -> rlink == NULL){
			previous -> rlink = NULL;
			current -> llink = NULL;
			free(current);
			return;
		}
		if(current -> data == ele && current -> rlink != NULL){
		previous -> rlink = current -> rlink;
		current -> rlink -> llink = previous;
		current -> rlink = current -> llink = NULL;
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
	printf("\n==========\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Insert by Order\n6.Insert by position\n7.Delete by positon\n8.Delete by key\n9.Search by key\n10.Search by Position\n11.Print\n-1.Exit\n==========\n");
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
		default: printf("Invalid Choice\n");			
		}
	}while(choice != -1);
	free(L);
}

#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct node{
	struct node* llink;
    int data;
	struct node* rlink;
};
struct Llist{
	struct node* tail;
};
struct node* getnode(int val){
	struct node* temp;
	temp = (struct node*) malloc (sizeof(struct node));
	temp -> llink = NULL;
    temp -> data = val;
	temp -> rlink = NULL;
    count++;
	return temp;
}
void print(struct Llist* L){
	if(L -> tail == NULL){
		printf("Empty\n");
		return;
	}
	struct node* temp = L -> tail -> rlink;
	printf("\nList is : ↓ ");
	while(temp -> rlink != L -> tail -> rlink){
		printf("%d ↔ ",temp -> data);
		temp = temp ->rlink;
	}
	printf("%d ↑ \n",temp -> data);
}
 void insertFront(struct Llist* L, int x){
 	struct node* newnode = getnode(x);
	if(L -> tail == NULL){
		L -> tail = newnode;
        newnode -> rlink = newnode;
        newnode -> llink = newnode;
		return;
	}
    newnode -> rlink = L -> tail -> rlink;
    L -> tail -> rlink  -> llink = newnode;
    newnode -> llink = L -> tail;
    L -> tail -> rlink = newnode;
    return; 		
}
void insertRear(struct Llist *L, int x){
	struct node* newnode = getnode(x);
	struct node* current = L -> tail;
	struct node* previous = L -> tail;
	if(L -> tail == NULL){
		L -> tail = newnode;
        newnode -> rlink = newnode;
        newnode -> llink = newnode;
		return;
	}
	else{
		newnode -> llink = L -> tail;
        newnode -> rlink = L -> tail -> rlink;
        L -> tail -> rlink -> llink = newnode;
        L -> tail -> rlink = newnode;
        L -> tail = newnode;
        return;
	}
}
void deleteRear(struct Llist* L){
	struct node* current = L -> tail;
	if(L -> tail == NULL){
		printf("List is Empty\n");
		
		return;
	}
	else{
        if(L -> tail -> rlink == L -> tail && L -> tail -> llink == L -> tail){
            L -> tail -> rlink = NULL;
            L -> tail -> llink = NULL;
            free(L -> tail);
            L -> tail = NULL;
            count--;
			return;
        }
        L -> tail -> rlink -> llink = L -> tail -> llink;
        L -> tail -> llink -> rlink = L -> tail -> rlink;
        L -> tail = L -> tail -> llink;
        current -> llink = NULL;
        current -> rlink =NULL;
        free(current);
        count--;
		return;
	}
}
void deleteFront(struct Llist* L){
		struct node* current = L -> tail;
	if(L -> tail == NULL){
		printf("List is empty\n");
		return;
	}
	else 
    {
        if(current -> rlink == L ->tail){
		current -> rlink = NULL;
		current -> llink = NULL;
		free(current);
		L -> tail = NULL;
		count--;
		return;
	    }
	    else{
            current -> rlink = current -> rlink -> rlink;
			current -> rlink -> llink = L -> tail;
            count--;
			return;
	    }
    }
}
void insertByOrder(struct Llist*  L, int val){
    struct node* newnode = getnode(val);
    struct node* current = L -> tail;
    struct node* previous = NULL;
    if(L -> tail == NULL){
        L -> tail = newnode;
		newnode -> rlink = newnode;
		newnode -> llink = newnode;
        return;
    }
    else{
        if(current -> rlink == current && current -> data <= val){
            current -> rlink = newnode;
			newnode -> llink = current;
			newnode -> rlink = current;
            current -> llink = newnode;
			L ->tail = newnode;
            return;
        }
        if(current -> rlink == current  && current -> data > val){
            newnode -> rlink = current;
            current -> llink = newnode;
			newnode -> llink = current;
			current -> rlink = newnode;
            L ->tail = current;
            return;
        }
		current = current -> rlink;
        while(current -> data < val && current -> rlink != L -> tail -> rlink ){
            previous = current;
            current = current -> rlink;
        }
        if(current -> data < val && current -> rlink == L -> tail -> rlink){
            newnode -> llink = current;
			newnode -> rlink = L -> tail -> rlink;
			current -> rlink = newnode;
			L -> tail = newnode;
            return; 
        }
		if(current -> data > val && current -> llink == L -> tail){
			newnode -> rlink = current;
			current -> llink = newnode;
			newnode -> llink = L -> tail;
			L -> tail -> rlink = newnode;
			return;
		}
        previous -> rlink = newnode;
        newnode -> rlink = current;
        current -> llink = newnode;
        newnode -> llink = previous;
		return;
    }
}
void searchByKey(struct Llist* L, int key){
	int pos = 1;
	struct node* current = L -> tail;
	if(L -> tail == NULL){
		return;
	}
    else{
		if(pos <= count){
        if(current -> rlink == current && current -> data == key){
            printf("%d is found at %d\n",key,pos);
            return;
        }
        if(current -> rlink == current && current -> data != key){
            printf("%d is not in the List\n",key);
            return;
        }
		current = current -> rlink;
        while(current -> data != key && current -> rlink != current ){
            current = current -> rlink;
            pos++;
        }
        if(current -> data == key){
            printf("%d is found at %d position\n",key,pos);
            return;
        }
        if(current -> data != key && current -> rlink == L -> tail -> rlink){
            printf("\n%d is not in the List\n",key);
            return;
        }
	}
}
void searchByPosition(struct Llist* L , int spos){
    int pos = 1;
    if(L -> tail == NULL){
		return;
	}
	struct node* previous = NULL;
	struct node* current = L -> tail -> rlink;
        if(spos <= count && spos > 0){
		
        if(current -> rlink == L -> tail  && spos == pos){
            printf("%d is found at %d\n",current->data,pos);
            return;
        }
		
        while(spos > pos && current -> rlink != L ->tail){
            current = current -> rlink;
            pos++;
        }
        if(spos == pos && current -> rlink == L -> tail){
            printf("%d is found at %d position\n",current -> data,pos);
            return;
        }
        if(spos == pos && current -> rlink != L -> tail){
            printf("%d is found at %d",current -> data,pos);
            return;
        }
		
        if(current -> rlink == L ->tail && spos != pos){
            printf("%d position is out of list\n",spos);
            return;
        }
        }
        else{
            printf("\n%d position is out of list\n",spos);
            return;
        }
    

}
// void insertByPosition(struct Llist* L, int x, int spos){
// 	int pos = 1;
// 	struct node* newnode = getnode(x);
// 	struct node* current = L -> tail;
// 	struct node* previous = NULL;
// 	if(L -> tail == NULL && spos == 1){
// 		L -> tail = newnode;
// 		return;
// 	}

// 	if(L -> tail == NULL && spos != 1){
// 		printf("List is Empty and Invalid position\n");
// 		return;
// 	}
// 	if(L -> tail != NULL && spos <= count){
// 		if(spos == 0){
// 			printf("0 is invalid position\n");
// 			return;
// 		}
// 		if(spos == 1){
// 			L -> tail = newnode;
// 			newnode -> rlink = current;
// 			return;
// 		}

// 		while(current -> rlink != NULL && spos != pos){
// 			previous = current;
// 			current = current -> rlink;
// 			pos++;
// 		}
// 		if(current -> rlink == NULL && spos == pos + 1){
// 			newnode -> llink = current;
// 			current -> rlink = newnode;
// 			return;
// 		}
// 		previous -> rlink = newnode;
// 		newnode ->rlink = current;
// 		current -> llink = newnode;
// 		newnode -> llink = previous; 
// 	}
// 	else{
// 		printf("Invalid position\n");
// 		return;
// 	}
// }
// void deleteByPosition(struct Llist* L, int spos){
// 	int pos = 1;
// 	struct node* current = L -> tail;
// 	struct node* start = L -> tail;
// 	struct node* previous = NULL;
// 	if(L -> tail == NULL){
// 		return;
// 	}
// 	if(spos <= count && spos > count){
// 		if(spos == 1 && current -> rlink == NULL){
// 			free(current);
// 			L ->tail = NULL;
// 			return;
// 		}
// 		if(spos == 1 && current -> rlink != NULL){
// 			L -> tail = current -> rlink;
// 			free(current);
// 			return;
// 		}
// 		while(pos != spos && current ->rlink != NULL){
// 			previous = current;
// 			current = current -> rlink;
// 			pos++;
// 		}
// 		if(pos == spos && current -> rlink != NULL){
// 			previous -> rlink = current -> rlink;
// 			current -> rlink -> llink = previous;
// 			free(current);
// 			return;
// 		}
// 		if(pos == spos && current -> rlink == NULL){
// 			previous -> rlink = NULL;
// 			current -> llink = NULL;
// 			free(current);
// 			return;
// 		}
// 	}
// 	else{
// 		printf("%d is invalid position\n",spos);
// 	}
// }
// void deleteByKey(struct Llist* L, int ele){
// 	struct node* current = L -> tail;
// 	struct node* start = L -> tail;
// 	struct node* previous = NULL;
// 	if(L -> tail == NULL){
// 		return;
// 	}
// 	if(L -> tail != NULL){
// 		if(current -> rlink == NULL && current -> data == ele){
// 			L -> tail = NULL;
// 			current -> rlink = NULL;
// 			free(current);
// 			return;
// 		}
// 		if(current -> rlink == NULL && current -> data != ele){
// 			printf("%d is not found\n",ele);
// 			return;
// 		}
// 		if(current -> rlink != NULL && current -> data == ele){
// 			L -> tail = current -> rlink;
// 			current -> rlink -> llink = NULL;
// 			free(current);
// 			return;
// 		}
// 		while(current -> data != ele && current -> rlink != NULL){
// 			previous = current; 
// 			current = current -> rlink;
// 		}
// 		if(current -> data ==  ele && current -> rlink == NULL){
// 			previous -> rlink = NULL;
// 			current -> llink = NULL;
// 			free(current);
// 			return;
// 		}
// 		if(current -> data == ele && current -> rlink != NULL){
// 		previous -> rlink = current -> rlink;
// 		current -> rlink -> llink = previous;
// 		current -> rlink = current -> llink = NULL;
// 		free(current);
// 		return;
// 		}
// 		printf("%d not found",ele);
// 		return;
// 	}
// }
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
		// case 6: printf("Enter the element:");
		// 		scanf("%d",&ele);
		// 		printf("Enter the Positon:");
		// 		scanf("%d",&spos);
		// 		insertByPosition(L,ele,spos);
		// 		print(L);
		// 		break;
		// case 7: printf("Enter the position: ");
		// 		scanf("%d",&spos);
		// 		deleteByPosition(L,spos);
		// 		print(L);
		// 		break;
		// case 8: printf("Enter the Key:");
		// 		scanf("%d",&ele);
		// 		deleteByKey(L,ele);
		// 		print(L);
		// 		break;
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
            case -1: printf("\nThank You\n");
                    exit(0); 
		default: printf("Invalid Choice\n");			
		}
	}while(choice != -1);
	free(L);
}
}
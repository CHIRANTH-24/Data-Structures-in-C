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
        temp = ( struct node*)malloc(sizeof(struct node));
        temp -> data = val;
        temp -> link = NULL;
	count++;//To track the number of nodes
        return temp;
    }
void insertAtFront(struct Llist* L,int val){
    struct node* newnode = getnode(val);
    struct node* temp = L -> head;
    L-> head = newnode;
    //1)Head will have the address of newnode.
    //2)Newnode's link will point to the head. 
    newnode -> link = temp;
}
void insertAtRear(struct Llist* L, int val){
    struct node* temp = getnode(val);
    struct node* current = L -> head;
    //1)Traverse till end without hampering the head
    //2)Now the current node's address should have newnode's address
    if(L->head == NULL){
        insertAtFront(L,val);
        return;
    }
    while(current -> link!= NULL){
        current = current ->link;
    }
    current -> link = temp;
}
void deleteAtFront(struct Llist* L){
	//Head shoud contain the next node of head
	if(L-> head == NULL){
		printf("\nList is already empty.So cannot be deleted\n");
		return;
	}
	L-> head = L -> head -> link;
}
void deleteAtRear(struct Llist* L){
	//Traverse till end and then make the last but one to point to NULL
	struct node* current = L -> head;
	if(L-> head == NULL){
		printf("\nList is already empty.So cannot be deleted\n");
		return;
	}
	struct node* previous = NULL;
	while(current -> link != NULL){
		previous = current;
		current = current -> link;
	}
	previous -> link = NULL;
	
}
void insertAtPosition(struct Llist* L, int val, int spos){
	struct node* newnode = getnode(val);
	struct node* current = L -> head;
	struct node* previous = current;
	int pos = 1;
	if(spos == 1 && L -> head == NULL){
		L -> head = newnode;
		return;
	}
	if(spos == 1 && L -> head != NULL){
		newnode -> link = current;
		L -> head = newnode;
		return;
		
	}
	while(current != NULL && spos != pos){
		previous = current;
		current = current -> link;
		pos++;
	}
	if(current == NULL && spos != pos){
		printf("Invalid positon\n");
		free(newnode);
		return;
	}
	newnode -> link = current;
	previous -> link = newnode;

	return;
}
void insertByOrder(struct Llist* L, int ele){
	struct node* newnode = getnode(ele);
	struct node* next = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL || ele < next -> data){
		insertAtFront(L,ele);
		return;
	}
	while(next -> data < ele && next -> link != NULL){
		previous = next;
		next = next -> link;
	}
	if(next ->  link == NULL && next ->data <= ele){
		next -> link = newnode;
		return;
	}
	newnode -> link = next;
	previous ->  link = newnode;
}
void deleteAtPosition (struct Llist* L , int spos){
	struct node* current = L -> head;
	struct node* previous = NULL;
	if(L -> head == NULL){
		printf("List is empty\n");
		return;
	}
	int pos = 1;
	while( spos != pos && count > pos){
		previous = current;
		current = current -> link;
		pos++;
	}
	if(spos == pos){
		previous = current -> link;
		current -> link = NULL;
	}
	else 
		printf("Invalid Positon\n");
	}
void deleteByKey (struct Llist* L, int ele){
	struct node* next = L -> head;
	struct node* previous =NULL;
	if(L -> head == NULL){
		return;
		}
	if( L -> head -> data == ele){
		L -> head = L -> head -> link;
		return;
		}
	while(next -> data != ele && next  -> link  != NULL){
		previous = next;
		next = next -> link;
	}
	if(next -> link == NULL && next -> data ==  ele){
		previous -> link = NULL;
		free(next);
		return;
		}
	previous -> link = next -> link;
	next -> link = NULL;
	free(next);
}

void searchByKey(struct Llist* L, int key){
	struct node* current = L -> head;
	int pos=1;
	if(L-> head == NULL){
		printf("\nList is Empty\nElement cannot be Searched\n");
		return;
	}
	while(current -> data != key && current -> link != NULL){
			current = current -> link;
			pos++;
		}

	 if(current -> data == key && current -> link == NULL){
		printf("\nThe key element %d is found at positon %d ",key,pos);
		return;
	 }
	 if(current -> data != key && current -> link == NULL){
	 	printf("\nThe key element %d is invalid\n",key);
	 	return;
	 }
	printf("\nThe key element %d if found at position %d",key,pos);
}
void searchByPosition(struct Llist* L,int spos){
	int pos = 1;
	struct node* current = L -> head;
	if(L-> head == NULL){
		printf("List is Empty\n");
		return;
	}
	if(spos > count){
		printf("\n%d is an invalid position(out of bound)\n",spos);
		return;
	}
	while(pos != spos && pos <= count && current -> link != NULL){
		current = current -> link;
		pos++;
		}
	if(current -> link == NULL && spos!= pos){
		printf("%d is invalid position\n",spos);
		return;
	}
	printf("At position %d the element found was %d\n",spos,current -> data);
	}
void print(struct Llist* L){
    if(L -> head == NULL){
    	printf("\nList is empty");
    	return;
    	}
    struct node* temp = L -> head;
    printf("\n");
    do{
        printf("%d-->",temp -> data);
        temp = temp -> link;
    }while(temp != NULL);
    printf("Null\n");

}
void main(){
    int choice,ele,pos;
	struct Llist*L = (struct Llist* )malloc(sizeof(struct Llist));
    L->head = NULL;
    printf("===========\nMain Menu\n==========\n1.Insert At Front\n2.Insert At Rear\n3.Delete At Front\n4.Delete At Rear\n5.Print\n6.Search by Key\n7.Search by Position\n8.Insert At Positon\n9.Delete by Positon\n10.Insert by order\n11.Delete by Key\n-1.Exit\n=============\n");
	do{
    printf("Enter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: printf("Enter the element:");
			scanf("%d",&ele);
			insertAtFront(L,ele);
			print(L);
			break;
		case 2: printf("Enter the element:");
			scanf("%d",&ele);
			insertAtRear(L,ele);
			print(L);
			break;
		case 3: deleteAtFront(L);
			print(L);
			break;
		case 4: deleteAtRear(L);
			print(L);
			break;
		case 5: print(L);
			break;
		case 6: printf("Enter the element to search:");
			scanf("%d",&ele);
			searchByKey(L,ele);
			break;
		case 7: 
			printf("Enter the positon:");
			scanf("%d",&pos);
			searchByPosition(L,pos);
			break;
		case 8: printf("Enter the element:");
			scanf("%d",&ele);
			printf("Enter the position:");
			scanf("%d",&pos);
			insertAtPosition(L,ele,pos);
			print(L);
			break;
		case 9: printf("Enter the position:");
				scanf("%d",&pos);
				deleteAtPosition(L,pos);
				print(L);
				break;
		case 10: printf("Enter the element to Insert by order:\n");
				scanf("%d",&ele);
				insertByOrder(L,ele);
				print(L);
				break;
		case 11: printf("Enter the element to delete: ");
				scanf("%d",&ele);
				deleteByKey(L,ele);
				print(L);
				break;
		case -1: printf("Thank You");
			 exit(0);
		default: printf("Invalid Choice");
	}
	}while(choice != -1);
	
    free(L);
    return;							
	}



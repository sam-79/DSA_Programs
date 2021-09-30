
#include <stdio.h>
#include <stdlib.h>

struct Node *head, *tail, *node;

//creating a node structure
struct Node
{
	int data;
	struct Node *ptr;
};

//Function for append element or add new node
void append()
{
	int x;
	printf("\nEnter value to store: ");
	scanf("%d", &x);

	if (head == NULL)
	{
		head = (struct Node *)malloc(sizeof(struct Node));
		node = head;
	}
	else
	{
		node = (struct Node *)malloc(sizeof(struct Node));
		tail->ptr = node;
	}
	node->data = x;
	tail = node;
}

//Function to insert element or insert node
void insert()
{
	if (head == NULL)
	{
		append();
	}
	else
	{
		int value, index;
		printf("\nEnter value to store: ");
		scanf("%d", &value);
		printf("Enter index: ");
		scanf("%d", &index);
		struct Node *b_node, *node;
		struct Node *a_node = head;
		node = (struct Node *)malloc(sizeof(struct Node));

		for (int i = 0; i < index; i++)
		{
			b_node = a_node;
			a_node = b_node->ptr;
		}

		node->data = value;
		node->ptr = a_node;
		if (index == 0)
			head = node;
		else
			b_node->ptr = node;
		
	}
}

//Function to delete node 
void delete_node()
{
	int index;
	printf("\nEnter Index: ");
	scanf("%d", &index);
	
	if(index==0)
	head=head->ptr;
	else{

	struct Node *b_node,*node;
	struct Node *a_node = head;
	
	for (int i = 0; i < index; i++)
	{
		b_node = a_node;
		a_node = b_node->ptr;
	}
	
	node=a_node->ptr;
	b_node->ptr=node;
	
	free(node);
	}
}

int main()
{
	int choice;
loop:
	printf("\tMain Menu\t\n");
	printf("1. Append\n");
	printf("2. Insert\n");
	printf("3. Delete\n");
	printf("4. Display\n");
	printf("5. Exit\n");
	printf("Enter You choice: ");
	scanf("%d", &choice);

	if (choice == 1)
	{
		append();
	}
	else if (choice == 2)
	{
		insert();
	}
	else if (choice == 3)
	{
		delete_node();
	}
	else if (choice == 4)
	{
		printf("\n\t");
		struct Node *i;
		i = head;
		while (i != NULL)
		{
			printf(" %d", i->data);
			i = i->ptr;
		}
	}
	else if(choice==5)
	return 0;
	else
		printf("\nEnter Valid Option\n");

	printf("\n");
	goto loop;

	
}

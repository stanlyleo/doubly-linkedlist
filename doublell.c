#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	
	struct node *head=NULL,*pos=NULL,*tail=NULL,*temp;
	
	int ch, entry,i;
	
	while(1)
	{
		printf("\n\n1)Insert(front)\n2)Insert(back)\n3)Display(front)\n4)Display(back)\n5)Delete(front)\n6)Delete(back)\n7)Exit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				printf("Enter data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					head->prev=(struct node*)malloc(sizeof(struct node));
					head->prev->next=head;
					head->prev->data=entry;
					head->prev->prev=NULL;
					head=head->prev;
				}
				break;
			}
			case 2:
			{
				printf("Enter data: ");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				}
				break;
			}
			case 3:
			{
				pos=head;
				if(head==NULL)
				{
					printf("Empty list");
					break;
				}
				printf("\nNumbers are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				}
				break;
			}
			case 4:
			{
				pos=tail;
				if(head==NULL)
				{
					printf("Empty list");
					break;
				}
				printf("\nNumbers are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->prev;
				}
				break;
			}
			case 5:
			{
				if(head==NULL)
				{
					printf("Underflow");
					break;
				}
				
				if(head->next==NULL)
				{
					printf("Deleted No: %d",head->data);
					head=NULL;
					break;
				}
				temp=head;
				head=head->next;
				temp->next=NULL;
				head->prev=NULL;
				printf("Deleted No: %d",temp->data);
				free(temp);
				break;
			}
			case 6:
			{
				if(head==NULL)
				{
					printf("Underflow");
					break;
				}
				if(head->next==NULL)
				{
					printf("Deleted No: %d",head->data);
					head=NULL;
					break;
				}
				temp=tail;
				tail=tail->prev;
				temp->prev=NULL;
				tail->next=NULL;
				printf("Deleted No: %d",temp->data);
				free(temp);
				break;
			}
			case 7:
			{
				printf("bye\n");
				exit(0);
			}
		}
	}
}
				


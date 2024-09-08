#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node*prev;

};
struct node*head,*Newnode,*p,*s,*old;

int Create()
{
    head=(struct node*)malloc(sizeof(struct node*));
    printf("Enter Data:");
    scanf("%d",&head->data);
    head->next=NULL;
    head->prev=NULL;
    old=head;

}

int CreateNnode()
{
    int i,count;
    printf("Enter Number U Want:");
    scanf("%d",&count);
    for(i=0; i<count; i++)
    {
        Newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter Data:");
        scanf("%d",&Newnode->data);
        Newnode->next=NULL;
        Newnode->prev=NULL;
        old->next=Newnode;
        Newnode->prev=old;
        old=old->next;

    }

}
int InsertAtBegin()

{
    printf("\n--Insert At Begin--\n");
    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element to Insert: ");
    scanf("%d", &Newnode->data);
    Newnode->next = head;
    head->prev=Newnode;
    head = Newnode;
}
int InsertAtMiddle()
{
    int i,pos;
    printf("Enter Position:");
    scanf("%d",&pos);

    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element to InserAtMiddle: ");
    scanf("%d", &Newnode->data);
    p=old=head;
    for(i=1; i<pos; i++)
    {
        old=p;
        p=p->next;

    }
    Newnode->next=p;
    p->prev=Newnode;
    old->next=Newnode;
    Newnode->prev=old;
}
int InsertAtEnd()
{
    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Element to Insert At End: ");
    scanf("%d", &Newnode->data);

    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=Newnode;
    Newnode->prev=p;
    Newnode->next=NULL;


}
int DeleteAtBegin()
{
    p=head;
    head=head->next;
    p->next=NULL;
    free(p);
}

int DeleteAtMiddle()
{
    int pos,i;
    p=old=head;
    printf("Enter Position:");
    scanf("%d",&pos);
    for(i=1; i<pos; i++)
    {
        old=p;
        p=p->next;

    }
    s=p->next;
    old->next=s;
    s->prev=old;
    free(p);
}
int DeleteAtEnd()
{
    old=p=head;
    while(p->next!=NULL)
    {
        old=p;
        p=p->next;
    }
    old->next=NULL;
    p->prev=NULL;
    free(p);

}
int count()
{
    int c=0;
    p=head;
    while(p!=NULL)
    {
        c++;
        p=p->next;

    }
    printf("\nCount Of Linked List: %d\n",c);

}

int display()
{
    p=head;
    while(p!=NULL)
    {

        printf("%d<->",p->data);
        p=p->next;

    }
    printf("NULL");
}

int main()
{
    int choice;

    do
    {
        printf("\n 1.Create Head Node");
        printf("\n 2.Create N Nodes");
        printf("\n 3.Insert At Begin");
        printf("\n 4.Insert At Middle");
        printf("\n 5.Insert At End");
        printf("\n 6.Delete At Begin");
        printf("\n 7.Delete At Middle");
        printf("\n 8.Delete At End");
        printf("\n 9.Display");
        printf("\n 10.Count");
        printf("\n 0.Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create();
            break;
        case 2:
            CreateNnode();
            break;
        case 3:
            InsertAtBegin();
            break;
        case 4:
            InsertAtMiddle();
            break;
        case 5:
            InsertAtEnd();
            break;
        case 6:
            DeleteAtBegin();
            break;
        case 7:
            DeleteAtMiddle();
            break;
        case 8:
            DeleteAtEnd();
            break;
        case 9:
            display();
            break;

        case 10:
            count();
            break;


        case 11:
            printf("Exiting...\n");
            break;
        default:
            printf("Enter a valid choice!\n");

        }

    }
    while (choice != 0);
    return 0;
}





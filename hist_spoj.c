#include<stdio.h>
#include<stdlib.h>

long long int a[100100],l[100100],r[100100];
struct node
{
	int data;
	struct node *next;
};

struct node *head;

void insertp(int data, int pos);
void insert(int data); //by default enters element at end
void delete(int pos);
void deleteval(int val);
int accesstop();
int isempty();

int main()
{
    int check=1;
    while(check != 0)
    {
        scanf("%d",&check);
        if(check == 0) return 0;
        for(int i=0;i<check;i++)
            scanf("%lld",&a[i]);
        head = NULL;
        for(int i=0;i<check;i++)
        {
            while(isempty() == 0 && a[i] <= a[accesstop()])
            {
                delete(1);
            }
            if(isempty() == 1) l[i] = 0;
            else l[i] = accesstop() + 1;
            insertp(i,1);
 //           printf("at i = %d l[i] = %d\n",i,l[i]);
        }
        head = NULL;
        for(int i=check-1;i>=0;i--)
        {
            while(isempty() == 0 && a[i] <= a[accesstop()])
            {
                delete(1);
            }
            if(isempty() == 1) r[i] = check - 1;
            else r[i] = accesstop() - 1;
            insertp(i,1);
        }
        long long int max = 0;
        for(int i=0;i<check;i++)
        {
            long long int ans = (r[i] - l[i]+ 1 ) * a[i];
      //     printf("at %d r[] = %d and l[] = %d\n",i,r[i],l[i]);
            if(ans > max)
            { max = ans;
     //           printf("%lld at %d\n",max,i);
            }
        }
        printf("%lld\n",max);
    }
}

void insertp(int data,int pos)
{
	struct node *temp=(struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(pos == 1)
	{
		temp->next = head;
		head = temp;
		return;
	}
	struct node *trav=head;
	trav = head;
	for(int i=1;i<=pos-2;i++) //go to the prev node
	{
		trav = trav->next;
	}
	temp->next = trav->next;
	trav->next = temp;
}

void insert(int data)
{
	struct node *temp=(struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	struct node *trav=head;
	if(head == NULL) head = temp;
	else 
	{
		while(trav->next!=NULL)
		{
			trav = trav->next;
		}
		trav->next = temp;
	}
}

int isempty()
{
    if(head == NULL)
        return 1;
    return 0;
}

int accesstop()
{
	struct node *trav=head;
	return trav->data;
}

void delete(int pos)
{
    struct node *trav = head;
	if(pos == 1)
	{
		head = trav->next;
		free(trav);
		return;
	}
	for(int i=1;i<=pos-2;i++)
	{
		trav = trav->next;
	}
	struct node *temp = trav->next;
	trav->next = temp->next;
	free(temp);
}

void deleteval(int val)
{
	struct node *trav = head;
	if(trav->data == val)
	{
		head = trav->next;
		free(trav);
		return;
	}
	while((trav->next)->data!=val)
	{
		trav = trav->next;
	}
	if(trav == NULL) return;
	struct node *temp = trav->next;
	trav->next = temp->next;
	free(temp);
}



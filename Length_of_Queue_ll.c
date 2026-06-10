#include <stdio.h>

struct Queue
{
    char data;
    struct Queue *next;
};

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

int lengthQueue();

struct Queue* enqueue(struct Queue *Front, char x);
struct Queue* dequeue(struct Queue *Front);
char peek(struct Queue *Front);
int isEmpty(struct Queue *Front);
void display();

int main() 
{
    
    char input[30];
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        Front = enqueue(Front, input[i]);
    }
    
    int length = lengthQueue();
    
    display();
    printf("\nlength of Queue - %d", length);
    
}

int lengthQueue()
{
    if(Front == NULL)
    {
        return 0;
    }
    
    int count = 0;
    
    struct Queue *q = Front;
    int flag = 0;
    
    while(Front != q || flag == 0)
    {
        if(flag == 0)
        {
            flag = 1;
        }
        count++;
        Front = enqueue(Front, peek(Front));
        Front = dequeue(Front);
        if(flag == 1)
        {
            q = Rear;
            flag = 2;
        }
    }
    
   return count;
    
}

struct Queue* enqueue(struct Queue *Front, char x)
{
     struct Queue *t = (struct Queue*) malloc (sizeof(struct Queue));
    t->data = x;
    
    if (Front==NULL)
    {
        Front = t;
        t->next = NULL;
        Rear = t;
        return Front;
    }
    
    Rear->next = t;
    t->next = NULL;
    Rear = Rear->next;
    
    return Front;

}

struct Queue* dequeue(struct Queue *Front)
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return NULL;
    }
    
    struct Queue *p = Front;
    Front =  Front->next;
    free(p);
    
    return Front;
}

char peek(struct Queue *Front)
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return -1;
    }
    return Front->data;
}

int isEmpty(struct Queue *Front)
{
    if (Front == NULL && Rear == NULL)
    {
        return 1;
    }   
    else
    {
        return 0;
    }
}

void display()
{
    struct Queue *po = Front;
    
   while (po != NULL)
    {
        printf("%c\t", po->data);
        po = po->next;
    }
    printf("\n");
}

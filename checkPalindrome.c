#include <stdio.h>

struct Queue
{
    struct Queue *prev;
    char data;
    struct Queue *next;
};

struct Queue *Front = NULL;
struct Queue *Rear = NULL;

int checkPalindrome();

struct Queue* enqueue_front(struct Queue *Front, char x);
struct Queue* dequeue_front(struct Queue *Front);
struct Queue* enqueue_rear(struct Queue *Front, char x);
struct Queue* dequeue_rear(struct Queue *Front);
char peek_front();
char peek_rear();
int isEmpty();
void display();

int main() 
{
    
    char input[30];
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        Front = enqueue_front(Front, input[i]);
    }
    
    int isPalindrome = checkPalindrome();
    
    if(isPalindrome)
    {
        printf("It is a palindrome\n");
    }
    else
    {
        printf("It is not a palindrome\n");
    }
    
    display();
    
}

int checkPalindrome()
{
    while(Rear != Front && Rear->prev != Front)
    {
        if(peek_front() != peek_rear())
        {
            return 0;
        }
        
        Front = dequeue_rear(Front);
        Front = dequeue_front(Front);
    }

    if(Rear->prev == Front && peek_front() != peek_rear())
    {
        return 0;
    }
    
    return 1;
}

struct Queue* enqueue_front(struct Queue *Front, char x)
{
     struct Queue *t = (struct Queue*) malloc (sizeof(struct Queue));
    t->data = x;
    
    if (Front==NULL)
    {
        Front = t;
        t->next = NULL;
        t->prev = NULL;
        Rear = t;
        return Front;
    }
    
    Rear->next = t;
    t->next = NULL;
    t->prev = Rear;
    Rear = Rear->next;
    
    return Front;

}

struct Queue* dequeue_front(struct Queue *Front)
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return NULL;
    }
    
    struct Queue *p = Front;
    Front =  Front->next;
    Front->prev = NULL;
    free(p);
    
    return Front;
}

char peek_front()
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return -1;
    }
    return Front->data;
}

struct Queue* enqueue_rear(struct Queue *Front, char x)
{
     struct Queue *t = (struct Queue*) malloc (sizeof(struct Queue));
    t->data = x;
    
    if (Front==NULL)
    {
        Front = t;
        t->next = NULL;
        t->prev = NULL;
        Rear = t;
        return Front;
    }
    
    t->next = Front;
    Front->prev = t;
    t->prev = NULL;
    Front = t;
    
    return Front;

}

struct Queue* dequeue_rear(struct Queue *Front)
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return NULL;
    }
    
    struct Queue *p = Rear;
    Rear =  Rear->prev;
    Rear->next = NULL;
    free(p);
    
    return Front;
}

char peek_rear()
{
    if (Front == NULL)
    {
        printf("Your stack is empty!\n");
        return -1;
    }
    return Rear->data;
}

int isEmpty()
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

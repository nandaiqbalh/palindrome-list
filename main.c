/*
 * C Program to Check whether a Singly Linked List is a Palindrome
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

// fungsi yang digunakan dalam program
int create(struct node **);
bool IsPalindrome (struct node *, int);
void release(struct node **);

int main()
{
    struct node *p = NULL;
    int result, count;

    printf("Masukkan data ke dalam List!\n");
    count = create(&p);
    result = IsPalindrome(p, count);
    if (result == 1)
    {
        printf("List anda adalah List Palindrome.\n");
    }
    else
    {
        printf("List anda bukan merupakan List Palindrome.\n");
    }
    release (&p);

    return 0;
}

bool IsPalindrome (struct node *p, int count)
{
    int i = 0, j;
    struct node *front, *rear;

    while (i != count / 2)
    {
        front = rear = p;
        for (j = 0; j < i; j++)
        {
            front = front->next;
        }
        for (j = 0; j < count - (i + 1); j++)
        {
            rear = rear->next;
        }
        if (front->data != rear->data)
        {
            return 0;
        }
        else
        {
            i++;
        }
    }

    return 1;
}

int create (struct node **head)
{
    int c, ch, count = 0;
    struct node *temp;

    do
    {
        printf("Masukkan angka: ");
        scanf("%d", &c);
        count++;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = c;
        temp->next = *head;
        *head = temp;
        printf("Apakah anda ingin memasukkan angka lagi? [1/0]: ");
        scanf("%d", &ch);
    }while (ch != 0);
    printf("\n");

    return count;
}

void release (struct node **head)
{
    struct node *temp = *head;

    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}

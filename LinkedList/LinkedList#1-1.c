#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    char elem;
    struct ListNode* prev;
    struct ListNode* next;
}LN;

typedef struct ListType
{
    int len;
    LN* H;
    LN* T;
}LT;

LT* init(LT* L)
{
    L = (LT*)malloc(sizeof(LT));

    L->H = (LN*)malloc(sizeof(LN));
    L->T = (LN*)malloc(sizeof(LN));

    L->H->prev = NULL;
    L->T->next = NULL;
    L->H->next = L->T;
    L->T->prev = L->H;

    L->len = 0;

    return L;
}

LN* trav(LT* L, int pos)
{
    int j;
    LN* tmp;

    tmp = (LN*)malloc(sizeof(LN));
    tmp = L->H;

    for (j = 0; j < pos - 1; j++)
        tmp = tmp->next;
    return tmp;
}

void add(LT* L, int pos, char item)
{
    LN* node;
    LN* tmp;

    node = (LN*)malloc(sizeof(LN));

    if (L->len + 1 < pos || pos < 0)
    {
        printf("invalid position\n");
        return;
    }
    node->elem = item;
    tmp = trav(L, pos);
    node->prev = tmp;
    node->next = tmp->next;
    tmp->next->prev = node;
    tmp->next = node;
    L->len++;
}

void del(LT* L, int pos)
{
    LN* p;
    int i;
    if (L->len < pos || pos < 0)
    {
        printf("invalid position\n");
        return;
    }

    p = L->H;
    for (i = 0; i < pos; i++)
        p = p->next;
    (p->prev)->next = p->next;
    (p->next)->prev = p->prev;
    L->len--;
    free(p);
}

void get_entry(LT* L, int pos)
{
    LN* p;
    if (L->len < pos || pos < 0)
    {
        printf("invalid position\n");
        return;
    }

    p = trav(L, pos);
    printf("%c\n", p->next->elem);
}

void print(LT* L)
{
    LN* tmp;
    tmp = L->H->next;

    while (tmp != L->T)
    {
        printf("%c", tmp->elem);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
    LT* L = NULL;
    LN* p = NULL;
    int n, i;
    char func, data;
    int pos;

    scanf("%d", &n);

    L = init(L);

    for (i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &func);

        switch (func)
        {
        case 'A':
            scanf("%d %c", &pos, &data);
            add(L, pos, data);
            break;

        case 'P':
            print(L);
            break;

        case 'G':
            scanf("%d", &pos);
            get_entry(L, pos);
            break;

        case 'D':
            scanf("%d", &pos);
            del(L, pos);
            break;
        }
    }
    do
    {
        p = L->H;
        L->H = L->H->next;
        free(p);
    } while (L->H != NULL);
}

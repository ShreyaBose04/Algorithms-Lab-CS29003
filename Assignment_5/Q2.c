// Shreya Bose
// 22CS30050
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5000
int ans[100];
int depth = 0;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
struct node
{
    int data;
    struct node *right, *left, *parent;
    int level;
};
struct node *treeroot;
struct Queue
{
    int front, rear;
    int size;
    struct node **array;
};
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;
    temp->level = 0;
    return temp;
}
struct Queue *makeQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node **)malloc(queue->size * sizeof(struct node *));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == queue->size - 1;
}

void Enqueue(struct node *root, struct Queue *queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}
struct node *Dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return NULL;

    struct node *temp = queue->array[queue->front];

    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}
struct node *getFront(struct Queue *queue)
{
    return queue->array[queue->front];
}
int hasBothChild(struct node *temp)
{
    return temp && temp->left && temp->right;
}
void makeTree(int data, struct Queue *queue)
{
    struct node *temp = newNode(data);
    struct node *front;
    front = getFront(queue);
    while (front->data == -1)
    {
        Dequeue(queue);
        front = getFront(queue);
    }
    if (!front->left)
        front->left = temp;
    else if (!front->right)
        front->right = temp;
    if (hasBothChild(front))
    {
        if (front->left->data == -1)
        {
            front->left = NULL;
        }
        if (front->right->data == -1)
        {
            front->right = NULL;
        }
        Dequeue(queue);
    }
    Enqueue(temp, queue);
}
void assign(struct node *root, int lvl, struct node *prt)
{
    if (root == NULL)
        return;
    root->level = lvl;
    root->parent = prt;
    depth = max(depth, lvl);
    lvl++;
    assign(root->left, lvl, root);
    assign(root->right, lvl, root);
}
void solve(struct node *root, int n)
{
    int i;
    int levelsum[depth + 1];
    for (i = 0; i <= depth; i++)
        levelsum[i] = 0;
    struct Queue *Q = makeQueue(n);
    struct node *arr[n];
    for (i = 0; i < n; i++)
        arr[i] = NULL;
    struct node *temp_node = root;
    Enqueue(root, Q);
    int cnt = 0;
    while (!isEmpty(Q))
    {
        arr[cnt++] = getFront(Q);
        temp_node = Dequeue(Q);
        if (temp_node->left)
            Enqueue(temp_node->left, Q);
        if (temp_node->right)
            Enqueue(temp_node->right, Q);
    }
    treeroot->data = 0;
    i = n - 1;
    while (arr[i] == NULL)
    {
        i--;
    }
    int idx = i;
    i = 1;
    int currlevel = 1;
    while (i <= idx)
    {
        while (i <= idx && arr[i]->level == currlevel)
        {
            levelsum[currlevel] += arr[i]->data;
            i++;
        }
        if (i <= idx)
            currlevel = arr[i]->level;
    }
    i = 1;
    currlevel = 1;
    int x = 0;
    int j;
    int newdata[idx + 1];
    while (i <= idx)
    {
        while (i <= idx && arr[i]->level == currlevel)
        {
            x = 0;
            if (((arr[i]->parent)->left != arr[i]) && ((arr[i]->parent)->left != NULL))
                x = ((arr[i]->parent)->left->data);
            else if (((arr[i]->parent)->right != arr[i]) && ((arr[i]->parent)->right != NULL))
                x = ((arr[i]->parent)->right->data);

            newdata[i] = levelsum[currlevel] - arr[i]->data - x;
            i++;
        }
        if (i <= idx)
            currlevel = arr[i]->level;
    }
    for (i = 1; i <= idx; i++)
    {
        arr[i]->data = newdata[i];
    }
}
void travLevelOrder(struct node *root, int n)
{
    struct Queue *Q = makeQueue(n);
    struct node *temp_node = root;
    Enqueue(root, Q);
    int cnt = 0;
    while (!isEmpty(Q))
    {
        if (getFront(Q) != NULL)
        {
            ans[cnt++] = getFront(Q)->data;
            temp_node = Dequeue(Q);
            Enqueue(temp_node->left, Q);
            Enqueue(temp_node->right, Q);
        }
        else
        {
            ans[cnt++] = -1;
            struct node *dummy = Dequeue(Q);
        }
    }
}
int main()
{
    int n, i, minv, maxv, idx;
    printf("enter size of input array: ");
    scanf("%d", &n);
    int a[n];
    printf("enter input array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    treeroot = newNode(a[0]);
    struct Queue *Q = makeQueue(n);
    Enqueue(treeroot, Q);
    for (i = 1; i < n; i++)
    {
        makeTree(a[i], Q);
    }
    assign(treeroot, 0, NULL);
    solve(treeroot, n);
    for (i = 0; i < 100; i++)
        ans[i] = -1;
    travLevelOrder(treeroot, n);
    i = 99;
    while (ans[i] == -1)
    {
        i--;
    }
    idx = i;
    printf("output: \n");
    for (i = 0; i <= idx; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
}
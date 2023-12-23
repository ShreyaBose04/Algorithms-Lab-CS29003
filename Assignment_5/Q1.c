// Shreya Bose
// 22CS30050
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5000
int ans[100];
struct node
{
    int data;
    struct node *right, *left;
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
    temp->left = temp->right = NULL;
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
struct node *getMinNode(struct node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}
struct node *delete(struct node *node, int key)
{
    if (node == NULL)
        return NULL;
    if (key < node->data)
        node->left = delete (node->left, key);
    else if (key > node->data)
        node->right = delete (node->right, key);
    else
    {
        if ((node->left == NULL) && (node->right == NULL))
        {
            free(node);
            return NULL;
        }
        else if ((node->left != NULL) && (node->right == NULL))
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
        else if ((node->left == NULL) && (node->right != NULL))
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        if ((node->left != NULL) && (node->right != NULL))
        {
            struct node *temp = getMinNode(node->right);
            node->data = temp->data;
            node->right = delete (node->right, temp->data);
        }
    }
    return node;
}
void check(struct node *root, int maxv, int minv)
{
    if (root == NULL)
        return;
    if (root->data > maxv || root->data < minv)
        treeroot = delete (treeroot, root->data);
    check(root->left, maxv, minv);
    check(root->right, maxv, minv);
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
    printf("min = ");
    scanf("%d", &minv);
    printf("max = ");
    scanf("%d", &maxv);
    treeroot = newNode(a[0]);
    struct Queue *Q = makeQueue(n);
    Enqueue(treeroot, Q);
    for (i = 1; i < n; i++)
    {
        makeTree(a[i], Q);
    }
    check(treeroot, maxv, minv);
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

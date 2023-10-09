#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    int row;
    int col;
    struct list *next_row;
    struct list *next_col;
};
typedef struct list element;
typedef element *link;

int main()
{
     printf("ENTER n m\n");
    int m , n, a, i, j, k;  //n row m col
     scanf("%d %d", &n, &m);
    link rowpt[n];
    link colpt[m]; 
    int check[m];
    for(i=0; i<m; i++)
    {
        check[i]=1;
        colpt[i]=NULL;
    }
    for(i=0; i<n; i++)
    {
        rowpt[i]=NULL;
    }
   
    link head=NULL; 
    link tail;
   
    for(i=0; i<n; i++)
    {
        head=NULL;
        for(j=0; j<m; j++)
        {
            scanf("%d",&a);
            if (a!=0)
            {
                head = (link)malloc(sizeof(element));
                rowpt[i]= head;
                colpt[j]= head;
                check[j]=0;
                head->data=a;
                tail = head;
                for(k=j+1; k<m; k++)
                {
              
                    scanf("%d",&a);
                    if(a!=0)
                    {
                        tail->next_col = (link)malloc(sizeof(element));
                        tail = tail->next_col;
                        if(check[k]==1)
                        {
                            printf("mark");
                            check[k]=0;
                            colpt[k]=tail;
                        }
                        tail->data = a;
                    }
                }
                tail->next_col=NULL;
                break;
            }
        }
    }
   link temp = rowpt[0];
//    printf("%d\n", temp->data);

    for(j=0; j<m; j++){
        if (colpt[j] == NULL) // for the last element
          printf("0 ");
        else // for other elements
            printf("%d ", colpt[j]->data);
    }

    // for(i=0; i<m; i++)
    // {
    //     printf("%d ", check[i]);
    // }
    return 0;
}


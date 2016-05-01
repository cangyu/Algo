// 左式堆，可合并的priority_queue
// 核心是merge操作，递归实现，reason？非递归较复杂，但能否实现一下？
// 实现可合并的priority_queue还可以有其它方式，如斜堆，斐波那契堆 and so on，能否实现？
// 结构体数组的初始化？

#include<cstdio>
using namespace std;

typedef struct node{
    int charm ;
    int npl;
    node *left , * right;
    node():charm (0), npl(0 ), left( NULL), right (NULL){}
}NodeTypeDef, *pNodeTypeDef ;

pNodeTypeDef leftistHeap_Merge(pNodeTypeDef h1 , pNodeTypeDef h2);
pNodeTypeDef leftistHeap_merge(pNodeTypeDef h1 , pNodeTypeDef h2);
pNodeTypeDef leftistHeap_DeleteMin(pNodeTypeDef h );
pNodeTypeDef leftistHeap_Insert(pNodeTypeDef h , int chm);

pNodeTypeDef group[300005 ] = { NULL };
NodeTypeDef pool[600005 ] = { node() };
int poolValidIndex = 0;

int main( int argc, char **argv)
{
    int n, m ;
    scanf("%d%d" , & n, &m );
    for (int i = 0; i < n; i++)
    {
        group [i] = &pool [poolValidIndex++];
        scanf ("%d", &(group [i]-> charm));
    }
    int op, a , b;
    for (int i = 0; i < m; i++)
    {
        scanf ("%d", &op );
         switch ( op)
         {
         case 0 :
            scanf("%d%d", &a, &b);
            group[a] = leftistHeap_Merge(group[a], group[b]);
            group[b] = NULL;
            break;
        case 1:
            scanf("%d", &a);
            group[a] = leftistHeap_DeleteMin(group[a]);
            break;
        case 2:
            scanf("%d%d", &a, &b);
            group[a] = leftistHeap_Insert(group[a], b);
            break;
        default:
            break;
        }
    }

    return 0;
}

pNodeTypeDef leftistHeap_Merge(pNodeTypeDef h1, pNodeTypeDef h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    return h1->charm < h2->charm ? leftistHeap_merge(h1, h2) : leftistHeap_merge(h2, h1);
}

pNodeTypeDef leftistHeap_merge(pNodeTypeDef h1, pNodeTypeDef h2)
{
    if (!h1->left)
        h1->left = h2;
    else
    {
        h1->right = leftistHeap_Merge(h1->right, h2);
        if (h1->left->npl < h1->right->npl)
        {
            pNodeTypeDef temp = h1->left;
            h1->left = h1->right;
            h1->right = temp;
        }

        h1->npl = h1->right->npl + 1;
    }
    return h1;
}

pNodeTypeDef leftistHeap_DeleteMin(pNodeTypeDef h)
{
    if (!h)
    {
        puts("-1\n");
        return h;
    }

    pNodeTypeDef leftHeap = h->left;
    pNodeTypeDef rightHeap = h->right;
    printf("%d\n", h->charm);
    h = NULL;
    return leftistHeap_Merge(leftHeap, rightHeap);
}

pNodeTypeDef leftistHeap_Insert(pNodeTypeDef h, int chm)
{
    int t = poolValidIndex;
    pool[poolValidIndex++].charm = chm;
    h = leftistHeap_Merge(h, &pool[t]);
    return h;
}

//表示一般的多叉树的方法
//树的遍历方法

#define _CRT_SECURE_NO_WARNINGS

#include<vector>
#include<cstdio>
#include<queue>

using namespace std;

struct node {
    int lmc;
    int rs;
    node() :lmc( 0), rs (0){}
};

void preOrderTraversal(const vector<node> &tr, int root);
void afterOrderTraversal(const vector<node> &tr, int root);
void levelOrderTraversal(const vector<node> &tr, int root);

int main( int argc, char **argv)
{
    int n;
    scanf("%d" , & n);
    vector<node > tree( n+1, node ());
    vector<bool > isRoot(n+1 , true );
    for (int i = 0; i < n; i++)
    {
         int x, cx, sx ;
        scanf ("%d%d%d", &x , & cx, &sx );
        tree [x]. lmc = cx , tree[ x].rs = sx ;
        isRoot [cx] = false, isRoot[sx ] = false;
    }
    int root = 0 ;
    for (int i = 1; i <= n; i++)
    {
         if ( isRoot[i ])
        {
            root = i;
            break;
        }
    }

    preOrderTraversal(tree, root); printf("\n");
    afterOrderTraversal(tree, root); printf("\n");
    levelOrderTraversal(tree, root); printf("\n");

    //system("pause");
    return 0;
}

void preOrderTraversal(const vector<node> &tr, int root)
{
    printf("%d ", root);
    int child = tr[root].lmc;
    while (child != 0)
    {
        preOrderTraversal(tr, child);
        child = tr[child].rs;
    }
}

void afterOrderTraversal(const vector<node> &tr, int root)
{
    int child = tr[root].lmc;
    while (child != 0)
    {
        afterOrderTraversal(tr, child);
        child = tr[child].rs;
    }
    printf("%d ", root);
}

void levelOrderTraversal(const vector<node> &tr, int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int t = q.front();
        printf("%d ", t);
        q.pop();
        int child = tr[t].lmc;
        while (child != 0)
        {
            q.push(child);
            child = tr[child].rs;
        }
    }
}

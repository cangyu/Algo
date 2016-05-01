//利用每个同学的学术水平都不一样来构造hash
//采用邻接链表方法来表示相互认识的关系

#include<cstdio>
#include<queue>

using namespace std;

struct node
{
    int id;
    node *next ;
    node(int i = 0, node *p = NULL) : id(i), next (p) {}
};

bool sf[ 1005] = { false };
int sl[ 10005] = { 0 };
int m[ 100005] = { 0 };
node s[10005 ];

int main( int argc, char **argv)
{
    //freopen("1112.in", "r", stdin);
    //freopen("1112.out", "w", stdout);

    int n, k , id, r;
    priority_queue <int> q;
    
    scanf("%d%d" , & n, &k );

    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", sl + i );
        m [sl[ i]] = i ;
    }

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &id);
        q.push(sl[id]);
        sf[id] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &r);
            if (r == 1)
                s[i].next = new node(j, s[i].next);
        }
    }

    while (!q.empty())
    {
        int highest = q.top();
        q.pop();
        id = m[highest];
        printf("%d\n", id);

        node *p = s[id].next;
        while (p)
        {
            if (sf[p->id] == false)
            {
                q.push(sl[p->id]);
                sf[p->id] = true;           
            }
            p = p->next;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        node *p = s[i].next;
        node *tmp;
        while (p)
        {
            tmp = p;
            p = p->next;
            delete tmp;
        }
    }

    return 0;
}


#include <iostream>
using namespace std;
const int N = 1e4 + 5;
int n, m;
int a[N];
int find(int i)
{
    int root = i;
    while(a[root] != root)
    {
        root = a[root];
    }
    
    while(i != root)
    {
        int father = a[i];
        a[father] = root;
        i = father;
    }

    return root;
}

void unionSet(int i, int j)
{
    int r1 = find(i);
    int r2 = find(j);
    if(r1 != r2)
    {
        a[r1] = r2;
    }
    else
    {
        a[i] = r1, a[j] = r2;
    }
}

void show()
{
    for(int i = 1; i <= 5; i ++ )
    {
        printf("a[%d]:%d\n",i,a[i]);
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= N; i ++ ) a[i] = i;
    while(m -- )
    {
        int k, c, b;
        cin >> k >> c >> b;
        if(k == 1)
        {
            unionSet(c, b);
            for(int i = 1; i <= n; i ++ )
                cout << a[i] << " ";
            puts("");
        }
        else
        {
            if(find(c) == find(b)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
}
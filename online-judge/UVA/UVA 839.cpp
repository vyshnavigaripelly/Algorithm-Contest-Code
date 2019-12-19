#include <iostream>
#include <string>
using namespace std;

struct BiNode
{
    int w, d;
    struct BiNode *lchild, *rchild;
};

int balanced = 1;

BiNode *Create(int weight, int dist)
{
    BiNode *now = new BiNode;
    if (weight == 0)
    {
        int wl, wr, dl, dr;
        cin >> wl >> dl >> wr >> dr;
        now->w = 0;
        now->d = dist;
        now->lchild = Create(wl, dl);
        now->rchild = Create(wr, dr);
    }
    else
    {
        now->w = weight;
        now->d = dist;
        now->lchild = NULL;
        now->rchild = NULL;
    }
    return now;
}

void postOrder(BiNode *t)
{
    if (!balanced)
    {
        return;
    }
    if (t->lchild != NULL && t->rchild != NULL)
    {
        postOrder(t->lchild);
        postOrder(t->rchild);
        if (t->lchild->w * t->lchild->d == t->rchild->w * t->rchild->d)
        {
            t->w = t->lchild->w + t->rchild->w;
            t->lchild = NULL;
            t->rchild = NULL;
        }
        else
        {
            balanced = 0;
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        balanced = 1;
        BiNode *root = Create(0, 0);
        postOrder(root);
        cout << (balanced ? "YES" : "NO") << endl;
        if (t != 0)
        {
            cout << endl;
        }
    }
    return 0;
}

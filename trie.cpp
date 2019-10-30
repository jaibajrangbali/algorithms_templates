#include <bits/stdc++.h>
using namespace std;
//find the maximum number of non-conflicting items using tries
struct node
{
    struct node *children[26];
    int No_of_zeros; //number of occurrences with zero bit
    int No_of_ones;  //number of occurrences with one bit
};
struct node *newnode()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->No_of_zeros = n->No_of_ones = 0;
    for (int i = 0; i < 26; i++)
        n->children[i] = NULL;
    return n;
}
struct node *root;
void insert_zero(char s[])
{
    struct node *p = root;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!p->children[s[i] - 'a'])
            p->children[s[i] - 'a'] = newnode();
        p = p->children[s[i] - 'a'];
    }
    p->No_of_zeros++;
}
void insert_one(char s[])
{
    struct node *p = root;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!p->children[s[i] - 'a'])
            p->children[s[i] - 'a'] = newnode();
        p = p->children[s[i] - 'a'];
    }
    p->No_of_ones++;
}
void display(struct node *n, char str[], int level)
{
    if (n->No_of_zeros)
    {
        str[level] = '\0';
        cout << str << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (n->children[i])
        {
            str[level] = i + 'a';
            display(n->children[i], str, level + 1);
        }
    }
}
int sum(struct node *now)
{
    if (now == NULL)
        return 0;
    int s = max(now->No_of_ones, now->No_of_zeros);
    for (int i = 0; i < 26; i++)
        s += sum(now->children[i]);
    return s;
}
void free_all(struct node *now)
{
    if (now == NULL)
        return;
    for (int i = 0; i < 26; i++)
        free_all(now->children[i]);
    free(now);
}
int main()
{
    int T, n, k;
    char str[100000];
    cin >> T;
    while (T--)
    {
        cin >> n;
        root = newnode();
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            cin >> k;
            if (k == 0)
                insert_zero(str);
            else
                insert_one(str);
        }
        cout << sum(root) << "\n";
        free_all(root);
    }
}

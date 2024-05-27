#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct treeNode
{
    int info;
    treeNode *left, *right;
    treeNode(int num, treeNode *L = NULL, treeNode *R = NULL)
        : info(num), left(L), right(R) {}
};

void insert(treeNode *tree, treeNode *node, int lnode, int bnode)
{
    if (tree->right == nullptr && tree->left == nullptr)
    {
        tree->left = node;
        return;
    }
    else if (tree->right == nullptr)
    {
        tree->right = node;
        return;
    }
    else
    {
        if (lnode == bnode || bnode < lnode / 2)
            insert(tree->left, node, lnode / 2, bnode);
        else
            insert(tree->right, node, lnode / 2, bnode - lnode / 2);
    }
}

void createBinaryTree(treeNode *tree)
{
    int v;
    cout << "\nEnter desired number of nodes: \n"
         << endl;
    cin >> v;

    for (int i = 0; i < v; i++)
    {
        int value;
        cout << "\nEnter value to add: " << endl;
        cin >> value;

        treeNode *node = new treeNode(value);
        int c, bnode, lnode;

        if (i == 0)
        {
            tree->info = value;
            lnode = 2;
            bnode = 0;
            c = 1;
        }
        else
        {
            insert(tree, node, lnode, bnode);
            bnode++;
            if (lnode == bnode)
            {
                bnode = 0;
                lnode = pow(2, c + 1);
                c++;
            }
        }
    }
}

int height(treeNode *tree)
{

    if (tree == nullptr)
        return 0;
    else
    {
        int left = height(tree->left);
        int right = height(tree->right);

        return std::max(left, right) + 1;
    }
}

int countLeaves(treeNode *tree)
{

    if (tree == nullptr)
        return 0;
    if (tree->left == nullptr && tree->right == nullptr)
        return 1;
    return countLeaves(tree->left) + countLeaves(tree->right);
}

int countTreeNodes(treeNode *tree)
{
    if (tree == nullptr)
        return 0;
    return 1 + countTreeNodes(tree->left) + countTreeNodes(tree->right);
}

void interchange(treeNode *tree)
{
    if (tree == nullptr)
        return;

    treeNode *hold = tree->right;
    tree->right = tree->left;
    tree->left = hold;
    delete &hold;
    interchange(tree->left);
    interchange(tree->right);
}

bool isAncestor(treeNode *tree, int p, int c)
{
    if (tree == nullptr)
        return false;
    if (tree->info == p)
    {
        return (tree->left != nullptr && tree->left->info == c) ||
               (tree->right != nullptr && tree->right->info == c);
    }
    return isAncestor(tree->left, p, c) || isAncestor(tree->right, p, c);
}

void printLevelNodes(treeNode *tree, int level)
{
    if (tree == nullptr)
        return;
    if (level == 0)
    {
        cout << tree->info << " ";
        return;
    }

    printLevelNodes(tree->left, level - 1);
    printLevelNodes(tree->right, level - 1);
}

void insertSearch(treeNode *&tree, treeNode *node)
{
    if (node->info <= tree->info)
    {
        if (tree->left == nullptr)
        {
            tree->left = node;
            return;
        }
        else
            insertSearch(tree->left, node);
    }
    else if (node->info >= tree->info)
    {
        if (tree->right == nullptr)
        {
            tree->right = node;
            return;
        }
        else
            insertSearch(tree->right, node);
    }
}
void createBinarySearchTree(treeNode *tree)
{
    int v;
    cout << "\nEnter desired number of nodes: \n"
         << endl;
    cin >> v;

    for (int i = 0; i < v; i++)
    {
        int value;
        cout << "\nEnter value to add: " << endl;
        cin >> value;
        treeNode *node = new treeNode(value);
        if (i == 0)
        {
            tree->info = value;
        }
        else
        {
            insertSearch(tree, node);
        }
    }
}

void inOrder(treeNode *tree)
{
    if (tree == nullptr)
        return;

    inOrder(tree->left);
    cout << tree->info << " ";
    inOrder(tree->right);
}

void preOrder(treeNode *tree)
{
    if (tree == nullptr)
        return;

    cout << tree->info << " ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(treeNode *tree)
{
    if (tree == nullptr)
        return;

    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->info << " ";
}

void menu(treeNode *bt, int dec)
{
    cout << "\n";
    if (dec == 1)
        cout << countTreeNodes(bt);
    else if (dec == 2)
        cout << countLeaves(bt);
    else if (dec == 3)
        cout << height(bt);
    else if (dec == 4)
        interchange(bt);
    else if (dec == 5)
    {
        int p, c;

        cout << "enter parent: ";
        cin >> p;
        cout << "enter child: ";
        cin >> c;

        cout << isAncestor(bt, p, c);
    }
    else if (dec == 6)
    {
        int l;
        cout << "enter level: ";
        cin >> l;

        printLevelNodes(bt, l);
    }
    else if (dec == 7)
        inOrder(bt);
    else if (dec == 8)
        preOrder(bt);
    else if (dec == 9)
        postOrder(bt);
}

int main()
{

    // // make my own trees
    // treeNode *three = new treeNode(1);
    // treeNode *rootL = new treeNode(2);
    // treeNode *rootR = new treeNode(3);
    // treeNode *rootLL = new treeNode(4);
    // treeNode *rootLR = new treeNode(5);
    // treeNode *rootRL = new treeNode(6);
    // treeNode *rootRR = new treeNode(7);
    // treeNode *twoL = new treeNode(8);
    // treeNode *twoR = new treeNode(9);
    // treeNode *one = new treeNode(1);
    // treeNode *two = new treeNode(2);

    // two->left = twoL;
    // two->right = twoR;
    // rootL->left = rootLL;
    // rootL->right = rootLR;
    // rootR->left = rootRL;
    // rootR->right = rootRR;
    // three->left = rootL;
    // three->right = rootR;

    // // test height, countLeaves, countTreeNodes
    // cout << "test height, countLeaves, and countTreeNodes\n";
    // cout << height(one);                   // print 1
    // cout << countLeaves(one);              // print 1
    // cout << countTreeNodes(one) << "  ";   // print 1
    // cout << height(two);                   // print 2
    // cout << countLeaves(two);              // print 2
    // cout << countTreeNodes(two) << "  ";   // print 3
    // cout << height(three);                 // print 3
    // cout << countLeaves(three);            // print 4
    // cout << countTreeNodes(three) << "\n"; // print 7

    // // test inOrder, preOrder, postOrder
    // cout << "\nin order:  ";
    // inOrder(three);
    // cout << "\npre order:  ";
    // preOrder(three);
    // cout << "\npost order:  ";
    // postOrder(three);
    // cout << "\n";

    // // test interchange
    // cout << "\ntest interchange\n";
    // cout << two->left->info;  // print 8
    // cout << two->right->info; // print 9
    // interchange(two);
    // cout << "\ninterchanged\n";
    // cout << two->left->info;          // print 9
    // cout << two->right->info; // print 8
    // cout << "\n";

    // // test printLevelNodes - 0 is first level, 1 is second level, 2 is third, etc
    // cout << "\ntest level nodes\n";
    // cout << "   ";
    // printLevelNodes(three,0);
    // cout << "\n  ";
    // printLevelNodes(three,1);
    // cout << "\n";
    // printLevelNodes(three,2);
    // cout << "\n";
    // // test isAncestor
    // cout << "\ntest ancestor\n";
    // cout << isAncestor(two, 2, 8); // print 1
    // cout << " ";
    // cout << isAncestor(two, 8, 2); // print 0
    // cout << "\n";

    // test createBinaryTree
    cout << "\ntest create binary tree\n";
    treeNode *tr = new treeNode(0);
    createBinaryTree(tr);

    // test createBinarySearchTree
    cout << "\ntest create binary search tree\n";
    treeNode *bst = new treeNode(0);
    createBinarySearchTree(bst);
    int dec = 1;

    while (dec != 0)
    {

        cout << "\n-----------------------\n";
        cout << "1. test countTreeNodes\n";
        cout << "2. test countLeaves\n";
        cout << "3. test height\n";
        cout << "4. test interchange\n";
        cout << "5. test isAncestor\n";
        cout << "6. test printLevelNodes\n";
        cout << "7. test inOrder\n";
        cout << "8. test preOrder\n";
        cout << "9. test postOrder\n";
        cout << "0 - exit\n";
        cin >> dec;

        int bt;
        cout << "test with Binary Tree(1) - test with Binary Search Tree(2)\n";
        cin >> bt;

        if (bt == 1)
            menu(tr, dec);
        else
            menu(bst, dec);
    }
}
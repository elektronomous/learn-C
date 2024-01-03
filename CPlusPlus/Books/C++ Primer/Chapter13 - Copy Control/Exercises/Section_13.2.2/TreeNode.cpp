#include <iostream>
#include <string>

using namespace std;

class TreeNode {
    TreeNode() = default;
    TreeNode(const TreeNode &rhs):
        value(rhs.value), count(rhs.count),
        left(rhs.left), right(rhs.right) {}
    TreeNode& operator=(const TreeNode &rhs);

    private:
        string value;
        int    count;
        TreeNode *left;
        TreeNode *right;
};

class BinStrTree { 
    BinStrTree(TreeNode *tr) :
        root(tr) {}
    private:
        TreeNode *root;
};

/*

                                                 BinStrTree
                                                      |
                            ________________________(root)________________________
                           /                                                      \
                          /                                                        \
             ________LeftNode________                                   ________RightNode________
            /                        \                                 /                         \
________LeftNode________  ________RightNode________         ________LeftNode________  ________RightNode________                       
/                      \ /                        \        /                        \ /                        \
..                      ....                .........   ......                  ......  .......             .......
*/
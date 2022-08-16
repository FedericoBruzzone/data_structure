#include "../../ALL_H_FILES.h"

#include "tree.cpp"

#include "4.2_minimal_tree.cpp"

// std::list was used as a Linked List

// =============================================================

// Depth-First Search
void createLevelLinkedListDFS(TNode* root, std::vector<std::list<TNode*>>* lists, int index)
{
    if (root == NULL) return;

    std::list<TNode*> list;

    if (lists->size() == index)
    {
        list = std::list<TNode*>();
        list.push_back(root);
        lists->push_back(list); 
    }
    else
    {   
        list = lists->at(index);
    }

    createLevelLinkedListDFS(root->left, lists, index + 1);
    createLevelLinkedListDFS(root->right, lists, index + 1);
}

std::vector<std::list<TNode*>> createLevelLinkedListDFS(TNode* root)
{
    std::vector<std::list<TNode*>>* lists = new std::vector<std::list<TNode*>>();
    createLevelLinkedListDFS(root, lists, 0);
    return *lists;
}

// =============================================================

// Breadth-First Search
std::vector<std::list<TNode*>> createLevelLinkedListBFS(TNode* root)
{
    std::vector<std::list<TNode*>> lists = std::vector<std::list<TNode*>>();

    std::list<TNode*> current = std::list<TNode*>();
    if (root != NULL) current.push_back(root);

    while (current.size() > 0)
    {
        lists.push_back(current);
        std::list<TNode*> parents = current;
        current.clear();

        for (TNode* parent : parents)
        {
            if (parent->left != NULL) current.push_back(parent->left);
            if (parent->right != NULL) current.push_back(parent->right);
        }
    }

    return lists;
}

// =============================================================

int main()
{
    TNode* btree = createMinimalBST({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    //std::vector<std::list<TNode*>> lists = createLevelLinkedListBFS(btree);
    std::vector<std::list<TNode*>> lists = createLevelLinkedListDFS(btree);

    for (std::list<TNode*> list : lists)
    {
        for (TNode* node : list)
        {
            LOG(node->data)
        }
        printf("\n");
    }

    
}
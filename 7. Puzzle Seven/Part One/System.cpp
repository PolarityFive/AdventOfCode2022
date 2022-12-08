#include "System.h"

System::System()
{
    rootDir = new Node();

    rootDir->name = "/";
    rootDir->size = 0;
    rootDir->parent = nullptr;
}

void System::cd(const std::string& name)
{
    for (int i = 0; i < currentDir->children.size(); i++)
    {
        if (currentDir->children[i]->name == name)
            currentDir = currentDir->children[i];
    }
}

void System::cdBack()
{
    if (currentDir->parent != nullptr)
        currentDir = currentDir->parent;
}

void System::addDir(Node *node) const
{
    currentDir->children.emplace_back(node);
    node->parent = currentDir;
}

void System::addSize(uintptr_t size) const
{
    currentDir->size += size;
}

void System::calcParentalSize(uintptr_t size) const
{
    Node *traversalNode = currentDir;

    while (traversalNode->parent != nullptr)
    {
        traversalNode->parent->size += size;
        traversalNode = traversalNode->parent;
    }
}

uintptr_t System::solve()
{
    uintptr_t sum = 0;

    solveFor(rootDir, sum);

    return sum;
}

void System::solveFor(Node *node, uintptr_t &sum)
{
    if (node->size <= this->maxSize)
        sum += node->size;

    for (auto & i : node->children)
        solveFor(i, sum);
}



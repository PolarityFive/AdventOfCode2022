#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H

#include <iostream>
#include <vector>

struct Node
{
    std::string name;
    uintptr_t size;

    Node *parent;
    std::vector<Node *> children;
};

class System
{
public:
    Node *rootDir;
    Node *currentDir;

    const uintptr_t maxSize = 100000;

public:
    System();
    void cd(const std::string& name);
    void cdBack();
    void addDir(Node *node) const;
    void addSize(uintptr_t size) const;
    void calcParentalSize(uintptr_t size) const;

    uintptr_t solve();
    void solveFor(Node *node, uintptr_t &sum);

};
#endif
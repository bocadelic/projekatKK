#ifndef MY_SET_H
#define MY_SET_H

#include "llvm/Pass.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Function.h"

using namespace llvm;

class MySet {
public:
    MySet();

    void insert(Value *Val);
    bool contains(Value *Val);
    void clear();
    std::vector<Value *>& getElements();

private:
    unsigned timestamp;
    std::set<Value *> ValueSet;
    std::set<std::pair<int, Value*>> SortedSet;
    std::vector<Value *> Values;
};

#endif
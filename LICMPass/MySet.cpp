#include "MySet.h"

MySet::MySet() : timestamp(0) {}

void MySet::insert(Value *Val) {
    ValueSet.insert(Val);
    SortedSet.insert(std::make_pair(timestamp, Val));
    timestamp++;
}

bool MySet::contains(Value *Val) {
    return ValueSet.find(Val) != ValueSet.end();
}

void MySet::clear() {
    ValueSet.clear();
    SortedSet.clear();
    Values.clear();
}

std::vector<Value *>& MySet::getElements() {
    // da li treba obrisati Values pre dodavanja???
    for (auto &Val : SortedSet) {
        Values.push_back(Val.second);
    }
    return Values;
}
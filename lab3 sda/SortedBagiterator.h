#pragma once
#include "SortedBag.h"

typedef int TComp;

typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);
class SortedBag;
class SortedBagIterator {

    friend class SortedBag;

private:
    SortedBag& bag;
    int currentindex;
    SortedBagIterator(SortedBag& bag);

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

};
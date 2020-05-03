#pragma once
#include "SortedBagiterator.h"

typedef int TComp;

typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);


class SortedBagIterator;

class SortedBag {

private:
    Relation rel;
    int s, capacity;
    TElem* elems;
    friend class SortedBagIterator;

public:
    void resize(int factor = 2);
    explicit SortedBag(Relation r);
    void add(TComp e);
    bool remove(TComp e);
    bool search(TComp e) const;
    int nrOccurrences(TComp e) const;
    int size() const;
    SortedBagIterator iterator();
    bool isEmpty() const;
    ~SortedBag();
};
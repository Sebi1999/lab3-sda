#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <iostream>

//theta(1)
SortedBagIterator::SortedBagIterator(SortedBag &bag): bag(bag)
{
    this->bag=bag;
    this->currentindex = 0;
}
//theta(1)
void SortedBagIterator::first()
{
    this->currentindex=0;
}
//theta(1)
void SortedBagIterator::next()
{
    if (!this->valid())
    {
        throw std::exception();
    }
    this->currentindex+=1;
}
//theta(1)
bool SortedBagIterator::valid() const
{
    return this->currentindex < this->bag.size();
}
//theta(1)
TElem SortedBagIterator::getCurrent() const
{
    if (!this->valid())
    {
        throw std::exception();
    }
    return this->bag.elems[currentindex];
}
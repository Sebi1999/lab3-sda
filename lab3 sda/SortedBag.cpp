#include "SortedBag.h"
#include <iostream>
using namespace std;

//AC=BC=WC:theta(1)
SortedBag::SortedBag(Relation r)
{
    this->s = 0;
    this->capacity = 2;
    this->elems = new TElem[this->capacity];
    this->rel = r;
}

//AC=BC=WC:theta(n)
void SortedBag::resize(int factor)
{
    this->capacity *= factor;
    TElem *auxArray = new TElem[this->capacity];

    for (int i=0; i<this->s; i++)
        auxArray[i] = this->elems[i];

    delete[] this->elems;
    this->elems = auxArray;
}

//BC:theta(1) WC:theta(n) AC:O(n)
void SortedBag::add(TComp e)
{
    if (this->s + 1 == this->capacity)
        this->resize();

    int pos = 0;
    if (this->s > 0)
    {
        while (pos < this->s && rel(this->elems[pos],e))
            pos++;

       for(int i=this->s + 1;i>pos;i--)
            this->elems[i] = this->elems[i-1];
    }
    this->elems[pos]=e;
    this->s++;
}
//BC:theta(1) WC:theta(n) AC:O(n)
bool SortedBag::remove(TComp e)
{
    int i;
    bool pos=this->search(e);

    if (pos)
    {
        int k=0;
        for (i=0; i < this->s; i++)
            if (this->elems[i]==e)
                k=i;

        for (i=k;i<this->s-1;i++)
            this->elems[i]=this->elems[i+1];

        this->s -= 1;
        return true;
    }
    return false;
}
//AC=BC=WC:theta(n)
bool SortedBag::search(TComp e) const
{
    int i;
    bool k=false;
    for (i=0;i<this->s;i++)
        if (this->elems[i]==e)
            k=true;

    return k;
}
//AC=BC=WC:theta(n)
int SortedBag::nrOccurrences(TComp e) const
{
    int k=0;
    for (int i=0;i<this->s;i++)
        if (this->elems[i]==e)
            k += 1;

    return k;
}
//AC=BC=WC:theta(1)
int SortedBag::size() const
{
    return this->s;
}
//AC=BC=WC:theta(1)
bool SortedBag::isEmpty() const
{
    return this->s==0;
}
//AC=BC=WC:theta(n)
SortedBag::~SortedBag()
{
    delete[] this->elems;
}
//AC=BC=WC:theta(1)
SortedBagIterator SortedBag::iterator()
{
    return SortedBagIterator(*this);
}
#ifndef ARRAYCOLLECTION_H
#define ARRAYCOLLECTION_H

#define START_LENGTH 30
#include "./data/abstractcollection.h"

//Iterator implementation based off of the one found here: https://www.robertlarsononline.com/2017/04/24/iterator-pattern-using-cplusplus/

template <class Item>
class ArrayCollection : public Collection <Item>
{
public:
    ArrayCollection();
    virtual ~ArrayCollection();
    virtual Iterator<Item> * CreateIterator() const;
    virtual unsigned int Count() const;
    virtual unsigned int Length() const;
    virtual void Append (Item item);
    virtual const Item& Get(unsigned int index) const;

private:
    Item * arr;
    unsigned int count;
    unsigned int length;
};

template <class Item>
class ArrayCollectionIterator : public Iterator <Item>
{
public:
    ArrayCollectionIterator(const ArrayCollection<Item> * arrC);
    virtual ~ArrayCollectionIterator ();
    virtual void First();
    virtual void Next();
    virtual bool IsDone() const;
    virtual Item CurrentItem() const;

private:
    const ArrayCollection<Item> * arrCollection;
    unsigned int index;
};

#endif // ARRAYCOLLECTION_H

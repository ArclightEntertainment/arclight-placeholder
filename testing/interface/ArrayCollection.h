#ifndef ARRAYCOLLECTION_H
#define ARRAYCOLLECTION_H

#define START_LENGTH 30
#include "./AbstractCollection.h"

//Iterator implementation based off of the one found here: https://www.robertlarsononline.com/2017/04/24/iterator-pattern-using-cplusplus/

template <class Item>
class ArrayCollection : public Collection <Item>
{
public:
    ArrayCollection();
    virtual ~ArrayCollection();
    virtual Iterator<Item> * createIterator() const;
    virtual unsigned int count() const;
    virtual unsigned int length() const;
    virtual void append (Item item);
    virtual const Item& get(unsigned int index) const;

private:
    Item * arr;
    unsigned int numElements;
    unsigned int maxNumElements;
};


template <class Item>
class ArrayCollectionIterator : public Iterator <Item>
{
public:
    ArrayCollectionIterator(const ArrayCollection<Item> * arrC);
    virtual ~ArrayCollectionIterator ();
    virtual void first();
    virtual void next();
    virtual bool isDone() const;
    virtual Item currentItem() const;

private:
    const ArrayCollection<Item> * arrCollection;
    unsigned int index;
};

#endif // ARRAYCOLLECTION_H

#ifndef ABSTRACTCOLLECTION_H
#define ABSTRACTCOLLECTION_H


template <class Item>
class Iterator
{
public:
    virtual void first()=0;
    virtual void next()=0;
    virtual bool isDone() const =0;
    virtual Item currentItem() const =0;
};

template <class Item>
class Collection
{
    virtual Iterator<Item> * createIterator() const =0;
    virtual unsigned int count() const =0;
    virtual unsigned int length() const =0;
    virtual void append (Item item) =0;
};


#endif // ABSTRACTCOLLECTION_H

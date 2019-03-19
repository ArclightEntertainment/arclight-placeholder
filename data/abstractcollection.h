#ifndef ABSTRACTCOLLECTION_H
#define ABSTRACTCOLLECTION_H


template <class Item>
class Iterator
{
public:
    virtual void First()=0;
    virtual void Next()=0;
    virtual bool IsDone() const =0;
    virtual Item CurrentItem() const =0;
};

template <class Item>
class Collection
{
    virtual Iterator<Item> * CreateIterator() const =0;
    virtual unsigned int Count() const =0;
    virtual unsigned int Length() const =0;
    virtual void Append (Item item) =0;
};


#endif // ABSTRACTCOLLECTION_H

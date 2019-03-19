#include "arraycollection.h"
#include <iostream>

template <class Item>
ArrayCollection<Item>::ArrayCollection() : count(0), length(START_LENGTH)
{
    arr = new Item[START_LENGTH];
}


template <class Item>
ArrayCollection<Item>::~ArrayCollection()
{

}

template <class Item>
Iterator<Item> * ArrayCollection<Item>::CreateIterator() const
{
    return new ArrayCollectionIterator<Item>(this);
}

template <class Item>
unsigned int ArrayCollection<Item>::Count() const
{
    return count;
}

template <class Item>
unsigned int ArrayCollection<Item>::Length() const
{
    return length;
}

template <class Item>
void ArrayCollection<Item>::Append (Item item)
{
    arr[count] = item;
    count ++;

    //std::cout<< "Current Count: " << count;
    //std::cout<< " Max Length: " << length <<std::endl;

    if (count == length-1)
    {
        std::cout<<"Reached Max Length: " << length <<std::endl;
        Item * newArr = new Item[length * 2];
        for (int i = 0; i < length; i ++)
        {
            newArr[i] = arr[i];
        }
        length *= 2;
        arr = newArr;
    }
}

template <class Item>
const Item& ArrayCollection<Item>::Get(unsigned int index) const
{
    if (index >= count)
    {
        return Item();
    }
    return arr[index];
}

template <class Item>
ArrayCollectionIterator<Item>::ArrayCollectionIterator(const ArrayCollection<Item> * arrC) : arrCollection(arrC), index (0)
{

}

template <class Item>
ArrayCollectionIterator<Item>::~ArrayCollectionIterator ()
{

}

template <class Item>
void ArrayCollectionIterator<Item>::First()
{
    index = 0;
}

template <class Item>
void ArrayCollectionIterator<Item>::Next()
{
    index ++;
}

template <class Item>
bool ArrayCollectionIterator<Item>::IsDone() const
{
    return (arrCollection->Count() <= index);
}

template <class Item>
Item ArrayCollectionIterator<Item>::CurrentItem() const
{
    if (IsDone())
    {
        return Item();
    }
    return arrCollection->Get(index);
}

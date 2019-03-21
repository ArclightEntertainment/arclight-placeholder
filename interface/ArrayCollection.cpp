#include <iostream>

#include "ArrayCollection.h"
#include "./Description.h"
#include "./Entity.h"


template <class Item>
ArrayCollection<Item>::ArrayCollection() : numElements(0), maxNumElements(START_LENGTH)
{
    arr = new Item[START_LENGTH];
}


template <class Item>
ArrayCollection<Item>::~ArrayCollection()
{

}

template <class Item>
Iterator<Item> * ArrayCollection<Item>::createIterator() const
{
    return new ArrayCollectionIterator<Item>(this);
}

template <class Item>
unsigned int ArrayCollection<Item>::count() const
{
    return numElements;
}

template <class Item>
unsigned int ArrayCollection<Item>::length() const
{
    return maxNumElements;
}

template <class Item>
void ArrayCollection<Item>::append (Item item)
{
    arr[numElements] = item;
    numElements ++;
    //std::cout << "Adding " << ((&item == NULL) ? "sadness" : "happyboi") << " in a list of size " << numElements << std::endl;

    if (numElements == maxNumElements-1)
    {
        Item * newArr = new Item[maxNumElements * 2];
        for (int i = 0; i < (int)maxNumElements; i ++)
        {
            newArr[i] = arr[i];
        }
        maxNumElements *= 2;
        arr = newArr;
    }
}

template <class Item>
const Item& ArrayCollection<Item>::get(unsigned int index) const
{
    if (index >= numElements)
    {
        return Item();
    }
    return arr[index];
}



template <class Item>
void ArrayCollection<Item>::setValue (int index, Item newVal)
{
    arr[index] = newVal;
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
void ArrayCollectionIterator<Item>::first()
{
    index = 0;
}

template <class Item>
void ArrayCollectionIterator<Item>::next()
{
    index ++;
}

template <class Item>
bool ArrayCollectionIterator<Item>::isDone() const
{
    return (index >= arrCollection->count());
}

template <class Item>
Item ArrayCollectionIterator<Item>::currentItem() const
{
    if (isDone())
    {
        return Item();
        //return NULL;
    }
    return arrCollection->get(index);
}
template class ArrayCollection<Description<int>>;
template class ArrayCollection<Description<std::string>>;
template class ArrayCollection<Description<bool>>;
template class ArrayCollection<UAnimal*>;
template class ArrayCollection<UClient*>;
template class ArrayCollection<Entity*>;

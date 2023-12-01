#include <stdexcept>
#include <iostream>

#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList(){
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;

    aList = new objPos[sizeArray]();
}

objPosArrayList::~objPosArrayList(){
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // prevent deletion of data
    if (sizeArray == sizeList){
        std::cout << "Array at max!\n";
        throw std::invalid_argument("Array at max capacity");
    }

    // shift all elements forward in prep for front insert
    for (int i = sizeList - 2; i > 0; i --){
        // std::cout << "Accessing " << i+1 << ", " << i << "\n";
        aList[i+1] = aList[i]; 
    }

    // set first elem to shifted elem
    aList[0] = thisPos;

    // update params
    sizeList ++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // prevent deletion of data
    if (sizeArray == sizeList){
        std::cout << "Array at max!\n";
        throw std::invalid_argument("Array at max capacity");
    }

    aList[sizeList] = thisPos;

    // update params
    sizeList ++;
}

void objPosArrayList::removeHead()
{
    // only remove if elems!=0
    if (sizeList == 0){
        std::cout << "No elements to remove!\n";
        // throw std::invalid_argument("No elems to remove");
    }

    // shift all over by 1. head will aturally be deleted
    for (int i = sizeList - 2; i >= 0; i --){
        aList[i] = aList[i+1]; 
    }
    // delete phantom remaining tail
    aList[sizeList-1] = objPos();

    // update params
    sizeList --;
}

void objPosArrayList::removeTail()
{
    // only remove if elems!=0
    if (sizeList == 0){
        std::cout << "No elements to remove!\n";
        // throw std::invalid_argument("No elems to remove");
    }

    aList[sizeList-1] = objPos(); // blank constructor

    // update params
    sizeList --;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    if (sizeList == 0){
        std::cout << "No elems\n";
        throw std::invalid_argument("No elems");
    }

    returnPos = aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    if (sizeList == 0){
        std::cout << "No elems\n";
        throw std::invalid_argument("No elems");
    }

    returnPos = aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos = aList[index];
}
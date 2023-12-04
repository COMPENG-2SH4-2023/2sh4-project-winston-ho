#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int sizeList;
        int sizeArray;

    public:
        objPosArrayList();
        ~objPosArrayList();

        int getSize();
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);

        // return:
        // -1: could not find
        // any_other_int: the index of the found object
        // strictMatchSymbol: default false 
        // if false, only need to have same coordinates to match. if true, must also match symbol
        int find(objPos toFind, bool strictMatchSymbol); 
        int find(int x, int y);
};

#endif
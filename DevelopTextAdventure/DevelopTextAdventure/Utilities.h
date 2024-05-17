#pragma once
#include <vector>
#include "String.h"
#include <algorithm>
#include "Spell.h"

int BinarySearch(std::vector<String*> vec, const String& search, int startIndex, int endIndex)
{
    std::sort(vec.begin(), vec.end());    //  sorts vector

    int pivot;  //  pivot for binary search

    String pivotPoint;

    String str(search);

    while (startIndex <= endIndex)  //  possible search length
    {
        pivot = (startIndex + endIndex) / 2;  //  start at centre of search area

        pivotPoint = vec[pivot]->CStr();

        if (pivotPoint == str)   //  if pivot is search target
        {
            return pivot;
        }
        else if (pivotPoint > str)   //  if pivot is greater than search target
        {
            endIndex = pivot - 1;
        }
        else   //   if pivot is less than search target
        {
            startIndex = pivot + 1;
        }
    }

    return -1;
}

int SpellBinarySearch(std::vector<Spell*> vec, const String& spell, int startIndex, int endIndex)
{
    std::sort(vec.begin(), vec.end());    //  sorts vector

    int pivot;  //  pivot for binary search

    String pivotPoint;

    String str(spell);

    while (startIndex <= endIndex)  //  possible search length
    {
        pivot = (startIndex + endIndex) / 2;  //  start at centre of search area

        pivotPoint = vec[pivot]->CStr();

        if (pivotPoint == str)   //  if pivot is search target
        {
            return pivot;
        }
        else if (pivotPoint > str)   //  if pivot is greater than search target
        {
            endIndex = pivot - 1;
        }
        else   //   if pivot is less than search target
        {
            startIndex = pivot + 1;
        }
    }

    return -1;
}
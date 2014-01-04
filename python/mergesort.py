#! /usr/bin/env python
# -*- coding: utf-8 -*-

def mergesort(arr):
    size = len(arr)

    if size < 2:
        return arr

    middle = size / 2
    arr1 = mergesort(arr[0:middle])
    arr2 = mergesort(arr[middle:])
    i = 0
    arr_res = []

    for item in arr1:
        while(i < len(arr2)) and (arr2[i] < item):
            arr_res.append(arr2[i])
            i += 1
        arr_res.append(item)

    for j in range(i, len(arr2)):
        arr_res.append(arr2[j])
    return arr_res

nums = [1, 3, 5, 3, 4, 8, 2, 22, 7, 11, 7]
print nums
b = mergesort(nums)
print b

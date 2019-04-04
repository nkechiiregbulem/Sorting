//
//  main.cpp
//  Sorting Lab
//
//  Created by Nkechi Iregbulem on 3/29/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
#include <chrono>
#include <vector>
#include <utility>
#include <math.h>

void print(vector<pair<string,int>> vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << ", " << vec[i].second << endl;
    }

}

void insertsortt2(vector<pair<string, int>> &vec)
{
    int i;
    int j;
     pair<string, int>temp;
    
    
    for (i = 1; i < vec.size(); ++i) {
        j=i;
        while(j > 0 && vec.at(j).second < vec.at(j-1).second) {
             temp = vec.at(j);
            vec.at(j) = vec.at(j-1);
            vec.at(j-1) = temp;
            --j;
        }
    }
}

int Partition(vector<pair<string,int>> &vec, int i, int k)
{
    int l;
    int h;
    int midpoint;
    int pivot;
    int temp;
    bool done;
    
    midpoint = i + (k-i)/2;
    pivot = vec.at(midpoint).second;
    done = false;
    l = i;
    h = k;
    
    while(!done) {
        while (vec.at(l).second < pivot) {
            ++l;
        }
        
        while (pivot < vec.at(h).second) {
            --h;
        }
        
        if (l >= h) {
            done = true;
        }
        else {
            temp = vec.at(l).second;
            vec.at(l).second= vec.at(h).second;
            vec.at(h).second = temp;
            ++l;
            --h;
        }
        
        
    }
    return h;
    
    
    
}
void QuickSort(vector<pair<string, int>> &vec, int i, int k) {
    int j;
    
    if (i >= k) {
        return;
    }
    j = Partition(vec, i, k);
    QuickSort(vec, i, j);
    QuickSort(vec, j + 1, k);
    
    
    
}
void Merge(vector<pair<string, int>> &vec, int i, int j, int k) {
    int mergedSize;
    int mergePos;
    int leftPos;
    int rightPos;
    int* mergedNumbers = nullptr;
    
    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i;
    rightPos = j + 1;
    mergedNumbers = new int[mergedSize];
    
    while (leftPos <= j && rightPos <= k) {
        if (vec[leftPos].second < vec[rightPos].second) {
            mergedNumbers[mergePos] = vec[leftPos].second;
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = vec[rightPos].second;
            ++rightPos;
            
        }
        ++mergePos;
        
}
    while (leftPos <= j) {
        mergedNumbers[mergePos] = vec[leftPos].second;
        ++leftPos;
        ++mergePos;
    }
    while (rightPos <= k) {
        mergedNumbers[mergePos] = vec[rightPos].second;
        ++rightPos;
        ++mergePos;
    }

    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        vec.at(i + mergePos).second = mergedNumbers[mergePos];
    }
}

void MergeSort(vector<pair<string, int>> &vec, int i, int k) {
    int j;
    
    if (i < k) {
        j = (i + k) / 2;
        
        MergeSort(vec, i, j);
        MergeSort(vec, j + 1, k);
        Merge(vec, i, j, k);
    }
}
int getMax(vector<pair<string, int>> &vec, int n)
{
    int mx = vec[0].second;
    for (int i = 1; i < n; i++)
        if (vec[i].second > mx)
            mx = vec[i].second;
    return mx;
}

void countSort(vector<pair<string, int>> &vec, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    
    for (i = 0; i < n; i++)
        count[ (vec[i].second/exp)%10 ]++;
    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (vec[i].second/exp)%10 ] - 1] = vec[i].second;
        count[ (vec[i].second/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        vec[i].second = output[i];
    
}

void RadixSort(vector<pair<string, int>> &vec, int n)
{
    int m = getMax(vec, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(vec, n, exp);
    
}

void SelectionSort(vector<pair<string, int>> &vec, int n)
{
    int i = 0;
    int j = 0;
    int indexSmallest = 0;
    pair<string, int>temp;

    for (i = 0; i < vec.size() - 1; ++i) {
        int indexSmallest = i;
        for (j = i + 1; j < vec.size(); ++j) {
            if ( vec[j].second < vec[indexSmallest].second ) {
                indexSmallest = j;
            }
        }
        temp = vec[i];
        vec[i].second = vec[indexSmallest].second;
        vec[indexSmallest] = temp;
        
    }
    
}

int ShellSort(vector<pair<string, int>> &vec, int n)
{
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = vec[i].second;
            int j;
            for (j = i; j >= gap && vec[j - gap].second > temp; j -= gap)
                vec[j].second = vec[j - gap].second;
            vec[j].second = temp;
        }
    }
    return 0;
}

void weekmain() {
    vector<pair<string,int>>Items;
    pair<string, int>Products;
    string name;
    int price;
    Products = make_pair(name, price);
    for (int i =0; i < 200; i++) {
        name = "item" + to_string(i);
        price = rand()%500;
         Products = make_pair(name, price);
        Items.push_back(Products);
    }
    cout << "1) Insertion Sort" << endl;
    cout << "2) Quick Sort" << endl;
    cout << "3) Merge Sort" << endl;
    cout << "4) Radix Sort" << endl;
    cout << "5) Selection Sort" << endl;
    cout << "6) Shell Sort" << endl;
    int option;
    cout << "Please Choose an option" << endl;
    while (option < 1 || option < 6) {
        cin >> option;
        if (option == 6) {
            int Itemsize = 200;
            auto start = chrono::high_resolution_clock::now();
            ShellSort(Items, Itemsize);
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double> elasped = finish - start;
            cout << "Elasped Time: " << elasped.count() << endl;
            print(Items);
        }
        if (option == 5) {
            int Itemsize = 200;
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(Items, Itemsize);
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double> elasped = finish - start;
            cout << "Elasped Time: " << elasped.count() << endl;
            print(Items);
        }
        if (option == 1 ) {
            auto start = chrono::high_resolution_clock::now();
            insertsortt2(Items);
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double> elasped = finish - start;
            cout << "Elasped Time: " << elasped.count() << endl;
            print(Items);
        }
        if (option == 2) {
            int Itemsize = 200;
            auto start = chrono::high_resolution_clock::now();
            QuickSort(Items, 0, Itemsize-1);
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double> elasped = finish - start;
            cout << "Elasped Time: " << elasped.count() << endl;
            print(Items);
        }
        if (option == 3) {
            int Itemsize = 200;
            MergeSort(Items, 0, Itemsize-1);
            print(Items);
        }
        if (option == 4) {
            int Itemsize = 200;
            RadixSort(Items, Itemsize);
            print(Items);
        }
        
        cout << "Choose another option" << endl;
        cin >> option;
    };
    
}

int main() {
    weekmain();
    return 0;
}


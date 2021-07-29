#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <cstdlib>
#include <iostream>
#include <stddef.h>

using namespace std;
// TODO: Implement the sorting algorithm

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end)
{
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end)
{
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}

// template < class T >
void mysort(int Larr[], int Rarr[], int nG, int lG, int rG, int cost)
{
    int size_L = lG;
    int size_R = rG;
    int Tcost = 0;
    int need_P = (int)(lG+rG)/2 - rG;
    int lost_P = need_P;
    QuickSort(Larr, 0, lG-1);
    QuickSort(Rarr, 0, rG-1);

    if (lost_P != 0) // need check pair
    {
        for (int l = 0; l < lG; l++)
        {
            if (lost_P == 0)
            {
                cout << "Z ";
                for (int r = 0; r < rG; r++) // only scan rest L is same as R or not
                {
                    if (Larr[l] == Rarr[r]) // cancel each other
                    {
                        cout << "F ";
                        Larr[l] = 0;
                        Rarr[r] = 0;
                        break;
                    }
                    cout << "G ";
                    continue;
                }
                continue;
            }

            bool CP = true; // check pair
            for (int r = 0; r < rG; r++)
            {
                if (Larr[l] == Rarr[r]) // cancel each other
                {
                    cout << "A ";
                    Larr[l] = 0;
                    Rarr[r] = 0;
                    CP = false;
                    break;
                }
                cout << "H ";
                continue;
            }

            if (CP)
            {
                if (l+1 != lG && Larr[l] == Larr[l+1] )  // construct one pair
                {
                    cout << "B ";
                    Larr[l] = 0;
                    Larr[l+1] = 0;
                    lost_P = lost_P - 1;
                    l = l + 1;
                    continue;
                }
                else // dont do nothing
                {
                    cout << "C ";
                    continue;
                }
            }
        }
    }
    else // original had same # L R
    {
        for (int l = 0; l < lG; l++)
        {
            for (int r = 0; r < rG; r++)
            {
                if (Larr[l] == Rarr[r]) // cancel each other
                {
                    cout << "D ";
                    Larr[l] = 0;
                    Rarr[r] = 0;
                    break;
                }
                cout << "E ";
                continue;
            }
        }
    }

    cout << endl;
    int NNZ = 0;
    for (int i = 0; i < lG; i++)
    {
        cout << " " << Larr[i];
        if (Larr[i] != 0)
        {
            NNZ += 1;
            continue;
        }
    }

    cout << endl;
    cout << "NNZ = " << NNZ << endl;
    cout << "lost_P = " << lost_P << endl;
    cout << "need_P = " << need_P << endl;

    Tcost = cost * (NNZ - lost_P + need_P);
    cout << Tcost << endl;
}

// TODO: Implement the funtion to read input, process data, and output answers.
void solve()
{
    int nG, lG, rG, cost, gem, L, S;
    cin >> nG >> lG >> rG >> cost;
    if (lG < rG)
    {
        L = rG;
        S = lG;
        int Larr[L], Sarr[S];
        for (int i = 0; i < S; i++)
        {
            cin >> gem;
            Sarr[i] = gem;
        }
        for (int i = 0; i < L; i++)
        {
            cin >> gem;
            Larr[i] = gem;
        }

        mysort(Larr, Sarr, nG, L, S, cost);
    }
    else
    {
        L = lG;
        S = rG;
        int Larr[L], Sarr[S];
        for (int i = 0; i < L; i++)
        {
            cin >> gem;
            Larr[i] = gem;
        }
        for (int i = 0; i < S; i++)
        {
            cin >> gem;
            Sarr[i] = gem;
        }
        mysort(Larr, Sarr, nG, L, S, cost);
    }
}


// The codes bellow prevent you from using bulit-in sorting function and from importing C++ containers.
// Nothing needed to be implemented below.
// Do not modify the codes below.

void qsort(void* , std::size_t , std::size_t , void*);

template <class RandomAccessIterator>
void sort (RandomAccessIterator , RandomAccessIterator );

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator , RandomAccessIterator , Compare );

#endif
#ifndef vector
#define vector
#endif
#ifndef list
#define list
#endif
#ifndef forward_list
#define forward_list
#endif
#ifndef deque
#define deque
#endif
#ifndef array
#define array
#endif
#ifndef set
#define set
#endif
#ifndef multiset
#define multiset
#endif
#ifndef map
#define map
#endif
#ifndef multimap
#define multimap
#endif
#ifndef unordered_set
#define unordered_set
#endif
#ifndef unordered_multiset
#define unordered_multiset
#endif
#ifndef unordered_map
#define unordered_map
#endif
#ifndef unordered_multimap
#define unordered_multimap
#endif
#ifndef bitset
#define bitset
#endif
#ifndef valarray
#define valarray
#endif
#ifndef stack
#define stack
#endif
#ifndef queue
#define queue
#endif
#ifndef priority_queue
#define priority_queue
#endif

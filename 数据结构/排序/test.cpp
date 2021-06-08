//
//  main.c
//  Insertion or Heap
//
//  Created by air on 2018/5/12.
//  Copyright © 2018年 air. All rights reserved.
//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
void Insertion_sort_Compare(ElementType A[], int N, ElementType Result[]);
void print(ElementType A[], int N);
bool Compare(ElementType tmpResult[], ElementType Result[], int length);
void Heap_sort_Compare(ElementType A[], int total,ElementType Result[]);
void PercolateDown(ElementType A[], int i, int N);
void myswap(ElementType *a, ElementType *b);
 
int main(int argc, const char * argv[]) {
    int total;
    scanf("%d",&total);
    ElementType * A;
    A = (ElementType *) malloc(sizeof(ElementType) * total);
    for(int i = 0; i < total; i++)
        scanf("%d",&A[i]);
    
    ElementType * Result;
    Result = (ElementType *)malloc(sizeof(ElementType) * total);
    for(int j = 0; j < total; j++)
        scanf("%d",&Result[j]);
    
    ElementType * tmpResult;
    tmpResult = (ElementType *) malloc(sizeof(ElementType) * total);
    for(int i = 0; i < total; i++)
        tmpResult[i] = A[i];
    
    Insertion_sort_Compare(tmpResult, total, Result);
    Heap_sort_Compare(A,total,Result);
    return 0;
}
/*----------------------------------------------------------------------
 Heap_sort_compare, Build MaxHeap and then HeapSort
 -----------------------------------------------------------------------*/
void PercolateDown(ElementType A[], int i, int N){
    int parent, child;
    ElementType tmp = A[i];
    for(parent = i; parent * 2 + 1 < N; parent = child){
        child = parent * 2 + 1;
        if(child+1 <= N-1 && A[child+1] > A[child])
            child++;
        if(A[child] < tmp)
            break;
        A[parent] = A[child];
    }
    A[parent] = tmp;
}
 
void Heap_sort_Compare(ElementType A[], int total,ElementType Result[]){
    int i, j, flag;
    flag = 0;
    for(i = total/2 -1; i >= 0; i--){
        PercolateDown(A, i ,total);
    }
    print(A,total);
    for(j = total-1; j > 0; j--){
        myswap(&A[0], &A[j]);
        PercolateDown(A, 0, j);
        print(A,total);
        if(Compare(A, Result, total)){
            flag = 1;
            continue;
        }
        if(flag == 1){
            printf("Heap Sort\n");
            print(A, total);
            break;
        }
    }
}
void myswap(ElementType *a, ElementType *b){
    ElementType tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
/*----------------------------------------------------------------------
 以下的插入排序正确，无需修改，只需要注意插入排序的第二个循环的判断条件就好了，一开始写错了
 -----------------------------------------------------------------------*/
void Insertion_sort_Compare(ElementType A[], int N, ElementType Result[]){
    int i,j;
    int tmp,flag = 0;
    for(i = 1; i < N; i++){
        tmp = A[i];
        for(j = i; j > 0 && A[j-1] > tmp; j--){  //POINT!!!!
            A[j] = A[j-1];
        }
        A[j] = tmp;
        if(flag == 1){
            print(A, N);
            break;
        }
            //每循环一次的时候就去比较一次
        if(Compare(A, Result, N)){
            printf("Insertion Sort\n");
            flag = 1;
            continue;
        }
    }
}
/*----------------------------------------------------------------------
 Comapre and Print
 -----------------------------------------------------------------------*/
bool Compare(ElementType tmpResult[], ElementType Result[], int length){
    for(int i = 0; i < length; i++){
        if(tmpResult[i] != Result[i])
            return false;
    }
    return true;
}
 
void print(ElementType A[], int N){
    int i;
    for(i = 0; i < N-1; i++)
        printf("%d ", A[i]);
    printf("%d\n",A[N-1]);
}
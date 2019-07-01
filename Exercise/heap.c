#include <stdio.h>

#define MAX_ELEMENT 200 // 힙 안에 저장된 요소의 개수

typedef struct{
  int key;
} element;

typedef struct{
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;

// 힙의 생성
HeapType heap1;
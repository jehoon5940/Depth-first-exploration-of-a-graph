#include <stdio.h>
#include <stdlib.h>
#include "stackL.h"

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data = item;  // 삽입 노드를 top의 위에 연결
    temp->link = top;  // top 위치를 삽입 노드로 이동
    top = temp;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
    element item;
    stackNode* temp = top;
    if (isStackEmpty()) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {
        item = temp->data;  // 삭제할 노드의 데이터를 item에 저장
        top = temp->link;  // top 위치를 삭제 노드 아래로 이동
        free(temp);  // 삭제된 노드의 메모리 반환
        return item;  // 삭제된 원소 반환
    }
}

// 스택의 top 원소를 검색하는 연산
element peek() {
    if (isStackEmpty()) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else return top->data;  // 현재 top의 원소 반환
}

// 스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack() {
    stackNode* p = top;
    printf("\n STACK [ ");
    while (p) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("] ");
}

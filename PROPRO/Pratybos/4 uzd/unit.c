#include <stdio.h>
#include <assert.h>
#include "func.c"

void test_FindMaxValue() {
    Node *start = NULL, *end = NULL;
    ReadList(&start, &end);
    assert(FindMaxValue(start) == 456);
}

void test_DeleteMaxValue() {
    Node *start = NULL, *end = NULL;
    ReadList(&start, &end);
    DeleteMaxValue(&start, 456);
    printf("Tiketinas sarasas po didziausio elemento naikinimo: 45 90 12 12 1 56 32 99 123 78 56 1 2 9.\n");
    printf("Duomenys kurius gavome: ");
    PrintList(start);
    printf("\n");
}

void test_ReadList() {
    Node *start = NULL, *end = NULL;
    ReadList(&start, &end);
    printf("Tiketini duomenys is failo: 45 90 12 456 12 1 56 32 99 123 78 56 1 2 9.\n");
    printf("Duomenys kurius gavome: ");
    PrintList(start);
    printf("\n");
}

void test_Validation() {
    assert(Validation('y') == 1);
    assert(Validation('n') == -1);
    assert(Validation(' ') == 0);
}

int main() {
    test_FindMaxValue();
    test_DeleteMaxValue();
    test_ReadList();
    test_Validation();

    printf("Visi testai sekmingi.\n");
    return 0;
}
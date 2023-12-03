#include <stdio.h>
#include <assert.h>
#include "func.h"

void testFind() {
    Node *start = NULL, *end = NULL;
    ReadList(&start, &end);
    assert(FindMaxValue(start) == 456);
}

void testDelete() {
    Node *start = NULL, *end = NULL;
    ReadList(&start, &end);
    DeleteMaxValue(&start, 456);
    printf("Tiketinas sarasas po didziausio elemento naikinimo: 45 90 12 12 1 56 32 99 123 78 56 1 2 9.\n");
    printf("Duomenys kurius gavome: ");
    PrintList(start);
    printf("\n");
}

void testRead() {
    Node *start = NULL, *end = NULL;
    ReadList(&start, &end);
    printf("Tiketini duomenys is failo: 45 90 12 456 12 1 56 32 99 123 78 56 1 2 9.\n");
    printf("Duomenys kurius gavome: ");
    PrintList(start);
    printf("\n");
}

void testValid() {
    assert(Validation('y') == 1);
    assert(Validation('n') == -1);
    assert(Validation(' ') == 0);
}

int main() {
    testFind();
    testDelete();
    testRead();
    testValid();

    printf("Visi testai sekmingi.\n");
    return 0;
}
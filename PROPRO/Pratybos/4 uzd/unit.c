#include <stdio.h>
#include <assert.h>
#include "func.h"

int testValues[] = {10, 20, 30, 40, 50};
int numTestValues = sizeof(testValues) / sizeof(testValues[0]);

void testFind(){
    Node *start = NULL, *end = NULL;
    InitializeTestValues(&start, &end, testValues, numTestValues);
    assert(FindMaxValue(start) == 50);
}

void testDelete(){
    Node *start = NULL, *end = NULL;
    int newValues[4] = {10, 20, 30, 40};
    int index = sizeof(newValues) / sizeof(newValues[0]);
    InitializeTestValues(&start, &end, testValues, numTestValues);
    DeleteMaxValue(&start, 50);
    assert(CompareListWithArray(start, newValues, index));
}

void testValid(){
    assert(Validation('y') == 1);
    assert(Validation('n') == -1);
    assert(Validation(' ') == 0);
}

int main(){
    testFind();
    testDelete();
    testValid();
    printf("Visi testai sekmingi.\n");
    return 0;
}
#include <iostream>

#include "signalhandle.h"

void test_func();

void test_func2() {
    test_func();
    int i = 0;
    i ++;
}

void test_func(){
    int * ptr = NULL;
    *ptr = 1;
}

int main() {
    SetSignalHandle(); 
    //print_stacktrace();

    
    test_func2();


    return 0;
}

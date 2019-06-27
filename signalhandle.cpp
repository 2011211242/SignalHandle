#include "signalhandle.h"
#include <signal.h>
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

void print_stacktrace()
{
    void * trace[128];
    int n = backtrace(trace, 128);
    char ** stacktrace = backtrace_symbols(trace, n);
    for (int i = 3; i < n - 2; ++i)
    {
        printf("%s\n", stacktrace[i]);
    }
    free(stacktrace);
    exit(0);
}

void SignalHandle(int seg) {
    print_stacktrace();
}

void SetSignalHandle(void) {
    sigset(SIGSEGV, SignalHandle);
}


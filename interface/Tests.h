#ifndef TESTS_H
#define TESTS_H

#include "MainWindow.h"
#include "Animal.h"
#include "Client.h"

class Tests
{
public:
    static void runTests();
    static void testClients();
    static void testACM(CUACSController *mediator);
};
#endif // TESTS_H

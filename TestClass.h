//
//  TestClass.h
//  GarbageCollector
//
//  Created by Alan Hummel on 15/03/14.
//
//

#ifndef GarbageCollector_TestClass_h
#define GarbageCollector_TestClass_h

class TestClass {
private:
    int a;
    int b;
    int c;

public:
    TestClass(int newA, int newB, int newC);
    ~TestClass();
};

TestClass::TestClass(int newA, int newB, int newC)
{
    a = newA;
    b = newB;
    c = newC;
}
TestClass::~TestClass()
{
    a = 0;
    b = 0;
    c = 0;
}

#endif

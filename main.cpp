#include "MemoryManager.h"
#include "TestClass.h"
#include <stdio.h>

int main() {
  
    MemoryManager *mem;
    mem = MemoryManager::getGlobalInstance();
    int *s = mem->allocate<int>();
    int *t = s;
    int *u = mem->allocate<int>();
    
 
    *s= 42;
    *u= 77;
    
    std::cout<< "s:" << *s << std::endl;
    std::cout<< "*s:" << s << std::endl;
    std::cout<< "&s:" << &s << std::endl;

    std::cout<< "t:" << *t << std::endl;
    std::cout<< "*t:" << t << std::endl;
    std::cout<< "&t:" << &t << std::endl;
    
    std::cout<< "u:" << *u << std::endl;
    std::cout<< "*u:" << u << std::endl;
    std::cout<< "&u:" << &u << std::endl;
    
    if (s == t)
    {
        std::cout << "They are the same!" << std::endl;
    }
    
    std::cout << "Memory used: " << mem->calculateMemoryUsedInBytes() << " bytes" << std::endl;
    
    mem->deallocate(s);
    mem->deallocate(t);
    
    std::cout << "Memory used after deallocation: " << mem->calculateMemoryUsedInBytes() << " bytes" << std::endl;
    
    TestClass *tc = mem->allocate<TestClass>();
    // Constructor
    new (tc) TestClass(10,20,30);
    // Destructor
    tc->~TestClass();
    delete mem;
	return 0;
}
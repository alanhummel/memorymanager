//
//  MemoryManager.h
//  GarbageCollector
//
//  Created by Alan Hummel on 19/09/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef GarbageCollector_MemoryManager_h
#define GarbageCollector_MemoryManager_h

#include <iostream>
#include <list>
#include <cstdlib>

class MemoryManager {
private:
    static bool instanceFlag;
    static MemoryManager* globalMemoryManager;
    long double memoryUsedinBytes;
    
    // Método
    long double getSizeOf(void* data);
    
protected:
    /*
    class memoryItem  {
    public:
        bool isInUse;
        long dataInBytes;
        void* data;    // data stored on memory
    };
    
	// defines a shortcut to access a node from the same type as
    // a standard on LinkedList.
    typedef memoryItem item;
    
    
    LinkedList<memoryItem> *memPayLoad;
     */

    std::list<void*> memoryData;
    
public:
    // Methods:
    static MemoryManager* getGlobalInstance();
    MemoryManager * getLocalInstance();
    
    long double getMemoryUsedInBytes();
    
    long double calculateMemoryUsedInBytes();
    
    template<typename Type>
    Type* allocate();
    void deallocate(void* data);
    void deallocateAll();
    
    // ----------------------------------------------------------------
    //  Name:           MemoryManager::MemoryManager
    //  Description:    Constructor, creates the Memory Manager.
    //  Arguments:      None.
    //  Return Value:   None.
    // ----------------------------------------------------------------    
    MemoryManager() {
        //memPayLoad =  new LinkedList<memoryItem>;
        memoryUsedinBytes = 0;
    }
    
    // ----------------------------------------------------------------
    //  Name:           MemoryManager::~MemoryManager
    //  Description:    Destructor, destroys the Memory Manager.
    //  Arguments:      None.
    //  Return Value:   None.
    // ----------------------------------------------------------------      
    ~MemoryManager() {
        // TODO clean the memory for remaining objects
        
        instanceFlag = false;
        // Destroy the structure.
        deallocateAll();
    }
    
};


bool MemoryManager::instanceFlag = false;
MemoryManager* MemoryManager::globalMemoryManager = NULL;


// ----------------------------------------------------------------
//  Name:           MemoryManager::getGlobalInstance
//  Description:    Singleton instance generator of MemoryManager.
//  Arguments:      None.
//  Return Value:   Instance of MemoryManager.
// ----------------------------------------------------------------
MemoryManager* MemoryManager::getGlobalInstance()
{
       if(! instanceFlag)
       {
           globalMemoryManager = new MemoryManager();
           instanceFlag = true;
           return globalMemoryManager;
       }
       else
       {
           return globalMemoryManager;
       }
}


// ----------------------------------------------------------------
//  Name:           MemoryManager::getLocalInstance
//  Description:    Multiple instance generator of MemoryManager.
//                  For local context.
//  Arguments:      None.
//  Return Value:   Instance of MemoryManager.
// ----------------------------------------------------------------
MemoryManager* MemoryManager::getLocalInstance()
{
    return new MemoryManager();
}


template<typename Type>
    
Type* MemoryManager::allocate() {
    Type* data = (Type*) malloc(sizeof(Type));
    memoryUsedinBytes += sizeof(Type);
    memoryData.push_back(data);
    std::cout << "Memory Allocated: " << data << std::endl;
    return data;
}
    
void MemoryManager::deallocate(void* data) {
    // Find the data
    void* currentData = NULL;
    bool dataFound = false;
    for (std::list<void*>::iterator it_type = memoryData.begin(); it_type != memoryData.end(); ++it_type)
    {
        currentData = *it_type;
        if (currentData == data)
        {
            std::cout << "Data found and erased: " << data << std::endl;
            free (data);
            memoryData.erase(it_type);
            dataFound = true;
            break;
        }
    }
    if (!dataFound)
    {
        std::cout << "Data *NOT* found: " << data << std::endl;
        //typedef std::list<void*>::iterator it_type;
        std::cout << "\tIterating all existing values"<< std::endl;

        for (std::list<void*>::iterator it_type = memoryData.begin(); it_type != memoryData.end(); ++it_type)
        {
            std::cout << "\tKey: " << *it_type << std::endl;
        }
    }
    
}

void MemoryManager::deallocateAll() {
    // Deallocate everything
    //typedef std::list<void*>::iterator it_type;
    std::cout << "Purging all existing values left"<< std::endl;
    void *data;
    
    for(std::list<void*>::iterator it_type = memoryData.begin(); it_type != memoryData.end(); ++it_type)
    {
        std::cout << "\tKey: " << *it_type << std::endl;
        data = *it_type;
        free(data);
    }
    memoryData.clear();
}

long double MemoryManager::calculateMemoryUsedInBytes()
{
    long double size = 0;
    typedef std::list<void*>::iterator it_type;
    
    for(it_type it_type = memoryData.begin(); it_type != memoryData.end(); it_type++)
    {
        size += getSizeOf(it_type.operator*());
    }
    memoryUsedinBytes = size;
    return size;
}

long double MemoryManager::getMemoryUsedInBytes()
{
    return memoryUsedinBytes;
}

long double MemoryManager::getSizeOf(void* data)
{
    
    long double theSizeOf=sizeof(data);
    
    return theSizeOf;
}

#endif

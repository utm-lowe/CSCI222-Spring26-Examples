/**
 * @file memviz.h
 * @author Bob Lowe <rlowe8@utm.edu>
 * @brief This is a small class for doing visualization of memory.
 * @version 0.1
 * @date 2026-01-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "memviz.h"

// static helper prototypes
static void displayLoc(unsigned char *ptr, int addrWidth, const std::string &label);
static void displayEllipses(int addrWidth);
static void displaySep(int addrWidth);


// Construct a new Mem Viz object
MemViz::MemViz()
{
    // This space left intentionally blank.
}

// Destroy the Mem Viz object.
MemViz::~MemViz()
{

}

// Add a thing to the visualization
void MemViz::add(const std::string &name, void *ptr, std::size_t size)
{
    things.push_back(Thing(name, (unsigned char *)ptr, size));
    std::sort(things.begin(), things.end());
}


void MemViz::visualize()
{
    Thing last("", nullptr, 0);
    int addrWidth = sizeof(void*)*2 + 2; 
    unsigned char *cur = (unsigned char*) last.ptr;

    // print all the things!
    for(auto itr=things.begin(); itr!=things.end(); itr++) {
        if(itr->ptr - cur > 10) {
            displayEllipses(addrWidth);
            displaySep(addrWidth);
            cur = itr->ptr;
        } else if(itr->ptr - cur >=1) {
            while(cur < itr->ptr) {
                displayLoc(cur++, addrWidth, "");
            }
            displaySep(addrWidth);
        }

        // start the thing
        displayLoc(cur++, addrWidth, itr->name);

        // display the remaining bytes
        while(cur < itr->ptr + itr->size) {
            displayLoc(cur++, addrWidth, "");
        }
        displaySep(addrWidth);
    }
}


static void displayLoc(unsigned char *ptr, int addrWidth, const std::string &label) 
{
    std::cout << std::hex << std::setfill('0')
              << "0x" << std::setw(addrWidth-2) << (void*)ptr
              << "| 0x"
              << std::setw(2) << (int) *ptr
              << " | " << label << std::endl
              << std::setfill(' ');
}

static void displaySep(int addrWidth) 
{
    std::cout << std::setw(addrWidth) << ' '
              << '+' 
              << std::setfill('-') << std::setw(6) << ""
              << '+'
              << std::setfill(' ')
              << std::endl;
}


static void displayEllipses(int addrWidth)
{
    std::cout << std::setw(addrWidth) << ' '
              << ' ' 
              << std::setfill('.') << std::setw(6) << ""
              << ' '
              << std::setfill(' ')
              << std::endl;
}
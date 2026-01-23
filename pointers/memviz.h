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
#ifndef MEMVIZ_H
#define MEMVIZ_H
#include <vector>
#include <string>
#include <cstddef>

class MemViz 
{
public:
    /**
     * @brief Construct a new Mem Viz object
     * 
     */
    MemViz();

    /**
     * @brief Destroy the Mem Viz object.
     * 
     */
    virtual ~MemViz();

    /**
     * @brief Add a thing to the visualization
     * 
     * @param name 
     * @param ptr 
     * @param size 
     */
    void add(const std::string &name, void *ptr, std::size_t size);

    
    /**
     * @brief Visualize the memory.
     * 
     */
    void visualize();

private:
    struct Thing
    {
        std::string name;
        std::size_t size; 
        unsigned char *ptr;

        Thing(const std::string &name, unsigned char *ptr, std::size_t size) :
            name(name), size(size), ptr(ptr) {}

        bool operator<(const Thing &rhs) {
            return ptr < rhs.ptr;
        }
    };

    std::vector<Thing> things;
};

#endif
#ifndef LINEARCOUNTING_H_INCLUDED
#define LINEARCOUNTING_H_INCLUDED

#include <bitset>
#include "BOBHash32.h"
#include <time.h>
#include <cstdlib>
template <int mem_in_bytes, uint8_t key_len>
class LinearCounting
{
private:
    bitset<mem_in_bytes> bitmap;
    BOBHash32* BOB;
public:
    LinearCounting()
    {
        BOB = new BOBHash32(rand() % MAX_PRIME32);
    }

    ~LinearCounting()
    {
        delete BOB;
    }

    void insert(uint8_t * key)
    {
        int pos = BOB->run((const char*)key, key_len) % mem_in_bytes;
        bitmap.set(pos, true);
    }

    int get_cardinality()
    {
        double m = 1.0* bitmap.count();
        return mem_in_bytes * log(mem_in_bytes / (mem_in_bytes - m));
    }
};

#endif // LINEARCOUNTING_H_INCLUDED

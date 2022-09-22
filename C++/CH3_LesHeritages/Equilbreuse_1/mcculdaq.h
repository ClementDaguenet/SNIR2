#ifndef MCCULDAQ_H
#define MCCULDAQ_H

#include "libs.h"

class MccUldaq
{
public:
    MccUldaq();
    void ulAOut(const int _numCanal, const int _tension);
};

#endif // MCCULDAQ_H

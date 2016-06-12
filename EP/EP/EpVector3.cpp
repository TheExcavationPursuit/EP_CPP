//
//  EpVector3.cpp
//  EpMath
//
//  Created by Joshua Pacana on 6/3/16.
//  Copyright © 2016 Pacana. All rights reserved.
//

#include "EpVector3.hpp"
#include <iostream>
#include <cmath>

EpVector3::EpVector3()
{
    mElements[0] = 0.0;
    mElements[1] = 0.0;
    mElements[2] = 0.0;
}

EpVector3::EpVector3(float x, float y, float z)
{
    mElements[0] = x;
    mElements[1] = y;
    mElements[2] = z;
}



void
EpVector3::print()
{
    std::cout << mElements[0] << " " << mElements[1] << " " << mElements[2] << std::endl;
}


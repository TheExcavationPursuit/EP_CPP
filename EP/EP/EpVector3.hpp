//
//  EpVector3.hpp
//  EpMath
//
//  Created by Joshua Pacana on 6/3/16.
//  Copyright © 2016 Pacana. All rights reserved.
//

#ifndef EpVector3_hpp
#define EpVector3_hpp

#include <stdio.h>
#include <array>
#include <cmath>
#include "EpMathConstants.hpp"

class EpVector3 {
public:
    EpVector3();
    EpVector3(float x, float y, float z);
    
    inline float& operator[](int i);
    inline void operator=(const EpVector3 &equalVector);
    inline bool operator==(const EpVector3 &equalVector) const;
    inline void operator*=(const float factor);
    inline EpVector3 operator+(const EpVector3 &addVector) const;
    inline EpVector3 operator-(const EpVector3 &subVector) const;
    inline EpVector3 operator*(const float &factor) const;
    inline EpVector3 operator/(const float &factor) const;
    
    static inline EpVector3 cross(const EpVector3 &aVector, const EpVector3 &bVector);
    inline EpVector3 cross(const EpVector3 &crossVector) const;
    static inline float dot(const EpVector3 &aVector, const EpVector3 &bVector);
    inline float dot(const EpVector3 &dotVector) const;
    
    inline float magnitude() const;
    inline void normalize();
    inline void negate();
    inline bool isZero() const;
    
    static inline float angleBetweenVectors(const EpVector3 &a, const EpVector3 &b);
    static inline bool areOrthogonal(const EpVector3 &a, const EpVector3 &b);
    static inline bool areParallel(const EpVector3 &a, const EpVector3 &b);
    
    void print();
    
private:
    float			mElements[3];
};

float&
EpVector3::operator[](int i)
{
    return mElements[i];
}

void
EpVector3::operator=(const EpVector3 &equalVector)
{
    mElements[0] = equalVector.mElements[0];
    mElements[1] = equalVector.mElements[1];
    mElements[2] = equalVector.mElements[2];
}

bool
EpVector3::operator==(const EpVector3 &equalVector) const
{
    if ((mElements[0] == equalVector.mElements[0]) &&
        (mElements[1] == equalVector.mElements[1]) &&
        (mElements[2] == equalVector.mElements[2]))
    {
        return true;
    }
    return false;
}

void
EpVector3::operator*=(const float factor)
{
    mElements[0] *= factor;
    mElements[1] *= factor;
    mElements[2] *= factor;
}

EpVector3
EpVector3::operator+(const EpVector3 &addVector) const
{
    EpVector3 retVector;
    retVector[0] = (mElements[0] + addVector.mElements[0]);
    retVector[1] = (mElements[1] + addVector.mElements[1]);
    retVector[2] = (mElements[2] + addVector.mElements[2]);
    return retVector;
}

EpVector3
EpVector3::operator-(const EpVector3 &addVector) const
{
    EpVector3 retVector;
    retVector[0] = (mElements[0] - addVector.mElements[0]);
    retVector[1] = (mElements[1] - addVector.mElements[1]);
    retVector[2] = (mElements[2] - addVector.mElements[2]);
    return retVector;
}

EpVector3
EpVector3::operator*(const float &factor) const
{
    EpVector3 retVector;
    retVector[0] = (mElements[0] * factor);
    retVector[1] = (mElements[1] * factor);
    retVector[2] = (mElements[2] * factor);
    return retVector;
}

EpVector3
EpVector3::operator/(const float &factor) const
{
    EpVector3 retVector;
    retVector[0] = (mElements[0] / factor);
    retVector[1] = (mElements[1] / factor);
    retVector[2] = (mElements[2] / factor);
    return retVector;
}

EpVector3
EpVector3::cross(const EpVector3 &aVector, const EpVector3 &bVector)
{
    EpVector3 returnVector;
    returnVector[0] = aVector.mElements[1]*bVector.mElements[2] - aVector.mElements[2]*bVector.mElements[1];
    returnVector[1] = aVector.mElements[2]*bVector.mElements[0] - aVector.mElements[0]*bVector.mElements[2];
    returnVector[2] = aVector.mElements[0]*bVector.mElements[1] - aVector.mElements[1]*bVector.mElements[0];
    return returnVector;
}


EpVector3
EpVector3::cross(const EpVector3 &crossVector) const
{
    EpVector3 returnVector;
    returnVector[0] = mElements[1]*crossVector.mElements[2] - mElements[2]*crossVector.mElements[1];
    returnVector[1] = mElements[2]*crossVector.mElements[0] - mElements[0]*crossVector.mElements[2];
    returnVector[2] = mElements[0]*crossVector.mElements[1] - mElements[1]*crossVector.mElements[0];
    return returnVector;
}

float
EpVector3::dot(const EpVector3 &aVector, const EpVector3 &bVector)
{
    float product = aVector.mElements[0] * bVector.mElements[0] +
                    aVector.mElements[1] * bVector.mElements[1] +
                    aVector.mElements[2] * bVector.mElements[2];
    return product;
}

float
EpVector3::dot(const EpVector3 &dotVector) const
{
    float product = mElements[0] * dotVector.mElements[0] +
                    mElements[1] * dotVector.mElements[1] +
                    mElements[2] * dotVector.mElements[2];
    return product;
}

float
EpVector3::magnitude() const
{
    float magnitude = sqrtf(mElements[0]*mElements[0] +
                            mElements[1]*mElements[1] +
                            mElements[2]*mElements[2]);
    return magnitude;
}

void
EpVector3::normalize()
{
    float magnitude = this->magnitude();
    mElements[0] /= magnitude;
    mElements[1] /= magnitude;
    mElements[2] /= magnitude;
}

void
EpVector3::negate()
{
    mElements[0] *= -1.0;
    mElements[1] *= -1.0;
    mElements[2] *= -1.0;
}

float
EpVector3::angleBetweenVectors(const EpVector3 &a, const EpVector3 &b)
{
    float cosAngle = dot(a, b) / (a.magnitude() * b.magnitude());
    float radians = acosf(cosAngle);
    return (radians * Ep_TO_DEGREES);
}
bool
EpVector3::areOrthogonal(const EpVector3 &a, const EpVector3 &b)
{
    if (a.dot(b) == 0.0)
        return true;
    
    return false;
}

bool
EpVector3::areParallel(const EpVector3 &a, const EpVector3 &b)
{
    EpVector3 crossProduct;
    crossProduct = a.cross(b);
    if (crossProduct.isZero())
        return true;
    
    return false;
}

bool
EpVector3::isZero() const
{
    if (this->magnitude() == 0.0)
        return true;
    return false;
}

#endif /* EpVector3_hpp */

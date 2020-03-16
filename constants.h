//
// Created by mikhail on 8/13/18.
//
#ifndef LBM_CPP_CONSTANTS_H
#define LBM_CPP_CONSTANTS_H

#include <iostream>
#include <vector>
#include <array>

template <typename T>
struct Vector{ // TODO: is this needed for velocity?
    T x;
    T y;
    Vector() {
        x = 0;
        y = 0;
    }
    Vector(T a, T b) {
        x = a;
        y = b;
    }
    T operator*(const Vector<T>&rhs) const{

        return this->x*rhs.x + this->y*rhs.y;
    }
    Vector operator+=(const Vector<T>& rhs){
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }
    friend Vector operator+(Vector<T> lhs, const Vector<T>& rhs ){
        lhs += rhs;
        return lhs;
    }
    Vector operator-=(const Vector<T>& rhs){
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }
    friend Vector operator-(Vector<T> lhs, const Vector<T>& rhs ){
        lhs -= rhs;
        return lhs;
    }
    friend Vector operator*(T scalar, const Vector<T>& rhs) {
        return Vector(scalar*rhs.x, scalar*rhs.y);
    }
};


constexpr std::size_t Q = 9;
double Pr = 2./3;
double Kn = 0.08;
size_t iterations = 1000;
std::array<Vector<double>, Q> e;
std::array<double, Q> w = {4./9, 1./9, 1./9, 1./9, 1./9, 1./36,1./36, 1./36,1./36};
size_t x_size, y_size;


#endif //LBM_CPP_CONSTANTS_H
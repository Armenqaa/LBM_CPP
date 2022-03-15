//
// Created by Evgenii Zheltonozhskii on 13/02/2021.
//

#ifndef LBM_CPP_VECTOR_2D_H
#define LBM_CPP_VECTOR_2D_H

template<typename T>
struct Vector2D {
    T x;
    T y;

    explicit Vector2D(T x = 0, T y = 0) : x(x), y(y) {}

    template<typename S>
    auto operator*(const Vector2D<S> &rhs) const {
        return this->x * rhs.x + this->y * rhs.y;
    }

    Vector2D operator+=(const Vector2D<T> &rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    template<typename S>
    friend auto operator+(Vector2D<T> &lhs, const Vector2D<S> &rhs) {
        return Vector2D<decltype(lhs.x + rhs.x)>(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    Vector2D operator-=(const Vector2D<T> &rhs) {
        this->x -= rhs.x;
        this->y -= rhs.y;
        return *this;
    }

    template<typename S>
    friend auto operator-(Vector2D<T> lhs, const Vector2D<S> &rhs) {
        return Vector2D<decltype(lhs.x - rhs.x)>(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    friend Vector2D operator*(T scalar, const Vector2D<T> &rhs) {
        return Vector2D(scalar * rhs.x, scalar * rhs.y);
    }
};

#endif // LBM_CPP_VECTOR_2D_H

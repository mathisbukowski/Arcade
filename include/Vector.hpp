/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/**
 * @class Vector
 * Template class representing a generic 2D vector.
 * @tparam T Type of the vector coordinates.
 */
template <typename T>
class Vector {
public:
    /**
     * Constructor with initial values.
     * @param x X coordinate.
     * @param y Y coordinate.
     */
    Vector(T x, T y) : _x(x), _y(y) {}

    /**
     * Default constructor (zero vector).
     */
    Vector() : _x(0), _y(0) {}

    ~Vector() = default;

        /**
         * Get the X values
         * @return X values
         */
        T getX() const { return _x; }
        /**
         * Get the Y values
         * @return Y values
         */
        T getY() const { return _y; }

        /**
         * Set the X value
         * @param x X value
         */
        void setX(T x) { _x = x; }
        /**
         * Set the Y value
         * @param y Y value
         */
        void setY(T y) { _y = y; }

        /**
         * Operator overloads
         * @param other Other vector
         * @return Vector object
         */
        Vector<T> operator+(const Vector<T>& other) const { return Vector(_x + other.getX(), _y + other.getY()); }
        Vector<T> operator-(const Vector<T>& other) const { return Vector(_x - other.getX(), _y - other.getY()); }
        Vector<T> operator*(const Vector<T>& other) const { return Vector(_x * other.getX(), _y * other.getY()); }
        Vector<T> operator/(const Vector<T>& other) const { return Vector(_x / other.getX(), _y / other.getY()); }
        bool operator==(const Vector<T>& other) const { return _x == other.getX() && _y == other.getY(); }
        bool operator!=(const Vector<T>& other) const { return _x != other.getX() || _y != other.getY(); }
        bool operator<(const Vector<T>& other) const { return _x < other.getX() && _y < other.getY(); }
        bool operator>(const Vector<T>& other) const { return _x > other.getX() && _y > other.getY(); }
        bool operator<=(const Vector<T>& other) const { return _x <= other.getX() && _y <= other.getY(); }
        bool operator>=(const Vector<T>& other) const { return _x >= other.getX() && _y >= other.getY(); }
        Vector<T> operator+=(const Vector<T>& other) { _x += other.getX(); _y += other.getY(); return *this; }
        Vector<T> operator-=(const Vector<T>& other) { _x -= other.getX(); _y -= other.getY(); return *this; }

private:
    T _x; /**< X coordinate. */
    T _y; /**< Y coordinate. */
};

#endif /* !VECTOR_HPP_ */

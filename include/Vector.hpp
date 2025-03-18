/*
** EPITECH PROJECT, 2025
** Arcade
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

/**
 * @brief Class to represent a 2D vector
 */

template <typename T>
class Vector {
    public:

        /**
         * @brief Construct a new Vector object
         * @param x X value
         * @param y Y value
         * @return Vector object
         */
        Vector(T x, T y) : _x(x), _y(y) {};
        Vector() : _x(0), _y(0) {};
        ~Vector() = default;

        /**
         * @brief Get the X and Y values
         * @return X and Y values
         */
        T getX() const { return _x; };
        T getY() const { return _y; };

        /**
         * @brief Set the X and Y values
         * @param x X value
         * @param y Y value
         */
        void setX(T x) { _x = x; };
        void setY(T y) { _y = y; };

        /**
         * @brief Operator overloads
         * @param other Other vector
         * @return Vector object
         */
        T operator+(const Vector<T>& other) const { return Vector(_x + other.getX(), _y + other.getY()); };
        T operator-(const Vector<T>& other) const { return Vector(_x - other.getX(), _y - other.getY()); };
        T operator*(const Vector<T>& other) const { return Vector(_x * other.getX(), _y * other.getY()); };
        T operator/(const Vector<T>& other) const { return Vector(_x / other.getX(), _y / other.getY()); };
        bool operator==(const Vector<T>& other) const { return _x == other.getX() && _y == other.getY(); };
        bool operator!=(const Vector<T>& other) const { return _x != other.getX() || _y != other.getY(); };
        bool operator<(const Vector<T>& other) const { return _x < other.getX() && _y < other.getY(); };
        bool operator>(const Vector<T>& other) const { return _x > other.getX() && _y > other.getY(); };
        bool operator<=(const Vector<T>& other) const { return _x <= other.getX() && _y <= other.getY(); };
        bool operator>=(const Vector<T>& other) const { return _x >= other.getX() && _y >= other.getY(); };
        T operator+=(const Vector<T>& other) { _x += other.getX(); _y += other.getY(); return *this; };
        T operator-=(const Vector<T>& other) { _x -= other.getX(); _y -= other.getY(); return *this; };

    private:
        T _x;
        T _y;
};

#endif /* !VECTOR_HPP_ */

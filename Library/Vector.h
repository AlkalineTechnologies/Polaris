//
// Created by Lysander Mealy on 10/23/21.
//

#ifndef POLARIS_VECTOR_H
#define POLARIS_VECTOR_H

#include <Exception.h>
#include <Utility.h>

namespace Polaris {
    class VectorOutOfRangeException: Exception {
        using Exception::Exception;

    private:
        const std::string _exceptionType = "Vector out of range";
    };

    template <typename T, size_t dimensions>
    class Vector_t {
        Vector_t(T arr[dimensions]) {
            _arr = arr;
        }

        template<typename ...TVariadic>
        explicit Vector_t(TVariadic... params) {
            _arr = Utility::variadicToArray<dimensions>(params...);
        }

        Vector_t *operator=(T arr[dimensions]) {
            _arr = arr;
        }

        template<typename ...TVariadic>
        Vector_t *operator=(TVariadic... params) {
            _arr = Utility::variadicToArray<dimensions>(params...);
        }

        Vector_t *operator+=(Vector_t<T, dimensions> other) {
            for (int i = 0; i < dimensions; i++) {
                _arr[i] += other[i];
            }
            return this;
        }

        Vector_t operator+(Vector_t<T, dimensions> other) {
            Vector_t copy = *this;
            for (int i = 0; i < dimensions; i++) {
                copy[i] += other[i];
            }
            return copy;
        }

        Vector_t *operator-=(Vector_t<T, dimensions> other) {
            for (int i = 0; i < dimensions; i++) {
                _arr[i] -= other[i];
            }
            return this;
        }

        Vector_t operator-(Vector_t<T, dimensions> other) {
            Vector_t copy = *this;
            for (int i = 0; i < dimensions; i++) {
                copy[i] -= other[i];
            }
            return copy;
        }

        Vector_t *operator*=(Vector_t<T, dimensions> other) {
            for (int i = 0; i < dimensions; i++) {
                _arr[i] *= other[i];
            }
            return this;
        }

        Vector_t operator*(Vector_t<T, dimensions> other) {
            Vector_t copy = *this;
            for (int i = 0; i < dimensions; i++) {
                copy[i] *= other[i];
            }
            return copy;
        }

        Vector_t *operator/=(Vector_t<T, dimensions> other) {
            for (int i = 0; i < dimensions; i++) {
                _arr[i] /= other[i];
            }
            return this;
        }

        Vector_t operator/(Vector_t<T, dimensions> other) {
            Vector_t copy = *this;
            for (int i = 0; i < dimensions; i++) {
                copy[i] /= other[i];
            }
            return copy;
        }

        T operator[](int index) {
            if (index >= dimensions) {
                std::string msg = "Vector index " + std::to_string(index) + " is greater than or equal to size " +
                                  std::to_string(dimensions);
                throw VectorOutOfRangeException(msg);
            }
            return _arr[index];
        }

    private:
        T _arr[dimensions];
    };

    template <size_t dimensions>
    using Vector = Vector_t<double, dimensions>;

    template <size_t dimensions>
    using VectorInt = Vector_t<int, dimensions>;

    typedef Vector<4> Vector4;
    typedef Vector<3> Vector3;
    typedef Vector<2> Vector2;

    typedef VectorInt<4> Vector4Int;
    typedef VectorInt<3> Vector3Int;
    typedef VectorInt<2> Vector2Int;
}


#endif //POLARIS_VECTOR_H

// Shourov Saha
// H file for Points3D class which can create or display points of any type.

#ifndef CSCI335_HOMEWORK1_POINTS3D_H_
#define CSCI335_HOMEWORK1_POINTS3D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
using namespace std;

namespace teaching_project {

// Points3D Class. Functions include the default "big five": Zero-parameter constructor, Copy-assignment, Move-constructor, Move-assignment, Destructor, and
// Operators =,+,[],<<,>>. Cordinates of points can be accessed in members as if the Point3D was a 2D array.
template<typename Object>
class Points3D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points3D() {
        size_ = 0;
        sequence_ = nullptr;
    }
        

    // Copy-constructor.
    Points3D(const Points3D &rhs) {
        size_ = rhs.size_;
        sequence_ = new array<Object, 3>[size_];
        for (size_t i = 0; i < size_; i++) {
            for (size_t j = 0; j < 3; j++) {
                sequence_[i][j] = rhs.sequence_[i][j];
            }
        }
    }

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points3D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points3D& operator=(const Points3D &rhs) {
        Points3D copy = rhs;
        swap(*this, copy);
        return *this;
    }

    // Move-constructor.
    Points3D(Points3D &&rhs) {
        size_ = 0;
        sequence_ = nullptr;
        swap(size_, rhs.size_);
        swap(sequence_,rhs.sequence_);
    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points3D& operator=(Points3D &&rhs) {
        swap(size_, rhs.size_);
        swap(sequence_,rhs.sequence_);
        return *this;
    }

    ~Points3D() {
        size_ = 0;
        delete sequence_;
    }

    // End of big-five.

    // One parameter constructor.
    Points3D(const array<Object, 3>& item) {
        size_ = item.size()/3;
        sequence_ = new array<Object, 3>[size_];
        for (size_t i = 0; i < size_; i++) {
            for (size_t j = 0; j < 3; j++) {
                sequence_[i][j] = item[j];
            }
        }
    }

    size_t size() const {
        return size_;
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const array<Object, 3>& operator[](size_t location) const {
        if (location < 0 or location >= sequence_->size()) {
            cout << "error with []";
            abort();
        }
        else {
            return sequence_[location];
        }
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points3D operator+(const Points3D &c1, const Points3D &c2) {
        if (c1.size() >= c2.size()) {
            Points3D<Object> copy1{c1};
            for (size_t j = 0; j < c2.size(); j++) {
                for (size_t i = 0; i < 3; i++) {
                    copy1.sequence_[j][i] += c2.sequence_[j][i];
                }
            }
            return copy1;
        }
        else {
            Points3D<Object> copy2{c2};
            for (size_t j = 0; j < c1.size(); j++) {
                for (size_t i = 0; i < 3; i++) {
                    copy2.sequence_[j][i] += c1.sequence_[j][i];
                }
            }
            return copy2;
        }
    }

    // Overloading the << operator.
    friend ostream &operator<<(ostream &out, const Points3D &some_points) {
        int size = some_points.size_;
        if (size == 0) { // If empty...
            out << "()";
        }
        for (int i = 0; i < size; i++) {
            out << "(";
            for (int j = 0; j < 3; j++) {
                out << some_points.sequence_[i][j];
                if (j != 2) {
                    out << ", ";
                }
            }
            out << ") ";
        }
        out << endl;
        return out;
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend istream &operator>>(istream &in, Points3D &some_points) {
        Object x, y, z;
        size_t size;
        int i = 0, j = 0;
        in >> size;
        some_points.size_ = size;
        some_points.sequence_ = new array<Object, 3>[size];
        for (size_t k = 0; k < size; k++) {
            in >> x;
            some_points.sequence_[i][j] = x;
            j++;
            in >> y;
            some_points.sequence_[i][j] = y;
            j++;
            in >> z;
            some_points.sequence_[i][j] = z;
            i++;
            j = 0;
        }
        cout << endl;
        return in;
    }

  private:
    // Sequence of points.
    std::array<Object, 3> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS3D_H_


#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <concepts>
#include <numeric> 

template<typename I> requires std::integral<I>
class rational {
private:
    I num_;
    I den_;

    void simplify() {
        if (den_ == 0) {
            if (num_ != 0) {
                num_ = (num_ > 0) ? 1 : -1; 
            }
            return; 
        }
        
        if (num_ == 0) {
            den_ = 1;
            return;
        }

        I g = std::gcd(num_, den_);
        num_ /= g;
        den_ /= g;

        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    rational() : num_(0), den_(1) {}

    rational(const I& n, const I& d) : num_(n), den_(d) {
        simplify(); 
    }

    /* Getters */
    I num() const { return num_; }
    I den() const { return den_; }

    rational& operator+=(const rational& other) {
        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    rational& operator-=(const rational& other) {
        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }

    rational& operator/=(const rational& other) {
        num_ *= other.den_;
        den_ *= other.num_;
        simplify();
        return *this;
    }
};

template<typename I>
rational<I> operator+(const rational<I>& a, const rational<I>& b) {
    rational<I> ret = a;
    ret += b;
    return ret;
}

template<typename I>
rational<I> operator-(const rational<I>& a, const rational<I>& b) {
    rational<I> ret = a;
    ret -= b;
    return ret;
}

template<typename I>
rational<I> operator*(const rational<I>& a, const rational<I>& b) {
    rational<I> ret = a;
    ret *= b;
    return ret;
}

template<typename I>
rational<I> operator/(const rational<I>& a, const rational<I>& b) {
    rational<I> ret = a;
    ret /= b;
    return ret;
}

template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() == 0) os << "NaN";
        else if (r.num() > 0) os << "+Inf";
        else os << "-Inf";
    } else {
        os << r.num() << "/" << r.den();
    }
    return os;
}

#endif 
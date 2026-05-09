#include "Calculator.h"
#include <stdexcept>

Calculator::Calculator() : lastResult_(0.0) {}

double Calculator::add(double a, double b) {
    lastResult_ = a + b;
    return lastResult_;
}

double Calculator::subtract(double a, double b) {
    lastResult_ = a - b;
    return lastResult_;
}

double Calculator::multiply(double a, double b) {
    lastResult_ = a * b;
    return lastResult_;
}

double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("division by zero");
    }
    lastResult_ = a / b;
    return lastResult_;
}

double Calculator::getLastResult() const {
    return lastResult_;
}
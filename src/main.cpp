#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;

    std::cout << "10 + 3 = " << calc.add(10, 3) << std::endl;
    std::cout << "10 - 3 = " << calc.subtract(10, 3) << std::endl;
    std::cout << "10 * 3 = " << calc.multiply(10, 3) << std::endl;
    std::cout << "10 / 3 = " << calc.divide(10, 3) << std::endl;
    std::cout << "last result: " << calc.getLastResult() << std::endl;

    // 测试除零异常
    try {
        calc.divide(5, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "catch exception: " << e.what() << std::endl;
    }

    return 0;
}
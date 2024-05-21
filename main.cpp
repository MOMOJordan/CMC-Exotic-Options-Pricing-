#include <iostream>
#include "UpAndOutOption.h"

void assertApproxEqual(double a, double b, double tolerance = 1e-6) {
    if (std::fabs(a - b) > tolerance) {
        std::cerr << "Assertion failed: " << a << " is not approximately equal to " << b << " within tolerance " << tolerance << std::endl;
        throw std::runtime_error("Assertion failed");
    }
}

int main() {
    UpAndOutOption o;
    o.setBarrier(100);
    o.setStrike(70);
    DoubleVector prices;
    prices.push_back(120);
    prices.push_back(80);
    assertApproxEqual( o.payoff( prices ), 0.0, 0.001);
    prices[0] = 90;
    assertApproxEqual( o.payoff( prices ), 10.0, 0.001);
    prices[1] = 60;
    assertApproxEqual( o.payoff( prices ), 0.0, 0.001);
}

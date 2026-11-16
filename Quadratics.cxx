#include <iostream>
#include <cmath>
#include <complex>
#include <utility>
struct Coefficients {
    double a;
    double b;
    double c;
};
struct Roots {
    std::complex<double> root1;
    std::complex<double> root2;
    bool isReal;
};

Coefficients getCoefficients() {
    Coefficients coeffs;
    std::cout << "Enter coefficients a, b, and c for (ax^2 + bx + c = 0):\n";
    
    while (true) {
        std::cout << "a (cannot be 0): ";
        std::cin >> coeffs.a;
        if (coeffs.a != 0) {
            break;
        }
        std::cout << "Invalid input. 'a' must not be zero for a quadratic equation.\n";
    }
    
    std::cout << "b: ";
    std::cin >> coeffs.b;
    std::cout << "c: ";
    std::cin >> coeffs.c;
    
    return coeffs;
}


double calculateDiscriminant(const Coefficients& coeffs) {
    return (coeffs.b * coeffs.b) - (4 * coeffs.a * coeffs.c);
}

Roots calculateRoots(const Coefficients& coeffs, double discriminant) {
    Roots roots;
    
    if (discriminant >= 0) {
        roots.isReal = true;
        roots.root1 = (-coeffs.b + std::sqrt(discriminant)) / (2 * coeffs.a);
        roots.root2 = (-coeffs.b - std::sqrt(discriminant)) / (2 * coeffs.a);
    } else {
        roots.isReal = false;
        
        std::complex<double> compSqrt = std::sqrt(std::complex<double>(discriminant, 0));
        roots.root1 = (-coeffs.b + compSqrt) / (2 * coeffs.a);
        roots.root2 = (-coeffs.b - compSqrt) / (2 * coeffs.a);
    }
    
    return roots;
}

void displayResults(const Roots& roots) {
    std::cout << "\n--- Results ---\n";
    if (roots.isReal) {
        if (roots.root1.real() == roots.root2.real()) {
            std::cout << "The equation has one repeated real root:\n";
            std::cout << "x = " << roots.root1.real() << "\n";
        } else {
            std::cout << "The equation has two distinct real roots:\n";
            std::cout << "x1 = " << roots.root1.real() << "\n";
            std::cout << "x2 = " << roots.root2.real() << "\n";
        }
    } else {
        std::cout << "The equation has two complex conjugate roots:\n";
        std::cout << "x1 = " << roots.root1.real() << " + " << roots.root1.imag() << "i\n";
        std::cout << "x2 = " << roots.root2.real() << " " << roots.root2.imag() << "i\n";
    }
}


int main() {
    std::cout << "       Quadratic Equation Solver       \n\n";
    Coefficients coeffs = getCoefficients();
    
    
    double discriminant = calculateDiscriminant(coeffs);   
    Roots roots = calculateRoots(coeffs, discriminant);
    displayResults(roots);
    
    return 0;
}

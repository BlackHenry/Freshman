#include "stdafx.h"
#include "NumericAlgebra.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>

typedef long double ld;

ld function(ld a) {
	return 1.0 / a;
}

int main()
{
	ld a, b;
	int precision;
	std::cout << "Choose precision and boundaries: " << std::endl;
	std::cin >> precision >> a >> b;
	NumericAlgebra::Integrator i(&function, precision, true);
	std::cout << std::fixed << std::setprecision(precision) << i.integrate(a, b) << std::endl;
	std::cout << "Total number of iterations: " << i.number_of_iterations << std::endl;
	std::cout << "Number of partitions: " << i.number_of_partitions << std::endl;
	std::cout << "Depth level: " << i.level << std::endl;
	std::cout << "Time elapsed: " << (int)(i.time) << " ms" << std::endl;
	system("pause");
    return 0;
}


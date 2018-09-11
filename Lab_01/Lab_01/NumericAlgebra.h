#pragma once

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

typedef long double ld;

namespace NumericAlgebra {
	class Integrator {
	public:

		long long int number_of_iterations = 0, number_of_partitions, precision, level = 0;
		double k = 2;
		time_t time;
		ld(*function)(ld);
		bool debug;

		Integrator() {};

		Integrator(ld(*f)(ld), int, bool);

		ld trapezoid_integrator(ld a, ld b, long long int partitions);

		ld simpsons_integrator(ld a, ld b, long long int partitions);

		ld integrate(ld a, ld b, std::string rule = "simpsons");
	};
}
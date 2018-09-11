#include "stdafx.h"
#include "NumericAlgebra.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>

typedef long double ld;

namespace NumericAlgebra {

	Integrator::Integrator(ld(*f)(ld), int p, bool b) {
		function = f;
		precision = p;
		debug = b;
	}

	ld Integrator::trapezoid_integrator(ld a, ld b, long long int partitions) {
		ld step = (b - a) / (ld)partitions, x = a, s = function(a) + function(b);
		for (long long int i = 0; i <= partitions - 1; i++) {
			s += 2 * (function(x + step));
			x += step;
			number_of_iterations++;
		}
		return s * step / 2;
	}

	ld Integrator::simpsons_integrator(ld a, ld b, long long int partitions) {
		partitions += partitions % 2;
		ld step = (b - a) / (ld)partitions, x = a, s = function(a) + function(b);
		ld y1 = function(x);
		for (long long int i = 1; i <= partitions; i++) {
			if (i % 2)
				s += 4 * function(x + step);
			else
				s += 2 * function(x + step);
			number_of_iterations++;
			x += step;
		}
		return s * step / 3.0;
	}

	ld Integrator::integrate(ld a, ld b, std::string rule) {
		ld dif = 1e8, result1 = 0, result2 = 0;
		long long int i = 1000;
		time = clock();
		ld(Integrator::*rule_function)(ld, ld, long long int) = NULL;
		std::ofstream debug_log("log.txt");

		if (rule == "trapezoid") {
			rule_function = &Integrator::trapezoid_integrator;
		}
		if (rule == "simpsons") {
			rule_function = &Integrator::simpsons_integrator;
		}

		result1 = (this->*rule_function)(a, b, i);
		while (10 * std::abs(dif) > std::pow(10, -precision)) {
			result2 = (this->*rule_function)(a, b, (int)(i * k));
			dif = result2 - result1;
			i *= k;
			number_of_partitions = i;
			result1 = result2;
			level++;
			if (debug)
			debug_log << result1 << " " << dif << " " << level << std::endl;
		}

		long long int buff = result1 * std::pow(10, precision);
		result1 = buff / std::pow(10, precision);
		time = clock() - time;
		return result1;
	}
}
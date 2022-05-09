#ifndef PRECISION_H_INCLUDED
#define PRECISION_H_INCLUDED


#include <cstdio>
#include <cmath>


#if defined(USE_FLOAT)

	#define Real		float
	#define eps		1e-15
	#define sqrt_r(x)	sqrt(x)
	#define print_r(x)	printf("%.9g", x)
	#define PI		3.141592

#else

	#define Real		double
	#define eps		1e-15
	#define sqrt_r(x)	sqrtf(x)
	#define print_r(x)	printf("%.14g", x)
	#define PI		3.141592653589793

#endif


#endif

#ifndef PRECISION_H_INCLUDED
#define PRECISION_H_INCLUDED


#include <cstdio>


#if defined(USE_FLOAT)

	#define Real		float
	#define eps		1e-15
	#define sqrt_r(x)	sqrt(x)
	#define print_r(x)	printf("%.9g", x)

#else

	#define Real		double
	#define eps		1e-15
	#define sqrt_r(x)	sqrtf(x)
	#define print_r(x)	printf("%.14g", x)

#endif


#endif

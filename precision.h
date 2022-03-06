#pragma once

// Il comportamento stantard è usare i float
#ifdef USE_DOUBLE

	#define REAL		double
	#define sqrt(x)		sqrt(x)
	#define pow(x, y)	pow(x, y)
	#define exp(x)		exp(x)

#else

	#define REAL		float
	#define sqrt(x)		sqrtf(x)
	#define pow(x, y)	powf(x, y)
	#define exp(x)		expf(x)

#endif

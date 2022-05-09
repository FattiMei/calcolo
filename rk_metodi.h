#ifndef RK_METODI_INCLUDED
#define RK_METODI_INCLUDED


#include "precision.h"


#if defined(EE)


	const unsigned int s = 1;
	
	const Real A[s][s] = {
		{0.0}
	};


	const Real b[s] = {1.0};
	const Real c[s] = {0.0};
	

#elif defined(HEUN)


	const unsigned int s = 2;
	
	const Real A[s][s] = {
		{0.0, 0.0},
		{1.0, 0.0}
	};


	const Real b[s] = {0.5, 0.5};
	const Real c[s] = {0.0, 1.0};
	

#elif defined(MIDPOINT)


	const unsigned int s = 2;
	
	const Real A[s][s] = {
		{0.0, 0.0},
		{0.5, 0.0}
	};


	const Real b[s] = {0.0, 1.0};
	const Real c[s] = {0.0, 0.5};
	

#elif defined(RALSTON)


	const unsigned int s = 2;
	
	const Real A[s][s] = {
		{0.0, 		0.0},
		{2.0/3.0, 	0.0}
	};


	const Real b[s] = {1.0/4.0, 3.0/4.0};
	const Real c[s] = {0.0, 2.0/3.0};
	

#elif defined(RK3)


	const unsigned int s = 3;
	
	const Real A[s][s] = {
		{0.0, 0.0, 0.0},
		{0.5, 0.0, 0.0},
		{-1.0, 2.0, 0.0}
	};


	const Real b[s] = {1.0/6.0, 2.0/3.0, 1.0/6.0};
	const Real c[s] = {0.0, 0.5, 1.0};
	

#elif defined(RK4)


	const unsigned int s = 4;
	
	const Real A[s][s] = {
		{0.0, 0.0, 0.0, 0.0},
		{0.5, 0.0, 0.0, 0.0},
		{0.0, 0.5, 0.0, 0.0},
		{1.0, 0.0, 1.0, 0.0}
	};


	const Real b[s] = {1.0/6.0, 1.0/3.0, 1.0/3.0, 1.0/6.0};
	const Real c[s] = {0.0, 0.5, 0.5, 1.0};
	

#endif


#endif

#ifndef PRECISION_H_INCLUDED
#define PRECISION_H_INCLUDED


// il comportamento standard è usare i double


#if !defined(USE_FLOAT)

	#define Real		double
	#define eps		    0.00000000001
	#define PI          3.1415
	#define print(x) 	printf("%.3f", x)

#elif defined(USE_FLOAT)

	#define Real		float
	#define eps		    0.00001
    #define PI          3.1415
	#define print(x)	printf("%.3f", x)

	#define sqrt(x)		sqrtf(x)
	#define pow(x, y)	powf(x, y)
	#define exp(x)		expf(x)

#endif


#endif

#include "precision.h"
#include "mat.h"


void dati_iniziali(Real *t_0, Real *T, vec<2> &u){
	*t_0 = 0.0;
	*T   = 2.0 * 3.1415;

	u[0] = 1.0;
	u[1] = 0.0;
}


void effe(vec<2> &dest, Real t, const vec<2> &u){
	dest[0] = u[1];
	dest[1] = -u[0];
}


int main(int argc, char *argv[]){
	long N = 1;
	Real t_0, t, T, h;
	vec<2> u, deriv;


	// da riga di comando prendo il numero di passi
	if(argc < 2)
		return 1;
	else
		N = atol(argv[1]);


	dati_iniziali(&t_0, &T, u);
	h = (T - t_0) / (Real) N;


	for(long i = 0; i <= N; ++i){
		t = t_0 + h * (Real) i;
		print_solution(t, u);


		// calcola il passo successivo
		effe(deriv, t, u);
		smul(deriv, h, deriv);
		sum(u, u, deriv);
	}


	return 0;
}

#include "precision.h"
#include "mat.h"


#define RK4
#include "rk_metodi.h"


// dimensione del problema
const unsigned int d = 2;


void dati_iniziali(Real *t_0, Real *T, vec<d> &u){
	*t_0 = 0.0;
	*T   = 2.0 * PI;

	u[0] = 1.0;
	u[1] = 0.0;
}


void effe(vec<d> &dest, Real t, const vec<d> &u){
	dest[0] = u[1];
	dest[1] = -u[0];
}


int main(int argc, char *argv[]){
	long N = 1;
	Real t_0, t, T, h;
	vec<d> u, deriv;


	// solo per i metodi di runge kutta devo memorizzare gli stadi
	mat<s, d> K;


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
		vec<d> p_int;


		for(unsigned int i = 0; i < s; ++i){
			// questo è un metodo esplicito, quindi la A è triangolare inferiore con diagonale nulla
			for(unsigned int j = 0; j < i; ++j){
				vec<d> tmp;
				smul(tmp, A[i][j], K[j]);
				sum(p_int, p_int, tmp);
			}

			smul(p_int, h, p_int);
			sum(p_int, u, p_int);
			effe(K[i], t + h * c[i], p_int);
		}


		// gli stadi sono stati calcolati interamente
		smul(deriv, 0.0, deriv);

		for(unsigned int i = 0; i < s; ++i){
			smul(K[i], b[i], K[i]);
			sum(deriv, K[i], deriv);
		}

		smul(deriv, h, deriv);
		sum(u, u, deriv);
	}


	return 0;
}

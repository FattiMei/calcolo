#ifndef MAT_H_INCLUDED
#define MAT_H_INCLUDED


#include "precision.h"
#include <cmath>


template <unsigned int N>
class vec{

	private:
		Real cols[N];


		void set(Real scalar){
			for(unsigned int i = 0; i < N; ++i)
				cols[i] = scalar;
		}

	public:
		vec(){
			set(0.0);
		}


		vec(Real r){
			set(r);
		}


		unsigned int elem(){
			return N;
		}


		void print_for_term(const char *label = NULL){
			if(label == NULL)
				label = "ans";

			printf("%s =\n", label);

			for(unsigned int i = 0; i < N; ++i){
				printf("\t");
				print_r(cols[i]);
			}

			printf("\n\n");
		}


			Real&	operator[](unsigned int idx)		{ return cols[idx]; }
		const 	Real& 	operator[](unsigned int idx)	const	{ return cols[idx]; }
};


template <unsigned int N>
void print_solution(Real t, const vec<N> &u){
	print_r(t);

	for(unsigned int i = 0; i < N; ++i){
		printf("\t");
		print_r(u[i]);
	}

	printf("\n");
}


template <unsigned int N>
Real dot(const vec<N> &v, const vec<N> &w){
	Real result = 0.0;

	for(unsigned int i = 0; i < N; ++i)
		result += v[i] * w[i];
	
	return result;
}


template <unsigned int N>
Real norm(const vec<N> &v){
	return sqrt(dot(v, v));
}


template <unsigned int N>
void sum(vec<N> &dest, const vec<N> &v, const vec<N> &w){
	for(unsigned int i = 0; i < N; ++i)
		dest[i] = v[i] + w[i];
}


template <unsigned int N>
void smul(vec<N> &dest, Real scalar, const vec<N> &v){
	for(unsigned int i = 0; i < N; ++i)
		dest[i] = scalar * v[i];
}


template <unsigned int N>
void point_mul(vec<N> &dest, const vec<N> &v, const vec<N> &w){
	for(unsigned int i = 0; i < N; ++i)
		dest[i] = v[i] * w[i];
}


template <unsigned int N, unsigned int M>
class mat{
	private:
		vec<M> rows[N];
	

	public:
		mat(){
			mat(0.0);
		}


		mat(Real scalar){
			for(unsigned int i = 0; i < N; ++i)
				rows[i] = vec<M>(scalar);
		}


		unsigned int elem(){
			return N * M;
		}


			vec<M>&	operator[](unsigned int idx)		{ return rows[idx]; }
		const 	vec<M>&	operator[](unsigned int idx)	const	{ return rows[idx]; }
};


template <unsigned int N, unsigned int M>
void sum(mat<N, M> &dest, const mat<N, M> &A, const mat<N, M> &B){
	for(unsigned int i = 0; i < M; ++i)
		sum(dest[i], A[i], B[i]);
}


template <unsigned int N, unsigned int M>
void smul(mat<N, M> &dest, Real scalar, const mat<N, M> &A){
	for(unsigned int i = 0; i < M; ++i)
		smul(dest[i], scalar, A[i]);
}


template <unsigned int N, unsigned int M>
void mul(vec<N> &dest, const mat<M, N> &A, const vec<N> &v){
	for(unsigned int i = 0; i < N; ++i)
		dest[i] = dot(A[i], v);
}


#endif

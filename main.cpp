#include <iostream>

#include "precision.h"
#include "mat.h"


using namespace std;


int main(){
	vec<6> v = vec<6>(0.2);
	cout << "|| v || = " << norm(v) << endl;

	return 0;
}

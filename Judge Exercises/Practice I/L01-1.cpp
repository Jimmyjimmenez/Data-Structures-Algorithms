/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 *
 * 
 *  * Introduce el nombre y apellidos de los/as componentes del grupo:
    *
    * Estudiante 1: Roxanne Caiafa
    * Estudiante 2: Jaime Jiménez
    *
*/

#include <iostream>
#include <cassert>
#include <fstream>

const int GRADO_MAX = 10000;

class Polinomio {

	public:

		Polinomio() : gradoMayor(0) { } //O(1)

        //O(1) 
		void anyadir_monomio(int coef,int exp) {
	        assert (exp <= GRADO_MAX && exp >= 0 );
		    this->coeficientes[exp] += coef;
        }

        //O(n) siendo n el número de componentes del array
		long evaluar(int valor) const {
            long result = 0;
	        long exp = valor;

	        for (int i = 0; i < GRADO_MAX; i++) {
		        if (coeficientes[i] != 0) {
			        if (i == 0) result += coeficientes[i];
			        else result += coeficientes[i] * exp;
                }
		    if (i > 0) exp *= valor;
            }

            return result;
        }

	private:
		int coeficientes[GRADO_MAX + 1]{};
		int gradoMayor;
};

bool tratar_caso() {
	int monomios, valor;
	std::cin >> monomios >> valor;
	assert((monomios >= 0 && monomios <= 2000) && (-10 <= valor && valor <= 10));
	if (monomios == 0 && valor == 0) return false;
	
	int i = 0, coef,exp;
	Polinomio poli;
	while (i < monomios) {
		std::cin >> coef >> exp;
		poli.anyadir_monomio(coef,exp);
		++i;
	}
	std::cout << poli.evaluar(valor) << '\n';
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("l1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (tratar_caso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
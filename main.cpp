#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>

#include "Escalonador.hpp"
#include "Gerencia.hpp"

#define MAX_N 26
#define MAX_T 100000

using namespace std;


enum getTarefa{
	A = 'A',
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};

int main() {
	unsigned n, t;
	
	while(true) {
		// Leitura
		cin >> n >> t;
		
		if (n == 0 || t == 0) 
			break;

		// tarefas.resize(n);
		vector<shared_ptr<Tarefa>> tarefas(n);
		for (unsigned i=0; i<n; i++) {
			unsigned c, p,d;
			cin >> c >> p >> d;
			getTarefa tarefa = static_cast<getTarefa>(A + i);
			char letra = static_cast<char>(tarefa);
			// tarefas[i].define(c,p,d,letra);
			tarefas[i] = make_shared<Tarefa>(c, p, d, letra); // faz o new dos ponteiros das tarefas
		}
		unique_ptr<Gerencia> gerente = make_unique<Gerencia>(tarefas); // faz o "new" do gerente, mas é mais seguro
		// gerente->defineU(tarefas, n );
		gerente->executaT(tarefas, t);
		// Resultado
		
		cout << gerente->obtemGrade() << endl;
		cout << gerente->obtemTr() << " " << gerente->obtemPreemp() << endl;
		cout << fixed << setprecision(4) << gerente->obtemU() << " ";
		cout << (gerente->obtemU()<=1.0 ? "OK" : "NOK") << endl << endl;
	}
	return 0;
}
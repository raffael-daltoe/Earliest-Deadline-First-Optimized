#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#define MAX_N 26
#define MAX_T 100000
using namespace std;
#include "Gerencia.hpp"

class Escalonador{
    static bool compararTarefas(const shared_ptr<Tarefa>& t1, const shared_ptr<Tarefa>& t2);
public:
	Tarefa* Organiza_Tarefas(vector<shared_ptr<Tarefa>> &t);
	Tarefa* escalona(Tarefa *nova, Tarefa *antiga, int exec, Gerencia *g);
    void atualizatarefas(vector<shared_ptr<Tarefa>> &t);
};

#pragma once

#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <memory>
#define MAX_N 26
#define MAX_T 100000
using namespace std;

#include "Tarefa.hpp"


class Gerencia{
	double U;
	unsigned tr_contexto, preemp;
	char grade[MAX_T];
	vector<char> tarefas;
public:	
	Gerencia(){
		tr_contexto = 0;
		preemp = 0;
		grade[0] = '\0';
	}

	Gerencia(vector<shared_ptr<Tarefa>>& tarefas) : Gerencia() {
		U = 0;
	    for(auto& it : tarefas)
    	    U = U + (static_cast<double>(it->obtemC()) / it->obtemP()); // converte o C em ponto flutuante e então se consegue o valor da di
	}

	char* obtemGrade();
	unsigned obtemTr();
	unsigned obtemPreemp(); 
	double obtemU();
	
	void incrementaGrade(char l,int i);
	void increaseTr_contexto();
	void increasePreemp();
	void executaT(vector<shared_ptr<Tarefa>> &t, int time);
};

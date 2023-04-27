#include "Gerencia.hpp"
#include "Escalonador.hpp"

char* Gerencia::obtemGrade() { return grade; }
unsigned Gerencia::obtemTr() { return tr_contexto; }
unsigned Gerencia::obtemPreemp() { return preemp; }
double Gerencia::obtemU() { return U; }

void Gerencia::increaseTr_contexto()
{
    tr_contexto += 1;
}

void Gerencia::increasePreemp()
{
    preemp += 1;
}
void Gerencia::executaT(vector<shared_ptr<Tarefa>> &t, int time)
{
    unique_ptr<Escalonador> sched = make_unique<Escalonador>();
    Tarefa *antiga=nullptr, *nova = nullptr;
    int i = 0, execucao = 0,flag=0;

    while (i!= time)
    {
        sched->atualizatarefas(t);                                              // atualiza computação atual e qual o tempo de execucao
        nova = sched->Organiza_Tarefas(t);                                       // atualiza o periodo das tarefas
        if ( nova == nullptr ){
            if(flag == 1)increaseTr_contexto();                                // flag para saber se houve uma troca de contexto no "IDLE"
            flag = 0;
            incrementaGrade('.',i);
        }
        else{
            if(t.size() == 1) antiga = nullptr;
            if ((nova != antiga) )                                                 // se for a mesma tarefa, não vai escalonar!!!
            {
                antiga = sched->escalona(nova, antiga, execucao, this);                 // vai escalonar se for diferente
                execucao = 0;                                                   
                flag = 1;
            }
            nova->defineComputacao_tmp(nova->obtemComput_tmp()+1);              // insere a nova computação da tarefa nvoa
            incrementaGrade(nova->obtemLetra(), i);                             // faz a grade da nova tarefa
        }
            i++;
            execucao++;
    }
}

void Gerencia::incrementaGrade(char l,int i){
    grade[i] = l;
}

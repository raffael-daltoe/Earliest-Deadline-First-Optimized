#include "Escalonador.hpp"

Tarefa *Escalonador::Organiza_Tarefas(vector<shared_ptr<Tarefa>> &t)
{
    std::sort(t.begin(), t.end(), compararTarefas);
    for (auto &it : t)
    {
        if (it->obtemState() == false)
        {
            return it.get();
        }
    }
    return nullptr;
    // vai verificar qual o valor do deadline dinamico e retornar se aquela tarefa atual continua, se não, vai ter que escalonar outra
}

Tarefa *Escalonador::escalona(Tarefa *nova, Tarefa *antiga, int exec, Gerencia *g)
{
    if (antiga != nullptr)
    {
        if (antiga->obtemComput_tmp() < antiga->obtemC())
        {
            g->increasePreemp();
        }
    }
    g->increaseTr_contexto();
    return nova;
    // aqui ele vai trocar de contexto, vai colocar outra tarefa para processar
}

bool Escalonador::compararTarefas(const shared_ptr<Tarefa> &t1, const shared_ptr<Tarefa> &t2)
{
    // compara as tarefas com base no valor dinamico do deadline
    return t1->obtemD_dinamic() < t2->obtemD_dinamic();
}

void Escalonador::atualizatarefas(vector<shared_ptr<Tarefa>> &t)
{

    for (auto &it : t)
    {

        if (it->obtemComput_tmp() >= it->obtemC())
        {
            it->defineState(true);
        }
        if (it->obtemP() == it->obtemTime_exec())
        {                           // verifica se o periodo já está renovado
            it->defineTime_exec(0); // se estiver ele define 0 o tempo dela e o estado false para escalonar
            it->defineComputacao_tmp(0);
            it->defineState(false);
        }
        it->defineD_dinamic(it->obtemD() - it->obtemTime_exec());
        it->defineTime_exec(it->obtemTime_exec() + 1); // atualiza qual o tempo real da tarefa
    }
}
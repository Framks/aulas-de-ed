#ifndef QUEUE_H
#define QUEUE_H
#include <stack>

// implementação de uma fila usando duas pilhas FIFO(First In, First Out)
class Queue
{
private:
    std::stack<int> deposito;
    std::stack<int> prateleira;
public:
    Queue();
    ~Queue();

    // função para adicionar um elemento na fila que vai ser a pilha de deposito
    void add(int value);

    // função para remover um elemento da fila que vai ser a pilha de prateleira
    // se a fila estiver vazia ela pega o que tiver na pilha deposito e coloca na 
    // pilha de prateleira.
    void remove();

    // retorna o primeiro elemento da fila que vai ser a pilha de prateleira
    // se não houver elementos, vai pegar tudo o que tem na pilha deposito e vai colocar
    // na pilha de prateleira se ainda estiver vazia vai lançar uma excesão
    int front();
};

#endif // QUEUE_H
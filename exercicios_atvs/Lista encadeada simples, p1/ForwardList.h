// NAO MEXA NESTE ARQUIVO DE CABECALHO, ELE JA ESTA FINALIZADO E PRONTO PARA SER USADO PELO MOODLE
#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <vector>
#include <string>
#include "Node.h"

/**************************************
 * Declaracao da classe ForwardList
 **************************************/
class ForwardList {
private:
    /**
     * m_head: ponteiro para o inicio da lista.
     * O ponteiro m_head sempre aponta para um no sentinela.
     */
    Node* m_head; 
    /**
     * m_size: numero de elementos na lista 
     */
    int m_size;  
    
public:
    // construtor: cria lista vazia
    ForwardList();

    // construtor de copia
    ForwardList(const ForwardList& lst);

    // retorna true se e somente se a lista esta vazia
    bool empty() const;

    // retorna o numero de elementos na lista
    int size() const;

    // deixa a lista vazia: size() == 0
    void clear();

    // destrutor: libera toda a memoria alocada, ate mesmo o no sentinela
    ~ForwardList();

    // operador[] para acesso a elemento
    // nao checa se indice eh valido
    Item& operator[](int index);
    const Item& operator[](int index) const;

    // insere um elemento no indice especificado
    void insert_at(int index, const Item& val);

    // remove o elemento no indice especificado
    void remove_at(int index);

    // retorna uma string contendo os elementos da lista entre colchetes [ ]
    std::string toString();

    // --------------------------------------------------------- //
    // ----------- funcoes adicionais - parte 1 ---------------- //
    // --------------------------------------------------------- //

    // retorna uma referencia para o primeiro elemento na lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    Item& front();
    const Item& front() const;
    
    // insere um elemento no inicio da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void push_front(const Item& val);

    // deleta o primeiro elemento da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void pop_front();

    // retorna uma referencia para o ultimo elemento na lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    Item& back();
    const Item& back() const;
    
    // insere um elemento no final da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void push_back(const Item& val);

    // deleta o ultimo elemento da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void pop_back();
    
    // Concatena a lista atual com a lista lst.
    // A lista lst eh modificada apos essa operacao.
    // Por exemplo, seja l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
    // Após fazer l1.concat(l2) você deve obter
    // l1 = [ 1 2 3 4 7 9 8] e l2 = [ ]
    // Restrição: está proibido usar funções auxiliares para resolver esta questão,
    // inclusive qualquer dos operadores sobrecarregados
    void concat(ForwardList& lst);


    // Remove da lista todas as ocorrencias do Item x.
    // Se a lista estiver vazia, esta funcao nao faz nada;
    // Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados
    void remove(const Item& x);


    // Devolve um ponteiro para uma copia desta lista.
    // Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados
    ForwardList* clone();


    // Copia os elementos do vector vec para o final da lista.
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados void appendVector(const vector<Item>& vec);
    // Troca o conteudo dessa lista pelo conteudo de lst.
    // Os tamanhos das listas podem diferir.
    // Apos a chamada para esta funcao, os elementos nesta lista
    // sao aqueles que estavam em lst antes da chamada,
    // e os elementos de lst sao aqueles que estavam nesta lista.
    void swap(ForwardList& lst);


    // Determina se a lista lst, passada por parametro, eh igual
    // a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho
    // e o valor do k-esimo elemento da primeira lista eh igual ao
    // k-esimo valor da segunda lista.
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados
    bool equals(const ForwardList& lst) const;

    // Inverte a ordem dos nós (o primeiro node passa a ser o último, o segundo passa a ser o penultimo, etc.)
    // Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
    // Voce pode criar ponteiros auxiliares (um número constante deles),
    // mas nao pode alocar novos nós.
    // Repetindo: está proibido chamar o operador new nesta questão.
    // Restrição: Também não é permitido usar funções auxiliares nesta questão
    void reverse();


    // retorna o elemento na posicao 'index'
    // Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
    // mensagem de erro "index out of range". Caso contrario retorne o elemento.
    // Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida

    Item& get(int index);

    const Item& get(int index) const;

    // Copia os elementos do vector vec para o final da lista.
    // Esta funcao deve ter complexidade O(n) no pior caso
    // Restrição: está proibido usar funções auxiliares nesta questão,
    // inclusive qualquer dos operadores sobrecarregados
    void appendVector(const std::vector<Item>& vec);
};


#endif
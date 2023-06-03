/**
 *                                   TRABALHO DE ESTRUTURA DE DADDOS
 *                     Nome: Francisco Gabriel Alves Nunes       Matricula: 497357
 *                     Nome: Fernando Paulino de castro junior   Matricula: 505499
 * 
 * 
*/
#ifndef NODE
#define NODE

// Nó da matriz esparsa
struct Node
{
    Node *right;
    Node *down;
    int col;
    int line;
    double value;

    // construtor que recebe respectivamente coluna, linha, valor, ponteiro para a direita, e ponteiro para baixo 
    Node(int col, int lin, double value, Node *down, Node *right){
        this->col = col;
        this->line = lin;
        this->right = right;
        this->down = down;
        this->value = value;
    }

    ~Node(){
        delete right;
        delete down;
    }

};

#endif
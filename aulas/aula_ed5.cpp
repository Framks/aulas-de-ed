/*
    ponteiro pode ser nulo ou o indereço de memória
    para iniciar o ponteiro como nulo se utiliza nullptr

    Ex.: int *ptr = nullptr;

    tambem fica valido como 0

    Ex.: int *ptr = 0;

    apenas inicializar um ponteiro com algum valor que eu queira que seja, NUNCA
    INICIALIZAR UM pONTEIRO DESSA FORMA:
        int *ptr;

    isso não vai dar erro mas pode dar um quebra cabeça.  
*/
#include <iostream>
#include <cmath>
using namespace std;
struct ponto
{
    double posicao_x;
    double posicao_y;
};

// dobra o valor dos campos de
// ponto
void dobra_ponto(ponto *p)
{
    p->posicao_x = p->posicao_x*2;
    p->posicao_y = p->posicao_y*2;
}

// calcula a distancia entre os dois pontos
double cal_distancia(ponto p, ponto q)
{
    return sqrt(pow(q.posicao_x - p.posicao_x, 2) + pow(q.posicao_y - q.posicao_y, 2));
}


void troca(ponto *a, ponto *b)
{
    ponto aux;
    aux.posicao_x = a->posicao_x;
    aux.posicao_y = a->posicao_y;

    a->posicao_x = b->posicao_x;
    a->posicao_y = b->posicao_y;

    b->posicao_x = aux.posicao_x;
    b->posicao_y = aux.posicao_y;
}

int main()
{
    ponto p{0, 0}, q;
    cout << "digite a coordenada x: ";
    cin >> q.posicao_x;
    cout << "digite a coordenada y: ";
    cin >> q.posicao_y;

    troca(&p,&q);

    /*double distancia = cal_distancia(p, q);
    cout << "a distancia do ponto p(" << p.posicao_x
         << "," << p.posicao_y << ") e o ponto q("
         << q.posicao_x << "," << q.posicao_y
         << ") e: " << distancia << endl;
         */
}
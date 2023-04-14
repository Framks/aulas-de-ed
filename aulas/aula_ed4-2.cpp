#include <iostream>
#include <cmath>
using namespace std;
struct ponto
{
    double posicao_x;
    double posicao_y;
};

struct retangulo
{
    ponto se;
    ponto id;
    ponto sd;
    ponto ie;
};

double cal_distancia(ponto p, ponto q)
{
    return sqrt(pow(q.posicao_x - p.posicao_x, 2) + pow(q.posicao_y - q.posicao_y, 2));
}

double area_retangulo(retangulo h)
{
    double altura = cal_distancia(h.id, h.sd);
    double base = cal_distancia(h.sd, h.se);
    return base * altura;
}

int main()
{
    retangulo h;
    cout << "digite o ponto superior esquerdo do quadrado: ";
    cin >> h.se.posicao_x >> h.se.posicao_y;
    cout << "digite o ponto inferior direito do quadrado: ";
    cin >> h.id.posicao_x >> h.id.posicao_y;
    h.sd.posicao_x = h.id.posicao_x;
    h.sd.posicao_y = h.se.posicao_y;
    h.ie.posicao_x = h.se.posicao_x;
    h.ie.posicao_y = h.id.posicao_y;

    double area = area_retangulo(h);
    cout << "a area do retangulo e: " << area;
}

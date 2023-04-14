/*struct :
    tipo composto de dados
    conjunto de variaveis
    exemplo de struct com construtor

    struct empregado
{
    short id;
    int idade;
    double salario;

    empregrado(int n, int i, double s)
    {
        id = n;
        idade = i;
        salario = s;
    }
}

empregado p(id, idade, salario) // a partir do c++ 11


int function(int x)

*/
#include <iostream>
#include <cmath>
using namespace std;
struct ponto
{
    double posicao_x;
    double posicao_y;
};

double cal_distancia(ponto p, ponto q)
{
    return sqrt(pow(q.posicao_x - p.posicao_x, 2) + pow(q.posicao_y - q.posicao_y, 2));
}

int main()
{
    ponto p{0, 0}, q;
    cout << "digite a coordenada x: ";
    cin >> q.posicao_x;
    cout << "digite a coordenada y: ";
    cin >> q.posicao_y;
    double distancia = cal_distancia(p, q);
    cout << "a distancia do ponto p(" << p.posicao_x
         << "," << p.posicao_y << ") e o ponto q("
         << q.posicao_x << "," << q.posicao_y
         << ") e: " << distancia << endl;
}

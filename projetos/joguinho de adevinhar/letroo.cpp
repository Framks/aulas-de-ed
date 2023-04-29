#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
using namespace std;

// função que testa se o sistema é linux ou windows e limpa a tela para as duas plataformas
void limparTela()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else defined(__linux__) || defined(__unix__)
    system("clear");
#endif
}

string carregarPalavra()
{
    ifstream outClientFile("clients.txt", ios::in);
    vector<string> dicionario;
    srand(time(NULL));
    string nome;
    if (!outClientFile.is_open())
    {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    while (outClientFile >> nome)
    {
        dicionario.push_back(nome);
    }
    outClientFile.close();
    return dicionario[rand() % dicionario.size()];
}

void menuInicial()
{
    cout << "               BEM VINDO AO JOGO DA FORCA REMASTERIZADO KKKKK \n\n"
         << endl;
    cout << "     Essa versao vai contar apenas com palavras sem acentuacao.\n"
         << "     Voce tem 6 chances de acertar uma palavra que vai ser escolhida aleatoriamente\n"
         << "     caso a palavra excolhida tenha uma litra que vc digitou vai ser colocado na tela a letra no local corespondente"
         << endl;
}

string verificarPalavra(string palavra, string palavraEscolhida)
{
    string resultado = "";
    if (palavra.length() != 5)
    {
        return resultado;
    }
    else
    {
        for (char c : palavra)
        {
            for (char d : palavraEscolhida)
            {
                if (c == d)
                {
                    resultado += c;
                    break;
                }
                else
                {
                    resultado += " ";
                }
            }
        }
        return resultado;
    }
}

void imprimirJogadas(string jogadas[] = 0)
{
    if (jogadas)
    {
        for (int i = 0; i < jogadas->length(); i++)
        {
            cout << jogadas[i] << endl;
        }
    }
}

// executa as 5 rodadas de cada partidas
void jogar()
{
    string jogadas[5];                           // vetor que contera todas as jogadas do player
    int rodadas = 6;                             // numero de que o jogador tera
    int i = 0;                                   // rodadas atuais
    string palavraEscolhida = carregarPalavra(); // palavra escolhida randomicamente
    limparTela();                                // vai limpar a tela em cada rodada
    menuInicial();                               // menu inicial com as informacoes
    while (i < rodadas)
    {
        imprimirJogadas(jogadas);
        cout << "voce tem " << rodadas - i << " rodadas para acertar a palavra,\n digite uma palavra de 5 letras: " << endl;
        cin >> jogadas[i];
        string resultado = verificarPalavra(jogadas[i], palavraEscolhida);
        if (resultado != "")
        {
            cout << resultado << endl;
        }
        else
        {
            cout << "digite uma palavra valida: " << endl;
        }
        i++;
    }
}

int main()
{
    int loop = 1;
    // esse vai ser o menu de inicio
    while (loop)
    {
        jogar();
        cout << "se deseja jogar novamente digite 1 se não digite 0: ";
        cin >> loop;
    }
    system("pause");
}
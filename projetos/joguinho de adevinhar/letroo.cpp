#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
using namespace std;

const string ARQUIVO = "clients.txt";
const int QUANT_TENTATIVAS = 6;
const int TAMANHO_pALAVRA = 5;

// função que testa se o sistema é linux ou windows e limpa a tela para as duas plataformas
void limparTela()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else defined(__linux__) || defined(__unix__)
    system("clear");
#endif
}

// esta função retorna uma palavra escolhida aleatoriamente do arquivo clients.txt
string carregarPalavra()
{
    ifstream outClientFile(ARQUIVO, ios::in);
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

// imprimi apenas o inicio
void menuInicial()
{
    cout << "               BEM VINDO AO JOGO DA FORCA REMASTERIZADO KKKKK \n\n"
         << endl;
    cout << "     Essa versao vai contar apenas com palavras sem acentuacao.\n"
         << "     Voce tem 6 chances de acertar uma palavra que vai ser escolhida aleatoriamente\n"
         << "     caso a palavra excolhida tenha uma litra que vc digitou vai ser colocado na tela a letra no local corespondente"
         << endl;
}

// verifica se a palavra esta correta e retorna uma string onde
// o 1 significa que a letra esta na posição certa
// o 0 significa que a letra esta na posição errada
// o 2 significa que não tem a letra na palavra
string verificarPalavra(string jogadas[], string palavra, string palavraEscolhida)
{
    if (palavra.length() != 5)
    {
        return "";
    }

    string result = "";
    for (int i = 0; i < TAMANHO_pALAVRA; i++)
    {
        for (int j = 0; j < TAMANHO_pALAVRA; j++)
        {
            if (palavra[i] == palavraEscolhida[j] && i == j)
            {
                result += "1";
                break;
            }
            else if (palavra[i] == palavraEscolhida[j] && i != j)
            {
                result += "0";
                break;
            }
        }
        if (result.length() < i + 1)
        {
            result += "2";
        }
    }
    return result;
}

// imprime cada rodada na tela
void imprimirJogadas(string jogadas[])
{
    if (jogadas != nullptr)
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
    string jogadas[5], palavra;                  // vetor que contera todas as jogadas do player
    int rodadas = QUANT_TENTATIVAS;              // numero de que o jogador tera
    int i = 0;                                   // rodadas atuais
    string palavraEscolhida = carregarPalavra(); // palavra escolhida randomicamente
    limparTela();                                // vai limpar a tela em cada rodada
    menuInicial();                               // menu inicial com as informacoes
    while (i < rodadas)
    {
        imprimirJogadas(jogadas);
        cout << "voce tem " << rodadas - i << " rodadas para acertar a palavra,\n digite uma palavra de 5 letras: " << endl;
        cin >> palavra;
        string resultado = verificarPalavra(jogadas, palavra, palavraEscolhida);
        if (resultado != "")
        {
            cout << resultado << endl;
            i++;
        }
        else
        {
            cout << "digite uma palavra valida: " << endl;
        }
    }
}

int main()
{
    int loop = 1;
    // esse vai ser o menu de inicio
    while (loop)
    {
        jogar();
        cout << "se deseja jogar novamente digite 1 se nao digite 0: ";
        cin >> loop;
    }
    system("pause");
}
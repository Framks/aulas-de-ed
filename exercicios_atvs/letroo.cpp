#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

const string DICT_FILE = "dictionary.txt"; // Arquivo com as palavras válidas
const int MAX_TIME = 60;                   // Tempo máximo em segundos
const int MIN_WORD_LEN = 3;                // Tamanho mínimo da palavra
const int MAX_WORD_LEN = 6;                // Tamanho máximo da palavra

vector<string> dictionary; // Vetor para armazenar as palavras válidas

// Função para ler o arquivo com as palavras válidas e armazená-las no vetor
void loadDictionary()
{
    ifstream dictFile(DICT_FILE);
    if (!dictFile)
    {
        cerr << "Erro ao abrir o arquivo de dicionário" << endl;
        exit(1);
    }

    string word;
    while (getline(dictFile, word))
    {
        dictionary.push_back(word);
    }

    dictFile.close();
}

// Função para gerar as letras aleatórias para o jogo
string generateLetters()
{
    string letters = "";
    char c;
    srand(time(NULL));

    for (int i = 0; i < MAX_WORD_LEN; i++)
    {
        c = 'A' + rand() % 26; // Gera uma letra aleatória
        letters += c;
    }

    return letters;
}

// Função para verificar se uma palavra é válida (está no dicionário)
bool isValidWord(string word)
{
    return (find(dictionary.begin(), dictionary.end(), word) != dictionary.end());
}

int main()
{
    loadDictionary();

    cout << "Bem-vindo ao jogo Letroo!" << endl;
    cout << "Você tem " << MAX_TIME << " segundos para encontrar o maior número possível de palavras." << endl;
    cout << "As letras para formar as palavras são:" << endl;

    string letters = generateLetters();
    cout << letters << endl;

    time_t startTime, endTime;
    time(&startTime);

    int score = 0;
    string word;
    while (true)
    {
        cout << "Digite uma palavra válida (entre " << MIN_WORD_LEN << " e " << MAX_WORD_LEN << " letras): ";
        cin >> word;

        if (word.length() < MIN_WORD_LEN || word.length() > MAX_WORD_LEN)
        {
            cout << "A palavra deve ter entre " << MIN_WORD_LEN << " e " << MAX_WORD_LEN << " letras." << endl;
            continue;
        }

        if (isValidWord(word))
        {
            score += word.length();
            cout << "Palavra válida! Pontuação atual: " << score << endl;
        }
        else
        {
            cout << "Palavra inválida. Tente novamente." << endl;
        }

        time(&endTime);
        double elapsedSeconds = difftime(endTime, startTime);
        if (elapsedSeconds >= MAX_TIME)
        {
            break;
        }
    }

    cout << "Tempo esgotado! Sua pontuação final é: " << score << endl;

    return 0;
}
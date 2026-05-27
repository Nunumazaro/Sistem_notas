#include <iostream>
#include <string>
using namespace std;
#include <fstream>

int main()
{
    // ENTRADA -Declaração de variáveis
    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;
    int opcaoInicial;

    // PROCESSAMENTO

    // LEITURA DE ALUNOS (commit 1)
    cout << "===SISTEMA DE NOTAS v4.0===" << endl;
    cout << "1 - novo relatório " << endl;
    cout << "2 - ver relatório salvo" << endl;
    cout << "escolha um opção: " << endl;
    cin >> opcaoInicial;

    // LEITURA DE ARQUIVO
    if (opcaoInicial == 2)
    {
        ifstream leitura("relatório.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\n";
            while (getline(leitura, linha))
            {
                cout << linha << endl;
            }
            leitura.close();
        }
        else
        {
            cout << "nenhum relatório encontrado. " << endl;
            return 0;
        }
    }

    do

    {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore();

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Nome do aluno: " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    // NOTAS E MEDIAS (commit 2)
    do
    {
        cout << "\nQuantidade de disciplinas (1 a 5): " << endl;
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplinas; j++)
        {
            do
            {
                cout << "Disciplina" << j + 1 << "(1 a 5)";
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }
    // SAÍDA
    cout << "\nAlunos cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "  " << i + 1 << ". " << nomes[i] << endl;
    }

    // CLASSIFICAÇÃO (commit 3)
    cout << " \n=== RELATÓRIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << nomes[i] << " - Média: " << media[i] << " - ";
        if (media[i] >= 7)
        {
            cout << "aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "recuperação" << endl;
            recuperacao++;
        }
        else
        {
            cout << "reprovado" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << "aprovados" << recuperacao << " em recuperacao" << reprovados << "reprovados" << endl;

    ofstream arquivo("relatorio.txt");

    // C
    if (arquivo.is_open())
    {
        arquivo << "=== RELATÓRIO ===" << endl;
        for (int i = 0; i < qtdAlunos; i++)
        {
            arquivo << nomes[i] << " - MÉDIA: " << media[i] << " - ";
            if (media[i] >= 7)
            {
                arquivo << "Aprovado" << endl;
            }
            else if (media[i] >= 5)
            {
                arquivo << "Recuperação" << endl;
            }
            else
            {
                arquivo << "Reprovado" << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << "aprovados" << recuperacao << "recuperaçao" << reprovados << "reprovados" << endl;

        arquivo.close();
        cout << "\nRelatório salvo em relatorio.txt" << endl;
        cout << "Erro ao criar arquivo." << endl;
    }

    return 0;
}

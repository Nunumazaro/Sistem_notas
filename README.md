## Sistema de Notas v4.1

O **Sistema de Notas v4.0** é uma aplicação de linha de comando (CLI) desenvolvida em C++ para o gerenciamento de alunos, disciplinas e notas. O programa permite o cadastro de turmas, lançamento de notas por disciplina, cálculo automatizado de médias, classificação do status do aluno e persistência dos dados em arquivo de texto.

## 🚀 Funcionalidades

-- **Menu Inicial Interativo**: Permite navegar facilmente entre criar um novo relatório, visualizar o último salvo ou acessar as informações do sistema.
- **Cadastro de Alunos e Notas por Disciplina**: Controle dinâmico e seguro que limita o cadastro de 1 a 20 alunos e de 1 a 5 disciplinas.
- **Cálculo Automático de Médias**: Determina a média aritmética exata de cada aluno com base no número de disciplinas informadas.
- **Classificação de Status**:
  - 🟢 **Aprovado**: Média ≥ 7.0
  - 🟡 **Recuperação**: Média entre 5.0 e 6.9
  - 🔴 **Reprovado**: Média < 5.0
- **Relatório Salvo com Data e Hora**: Exportação automática do relatório detalhado e do resumo estatístico para o arquivo `relatorio.txt`, registrando o momento exato da geração.
- **Leitura de Relatório Salvo**: Opção direta no menu para ler e exibir no terminal o conteúdo do arquivo `.txt` gerado anteriormente.
- **Menu "Sobre o sistema"**: Seção dedicada a exibir os créditos de desenvolvimento, versão atual do software e informações da turma.

## 🛠️ Pré-requisitos

Para compilar e executar este projeto, você precisará de um compilador C++ instalado em seu sistema:
- **Windows**: [MinGW](https://www.mingw-w64.org/) ou Visual Studio.
- **Linux/macOS**: GCC/G++ (geralmente disponível nativamente ou através do pacote `build-essential`).

## ⚙️ Como Compilar e Executar

1. Salve o código fonte em um arquivo chamado `main.cpp`.
2. Abra o terminal ou prompt de comando no diretório onde o arquivo foi salvo.
3. Compile o código com o seguinte comando:
   ```bash
   g++ main.cpp -o sistema_notas
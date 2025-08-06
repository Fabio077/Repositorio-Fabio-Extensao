#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 10

// Definindo a estrutura Livro
typedef struct {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
    double preco;
    int disponivel;  // 1 = disponível, 0 = não disponível
} Livro;

// Funções de Setter para os atributos

void setTitulo(Livro* livro, const char* titulo) {
    strncpy(livro->titulo, titulo, sizeof(livro->titulo) - 1);
}

void setAutor(Livro* livro, const char* autor) {
    strncpy(livro->autor, autor, sizeof(livro->autor) - 1);
}

void setAnoPublicacao(Livro* livro, int anoPublicacao) {
    livro->anoPublicacao = anoPublicacao;
}

void setPreco(Livro* livro, double preco) {
    livro->preco = preco;
}

void setDisponivel(Livro* livro, int disponivel) {
    livro->disponivel = disponivel;
}

// Funções de Getter para os atributos

const char* getTitulo(Livro* livro) {
    return livro->titulo;
}

const char* getAutor(Livro* livro) {
    return livro->autor;
}

int getAnoPublicacao(Livro* livro) {
    return livro->anoPublicacao;
}

double getPreco(Livro* livro) {
    return livro->preco;
}

int getDisponivel(Livro* livro) {
    return livro->disponivel;
}

// Função para inicializar um livro
void inicializarLivro(Livro* livro, const char* titulo, const char* autor, int anoPublicacao, double preco) {
    setTitulo(livro, titulo);
    setAutor(livro, autor);
    setAnoPublicacao(livro, anoPublicacao);
    setPreco(livro, preco);
    setDisponivel(livro, 1);  // Por padrão, o livro está disponível
}

// Função para emprestar o livro
void emprestar(Livro* livro) {
    if (getDisponivel(livro)) {
        setDisponivel(livro, 0);
        printf("Livro emprestado: %s\n", getTitulo(livro));
    } else {
        printf("Livro não disponível para empréstimo.\n");
    }
}

// Função para devolver o livro
void devolver(Livro* livro) {
    setDisponivel(livro, 1);
    printf("Livro devolvido: %s\n", getTitulo(livro));
}

// Função para obter a idade do livro
int obterIdade(Livro* livro, int anoAtual) {
    return anoAtual - getAnoPublicacao(livro);
}

// Função para aplicar desconto no preço do livro
void aplicarDesconto(Livro* livro, double percentual) {
    double novoPreco = getPreco(livro) - getPreco(livro) * (percentual / 100);
    setPreco(livro, novoPreco);
    printf("Preço com desconto: R$ %.2f\n", novoPreco);
}

// Definindo a estrutura Biblioteca
typedef struct {
    Livro livros[MAX_LIVROS];
    int quantidadeLivros;
} Biblioteca;

// Função para inicializar a biblioteca
void inicializarBiblioteca(Biblioteca* biblioteca) {
    biblioteca->quantidadeLivros = 0;
}

// Função para adicionar um livro à biblioteca
void adicionarLivro(Biblioteca* biblioteca, Livro livro) {
    if (biblioteca->quantidadeLivros < MAX_LIVROS) {
        biblioteca->livros[biblioteca->quantidadeLivros++] = livro;
        printf("Livro adicionado: %s\n", getTitulo(&livro));
    } else {
        printf("Não há espaço para mais livros.\n");
    }
}

// Função para buscar um livro por título
Livro* buscarLivroPorTitulo(Biblioteca* biblioteca, const char* titulo) {
    for (int i = 0; i < biblioteca->quantidadeLivros; i++) {
        if (strcmp(getTitulo(&biblioteca->livros[i]), titulo) == 0) {
            return &biblioteca->livros[i];
        }
    }
    return NULL; // Livro não encontrado
}

// Função para listar livros disponíveis
void listarLivrosDisponiveis(Biblioteca* biblioteca) {
    printf("Livros disponíveis:\n");
    for (int i = 0; i < biblioteca->quantidadeLivros; i++) {
        if (getDisponivel(&biblioteca->livros[i])) {
            printf("%s - %s\n", getTitulo(&biblioteca->livros[i]), getAutor(&biblioteca->livros[i]));
        }
    }
}

// Função para calcular o valor total dos livros
double calcularValorTotal(Biblioteca* biblioteca) {
    double valorTotal = 0.0;
    for (int i = 0; i < biblioteca->quantidadeLivros; i++) {
        valorTotal += getPreco(&biblioteca->livros[i]);
    }
    return valorTotal;
}

int main() {
    // Criando a biblioteca
    Biblioteca biblioteca;
    inicializarBiblioteca(&biblioteca);

    // Criando livros
    Livro livro1, livro2, livro3;
    inicializarLivro(&livro1, "O Senhor dos Anéis", "J.R.R. Tolkien", 1954, 59.90);
    inicializarLivro(&livro2, "1984", "George Orwell", 1949, 39.90);
    inicializarLivro(&livro3, "A Revolução dos Bichos", "George Orwell", 1945, 29.90);

    // Adicionando livros à biblioteca
    adicionarLivro(&biblioteca, livro1);
    adicionarLivro(&biblioteca, livro2);
    adicionarLivro(&biblioteca, livro3);

    // Listando livros disponíveis
    listarLivrosDisponiveis(&biblioteca);

    // Emprestando um livro
    emprestar(&livro1);

    // Tentando listar livros disponíveis novamente
    listarLivrosDisponiveis(&biblioteca);

    // Devolvendo o livro
    devolver(&livro1);

    // Listando livros disponíveis novamente
    listarLivrosDisponiveis(&biblioteca);

    // Aplicando desconto no livro
    aplicarDesconto(&livro1, 10);

    // Calculando o valor total de todos os livros na biblioteca
    printf("Valor total dos livros: R$ %.2f\n", calcularValorTotal(&biblioteca));

    return 0;
}
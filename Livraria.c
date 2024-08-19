#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  // Para usar strcasecmp

struct Livro 
{
    char titulo[100];
    char autor[100];
    char genero[50];
    char isbn[14];
    int quantidade;
    float preco;
};

void pesquisarLivro(struct Livro livros[], int quantidadeTotal, char parametro[], char tipoBusca[]) //função de pesquisa de livro no sistema
{
    int encontrado = 0; //já é atribuído o valor de 0 como se o livro não existisse no sistema

    for (int i = 0; i < quantidadeTotal; i++) //a repetição passa de livro por livro cadastrado
    {
        if ((strcmp(tipoBusca, "titulo") == 0 && strcasecmp(livros[i].titulo, parametro) == 0) ||
            (strcmp(tipoBusca, "autor") == 0 && strcasecmp(livros[i].autor, parametro) == 0) ||
            (strcmp(tipoBusca, "genero") == 0 && strcasecmp(livros[i].genero, parametro) == 0) ||
            (strcmp(tipoBusca, "isbn") == 0 && strcasecmp(livros[i].isbn, parametro) == 0)) //a condição verifica se o parametro e o tipo de busca são iguais
        {
            
            printf("\n\nLivro encontrado:\n");
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Genero: %s\n", livros[i].genero);
            printf("ISBN: %s\n", livros[i].isbn);
            printf("Quantidade em estoque: %d\n", livros[i].quantidade);
            printf("Preco: R$ %.2f\n\n", livros[i].preco);
            
            encontrado = 1;
            break;  // Encerra o loop ao encontrar o livro
        }
    }

    if (!encontrado)  // Se Encontrado=0, quer dizer que o sistema não encontrou o livro
    { 
        printf("\nLivro não encontrado.\n");
    }
}

void removerLivro(struct Livro livros[], int quantidadeTotal, char parametro[], char tipoBusca[]) //função de remover livro no sistema
{
    int encontrado = 0; //já é atribuído o valor de 0 como se o livro não existisse no sistema

    for (int i = 0; i < quantidadeTotal; i++) //a repetição passa de livro por livro cadastrado
    {
        if ((strcmp(tipoBusca, "titulo") == 0 && strcasecmp(livros[i].titulo, parametro) == 0) ||
            (strcmp(tipoBusca, "isbn") == 0 && strcasecmp(livros[i].isbn, parametro) == 0)) //a condição verifica se o parametro e o tipo de busca são iguais
        {
            
            printf("\n\nRemovendo livro %s do sistema\n...\n...\n...\nLivro removido com sucesso", parametro);
            
            encontrado = 1;
            break;  // Encerra o loop ao encontrar o livro
        }
    }

    if (!encontrado)  // Se Encontrado=0, quer dizer que o sistema não encontrou o livro
    { 
        printf("\nLivro não encontrado.\n");
    }
}

void disponibilidade(struct Livro livros[], int quantidadeTotal, char parametro[], char tipoBusca[]) //função de quantidade de exemplares de um livro no sistema
{
    int encontrado = 0; //já é atribuído o valor de 0 como se o livro não existisse no sistema

    for (int i = 0; i < quantidadeTotal; i++) //a repetição passa de livro por livro cadastrado
    {
        if ((strcmp(tipoBusca, "titulo") == 0 && strcasecmp(livros[i].titulo, parametro) == 0) ||
            (strcmp(tipoBusca, "isbn") == 0 && strcasecmp(livros[i].isbn, parametro) == 0)) //a condição verifica se o parametro e o tipo de busca são iguais
        {
            
            printf("\n\nA livraria possui %d exemplares do livro %s\n", livros[i].quantidade, parametro);
            
            encontrado = 1;
            break;  // Encerra o loop ao encontrar o livro
        }
    }

    if (!encontrado)  // Se Encontrado=0, quer dizer que o sistema não encontrou o livro
    { 
        printf("\nLivro não encontrado.\n");
    }
}

void reabastecer(struct Livro livros[], int quantidadeTotal, char parametro[], char tipoBusca[]) //função de reabastecer exemplares de livros no sistema
{
    int encontrado = 0; //já é atribuído o valor de 0 como se o livro não existisse no sistema

    for (int i = 0; i < quantidadeTotal; i++) //a repetição passa de livro por livro cadastrado
    {
        if ((strcmp(tipoBusca, "titulo") == 0 && strcasecmp(livros[i].titulo, parametro) == 0) ||
            (strcmp(tipoBusca, "isbn") == 0 && strcasecmp(livros[i].isbn, parametro) == 0)) //a condição verifica se o parametro e o tipo de busca são iguais
        {
            
            printf("\n\nA livraria possui %d exemplares do livro %s\n", livros[i].quantidade, parametro);
            printf("Deseja colocar quantos exemplares a mais? ");
            int exemplares;
            scanf("%d", &exemplares);
            printf("Adicionando exemplares no sistema\n...\n...\n...\nAgora o livro %s possui %d exemplares", parametro, livros[i].quantidade+exemplares);
            
            encontrado = 1;
            break;  // Encerra o loop ao encontrar o livro
        }
    }

    if (!encontrado)  // Se Encontrado=0, quer dizer que o sistema não encontrou o livro
    { 
        printf("\nLivro não encontrado.\n");
    }
}

void venda(struct Livro livros[], int quantidadeTotal, char parametro[], char tipoBusca[]) //função de registrar venda no sistema e atualizar estoque
{
    int encontrado = 0; //já é atribuído o valor de 0 como se o livro não existisse no sistema

    for (int i = 0; i < quantidadeTotal; i++) //a repetição passa de livro por livro cadastrado
    {
        if ((strcmp(tipoBusca, "titulo") == 0 && strcasecmp(livros[i].titulo, parametro) == 0) ||
            (strcmp(tipoBusca, "isbn") == 0 && strcasecmp(livros[i].isbn, parametro) == 0)) //a condição verifica se o parametro e o tipo de busca são iguais
        {
            
            printf("\n\nA livraria possui %d exemplares do livro %s\n", livros[i].quantidade, parametro);
            printf("Quantos livros seram vendidos? ");
            int exemplares;
            scanf("%d", &exemplares);
            printf("Venda sendo registrada\n...\n...\n...\nAgora o livro %s possui %d exemplares", parametro, livros[i].quantidade-exemplares);
            
            encontrado = 1;
            break;  // Encerra o loop ao encontrar o livro
        }
    }

    if (!encontrado)  // Se Encontrado=0, quer dizer que o sistema não encontrou o livro
    { 
        printf("\nLivro não encontrado.\n");
    }
}

float receita(struct Livro livros[], int quantidadeTotal) 
{
    int op;
    float receitaTotal = 0.0;

    printf("\nDeseja calcular a receita de qual tipo?\n1 - Um livro\n2 - Vários livros\nDigite: ");
    scanf("%d", &op);

    if(op == 1) 
    {
        char tipoBusca[10], parametro[100];
        int encontrado = 0;
        int exemplares;

        printf("\nEscreva o tipo de busca (titulo ou isbn): "); 
        scanf("%s", tipoBusca); //define qual método de busca o usuário deseja
        
        if (strcmp(tipoBusca, "titulo") != 0 && strcmp(tipoBusca, "isbn") != 0) // Verifique se o tipo de busca é válido
        {
            printf("Tipo de busca invalido.\n");
            return receitaTotal;
        }

        printf("Escreva o %s: ", tipoBusca);
        scanf(" %[^\n]", parametro); //define qual parametro o usuario deseja(título do livro em questão ou seu isbn)

        for (int i = 0; i < quantidadeTotal; i++) 
        {
            if ((strcmp(tipoBusca, "titulo") == 0 && strcasecmp(livros[i].titulo, parametro) == 0) ||
                (strcmp(tipoBusca, "isbn") == 0 && strcasecmp(livros[i].isbn, parametro) == 0)) //compara o que o usuário digitou no sistema com oque está armazenado
            {
                printf("Quantos livros serão vendidos? ");
                if (scanf("%d", &exemplares) != 1 || exemplares < 0) //define quantos exemplares serão contados e compara se é válido(aior que 0)
                {
                    printf("Quantidade inválida. Por favor, insira um número inteiro positivo.\n");
                    return receitaTotal;
                }

                if (exemplares <= livros[i].quantidade) //se os exemplares digitados for menor que  a quantidade presente no sistema, o computador efetua faz a conta
                {
                    receitaTotal = exemplares * livros[i].preco;
                    printf("Receita para %d exemplares do livro %s: R$ %.2f\n", exemplares, parametro, receitaTotal);
                } 
                else 
                {
                    printf("Quantidade de exemplares insuficiente.\n");
                }
                
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) 
        { 
            printf("Livro não encontrado.\n");
        }
    }
    else if(op == 2) 
    {
        int exemplares;
        char parametro[100];
        float receitaParcial;
        int encontrado;

        printf("Para calcular a receita de vários livros, insira as seguintes informações para cada livro:\n");
        
        do
        {
            printf("\nEscreva o título ou ISBN do livro (ou digite 'fim' para terminar): ");
            scanf(" %[^\n]", parametro);

            if (strcasecmp(parametro, "fim") == 0) //se o usuário digitar fim, a repetição se encerra
            {
                break;
            }

            encontrado = 0;
            for (int i = 0; i < quantidadeTotal; i++) 
            {
                if ((strcasecmp(livros[i].titulo, parametro) == 0) ||
                    (strcasecmp(livros[i].isbn, parametro) == 0)) 
                {
                    printf("Quantos livros serão vendidos? ");
                    if (scanf("%d", &exemplares) != 1 || exemplares < 0) 
                    {
                        printf("Quantidade inválida. Por favor, insira um número inteiro positivo.\n");
                        return receitaTotal;
                    }

                    if (exemplares <= livros[i].quantidade) 
                    {
                        receitaParcial = exemplares * livros[i].preco;
                        receitaTotal += receitaParcial;
                        printf("Receita para %d exemplares do livro %s: R$ %.2f\n", exemplares, parametro, receitaParcial);
                    } 
                    else 
                    {
                        printf("Quantidade de exemplares insuficiente para o livro %s.\n", parametro);
                    }

                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado) 
            { 
                printf("Livro não encontrado: %s.\n", parametro);
            }
        }
        while (1); // Continue até o usuário digitar "fim"
    }
    else 
    {
        printf("Opção inválida.\n");
    }

    return receitaTotal;
}


int main() 
{
    struct Livro livros[] = {
    {"O Senhor dos Anéis", "J.R.R. Tolkien", "Fantasia", "1234567890123", 10, 59.90},
    {"1984", "George Orwell", "Distopia", "9876543210987", 8, 45.50},
    {"A Revolução dos Bichos", "George Orwell", "Sátira", "1122334455667", 5, 39.90},
    {"Dom Quixote", "Miguel de Cervantes", "Clássico", "1234432112344", 7, 49.90},
    {"O Pequeno Príncipe", "Antoine de Saint-Exupéry", "Fábula", "9988776655443", 15, 29.90},
    {"Crime e Castigo", "Fiódor Dostoiévski", "Romance", "4455667788991", 6, 54.80},
    {"O Hobbit", "J.R.R. Tolkien", "Fantasia", "2233445566778", 12, 44.90},
    {"Orgulho e Preconceito", "Jane Austen", "Romance", "3344556677889", 9, 38.50},
    {"Cem Anos de Solidão", "Gabriel García Márquez", "Realismo Mágico", "5566778899001", 8, 48.90},
    {"Moby Dick", "Herman Melville", "Aventura", "6677889900112", 4, 52.30}
    };

    int quantidadeTotal = 10; //vamos fazer de conta que exista apenas 10 livros no sistema da livraria
    int senha = 123, senhaUsuario;
    char repetir;

    char nome[100]; 

    printf("\tLIVRARIA CEFA'S\n\n");
    printf("Ola, qual eh o seu nome? ");
    scanf(" %[^\n]", nome);
    printf("\nOla, %s\n", nome);

    int op;

    printf("\nAntes de prosseguirmos, precisamos saber se voce eh funcionario ou cliente...");
    printf("\n1 - Funcionario\n2 - Cliente\nDigite a opcao: ");
    scanf("%d", &op);

    if(op == 1) 
    {
        printf("\nAntes de prosseguirmos, precisamos que voce digite a senha do sistema: ");
        scanf("%d", &senhaUsuario);

        while (senha != senhaUsuario)
        {
            printf("Senha incorreta, tente novamente: ");
            scanf("%d", &senhaUsuario);
        }
        
        int setor;
        printf("\nQual o seu setor?\n1 - Vendedor\n2 - Administracao\n3 - Estoque\nDigite: ");
        scanf("%d", &setor); //usuário digita qual setor ele pertence

        if(setor == 1) //opção de vendedor
        {
            do
            {
                int opp;
                printf("\nO que deseja fazer?");
                printf("\n\n\tMENU\n\n1 - Pesquisar dados de livro\n2 - Remover livro do sistema\n3 - Disponibilidade de exemplar\n4 - Registro de venda");
                printf("\nDigite: "); //usuário escolhe oque ele quer fazer no sistema
                scanf("%d", &opp);

                if(opp == 1) //opção de pesquisar o livro no sistema
                {
                    char tipoBusca[10], parametro[100];
                    printf("\nEscreva o tipo de busca (titulo, autor, genero, isbn): ");
                    scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                    printf("Escreva o %s: ", tipoBusca);
                    scanf(" %[^\n]", parametro); //usuário 

                    pesquisarLivro(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de pesquisa de livro no sistema
                }

                else if(opp == 2) //opção de remover livro do sistema
                {
                    char tipoBusca[10], parametro[100];
                    printf("\nEscreva o tipo de busca (titulo ou isbn): ");
                    scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                    printf("Escreva o %s: ", tipoBusca);
                    scanf(" %[^\n]", parametro); //usuário digita o titulo ou isbn do livro

                    removerLivro(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de pesquisa de livro no sistema
                }

                else if(opp == 3) //opção de quantidade de exemplares de um livro a loja possui
                {
                    char tipoBusca[10], parametro[100];
                    printf("\nEscreva o tipo de busca (titulo ou isbn): ");
                    scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                    printf("Escreva o %s: ", tipoBusca);
                    scanf(" %[^\n]", parametro); //usuário digita o titulo ou isbn do livro

                    disponibilidade(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de disponibilidade de livro no sistema
                }

                else if(opp == 4) //opção de registro de venda
                {
                    char tipoBusca[10], parametro[100];
                    printf("\nEscreva o tipo de busca (titulo ou isbn): ");
                    scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                    printf("Escreva o %s: ", tipoBusca);
                    scanf(" %[^\n]", parametro); //usuário digita o titulo ou isbn do livro

                    venda(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de disponibilidade de livro no sistema
                }


                printf("\nDeseja algo mais?(s/n) ");
                scanf("%s", &repetir);

            }while (repetir == 's');
            
        }

        else if(setor == 2) // opção de administração
        {
            do
            {
                int opp;
                printf("\nO que deseja fazer?");
                printf("\n\n\tMENU\n\n1 - Calcular Receita");
                printf("\nDigite: "); //usuário escolhe oque ele quer fazer no sistema
                scanf("%d", &opp);

                if(opp == 1) 
                {
                    float total = receita(livros, quantidadeTotal);
                    printf("A livraria teve uma receita de R$ %.2f no período escolhido\n", total);
                }


                printf("\nDeseja algo mais?(s/n) ");
                scanf("%s", &repetir);

            }while (repetir == 's');

        }

        else if(setor == 3) //opção de estoque
        {
            do
            {
                int opp;
                printf("\nO que deseja fazer?");
                printf("\n\n\tMENU\n\n1 - Pesquisar dados de livro\n2 - Reabastecer estoque");
                printf("\nDigite: "); //usuário escolhe oque ele quer fazer no sistema
                scanf("%d", &opp);

                if(opp == 1) //opção de pesquisar o livro no sistema
                {
                    char tipoBusca[10], parametro[100];
                    printf("\nEscreva o tipo de busca (titulo, autor, genero, isbn): ");
                    scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                    printf("Escreva o %s: ", tipoBusca);
                    scanf(" %[^\n]", parametro); //usuário 

                    pesquisarLivro(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de pesquisa de livro no sistema
                }

                if(opp == 2) //opção de reabastecer o estoque
                {
                    char tipoBusca[10], parametro[100];
                    printf("\nEscreva o tipo de busca (titulo, autor, genero, isbn): ");
                    scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                    printf("Escreva o %s: ", tipoBusca);
                    scanf(" %[^\n]", parametro); //usuário 

                    reabastecer(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de reabastecer estoque
                }


                printf("\nDeseja algo mais?(s/n) ");
                scanf("%s", &repetir);

            }while (repetir == 's');

        }
    } 
    
    else if(op == 2) //opção cliente
    {
        do
        {
            int opp;
            printf("\nQuerido cliente, o que deseja fazer?");
            printf("\n\n\tMENU\n\n1 - Pesquisar dados de livro\n");
            printf("Digite: ");
            scanf("%d", &opp); //usuário escolhe oque ele quer fazer no sistema

            if(opp == 1) //opção de pesquisar o livro no sistema
            {
                char tipoBusca[10], parametro[100];
                printf("\nEscreva o tipo de busca (titulo, autor, genero, isbn): ");
                scanf("%s", tipoBusca); //usuário escolhe o tipo de busca
                printf("Escreva o %s: ", tipoBusca);
                scanf(" %[^\n]", parametro); //usuário digita o titulo ou autor ou genero ou isbn do livro

                pesquisarLivro(livros, quantidadeTotal, parametro, tipoBusca); //chama a função de pesquisa de livro no sistema
            }

            printf("\nDeseja algo mais?(s/n) ");
            scanf("%s", &repetir);

        }while (repetir == 's');
    } 
    
    else 
    {
        printf("OPÇÃO INVÁLIDA"); //se o usuário escolher uma opção fora do apresentado (funcionário ou cliente)
        return 1;
    }

    return 0;
}
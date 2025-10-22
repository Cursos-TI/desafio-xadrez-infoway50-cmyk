#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// --- INÍCIO: Nível Mestre - Funções Recursivas ---

/* Função recursiva para a Torre: move 'passos' casas para a direita.
   A cada chamada imprime "Direita" e chama recursão com passos-1. */
void torre_recursiva(int passos) {
    // Condição de parada: quando não há mais passos a dar, a função retorna.
    if (passos <= 0) {
        return;
    }
    // Ação: imprime o movimento atual.
    printf("Direita\n");
    // Chamada recursiva: chama a si mesma com o problema reduzido (passos - 1).
    torre_recursiva(passos - 1);
}

/* Função recursiva para a Rainha: move 'passos' casas para a esquerda.
   A cada chamada imprime "Esquerda" e chama recursão com passos-1. */
void rainha_recursiva(int passos) {
    // Condição de parada.
    if (passos <= 0) {
        return;
    }
    // Ação.
    printf("Esquerda\n");
    // Chamada recursiva.
    rainha_recursiva(passos - 1);
}

/* Função recursiva para o Bispo:
   Implementa recursividade e, por requisito, usa loops aninhados onde o
   loop externo representa o movimento vertical (Cima) e o interno o
   movimento horizontal (Direita). Para cada passo recursivo imprime uma
   combinação "Cima Direita" utilizando os loops aninhados. */
void bispo_recursivo(int passos) {
    // Condição de parada.
    if (passos <= 0) {
        return;
    }

    /* Loop externo (vertical) e interno (horizontal).
       Aqui cada iteração combinada corresponde a uma casa na diagonal. */
    for (int vertical = 0; vertical < 1; vertical++) {      /* loop mais externo: vertical */
        for (int horizontal = 0; horizontal < 1; horizontal++) { /* loop interno: horizontal */
            printf("Cima Direita\n");
        }
    }

    /* Chamada recursiva para o próximo passo diagonal */
    bispo_recursivo(passos - 1);
}

// --- FIM: Nível Mestre - Funções Recursivas ---


int main() {
    // --- INÍCIO: Nível Novato - Movimentação das Peças ---
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.
    int torre_passos = 5;    /* Torre: 5 casas para a direita */
    int bispo_passos = 5;    /* Bispo: 5 casas na diagonal cima-direita */
    int rainha_passos = 8;   /* Rainha: 8 casas para a esquerda */


    // --- INÍCIO: Nível Mestre - Chamadas Recursivas ---
    // Sugestão: Substitua as movimentações das peças por funções recursivas.

    // Implementação de Movimentação da Torre
    printf("Torre:\n");
    torre_recursiva(torre_passos);

    // Implementação de Movimentação do Bispo
    printf("\nBispo:\n");
    bispo_recursivo(bispo_passos);

    // Implementação de Movimentação da Rainha
    printf("\nRainha:\n");
    rainha_recursiva(rainha_passos);

    // --- FIM: Nível Mestre - Chamadas Recursivas ---


    // --- INÍCIO: Nível Aventureiro/Mestre - Movimentação do Cavalo ---
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    printf("\nCavalo:\n");

    int cavalo_movimentos = 4;      /* número de movimentos em L a simular */
    int casas_para_cima = 2;        /* duas casas para cima por movimento em L */
    int casas_para_direita = 1;     /* uma casa para direita por movimento em L */

    /* Loop externo (for) controla quantos movimentos em L serão feitos.
       Dentro dele, há um while que usa duas variáveis (up_i e guard) e
       condições compostas; demonstra continue/break para controlar o
       fluxo sem afetar a intenção: sempre imprimir 'Cima' duas vezes,
       depois imprimir 'Direita' uma vez. */
    for (int mov = 0; mov < cavalo_movimentos; mov++) {
        int up_i = 0;       /* contador real de passos para cima efetuados */
        int guard = 0;      /* variável auxiliar que participa da condição */
        /* while com condição composta; loop aninhado que move para cima */
        while (up_i < casas_para_cima && guard < 10) {
            /* exemplo de uso de continue: se guard for 5 (situação artificial
               de controle), incrementamos guard e pulamos para próxima iteração
               sem alterar up_i (não muda a lógica principal do movimento). */
            if (guard == 5) {
                guard++;
                continue; /* demonstra controle de fluxo */
            }

            /* imprime cada casa percorrida para cima */
            printf("Cima\n");
            up_i++;
            guard++;

            /* exemplo de uso de break: condição de segurança que interrompe
               o loop interno em caso de um comportamento inesperado. */
            if (guard > 100) {
                break;
            }
        }

        /* Após completar os dois passos para cima, mover uma casa para a direita.
           Utilizamos um loop for aninhado (dentro do for externo) para a etapa
           horizontal, possibilitando expansão caso casas_para_direita > 1. */
        for (int r = 0; r < casas_para_direita; r++) {
            printf("Direita\n");
        }
    }

    // --- FIM: Nível Aventureiro/Mestre - Movimentação do Cavalo ---

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void push(int[], int*, int);
int pop(int[], int*);
void calcularOperacao(int[], int*);

int main() {
    int pilha[MAX];
    int topo = -1; 
    
    push(pilha, &topo, '*');
    push(pilha, &topo, 4);
    push(pilha, &topo, 2);
    calcularOperacao(pilha, &topo); 
    return 0;
}

void push(int pilha[], int *pTopo, int valor) {
    if (*pTopo == MAX - 1) {
        printf("ERRO! Pilha Cheia.");
        exit(1); 
    } else {
        (*pTopo)++;
        pilha[*pTopo] = valor;
    }
}

int pop(int pilha[], int *pTopo) {
    if (*pTopo == -1) {
        printf("ERRO! Pilha vazia.");
        exit(1); 
    } else {
        int valor = pilha[*pTopo];
        (*pTopo)--;
        return valor;
    }
}

void calcularOperacao(int pilha[], int *pTopo) {
    int op1, op2;
    char operador;
    
    op2 = pop(pilha, pTopo);
    op1 = pop(pilha, pTopo);
    operador = (char)pop(pilha, pTopo);
    
    switch (operador) {
        case '+':
            printf("Resultado: %d\n", op1 + op2);
            break;
        case '-':
            printf("Resultado: %d\n", op1 - op2);
            break;
        case '*':
            printf("Resultado: %d\n", op1 * op2);
            break;
        case '/':
            if (op2 != 0) {
                printf("Resultado: %d\n", op1 / op2);
            } else {
                printf("Erro! Divisão por zero!\n");
                exit(1); 
            }
            break;
        default:
            printf("Operador inválido: %c\n", operador);
            exit(1);
    }
}


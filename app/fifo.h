#ifndef _FIFO_H_  // Verifica se _FIFO_H_ não foi definido anteriormente
#define _FIFO_H_  // Define _FIFO_H_ para evitar múltiplas inclusões

// Declaração do template com parâmetros N (tamanho do buffer) e T (tipo dos dados)
template<int N, typename T>

class FIFO {
private:
    T data[N];  // Array de dados de tamanho N
    int in;     // Índice de entrada
    int out;    // Índice de saída
    int size;   // Tamanho do buffer (sempre igual a N)
    int count;  // Contador de elementos no buffer

public:
    // Construtor que inicializa os membros da classe
    FIFO() {
        this->size = N;  // Define o tamanho do buffer como N
        this->in = 0;    // Inicializa o índice de entrada
        this->out = 0;   // Inicializa o índice de saída
        this->count = 0; // Inicializa o contador de elementos
    }

    // Método para adicionar um elemento ao buffer
    bool put(T c) {
        if (in == size) {  // Se o índice de entrada atingir o tamanho do buffer
            in = 0;        // Reseta o índice de entrada
        }
        if (count == size) {   // Se o buffer estiver cheio
            return false;  // Retorna false indicando falha na inserção
        }
        data[in] = c;  // Adiciona o elemento no índice de entrada
        in++;          // Incrementa o índice de entrada
        count++;       // Incrementa o contador de elementos
        return true;   // Retorna true indicando sucesso na inserção
    }

    // Método para remover um elemento do buffer
    T get() {
        if (out == size) {  // Se o índice de saída atingir o tamanho do buffer
            out = 0;        // Reseta o índice de saída
        }
        if (count == 0) {    // Se o buffer estiver vazio
            return 0;       // Retorna 0 indicando falha na remoção
        }
        T c = data[out];  // Obtém o elemento no índice de saída
        out++;            // Incrementa o índice de saída
        count--;          // Decrementa o contador de elementos
        return c;         // Retorna o elemento removido
    }

    // Método para obter a contagem de elementos no buffer
    int getCount() {
        return count;  // Retorna o contador de elementos
    }

    int getSize() {
        return size;
    }

    void pop(){
        if (out == size) {  // Se o índice de saída atingir o tamanho do buffer
            out = 0;        // Reseta o índice de saída
        }
        if (count == 0) {    // Se o buffer estiver vazio
            return;       // Retorna 0 indicando falha na remoção
        }
        out++;            // Incrementa o índice de saída
        count--;          // Decrementa o contador de elementos
    }
};

#endif 
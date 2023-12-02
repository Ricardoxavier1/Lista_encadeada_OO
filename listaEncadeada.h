

class listaEncadeada{
    private:
        class No{
            public:
                int dado;
                No* proximo;
                
                No(int dado){
                    this -> dado = dado;
                }

                No(int dado, No* prox){
                    this -> dado = dado;
                    this -> proximo = prox;
                }
        };

        int qtd;
        No* primeiro;
        No* ultimo;


    public:
        listaEncadeada();    
        ~listaEncadeada();    

        bool anexar(int elemento);
        bool inserir(int elemento, int posicao);
        bool substituir(int posicao, int elemento);
        int removerPorElemento(int elemento);
        bool removerPorPosicao(int posicao, int &removido);
        int tamanho();
        int buscarPorElemento(int elemento);
        int buscarPorPosicao(int posicao);
        void imprimir();

};
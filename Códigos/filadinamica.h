// Fila Dinamica = Dynamic Queue

typedef int TipoItem;

class No
{
    public:
    TipoItem valor; // Quem está inserindo
    No* proximo; //Endereço do proximo
};

class filadinamica{
    private:
    No* primeiro; //front
    No* ultimo; //rear

    public:

    filadinamica(); // construtor
    ~filadinamica(); // destrutor
    bool estavazio(); // isempty
    bool estacheio(); // isfull
    void inserir(TipoItem item); // push
    TipoItem remover(); // pop
    void imprimir(); // print
};
#include <string>

enum class TipoTema { Academico = 'A', Pessoal = 'P'};

class Tema
{
private:
    unsigned _id;
    std::string _nome;
    TipoTema _tipo;
public:
    Tema(/* args */);
    ~Tema();
};

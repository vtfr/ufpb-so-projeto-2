#ifndef PROJETO_SO_2_LRU
#define PROJETO_SO_2_LRU

#include <pagina.hpp> // Paginador
#include <cstddef> // std::size_t

// PaginaLRU é uma página usada pelo LRU que contém o número de acessos
struct PaginaLRU {
  int pagina;
  int rodada;

  // Retorna se a página é a mesma
  inline bool operator==(int p) const {
    return pagina == p;
  }

  // Retorna quem tem a menor rodada
  inline bool operator<(const PaginaLRU& rhs ) {
    return rodada < rhs.rodada;
  }
};

// Define o que é uma página vazia no contexto das páginas LRU
constexpr PaginaLRU PaginaVaziaLRU { PaginaVazia, -1 };

// PaginadorLRU realiza paginação via LRU
class PaginadorLRU : public Paginador {
public:
  PaginadorLRU(std::size_t tamanho);

  bool acessar(int pagina);

private:
  int rodadaAtual = 0;
  std::vector<PaginaLRU> memory;
};

#endif // PROJETO_SO_2_LRU

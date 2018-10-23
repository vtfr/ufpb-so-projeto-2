#ifndef PROJETO_SO_2_FIFO
#define PROJETO_SO_2_FIFO

#include <pagina.hpp>
#include <cstddef> // std::size_t

// FIFO é um Paginador que mantêm uma queue de tamanho constante onde cada
// inserção remove o último elemento
class PaginadorFIFO : public Paginador {
public:
  PaginadorFIFO(std::size_t tamanho);

  // Acessa uma página. Retorna true caso ela tenha sido encontrada
  bool acessar(int pagina);

private:
  std::vector<int> memory;
};

#endif // PROJETO_SO_2_FIFO

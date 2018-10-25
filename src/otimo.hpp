#ifndef PROJETO_SO_2_OTM
#define PROJETO_SO_2_OTM

#include <pagina.hpp>
#include <cstddef> // std::size_t

// PaginadorOtimo é um Paginador que sabe exatamente qual página remover
// visando a maior duração das páginas no sistema.
class PaginadorOtimo : public Paginador {
public:
  PaginadorOtimo(std::size_t tamanho,
    std::vector<int>::const_iterator futuroBegin,
    std::vector<int>::const_iterator futuroEnd);

  // Acessa uma página. Retorna true caso ela tenha sido encontrada
  bool acessar(int pagina);

protected:
  // Insere no lugar da página carregada mais distante
  void inserir(int pagina);

private:
  std::vector<int> memory;
  std::vector<int>::const_iterator futuroBegin;
  std::vector<int>::const_iterator futuroEnd;
};

#endif // PROJETO_SO_2_OTM

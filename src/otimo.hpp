#ifndef PROJETO_SO_2_OTM
#define PROJETO_SO_2_OTM

#include <pagina.hpp>
#include <cstddef> // std::size_t

// PaginadorOtimo é um Paginador que sabe exatamente qual página remover
// visando a maior duração das páginas no sistema.
class PaginadorOtimo : public Paginador {
public:
  PaginadorOtimo(std::size_t tamanho, const std::vector<int>& acessos);

  // Acessa uma página. Retorna true caso ela tenha sido encontrada
  bool acessar(int pagina);

protected:
  // Insere na posição certa
  void inserir(int pagina);

  // Retorna a posição de memória em que deverá ser escrito a página,
  // prevendo o futuro.
  int& prevePosicaoMemoria();

private:
  std::vector<int> memory;

  std::vector<int> futuro;
  int indexFuturo;
};

#endif // PROJETO_SO_2_OTM

#ifndef PROJETO_SO_2_PAGINA
#define PROJETO_SO_2_PAGINA

#include <vector>

// Constante que representa uma página vazia
constexpr int PaginaVazia = -1;

// Paginador é toda classe que implementa a função de acesso de página
class Paginador {
public:
  // Acessa uma página. Retorna true caso ela tenha sido encontrada
  virtual bool acessar(int pagina) = 0;

  // Realiza um paginamento com um paginador qualquer
  static int paginar(const std::vector<int>& acessos, Paginador* paginador);
};

#endif // PROJETO_SO_2_PAGINA

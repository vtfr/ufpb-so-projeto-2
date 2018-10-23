#include <otimo.hpp>

#include <debug.hpp> // debug_message
#include <algorithm> // std::find

PaginadorOtimo::PaginadorOtimo(std::size_t tamanho, const std::vector<int>& acessos)
  : memory{ }
  , futuro{ acessos }
  , indexFuturo{ 0 }
{
  memory.resize(tamanho);
  for (auto& pagina : memory)
    pagina = PaginaVazia;
}

// Acessa uma página. Retorna true caso ela tenha sido encontrada
bool PaginadorOtimo::acessar(int pagina) {
  indexFuturo++;

  // Procura uma página.
  if (std::find(memory.begin(), memory.end(), pagina) != memory.end()) {
    return true;
  }

  // Procura qual será a página mais próxima de ser removida
  inserir(pagina);
  return false;
}

void PaginadorOtimo::inserir(int pagina) {
  prevePosicaoMemoria() = pagina;
}

int& PaginadorOtimo::prevePosicaoMemoria() {
  // Procura me toda a memória qual será a posição menos usada lendo o futuro.
  int menorPagina = PaginaVazia;
  int menorDistancia = std::numeric_limits<int>::max();

  for (auto& paginaNaMemoria : memory) {
    const auto acesso = std::find(futuro.begin() + indexFuturo, futuro.end(), paginaNaMemoria);

    // Caso não haja mais acesso dessa página na memória, retorna ela
    if (acesso == futuro.end()) {
      debug_message("[OTM] Não há mais referências para " << paginaNaMemoria);
      return paginaNaMemoria;
    }

    const auto distancia = futuro.begin() - acesso;
    debug_message("[OTM] Pagina " << paginaNaMemoria << ": " << distancia);

    if (distancia < menorDistancia) {
      menorPagina = paginaNaMemoria;
      menorDistancia = distancia;
    }
  }

  debug_message("[OTM] Pagina mais Próxima " << menorPagina << ": " << menorDistancia);
  auto pagina = std::find(memory.begin(), memory.end(), menorPagina);
  return *pagina;
}

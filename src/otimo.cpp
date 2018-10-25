#include <otimo.hpp>

#include <debug.hpp> // debug_message
#include <algorithm> // std::find
#include <iterator> // std::distance

PaginadorOtimo::PaginadorOtimo(std::size_t tamanho,
  std::vector<int>::const_iterator futuroBegin,
  std::vector<int>::const_iterator futuroEnd)
    : memory(tamanho, PaginaVazia)
    , futuroBegin(futuroBegin)
    , futuroEnd(futuroEnd)
{ }

// Acessa uma página. Retorna true caso ela tenha sido encontrada
bool PaginadorOtimo::acessar(int pagina) {
  futuroBegin++;

  // Procura uma página.
  if (std::find(memory.begin(), memory.end(), pagina) != memory.end()) {
    return true;
  }

  // Procura qual será a página mais próxima de ser removida
  inserir(pagina);
  return false;
}

void PaginadorOtimo::inserir(int pagina) {
  debug_message("[OTM] Iniciando busca pela página mais distante... ");

  // Inicialmente atribui um valor vazio a página mais distante
  auto paginaSubstituicao = memory.begin();
  auto maiorDistancia = 0;

  // Inicia busca pela posição da memória mais distante. Começa iterando toda
  // a memória atual
  for (auto it = memory.begin(); it != memory.end(); it++) {
    // Busca a referência mais próxima para a página desejada nos acessos
    // futuros
    const auto acesso = std::find(futuroBegin, futuroEnd, *it);

    // Caso o acesso nunca ocorra no futuro, então é essa a página. Substitui
    // ela pela página desejada e retorna
    if (acesso == futuroEnd) {
      debug_message("[OTM] Página " << *it << " nunca mais referenciada. Substituindo.");

      *it = pagina;
      return;
    }

    const auto distancia = std::distance(futuroBegin, acesso);
    if (distancia > maiorDistancia) {
      paginaSubstituicao = it;
      maiorDistancia = distancia;
    }
  }

  // Substitui a página mais distante pela página desejada
  debug_message("[OTM] Pagina mais distante: " << *paginaSubstituicao
    << " [" << maiorDistancia << "]");
  *paginaSubstituicao = pagina;
  return;
}

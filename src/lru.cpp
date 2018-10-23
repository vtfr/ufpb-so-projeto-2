#include <lru.hpp>
#include <debug.hpp> // debug_message
#include <algorithm> // std::find

PaginadorLRU::PaginadorLRU(std::size_t tamanho)
  : memory(tamanho, PaginaVaziaLRU)
{ }

bool PaginadorLRU::acessar(int pagina) {
  // Incrementa a rodada para indicar que o tempo passou
  rodadaAtual++;

  // Procura se a página existe
  auto p = std::find(memory.begin(), memory.end(), pagina);
  if (p != memory.end()) {
    debug_message("[LRU] Modificando ultimo acesso");
    p->rodada = rodadaAtual;
    return true;
  }

  // Procura menor página para inserir
  auto menor = std::min_element(memory.begin(), memory.end());
  debug_message("[LRU] Menor página encontrada: " << menor->pagina);
  *menor = PaginaLRU{ pagina, rodadaAtual };

  return false;
}

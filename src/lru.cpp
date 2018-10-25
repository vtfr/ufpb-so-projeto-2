#include <lru.hpp>
#include <debug.hpp> // debug_message
#include <algorithm> // std::find

PaginadorLRU::PaginadorLRU(std::size_t tamanho)
  : memory(tamanho, PaginaVaziaLRU)
{ }

bool PaginadorLRU::acessar(int pagina) {
  // Incrementa a rodada para indicar que o tempo passou
  rodadaAtual++;

  // Procura se a página existe. Caso exista, atualiza seu último acesso para
  // a rodada atual
  auto paginaEncontrada = std::find(memory.begin(), memory.end(), pagina);
  if (paginaEncontrada != memory.end()) {
    debug_message("[LRU] Página encontrada. Modificando ultimo acesso");
    paginaEncontrada->rodada = rodadaAtual;

    return true;
  }

  // Procura a página com a menor rodada para inserir
  auto menor = std::min_element(memory.begin(), memory.end());
  debug_message("[LRU] Menor página encontrada: " << menor->pagina << " ["
    << menor->rodada << "]");

  menor->pagina = pagina;
  menor->rodada = rodadaAtual;
  return false;
}

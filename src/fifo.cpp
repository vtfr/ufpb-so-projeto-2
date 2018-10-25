#include <fifo.hpp>

#include <algorithm> // std::find
#include <debug.hpp> // debug_message

PaginadorFIFO::PaginadorFIFO(std::size_t tamanho)
  : memory(tamanho, PaginaVazia)
{ }

// FIFO é um Paginador que mantêm uma queue de tamanho constante onde cada
// inserção remove o último elemento
bool PaginadorFIFO::acessar(int pagina) {
  // Procura uma página.
  if (std::find(memory.begin(), memory.end(), pagina) != memory.end())
    return true;

  debug_message("[FIFO] Rodando memória e inserindo página")

  // Caso a página não tenha sido encontrada, move todos os elementos para a
  // esquerda e, no final, insere a página necessária
  std::rotate(memory.begin(), memory.begin() + 1, memory.end());
  memory.back() = pagina;

  return false;
}

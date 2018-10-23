#include <fifo.hpp>

#include <algorithm> // std::find

PaginadorFIFO::PaginadorFIFO(std::size_t tamanho)
  : memory{ }
{
  memory.resize(tamanho);
  for (auto& pagina : memory)
    pagina = PaginaVazia;
}

// FIFO é um Paginador que mantêm uma queue de tamanho constante onde cada
// inserção remove o último elemento
bool PaginadorFIFO::acessar(int pagina) {
  // Procura uma página.
  if (std::find(memory.begin(), memory.end(), pagina) != memory.end())
    return true;

  // Caso a página não tenha sido encontrada, move todos os elementos para a
  // esquerda e, no final, insere a página necessária
  const int tamanho = memory.size() - 1;
  for (int i = 0; i < tamanho; i++)
    memory[i] = memory[i + 1];
  memory[tamanho] = pagina;

  return false;
}

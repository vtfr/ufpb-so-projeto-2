/*
 * Victor Franco Vieira Lima - 11411786
 */

#include <debug.hpp> // debug_message
#include <pagina.hpp> // Paginador
#include <otimo.hpp> // PaginadorOtimo
#include <lru.hpp> // PaginadorLRU
#include <fifo.hpp> // PaginadorFIFO
#include <iostream> // std::cout std::cin
#include <vector>

int main() {
  std::size_t quadros;
  std::vector<int> acessos;

  // Lê número de quadros
  if (!(std::cin >> quadros)) {
    debug_message("[main] Falha lendo o número de quadros");
    return 1;
  }

  debug_message("[main] Número de quadros: " << quadros);

  // Lê páginas
  int pagina;
  while (std::cin >> pagina) {
    acessos.push_back(pagina);

    if (pagina < 0) {
      debug_message("[main] Falha lendo página negativa");
      return 1;
    }
  }

  // Executa paginação
  debug_message("[main] Executando FIFO");
  const int falhasFIFO = (PaginadorFIFO { quadros }).paginar(acessos);

  debug_message("[main] Executando OTM");
  const int falhasOTM = (PaginadorOtimo { quadros, acessos.cbegin(),
    acessos.cend() }).paginar(acessos);

  debug_message("[main] Executando LRU");
  const int falhasLRU = (PaginadorLRU { quadros }).paginar(acessos);

  std::cout
    << "FIFO " << falhasFIFO << std::endl
    << "OTM " << falhasOTM << std::endl
    << "LRU " << falhasLRU << std::endl;

  return 0;
}

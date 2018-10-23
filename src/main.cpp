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
  PaginadorFIFO fifo { quadros };
  PaginadorLRU lru { quadros };
  PaginadorOtimo otm { quadros, acessos };

  std::cout << "FIFO " << Paginador::paginar(acessos, &fifo) << std::endl;
  std::cout << "OTM " << Paginador::paginar(acessos, &otm) << std::endl;
  std::cout << "LRU " << Paginador::paginar(acessos, &lru) << std::endl;

  return 0;
}

#include <pagina.hpp>
#include <debug.hpp> // debug_message
#include <algorithm> // std::count_if

// Realiza um paginamento com um paginador qualquer e retorna o número de
// falhas
int Paginador::paginar(const std::vector<int>& acessos) {
  return std::count_if(acessos.cbegin(), acessos.cend(),
    [this](int i) {
      debug_message("[Paginar] Acessando página: " << i);
      return !this->acessar(i);
    });
}

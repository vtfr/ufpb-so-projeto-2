#include <pagina.hpp>
#include <debug.hpp>

// Realiza um paginamento com um paginador qualquer
int Paginador::paginar(const std::vector<int>& acessos, Paginador* paginador) {
  int falhas = 0;

  // Para todos os acessos, tenta paginar usando o paginador em questão,
  // contanto o número de falhas
  for (auto acesso : acessos) {
    debug_message("[Paginar] Acessando página: " << acesso);
    if (!paginador->acessar(acesso)) {
      debug_message("[Paginar] Página não encontrada: " << acesso);
      falhas++;
    }
  }

  return falhas;
}

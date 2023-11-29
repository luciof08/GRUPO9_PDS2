#include <string>
#include "FormaDePagamento.hpp"

/// @brief Classe utilitária para as formas de pagamento.
class FormaDePagamentoUtil {

public:
    /// @brief Converte o valor da enumeração em formato texto (string). Lança a exceção FormaDePagamentoInvalida caso não consiga converter.
    /// @param forma o objeto do tipo FormaDePagamento
    /// @return string da conversão.
    static std::string toString(FormaDePagamento forma);

};

# Decisões técnicas

Irei explicar aqui um pouco sobre as decisões técnicas utilizadas para construir o sistema.

## Controller

No controller, temos o método `available` que processa o pedido da _view_ para retornar a lista com nomes dos restaurantes disponíveis em uma dada hora. Por ser o intermediário entre a _view_ e o _service_ na aplicação, fica responsável por compreender os tipos de dados que cada camada trabalha. A _view_ com: `QStringList` e `QString`. A _service_ com classes padrão de `C++` e demais classes da aplicação.
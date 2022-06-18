# Decisões técnicas

Irei explicar aqui um pouco sobre as decisões técnicas utilizadas para construir o sistema.

## Controller

No controller, temos o método `available` que processa o pedido da _view_ para retornar a lista com nomes dos restaurantes disponíveis em uma dada hora. Por ser o intermediário entre a _view_ e o _service_ na aplicação, fica responsável por compreender os tipos de dados que cada camada trabalha. A _view_ com: `QStringList` e `QString`. A _service_ com classes padrão de `C++` e demais classes da aplicação.

## Service

Em resumo, esta camada é responsável por executar a regra de negócio do desafio: filtrar restaurantes abertos em uma dada hora.

Nesta camada temos a classe `AvailableRestaurants` que se comunica com a camada de acesso aos dados para recuperar todos os restaurantes e então selecionar aqueles abertos na hora desejada.

Isso ocorre com uma simples verificação direta sobre a entidade `Restaurant` para saber se o mesmo está aberto naquela dada hora para então, se esse for o caso, adicionar o nome do mesmo na lista de nomes a ser retornada para o `controller`.

## Data (DAO)

Esta camada contém uma classe que recebe como argumento no construtor o caminho para o arquivo com os dados necessários para este desafio (`restaurant-hours.csv`).

> OBS.: Esse path é fixo, pois o arquivo se encontra junto com a solução na pasta `data`. A princípio, eu não colocaria os dados junto da aplicação, nem deixaria esse caminho para o arquivo fixo. Contudo, achei uma forma simples de ter acesso aos dados para o cenário deste desafio.
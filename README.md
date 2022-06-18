# Aditum Challenge

Este é um desafio que faz parte do processo seletivo para a empresa **Aditum**.

## Desafio

O desafio consiste no seguinte: **com base no CSV em anexo**, construa um método que receba uma hora do dia como input no formato HH:MM, sendo HH entre 1 e 24 e MM entre 00 e 60, e retorne uma lista de strings com os nomes dos restaurantes que estão abertos nessa hora. Exemplo: availableHours("restaurant-hours.csv", "17:45"); retornando ["RestaurantA", "RestaurantB"].

A aplicação deve possuir UI feita com um input de hora para ser passado ao método availableHours e exibir o resultados do método em um componente de tela à sua escolha.

**Atenção:** O CSV em anexo não é simplesmente a estrutura que dita como será mapeado a sua classe de Restaurante, **o arquivo CSV vai ser um parâmetro no seu método que processa o arquivo CSV**. Não precisa se preocupar com time zones, vamos supor que todas as horas são locais. O time espera que você entregue os requisitos mínimos:

- Funcionar;
- Suíte de testes unitários que sejam relevantes;
- README explicando como funciona o projeto e o por que das suas escolhas e também uma documentação do seu código.

O que será avaliado:

- Qualidade do código (funcionalidade, manutenibilidade, desempenho);
- Arquitetura;
- Testes de unidade;
- Utilização do Git.

O desafio deve ser entregue usando o **Qt 5.15.0** num **repositório público do GitHub** para que o time possa avaliar a qualidade da sua entrega.

A implementação da UI deve ser feita em **QML** e o método availableHours deve estar em **C++**.

## Documentação

- [Arquitetura](https://github.com/patrickpiresdev/aditum-challenge/blob/master/docs/architecture/architecture.md)
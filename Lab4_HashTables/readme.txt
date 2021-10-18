A função de hash escolhida realiza a soma de termos de acordo com o valor ASCII de cada caractere
da palavra.

    Função: c0.a^k-1 + c1.a^k-2 + ... + ck-2.a^1 + ck-1.a^0, onde c é o ASCII do caractere, a é um número primo
escolhido arbitrariamente e k é um número que decresce de acordo com o tamanho da palavra.

Por exemplo, para o nome IAGO, a série será:

    I = 73
    A = 65
    G = 71
    O = 79

    (73 x 3^3) + (65 x 3^2) + (71 x 3^1) + (79 x 3^0)

Após, o valor encontrado é divido pelo número de entradas da tabela hash, onde o valor inteiro obtido será o
índice em que a palavra será inserida.

Para a resolução de conflitos, o método utilizado é o fechado, onde para cada entrada da tabela haverá uma lista.
Cada novo nome é inserido no final da lista no endereço correspondente ao índice calculado pela função hash. Ou seja,
a resolução de conflitos se mantém dentro da própria tabela hash.
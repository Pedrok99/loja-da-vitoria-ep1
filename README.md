# EP1 - OO 2019.2 (UnB - Gama)

## Descrição

Victoria possui um pequeno comércio que atende a população de seu bairro. Com o passar do tempo, a pequena empreendedora foi adquirindo experiência e, por conta de seu excelente poder de negociação, ela conseguia reduzir significativamente o preço dos produtos oferecidos.

Entretanto, apenas preços baixos não eram o bastante para manter a clientela. Em uma noite de inspiração, Victoria pensou em duas estratégias para atrair mais pessoas:
- Oferecer descontos de 15% para clientes sócios;
- Oferecer produtos recomendados exclusivamente para cada cliente;

Para colocar as ideias em prática, ela deve abandonar seu velho hábito de utilizar seu estimado caderninho para gerenciar sua loja. Uma amiga te recomendou para desenvolver um *software* que ajude o estabelecimento a implementar as novas estratégias de negócio. Com a sua ajuda, **todas as vendas serão realizadas pelo computador operado por uma funcionária**. Em uma breve conversa com Victoria, foi possível entender algumas características importantes do sistema:
- Victoria está aprendendo C++ em um curso online e, portanto, prefere que o sistema seja feito nesta linguagem para que ela consiga fazer as próprias manutenções quando necessário;
- Devem existir três modos de operação do sistema:
    - **Modo venda**
    - **Modo recomendação**
    - **Modo estoque**

### Modo venda
Em relação ao modo venda, deve-se observar os seguintes pontos:
- Antes de cada venda, deve ser possível inserir os dados do cliente para identificar se ele é sócio ou não;
- Caso o cliente não possuir cadastro, ele é feito antes da compra;
- A cada compra, deve ser possível colocar vários produtos no carrinho;
- No fim da compra, devem ser exibidas na tela as seguintes informações:
    - Lista de produtos vendidos, a quantidade e seus respectivos valores;
    - Valor total dos produtos;
    - Valor do desconto oferecido;
    - Valor final da venda;
- Ao fim, caso a compra apresente algum produto em quantidade maior que a existente no estoque, ela deve ser cancelada sem alterar o estoque e uma mensagem de erro deve ser apresentada;

Para evitar o recadastro de clientes, Victoria deseja que os dados de cadastro sejam salvos em arquivos. Assim, será possível acessar os dados mesmo que se encerre a execução do programa.

### Modo estoque
Para manter o estoque do estabelecimento, deve ser possível cadastrar novos produtos (não haverá a necessidade de se deletar produtos, apenas de se atualizar sua quantidade). Além disso, para evitar o recadastro de produtos e categorias, os dados devem ser armazenados em arquivos.

Aqui estão alguns aspectos importantes deste modo:
- Há várias categorias de produtos existentes no estabelecimento e, sempre que possível, Victoria tenta trazer coisas novas (O número de categorias não é fixo mas, assim como no caso dos produtos, não será necessário deletar nenhuma categoria);
- Um produto pode pertencer a mais de uma categoria;

### Modo recomendação
Para listar os itens recomendados para cada cliente, Victoria pensou em uma solução bem simples. A cada compra, é possível identificar a categoria de cada produto. Com este dado, é possível saber qual categoria que mais interessa o cliente.

Neste modo, também há alguns pontos a serem considerados:
- Ao entrar no modo recomendação, deve ser possível inserir os dados do cliente para buscar os produtos recomendados exclusivamente;
- Caso o cliente não possuir cadastro, uma mensagem de erro deve ser mostrada;
- A lista de recomendações deve ter as seguintes características:
    - Até 10 produtos;
    - Ordenados de acordo com o grau de recomendação (mais recomendados primeiro, menos recomendados por último);
    - Caso o grau de recomendação for o mesmo, o critério de ordenação deve obedecer a ordem lexicográfica;

## Dicas

### Ordenação customizada em C++

Descrição #TODO

```c++
sort(vector.begin(), vector.end(), [](int a, int b){
    return a < b;
})
```

### Algoritmo de recomendação

Descrição e imagens #TODO

### Escrita e leitura em arquivo

Descrição e code snippet #TODO

### C++ Vector

Descrição #TODO

```c++
#include <bits/stdc++.h>

int main(){
    std::vector<int> v;

    v.push_back(1); // [1]
    v.push_back(2); // [1, 2]

    std::cout << v[1] << std::endl;

    return 0;
}
```
Output:
```
2
```

### Auto for loop (C++ 11)

Descrição #TODO

```c++
#include <bits/stdc++.h>

int main(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // Imprimindo todos os valores do vetor
    for(auto &valor : v){
        std::cout << valor << std::endl;
    }
}
```
Output:
```
1
2
```
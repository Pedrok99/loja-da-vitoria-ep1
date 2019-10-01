#EP1 - OO 2019.2 (UnB - Gama)

##Loja da Victoria

Pedro Henrique Vieira de Lima

18/0129287

###Descrição :

    O programa apresenta 3 funções principais : Modo venda, onde o usuário tem 
acesso aos produtos, modo estoque, para a reposição de mercadorias e adição de
outras novas e o modo recomendação, onde baseado em compras passadas, o software
recomenda ao usuário produtos que provavelmente o usuário tende a comprar.

###Modo Venda:

	Ao acessar o modo venda, será solicitado o CPF do cliente caso já seja 
cadastrado. Caso ainda não possua cadastro, o mesmo será feito antes que o 
usuário seja redirecionado ao catálogo de produtos. Para o cadastro de novos 
clientes, é necessário apenas o nome, cpf, idade e uma opção para torná-lo sócio
ou não. Após o cadastro, o catálogo aparecerá, permitindo que o cliente adicione
inúmeros produtos a seu carrinho. Ao final, caso seja sócio, receberá um 
desconto de 15 % no valor total.

###Modo Estoque:

	Acessando o modo estoque, será permitido ao usuário definir novos produtos
ou atualizar a quantidade de produtos já existentes. Ao acrescentar novos produtos,
será solicitado que o usuário especifique as categorias dos mesmos. Não é 
possível retirar produtos e nem editá-los, apenas atualizar sua quantidade.

###Modo Recomendação:

	No modo recomendação, o usuário informa o cpf do cliente e lhe será fornecido
uma lista de produtos que, baseado em sua frequência de compras na loja,
irá recomendar produtos semelhantes aos produtos comprados pelo cliente.


###Bibliotecas e comandos:

    O software pode ser executado através do Make. Os menus são baseados em 
indices numéricos. Além das classes criadas, o software tem como dependências as
seguintes bibliotecas:

Iostream, Strings, Vector, Fstream, Ctime e Random.

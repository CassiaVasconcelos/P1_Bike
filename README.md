# P1_Bike
Sistema de gerenciamento de aluguer de bicicletas para o IPL para a cadeira de Prog. I


Resumo: Programa em C para gerir uso de bicicletas entre os campi do IPL. Os campi referidos são: as Residências, os Campus 1, Campus 2 e Campus 5. Quando um usuário quiser efetuar o empréstimo de uma bicicleta, o mesmo deverá indicar para qual campus tem intenção de ir e qual é seu campus atual. SE houver bicicletas disponíveis no campus atual, o empréstimo será efetuado. SE NÃO houver, o usuário entrará em uma fila de espera. APÓS chegar ao campus destino, o usuário devolve a bicicleta.

Elementos:

->15 Bicicletas:
	.designação única (ID da bicicleta automático) -> função de geração automática de ID de Bicicleta
	.nome
	.modelo
	.status, que pode ser 1-disponível, 2-emprestada ou 3-danificada
	.campus que se localiza(1,2,5,3).
	
->Usuário(máximo 50):
	.código (ID do usuário automático) -> função de geração automática de ID de Usuário
	.nome
	.telefoness
	.tipo (estudante, docente, técnico administrativo ou convidado).
	
->Empréstimo:
	.número de registro, criado automaticamente (ID do empréstimo automático) -> função de geração automática de ID de Empréstimo
	.código do usuário (ID do usuário)
	.código da bicicleta (ID da bicicleta)
	.data e hora do empréstimo (função para pegar hora/data do sistema) 
		|» ("https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program")
	.campus de origem
	.campus de destino
		->Após devolução (fazer outra estrutura dentro de Empréstimo):
			.data e hora da devolução (função para pegar hora/data do sistema)
			.distância percorrida.

->Lista de espera: vetor dinâmico que contém os pedidos de empréstimo em espera de uma bicicleta
Algoritmo Geral:
Apresentação de um menu onde pode-se (dividir em submenus):
	- Informações sobre: Usuários atuais			- Empréstimos registrados
	- Distância total já percorrida				- Empréstimos em espera.

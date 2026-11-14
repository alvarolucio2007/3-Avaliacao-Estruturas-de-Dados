from typing import Any

from sistema.estruturas import PilhaGenerica
from sistema.funcoes import FilaReservas, GrafoCampi
from sistema.livro import Livro


class Sistema:
    def __init__(self) -> None:
        self.contador_livro_id=0
        self.lista_livros:list[Livro]=[]
        self.dict_livros:dict[int,Livro]={}
        self.fila_reserva=FilaReservas()
        self.pilha_emprestimo:PilhaGenerica[Livro]=PilhaGenerica([])
        self.grafo_campi=GrafoCampi()

    def render_menu(self)->int:
        print("\n Menu Principal")
        print("Por favor selecione a operação que deseja fazer. ")
        print("1 - Criar Livro ")
        print("2 - Procurar Livro por ID ")
        print("3 - Procurar Livro por Nome ")
        print("4 - Reservar Livro ")
        print("5 - Listar as reservas de um livro ")
        print("6 - Emprestar Livro ")
        print("7 - Desfazer o último empréstimo do Livro ")
        print("8 - Transferir livro de um Campus para outro ")
        print("9 - Listar campi alcançáveis em até 2 transferências ")
        print("10 - Sair ")
        while True:
            try:
                res=int(input("Por favor, selecione a opção"))
                if 1<=res<=10:
                    return res
            except ValueError:
                print("Por favor, insira apenas numeros de 1 a 9!")
    def criar_livro(self) -> None:
        nome = input("Por favor, insira o nome do livro: ")
        while True:
            try:
                valor = float(input("Por favor, insira o preço do livro: "))
                if valor <= 0:
                    raise ValueError("Por favor, insira um preço maior que 0!")
                estoque = int(input("Por favor, insira o estoque do livro: "))
                if estoque < 0:
                    raise ValueError("Por favor, insira um estoque maior ou igual a 0!")
                emprestado = input("O livro foi emprestado? (s/n): ")
                if emprestado.strip().lower() not in ["s", "n"]:
                    raise ValueError("Por favor, insira apenas s (sim) ou n (não)")

                emprestado = emprestado.strip().lower() == "s"

                # Incrementa o contador corretamente
                self.contador_livro_id += 1
                livro = Livro(
                    id=self.contador_livro_id,
                    nome=nome,
                    valor=valor,
                    estoque=estoque,
                    emprestado=emprestado
                )
                break
            except ValueError as e:
                print(e if str(e) else "Por favor, insira valores válidos!")
        self.lista_livros.append(livro)
        self.dict_livros[livro.id] = livro
        print(f"Livro '{livro.nome}' criado com sucesso com o ID {livro.id}!")
    def procurar_por_id(self)->None:
        while True:
            try:
                id=int(input("Por favor, selecione um ID"))
                if id>0:
                    livro=self.dict_livros.get(id)
                    if livro is not None:
                        print(f"O nome do livro é {livro.nome}")
                        return
                    else:
                        print("Livro não existe.")
                        return
                raise ValueError
            except ValueError:
                print("Por favor, insira apenas numeros maiores que zero!")
    def procurar_por_titulo(self)->None:
        titulo=input("Por favor, insira o título do livro")
        print(f"O livro {titulo} existe." if any(l.nome == titulo for l in self.lista_livros) else "O livro não existe." )
    def reservar_livro(self)->None:
        while True:
            try:
                id=int(input("Por favor, selecione um ID"))
                if id>0:
                    livro=self.dict_livros.get(id)
                    if livro is not None:
                        self.fila_reserva.enfileirar(livro)
                        print(f"livro {livro.nome} foi adicionado com sucesso.")
                        return
                    else:
                        print("Livro não existe.")
            except ValueError:
                print("Por favor, insira apenas numeros maiores que zero!")
    def ler_reservas(self)->None:
        print(self.fila_reserva.desenfileirar())
    def emprestar_livro(self)->None:
        while True:
            try:
                id=int(input("Por favor, selecione um ID"))
                if id>0:
                    livro=self.dict_livros.get(id)
                    if livro is not None:
                        self.pilha_emprestimo.adicionar(livro)
                        print(f"livro {livro.nome} foi adicionado com sucesso.")
                        break
                    else:
                        print("Livro não existe.")
            except ValueError:
                print("Por favor, insira apenas numeros maiores que zero!")
    def remover_ultimo_emprestimo(self)->None:
        try:
            livro=self.pilha_emprestimo.remover()
        except IndexError:
            print("Não há empréstimos.")
            return
        print(f"livro {livro.nome} foi removido com sucesso.")
    def transferir_campus_livro(self) -> None:
            while True:
                try:
                    id = int(input("Por favor, selecione o ID do livro: "))
                    if id <= 0 or id not in self.dict_livros:
                        print("Livro não existe ou ID inválido.")
                        continue

                    livro = self.dict_livros[id]

                    id_campus_origem = int(input("Campus de origem (1, 2 ou 3): "))
                    if id_campus_origem not in [1, 2, 3]:
                        print("Por favor, insira apenas números de 1 a 3 para a origem.")
                        continue
                    self.grafo_campi.adicionar_campus(id_campus_origem)

                    id_campus_destino = int(input("Campus de destino (1, 2 ou 3): "))
                    if id_campus_destino not in [1, 2, 3]:
                        print("Por favor, insira apenas números de 1 a 3 para o destino.")
                        continue

                    if id_campus_destino == id_campus_origem:
                        print("O campus de destino não pode ser igual ao de origem.")
                        continue

                    self.grafo_campi.adicionar_campus(id_campus_destino)
                    self.grafo_campi.adicionar_transferencia(id_campus_origem, id_campus_destino)
                    print(f"Transferência do livro '{livro.nome}' do campus {id_campus_origem} para {id_campus_destino} registrada com sucesso!")
                    return

                except ValueError:
                    print("Por favor, insira apenas números válidos!")
    def campus_alcancaveis_duas_transferencias(self)->None:
        while True:
            try:
                id_campus=int(input("Por favor, selecione o campus de origem do livro (Anexo 1, 2 e 3, apenas números.)"))
                if id_campus>0 and id_campus in [1,2,3]:
                    print(sorted(self.grafo_campi.campi_ate_duas_transferencias(id_campus)))
                    break
                else:
                    print("Por favor, insira apenas números de 1 a 3.")
                    continue
            except ValueError:
                print("Por favor, insira apenas numeros maiores que zero!")

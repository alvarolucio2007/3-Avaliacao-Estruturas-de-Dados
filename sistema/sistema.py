from sistema.estruturas import PilhaGenerica
from sistema.funcoes import FilaReservas
from sistema.livro import Livro


class Sistema:
    def __init__(self) -> None:
        self.contador_livro_id=0
        self.lista_livros:list[Livro]=[]
        self.dict_livros:dict[int,Livro]={}
        self.fila_reserva=FilaReservas

    def render_menu(self)->int:
        print("Menu Principal")
        print("Por favor selecione a operação que deseja fazer.")
        print("1 - Criar Livro")
        print("2 - Procurar Livro por ID")
        print("3 - Procurar Livro por Nome")
        print("4 - Reservar Livro")
        print("5 - Listar as reservas de um livro")
        print("6 - Emprestar Livro")
        print("7 - Desfazer o último empréstimo do Livro")
        print("8 - Transferir livro de um Campus para outro")
        print("9 - Listar campi alcançáveis em até 2 transferências")
        print("10 - Sair")
        while True:
            try:
                res=int(input("Por favor, selecione a opção"))
                if 1<=res<=10:
                    return res
            except ValueError:
                print("Por favor, insira apenas numeros de 1 a 9!")
    def criar_livro(self)->None:
        nome=input("Por favor, insira o nome do livro")
        while True:
            try:
                valor=float(input("Por favor, insira o preço do livro"))
                if valor<=0:
                    raise ValueError("Por favor, insira um preço maior que 0!")
                estoque=int(input("Por favor, insira o estoque do livro"))
                if estoque<0:
                    raise ValueError("Por favor, insira um estoque maior ou igual a 0!")
                emprestado=input("O livro foi emprestado? (s/n)")
                if emprestado.strip().lower() not in ['s','n']:
                    raise ValueError("Por favor, insira apenas s (sim) ou n (não)")
                emprestado=emprestado.strip().lower()=='s'
                livro=Livro(id=self.contador_livro_id+1,nome=nome,valor=valor,estoque=estoque,emprestado=emprestado)
                break
            except ValueError:
                pass
        self.lista_livros.append(livro)  # pyright: ignore[reportPossiblyUnboundVariable]
        self.dict_livros[livro.id]=livro  # pyright: ignore[reportPossiblyUnboundVariable]
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

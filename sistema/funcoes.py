from sistema.livro import Livro


def buscar_por_codigo(dicionario:dict[int,Livro],id:int)->Livro|None:
    return dicionario.get(id, None)
def buscar_por_titulo(lista_livros:list[Livro],nome:str)->Livro|None:
    for livro in lista_livros:
        if nome==livro.nome:
            return livro
    return None
# A fazer: Funcoes de pilha, grafo e fila.

# Sistema de biblioteca precisa das seguintes estruturas:
# D1:HashMap (mapa), python ja tem, ent posso usar o propio do python
# D2: Busca em lista simples, python tambem ja tem
# D3: Fila
# D4: Pilha
# D5: Grafo

class PilhaGenerica[T]:
    def __init__(self,lista_elementos:list[T]|None=None) -> None:
        self.lista_elementos = lista_elementos if lista_elementos is not None else []
        self.tamanho = len(self.lista_elementos)
    def Adicionar(self,elemento:T)->None:
        self.lista_elementos.append(elemento)
        self.tamanho+=1
    def Remover(self)->T:
        if not self.lista_elementos:
            raise IndexError("Pilha vazia")
        self.tamanho-=1
        return self.lista_elementos.pop()

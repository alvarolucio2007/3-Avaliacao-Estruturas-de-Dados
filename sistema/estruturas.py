# Sistema de biblioteca precisa das seguintes estruturas:
# D1: HashMap (mapa), python ja tem, ent posso usar o propio do python
# D2: Busca em lista simples, python tambem ja tem
# D3: Fila
# D4: Pilha (feita)
# D5: Grafo (A fazer)

from collections import deque


class PilhaGenerica[T]:
    def __init__(self,lista_elementos:list[T]|None=None) -> None:
        self.lista_elementos = lista_elementos if lista_elementos is not None else []
        self.tamanho = len(self.lista_elementos)
    def adicionar(self,elemento:T)->None:
        self.lista_elementos.append(elemento)
        self.tamanho+=1
    def remover(self)->T:
        if not self.lista_elementos:
            raise IndexError("Pilha vazia")
        self.tamanho-=1
        return self.lista_elementos.pop()

class GrafoGenerico[T]:
    def __init__(self,gdict:dict[T,list[T]]|None=None, direcionado:bool=False) -> None:
        self.gdict=gdict if gdict is not None else {}
        self.direcionado=direcionado
    def adicionar_vertice(self,vertice:T)->None:
        if vertice not in self.gdict:
            self.gdict[vertice]=[]
    def adicionar_edge(self,u:T, v:T)->None:
        self.adicionar_vertice(u)
        self.adicionar_vertice(v)
        if v not in self.gdict[u]:
            self.gdict[u].append(v)
        if not self.direcionado and u not in self.gdict[v]:
            self.gdict[v].append(u)
    def get_vizinhos(self,vertice:T)->list[T]|None:
        return self.gdict.get(vertice,[])
    def __str__(self) -> str:
        resultado=[]
        for vertice,vizinho in self.gdict.items():
            resultado.append(f"{vertice} -> {vizinho}")
        return "\n".join(resultado)
    def distancia(self, inicio: T, destino: T) -> int:
        if inicio not in self.gdict or destino not in self.gdict:
            return -1
        if inicio == destino:
            return 0
        fila = deque([(inicio, 0)])
        visitados = {inicio}

        while fila:
            atual, dist = fila.popleft()
            if atual == destino:
                return dist
            for vizinho in self.gdict[atual]:
                if vizinho not in visitados:
                    visitados.add(vizinho)
                    fila.append((vizinho, dist + 1))
        return -1

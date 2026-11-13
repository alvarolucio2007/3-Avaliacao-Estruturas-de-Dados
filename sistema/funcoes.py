from sistema.livro import Livro


def buscar_por_codigo(dicionario:dict[int,Livro],id:int)->Livro|None:
    return dicionario.get(id, None)
def buscar_por_titulo(lista_livros:list[Livro],nome:str)->Livro|None:
    for livro in lista_livros:
        if nome==livro.nome:
            return livro
    return None
# A fazer: Funcoes de pilha, grafo e fila.

# FILA
class No:
    def __init__(self, matricula):
        self.matricula = matricula
        self.proximo = None


class FilaReservas:

    def __init__(self):
        self.inicio = None
        self.fim = None
        self.tamanho = 0

    def esta_vazia(self):
        return self.inicio is None

    def enfileirar(self, matricula):
        novo = No(matricula)

        if self.esta_vazia():
            self.inicio = novo
        else:
            self.fim.proximo = novo

        self.fim = novo
        self.tamanho += 1

    def desenfileirar(self):
        if self.esta_vazia():
            return None

        matricula = self.inicio.matricula
        self.inicio = self.inicio.proximo
        self.tamanho -= 1

        if self.inicio is None:
            self.fim = None

        return matricula

    def consultar_proximo(self):
        if self.esta_vazia():
            return None
        return self.inicio.matricula

    def __len__(self):
        return self.tamanho

class ReservasBiblioteca:
    def __init__(self):
        self.filas_por_livro = {}

    def reservar(self, codigo_livro, matricula):
        if codigo_livro not in self.filas_por_livro:
            self.filas_por_livro[codigo_livro] = FilaReservas()

        self.filas_por_livro[codigo_livro].enfileirar(matricula)

    def atender_devolucao(self, codigo_livro):
        fila = self.filas_por_livro.get(codigo_livro)

        if fila is None or fila.esta_vazia():
            return None

        return fila.desenfileirar()

    def proximo_da_fila(self, codigo_livro):
        fila = self.filas_por_livro.get(codigo_livro)

        if fila is None:
            return None

        return fila.consultar_proximo()


## Grafo de campi

class GrafoCampi:

    def __init__(self):
        self.adjacencias = {}

    def adicionar_campus(self, campus):
        if campus not in self.adjacencias:
            self.adjacencias[campus] = set()

    def adicionar_transferencia(self, campus_a, campus_b):
        self.adicionar_campus(campus_a)
        self.adicionar_campus(campus_b)

        self.adjacencias[campus_a].add(campus_b)
        self.adjacencias[campus_b].add(campus_a)

    def campi_ate_duas_transferencias(self, origem):
        if origem not in self.adjacencias:
            return set()

        distancias = {origem: 0}
        fila = [origem]
        inicio_fila = 0

        while inicio_fila < len(fila):
            atual = fila[inicio_fila]
            inicio_fila += 1

            if distancias[atual] == 2:
                continue

            for vizinho in self.adjacencias[atual]:
                if vizinho not in distancias:
                    distancias[vizinho] = distancias[atual] + 1
                    fila.append(vizinho)

        return {
            campus
            for campus, distancia in distancias.items()
            if 1 <= distancia <= 2
        }

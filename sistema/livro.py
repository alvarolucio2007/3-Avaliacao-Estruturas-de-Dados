from dataclasses import dataclass


@dataclass
class Livro:
    id:int
    nome:str
    valor_em_centavos:int
    estoque:int
    emprestado:bool

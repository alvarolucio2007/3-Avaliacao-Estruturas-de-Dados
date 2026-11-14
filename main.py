from sistema.sistema import Sistema

sistema=Sistema()
while True:
    opcao=sistema.render_menu()
    match opcao:
        case 1:
            sistema.criar_livro()
        case 2:
            sistema.procurar_por_id()
        case 3:
            sistema.procurar_por_titulo()
        case 4:
            sistema.reservar_livro()
        case 5:
            sistema.ler_reservas()
        case 6:
            sistema.emprestar_livro()
        case 7:
            sistema.remover_ultimo_emprestimo()
        case 8:
            sistema.transferir_campus_livro()
        case 9:
            sistema.campus_alcancaveis_duas_transferencias()
        case 10:
            break

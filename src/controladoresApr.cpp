#include "../include/controladoresApr.hpp"


using namespace std;


void CntrAprInicial::executar()
{
    Conta* conta_ptr = nullptr;
    int entrada_do_usuario;
    while (true)
    {
        cout << "Essa eh a tela inicial. Selecione uma das opcoes abaixo:" << endl;
        cout << "1. Criar conta" << endl;
        cout << "2. Login" << endl;
        cout << "-1. Sair" << endl;
        cin >> entrada_do_usuario;
        switch(entrada_do_usuario)
        {
        case 1:
            this->cntrAprCRUDConta->create(conta_ptr);
        case 2:
            this->cntrAprAutenticacao->autenticar(conta_ptr);
            break;
        case -1: 
            return;
        default:
            std::cout << "Essa opcao nao existe !" << endl;
        }
    }
}

void CntrAprAutenticacao::autenticar(Conta* conta_ptr)
{   
    Codigo codigo; string codigo_string;
    Senha senha; string senha_string;

    cout << "Tela de autenticacao" << endl;
    cout << "Digite o codigo: " << endl; cin >> codigo_string;
    cout << "Digite a senha: " << endl; cin >> senha_string;
    try
    {
        codigo.set_valor(codigo_string);
        senha.set_valor(senha_string);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    conta_ptr->set_codigo(codigo);
    conta_ptr->set_senha(senha);
    //Codigo a ser implementado
    ContainerContas* container_contas = ContainerContas::get_instancia();
    bool autenticado = container_contas->fetch_conta(conta_ptr);
    if (autenticado)
        this->cntrAprCRUDConta->read(conta_ptr);
    else
        {
        cout << "Codigo e/ou senha incorreto(s)" << endl;
        return;
        }
}


void CntrAprCRUDConta::create(Conta* conta_ptr)
{
    cout << "Tela de criacao de conta" << endl;
    Codigo codigo; string codigo_string;
    Senha senha; string senha_string;
    cout << "Codigo da conta: " << endl; cin >> codigo_string;
    cout << "Senha da conta: " << endl; cin >> senha_string;
    try
    {
        codigo.set_valor(codigo_string);
        senha.set_valor(senha_string);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    bool ja_existe = this->cntrSerCUDConta->create(conta_ptr, codigo, senha);
    if (ja_existe)
    {
        cout << "Essa conta ja existe" << endl;
        return;
    }
    else
    {
        cout << "Conta criada com sucesso" << endl;
        return;
    }
}

void CntrAprCRUDConta::read(Conta* conta_ptr)
{
    while (true)
    {
        cout << "Tela de leitura de conta" << endl;
        cout << "Detalhes da conta " << conta_ptr->get_codigo().get_valor() << ":" << endl;
        cout << "Senha da conta: " << conta_ptr->get_senha().get_valor() << endl;
        if (conta_ptr->is_viagem_ptr_empty())
        cout << "Ainda nao ha nenhuma viagem associada a essa conta" << endl;
        else
            {
                cout << "Viagens associadas a essa conta:" << endl;
                for (Viagem* viagem_ptr : conta_ptr->get_viagens_ptr())
                {
                    cout << viagem_ptr->get_nome().get_valor() << "(codigo " <<  viagem_ptr->get_codigo().get_valor() << ")" << endl;
                }
            }
        int entrada_do_usuario;
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar conta" << endl;
        cout << "2. Deletar conta" << endl;
        cout << "3. Escolher Viagem" << endl;
        cout << "-1. Voltar" << endl;

        Codigo viagem_codigo; string viagem_codigo_string;
        Viagem* viagem_ptr = nullptr;
        switch(entrada_do_usuario)
        {
        case 1:
            update(conta_ptr);
            break;
        case 2:
            if(destroy(conta_ptr)) return;
            else break;
        case 3:
            cout << "Digite o codigo da viagem: " << endl;
            
            cin >> viagem_codigo_string;
            try
            {
                viagem_codigo.set_valor(viagem_codigo_string);
            }
            catch(const invalid_argument& e)
            {
                cerr << "Valor inválido" << '\n';
                break;
            }
            viagem_ptr = conta_ptr->get_viagem_ptr(viagem_codigo);
            if (viagem_ptr == nullptr)
            {
                cout << "Viagem nao encontrada" << endl;
                break;
            }
            else this->cntrAprCRUDViagem->read(conta_ptr, viagem_ptr);
            break;
        case -1:
            return;
        }
    }
}

void CntrAprCRUDConta::update(Conta* conta_ptr)
{
    cout << "Tela de atualizacao de conta" << endl;
    cout << "Atualizando conta " << conta_ptr->get_codigo().get_valor() << endl;
    Codigo codigo; string codigo_string;
    Senha senha; string senha_string;
    cout << "Nova senha da conta: " << endl; cin >> senha_string;
    try
    {
        senha.set_valor(senha_string);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDConta->update(conta_ptr, senha);
    cout << "Conta atualizada com sucesso" << endl;
}

bool CntrAprCRUDConta::destroy(Conta* conta_ptr)
{
    cout << "Tela de delecao de conta" << endl;
    cout << "Deletando conta " << conta_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa conta?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    int entrada_do_usuario;
    cin >> entrada_do_usuario;
    switch (entrada_do_usuario)
    {
    case 1:
        this->cntrSerCUDConta->destroy(conta_ptr);
        cout << "Conta deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
    }
}



void CntrAprCRUDViagem::create(Conta* conta_ptr)
{   
    cout << "Tela de criacao de viagem" << endl;
    cout << "Criando viagem para a conta " << conta_ptr->get_codigo().get_valor() << endl;
    Codigo codigo; string codigo_string;;
    Nome nome; string nome_string;
    Avaliacao avaliacao; int avaliacao_int;
    cout << "Codigo da viagem: " << endl; cin >> codigo_string;
    cout << "Nome da viagem: " << endl; cin >> nome_string;
    cout << "Avaliacao da viagem: " << endl; cin >> avaliacao_int;
    try
    {
        codigo.set_valor(codigo_string);
        nome.set_valor(nome_string);
        avaliacao.set_valor(avaliacao_int);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDViagem->create(conta_ptr, codigo, nome, avaliacao);
    cout << "Viagem criada com sucesso" << endl;
}


void CntrAprCRUDViagem::read(Conta* conta_ptr, Viagem* viagem_ptr)
{
    while (true)
    {
        cout << "Tela de leitura de viagem" << endl;
        cout << "Detalhes da viagem " << viagem_ptr->get_codigo().get_valor() << ":" << endl;
        cout << "Nome da viagem: " << viagem_ptr->get_nome().get_valor() << endl;
        cout << "Avaliacao da viagem: " << viagem_ptr->get_avaliacao().get_valor() << endl;
        cout << endl;
        if (viagem_ptr->is_destino_ptr_empty())
            cout << "Ainda nao ha nenhum destino associado a essa viagem" << endl;
        else
            {
                cout << "Destinos associados a essa viagem:" << endl;
                for (Destino* destino_ptr : viagem_ptr->get_destinos_ptr())
                {
                    cout << destino_ptr->get_nome().get_valor() << "(codigo " <<  destino_ptr->get_codigo().get_valor() << ")" << endl;
                }
            }

        int entrada_do_usuario;
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar viagem" << endl;
        cout << "2. Deletar viagem" << endl;
        cout << "3. Escolher destino" << endl;
        cout << "-1. Voltar" << endl;

        Codigo destino_codigo; string destino_codigo_string;
        Destino* destino_ptr = nullptr;
        switch(entrada_do_usuario)
        {
        case 1:
            update(conta_ptr,viagem_ptr);
            break;
        case 2:
            if(destroy(conta_ptr,viagem_ptr)) return;
            else break;
        case 3:
            cout << "Digite o codigo do destino: " << endl;
            
            cin >> destino_codigo_string;
            try
            {
                destino_codigo.set_valor(destino_codigo_string);
            }
            catch(const invalid_argument& e)
            {
                cerr << "Valor inválido" << '\n';
                break;
            }
            destino_ptr = viagem_ptr->get_destino_ptr(destino_codigo);
            if (destino_ptr == nullptr)
            {
                cout << "Destino nao encontrado" << endl;
                break;
            }
            else this->cntrAprCRUDDestino->read(viagem_ptr, destino_ptr);
            break;
        case -1:
            return;
        }
    }
}

void CntrAprCRUDViagem::update(Conta* conta_ptr, Viagem* viagem_ptr)
{   
    cout << "Tela de atualizacao de viagem" << endl;
    cout << "Atualizando viagem da conta " << conta_ptr->get_codigo().get_valor() << endl;
    Nome nome; string nome_string;
    Avaliacao avaliacao; int avaliacao_int;

    cout << "Novo nome da viagem: " << endl;
    cin >> nome_string;
    cout << "Nova avaliacao da viagem: " << endl;
    cin >> avaliacao_int;
    try
    {
        nome.set_valor(nome_string);
        avaliacao.set_valor(avaliacao_int);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDViagem->update(viagem_ptr, nome, avaliacao);
    cout << "Viagem atualizada com sucesso" << endl;
}

bool CntrAprCRUDViagem::destroy(Conta* conta_ptr, Viagem* viagem_ptr)
{
    cout << "Tela de delecao de viagem" << endl;
    cout << "Deletando viagem da conta " << conta_ptr->get_codigo().get_valor() << endl;
    cout << "Nome da viagem: " << viagem_ptr->get_nome().get_valor() << endl;
    cout << "Codigo da viagem: " << viagem_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa viagem?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    int entrada_do_usuario;
    cin >> entrada_do_usuario;
    switch (entrada_do_usuario)
    {
    case 1:
        this->cntrSerCUDViagem->destroy(conta_ptr, viagem_ptr);
        cout << "Viagem deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
    }
}


void CntrAprCRUDDestino::create(Viagem* viagem_ptr)
{
    cout << "Tela de criacao de destino" << endl;
    cout << "Criando destino para a viagem " << viagem_ptr->get_nome().get_valor() << "(codigo " << viagem_ptr->get_codigo().get_valor() << ")" << endl;
    Codigo codigo; string codigo_string;
    Nome nome; string nome_string;
    Data data_inicio; string data_inicio_string;
    Data data_termino; string data_termino_string;
    Avaliacao avaliacao; int avaliacao_int;
    cout << "Codigo do destino: " << endl; cin >> codigo_string;
    cout << "Nome do destino: " << endl; cin >> nome_string;
    cout << "Data de inicio do destino: " << endl; cin >> data_inicio_string;
    cout << "Data de termino do destino: " << endl; cin >> data_termino_string;
    cout << "Avaliacao do destino: " << endl; cin >> avaliacao_int;
    try
    {
        Destino* destino_teste = new Destino();
        codigo.set_valor(codigo_string);
        nome.set_valor(nome_string);
        data_inicio.set_valor(data_inicio_string);
        data_termino.set_valor(data_termino_string);
        avaliacao.set_valor(avaliacao_int);
        destino_teste->set_data_inicio(data_inicio);
        destino_teste->set_data_termino(data_termino);
        delete destino_teste;
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDDestino->create(viagem_ptr, codigo, nome, data_inicio, data_termino, avaliacao);
    cout << "Destino criado com sucesso" << endl;
}

void CntrAprCRUDDestino::read(Viagem* viagem_ptr, Destino* destino_ptr)
{
    while (true)
    {
        cout << "Tela de leitura de destino" << endl;
        cout << "Detalhes do destino " << destino_ptr->get_codigo().get_valor() << ":" << endl;
        cout << "Nome do destino: " << destino_ptr->get_nome().get_valor() << endl;
        cout << "Data de inicio do destino: " << destino_ptr->get_data_inicio().get_valor() << endl;
        cout << "Data de termino do destino: " << destino_ptr->get_data_termino().get_valor() << endl;
        cout << "Avaliacao do destino: " << destino_ptr->get_avaliacao().get_valor() << endl;
        cout << endl;
        if (destino_ptr->is_hospedagem_ptr_empty())
            cout << "Ainda nao ha nenhuma hospedagem associada a esse destino" << endl;
        else
            {
                cout << "Hospedagens associadas a esse destino:" << endl;
                for (Hospedagem* hospedagem_ptr : destino_ptr->get_hospedagens_ptr())
                {
                    cout << hospedagem_ptr->get_nome().get_valor() << "(codigo " <<  hospedagem_ptr->get_codigo().get_valor() << ")" << endl;
                }
            }
        int entrada_do_usuario;
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar Destino" << endl;
        cout << "2. Deletar Destino" << endl;
        cout << "3. Escolher Hospedagem" << endl;
        cout << "4. Escolher Atividade" << endl;
        cout << "-1. Voltar" << endl;

        Codigo codigo; string codigo_string;
        Hospedagem* hospedagem_ptr = nullptr;
        Atividade* atividade_ptr = nullptr;
        switch(entrada_do_usuario)
        {
        case 1:
            update(viagem_ptr, destino_ptr);
            break;
        case 2:
            if(destroy(viagem_ptr,destino_ptr)) return;
            else break;
        case 3:
            cout << "Digite o codigo da hospedagem: " << endl;
            
            cin >> codigo_string;
            try
            {
                codigo.set_valor(codigo_string);
            }
            catch(const invalid_argument& e)
            {
                cerr << "Valor inválido" << '\n';
                break;
            }
            hospedagem_ptr = destino_ptr->get_hospedagem_ptr(codigo);
            if (hospedagem_ptr == nullptr)
            {
                cout << "Hospedagem nao encontrada" << endl;
                break;
            }
            else this->cntrAprCRUDHospedagem->read(destino_ptr, hospedagem_ptr);
            break;
        case 4:
            cout << "Digite o codigo da atividade: " << endl;
            
            cin >> codigo_string;
            try
            {
                codigo.set_valor(codigo_string);
            }
            catch(const invalid_argument& e)
            {
                cerr << "Valor inválido" << '\n';
                break;
            }
            atividade_ptr = destino_ptr->get_atividade_ptr(codigo);
            if (atividade_ptr == nullptr)
            {
                cout << "Atividade nao encontrada" << endl;
                break;
            }
            else this->cntrAprCRUDAtividade->read(destino_ptr, atividade_ptr);
            break;
        case -1:
            return;
        }
    }
}

void CntrAprCRUDDestino::update(Viagem* viagem_ptr, Destino* destino_ptr)
{
    cout << "Tela de atualizacao de destino" << endl;
    cout << "Atualizando destino da viagem " << viagem_ptr->get_nome().get_valor() << endl;
    Nome nome; string nome_string;
    Data data_inicio; string data_inicio_string;
    Data data_termino; string data_termino_string;
    Avaliacao avaliacao; int avaliacao_int;
    cout << "Novo nome do destino: " << endl; cin >> nome_string;
    cout << "Nova data de inicio do destino: " << endl; cin >> data_inicio_string;
    cout << "Nova data de termino do destino: " << endl; cin >> data_termino_string;
    cout << "Nova avaliacao do destino: " << endl; cin >> avaliacao_int;
    try
    {
        Destino* destino_teste = new Destino();
        nome.set_valor(nome_string);
        data_inicio.set_valor(data_inicio_string);
        data_termino.set_valor(data_termino_string);
        avaliacao.set_valor(avaliacao_int);
        destino_teste->set_data_inicio(data_inicio);
        destino_teste->set_data_termino(data_termino);
        delete destino_teste;
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDDestino->update(destino_ptr, nome, data_inicio, data_termino, avaliacao);
    cout << "Destino atualizado com sucesso" << endl;
}

bool CntrAprCRUDDestino::destroy(Viagem* viagem_ptr, Destino* destino_ptr)
{
    cout << "Tela de delecao de destino" << endl;
    cout << "Deletando destino da viagem " << viagem_ptr->get_nome().get_valor() << "(codigo" << viagem_ptr->get_codigo().get_valor() << endl;
    cout << "Nome do destino: " << destino_ptr->get_nome().get_valor() << endl;
    cout << "Codigo do destino: " << destino_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar esse destino?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    int entrada_do_usuario;
    cin >> entrada_do_usuario;
    switch (entrada_do_usuario)
    {
    case 1:
        this->cntrSerCUDDestino->destroy(viagem_ptr, destino_ptr);
        cout << "Destino deletado com sucesso" << endl;
        return true;
    case 2:
        return false;
    }
}



void CntrAprCRUDHospedagem::create(Destino* destino_ptr)
{
    cout << "Tela de criacao de hospedagem" << endl;
    cout << "Criando hospedagem para o destino " << destino_ptr->get_nome().get_valor() << "(codigo " << destino_ptr->get_codigo().get_valor() << ")" << endl;
    Codigo codigo; string codigo_string;
    Nome nome; string nome_string;
    Dinheiro diaria; double diaria_double;
    Avaliacao avaliacao;int avaliacao_int;
    
    cout << "Codigo da hospedagem: " << endl; cin >> codigo_string;
    cout << "Nome da hospedagem: " << endl; cin >> nome_string;
    cout << "Diaria da hospedagem: " << endl; cin >> diaria_double;
    cout << "Avaliacao da hospedagem: " << endl; cin >> avaliacao_int;
    try
    {
        codigo.set_valor(codigo_string);
        nome.set_valor(nome_string);
        diaria.set_valor(diaria_double);
        avaliacao.set_valor(avaliacao_int);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDHospedagem->create(destino_ptr, codigo, nome, diaria, avaliacao);
    cout << "Hospedagem criada com sucesso" << endl;
}

void CntrAprCRUDHospedagem::read(Destino* destino_ptr, Hospedagem* hospedagem_ptr)
{
    while (true)
    {
        cout << "Tela de leitura de hospedagem" << endl;
        cout << "Detalhes da hospedagem " << hospedagem_ptr->get_codigo().get_valor() << ":" << endl;
        cout << "Nome da hospedagem: " << hospedagem_ptr->get_nome().get_valor() << endl;
        cout << "Diaria da hospedagem: " << hospedagem_ptr->get_diaria().get_valor() << endl;
        cout << "Avaliacao da hospedagem: " << hospedagem_ptr->get_avaliacao().get_valor() << endl;
        cout << endl;

        int entrada_do_usuario;
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar hospedagem" << endl;
        cout << "2. Deletar hospedagem" << endl;
        cout << "-1. Voltar" << endl;

        switch(entrada_do_usuario)
        {
        case 1:
            update(destino_ptr, hospedagem_ptr);
            break;
        case 2:
            if(destroy(destino_ptr,hospedagem_ptr)) return;
            else break;
        case -1:
            return;
        }
    }
}

void CntrAprCRUDHospedagem::update(Destino* destino_ptr, Hospedagem* hospedagem_ptr)
{
    cout << "Tela de atualizacao de hospedagem" << endl;
    cout << "Atualizando hospedagem do destino " << destino_ptr->get_nome().get_valor() << endl;
    Nome nome; string nome_string;
    Dinheiro diaria; double diaria_double;
    Avaliacao avaliacao; int avaliacao_int;
    cout << "Novo nome da hospedagem: " << endl; cin >> nome_string;
    cout << "Nova diaria da hospedagem: " << endl; cin >> diaria_double;
    cout << "Nova avaliacao da hospedagem: " << endl; cin >> avaliacao_int;
    try
    {
        nome.set_valor(nome_string);
        diaria.set_valor(diaria_double);
        avaliacao.set_valor(avaliacao_int);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDHospedagem->update(hospedagem_ptr, nome, diaria, avaliacao);
    cout << "Hospedagem atualizada com sucesso" << endl;
}


bool CntrAprCRUDHospedagem::destroy(Destino* destino_ptr, Hospedagem* hospedagem_ptr)
{
    cout << "Tela de delecao de hospedagem" << endl;
    cout << "Deletando hospedagem do destino " << destino_ptr->get_nome().get_valor() << "(codigo" << destino_ptr->get_codigo().get_valor() << endl;
    cout << "Nome da hospedagem: " << hospedagem_ptr->get_nome().get_valor() << endl;
    cout << "Codigo da hospedagem: " << hospedagem_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa hospedagem?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    int entrada_do_usuario;
    cin >> entrada_do_usuario;
    switch (entrada_do_usuario)
    {
    case 1:
        this->cntrSerCUDHospedagem->destroy(destino_ptr, hospedagem_ptr);
        cout << "Hospedagem deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
    }
}

void CntrAprCRUDAtividade::create(Destino* destino_ptr)
{
    cout << "Tela de criacao de atividade" << endl;
    cout << "Criando atividade para o destino " << destino_ptr->get_nome().get_valor() << "(codigo " << destino_ptr->get_codigo().get_valor() << ")" << endl;
    Codigo codigo; string codigo_string;
    Nome nome; string nome_string;
    Data data; string data_string;
    Horario horario; string horario_string;
    Duracao duracao; int duracao_int;
    Dinheiro preco; double preco_double;
    Avaliacao avaliacao; int avaliacao_int;
    cout << "Codigo da atividade: " << endl; cin >> codigo_string;
    cout << "Nome da atividade: " << endl; cin >> nome_string;
    cout << "Data da atividade: " << endl; cin >> data_string;
    cout << "Horario da atividade: " << endl; cin >> horario_string;
    cout << "Duracao da atividade: " << endl; cin >> duracao_int;
    cout << "Preco da atividade: " << endl; cin >> preco_double;
    cout << "Avaliacao da atividade: " << endl; cin >> avaliacao_int;
    try
    {
        codigo.set_valor(codigo_string);
        nome.set_valor(nome_string);
        data.set_valor(data_string);
        horario.set_valor(horario_string);
        duracao.set_valor(duracao_int);
        preco.set_valor(preco_double);
        avaliacao.set_valor(avaliacao_int);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDAtividade->create(destino_ptr, codigo, nome, data, horario, duracao, preco, avaliacao);
    cout << "Atividade criada com sucesso" << endl;
}

void CntrAprCRUDAtividade::read(Destino* destino_ptr, Atividade* atividade_ptr)
{
    cout << "Tela de leitura de atividade" << endl;
    cout << "Detalhes da atividade " << atividade_ptr->get_codigo().get_valor() << ":" << endl;
    cout << "Nome da atividade: " << atividade_ptr->get_nome().get_valor() << endl;
    cout << "Data da atividade: " << atividade_ptr->get_data().get_valor() << endl;
    cout << "Horario da atividade: " << atividade_ptr->get_horario().get_valor() << endl;
    cout << "Duracao da atividade: " << atividade_ptr->get_duracao().get_valor() << endl;
    cout << "Preco da atividade: " << atividade_ptr->get_preco().get_valor() << endl;
    cout << "Avaliacao da atividade: " << atividade_ptr->get_avaliacao().get_valor() << endl;
    cout << endl;

    int entrada_do_usuario;
    cout << "Escolha uma opcao:" << endl;
    cout << "1. Atualizar atividade" << endl;
    cout << "2. Deletar atividade" << endl;
    cout << "-1. Voltar" << endl;

    switch(entrada_do_usuario)
    {
    case 1:
        update(destino_ptr, atividade_ptr);
        break;
    case 2:
        if(destroy(destino_ptr,atividade_ptr)) return;
        else break;
    case -1:
        return;
    }
}


void CntrAprCRUDAtividade::update(Destino* destino_ptr, Atividade* atividade_ptr)
{
    cout << "Tela de atualizacao de atividade" << endl;
    cout << "Atualizando atividade do destino " << destino_ptr->get_nome().get_valor() << endl;
    Nome nome; string nome_string;
    Data data; string data_string;
    Horario horario; string horario_string;
    Duracao duracao; int duracao_int;
    Dinheiro preco; double preco_double;
    Avaliacao avaliacao; int avaliacao_int;
    cout << "Novo nome da atividade: " << endl; cin >> nome_string;
    cout << "Nova data da atividade: " << endl; cin >> data_string;
    cout << "Novo horario da atividade: " << endl; cin >> horario_string;
    cout << "Nova duracao da atividade: " << endl; cin >> duracao_int;
    cout << "Novo preco da atividade: " << endl; cin >> preco_double;
    cout << "Nova avaliacao da atividade: " << endl; cin >> avaliacao_int;
    try
    {
        nome.set_valor(nome_string);
        data.set_valor(data_string);
        horario.set_valor(horario_string);
        duracao.set_valor(duracao_int);
        preco.set_valor(preco_double);
        avaliacao.set_valor(avaliacao_int);
    }
    catch(const invalid_argument& e)
    {
        cerr << "Valor inválido" << '\n';
        return;
    }
    this->cntrSerCUDAtividade->update(atividade_ptr, nome, data, horario, duracao, preco, avaliacao);
    cout << "Atividade atualizada com sucesso" << endl;
}


bool CntrAprCRUDAtividade::destroy(Destino* destino_ptr, Atividade* atividade_ptr)
{
    cout << "Tela de delecao de atividade" << endl;
    cout << "Deletando atividade do destino " << destino_ptr->get_nome().get_valor() << "(codigo" << destino_ptr->get_codigo().get_valor() << endl;
    cout << "Nome da atividade: " << atividade_ptr->get_nome().get_valor() << endl;
    cout << "Codigo da atividade: " << atividade_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa atividade?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    int entrada_do_usuario;
    cin >> entrada_do_usuario;
    switch (entrada_do_usuario)
    {
    case 1:
        this->cntrSerCUDAtividade->destroy(destino_ptr, atividade_ptr);
        cout << "Atividade deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
    }
}
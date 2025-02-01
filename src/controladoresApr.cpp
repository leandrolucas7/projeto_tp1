#include "../include/controladoresApr.hpp"
#include <iostream>  // Necessário para usar std::cin, std::cout, etc.
#include <limits>    // Necessário para usar std::numeric_limits


using namespace std;


void separa_telas()
{
	cout << "\n\n";
	cout << "***************************************************";
	cout << "\n\n";
}




CntrAprInput* CntrAprInput::instancia = nullptr;

CntrAprInput* CntrAprInput::get_instancia()
{
    if (instancia == nullptr)
    {
        instancia = new CntrAprInput();
    }
    return instancia;
}

void CntrAprInput::delete_instancia()
{
    delete instancia;
    instancia = nullptr;
}



void CntrAprInput::limpa_buffer()
{
    if (contador != 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    contador++;
}


int CntrAprInput::get_user_input()
{
    int user_input;
    limpa_buffer();
    while (true)
    {
        cin >> user_input;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "Entrada invalida. Por favor, digite um inteiro: ";
            continue;
        }
        return user_input;
    }
}

Codigo CntrAprInput::get_codigo()
{
    Codigo codigo; string codigo_string;
    limpa_buffer();
    while (true)
    {
        cout << "Digite um codigo: ";
        cin >> codigo_string;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "O codigo deve ser uma string sem espacos." << endl;
            continue;
        }
        try
        {
            codigo.set_valor(codigo_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        return codigo;
    }
}

Senha CntrAprInput::get_senha()
{
    Senha senha; string senha_string;
    limpa_buffer();
    while (true)
    {
        cout << "Digite uma senha: ";
        cin >> senha_string;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A senha deve ser uma string sem espacos" << endl;
            continue;
        }
        try
        {
            senha.set_valor(senha_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        return senha;
    }
}

Nome CntrAprInput::get_nome()
{
    Nome nome; string nome_string;
    limpa_buffer();
    while (true)
    {
        cout << "Digite um nome: ";
        getline(cin, nome_string);
        cin.putback('\n');1
        if (cin.fail())
        {
            limpa_buffer();
            cout << "Erro na leitura da linha." << endl;
            continue;
        }
        try
        {
            nome.set_valor(nome_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        return nome;
    }
}

Avaliacao CntrAprInput::get_avaliacao()
{
    Avaliacao avaliacao; int avaliacao_int;
    limpa_buffer();
    while (true)
    {
        cout << "Digite uma avaliacao: ";
        cin >> avaliacao_int;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A avaliacao deve ser um inteiro" << endl;
            continue;
        }
        try
        {
            avaliacao.set_valor(avaliacao_int);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
		return avaliacao;
    }
}

Dinheiro CntrAprInput::get_diaria()
{
    Dinheiro dinheiro; double dinheiro_double;
    limpa_buffer();
    while (true)
    {
        cout << "Digite uma diaria: ";
        cin >> dinheiro_double;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A diaria deve ser um double" << endl;
            continue;
        }
        try
        {
            dinheiro.set_valor(dinheiro_double);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
		return dinheiro;
    }
}

Dinheiro CntrAprInput::get_preco()
{
    Dinheiro dinheiro; double dinheiro_double;
    limpa_buffer();
    while (true)
    {
        cout << "Digite um preco: ";
        cin >> dinheiro_double;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "O preco deve ser um double" << endl;
            continue;
        }
        try
        {
            dinheiro.set_valor(dinheiro_double);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
		return dinheiro;
    }
}

Duracao CntrAprInput::get_duracao()
{
    Duracao duracao; int duracao_int;
    limpa_buffer();
    while (true)
    {
        cout << "Digite uma duracao: ";
        cin >> duracao_int;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A duracao deve ser um inteiro" << endl;
            continue;
        }
        try
        {
            duracao.set_valor(duracao_int);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        return duracao;
    }
}

Horario CntrAprInput::get_horario()
{
    Horario horario; string horario_string;
    limpa_buffer();
    while (true)
    {
        cout << "Digite um horario: ";
        cin >> horario_string;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "O horario deve ser uma string sem espacos" << endl;
            continue;
        }
        try
        {
            horario.set_valor(horario_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        return horario;
    }
}

Data CntrAprInput::get_data_inicio()
{
    Data data_inicio; string data_inicio_string;
    limpa_buffer();
    while (true)
    {
        cout << "Digite a data de inicio: ";
        cin >> data_inicio_string;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A data deve ser uma string sem espacos" << endl;
            continue;
        }
        try
        {
            data_inicio.set_valor(data_inicio_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        return data_inicio;
    }
}

Data CntrAprInput::get_data_termino(Data data_inicio)
{
    Data data_termino; string data_termino_string;
    limpa_buffer();
    while (true)
    {
        cout << "Data de termino: ";
        cin >> data_termino_string;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A data deve ser uma string sem espacos." << endl;
            continue;
        }
        try
        {
            data_termino.set_valor(data_termino_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }
        //Verificando se data_inicio <= data_termino
        bool flag = true;
        int dia_data_inicio = stoi(data_inicio.get_valor().substr(0, 2));
        int mes_data_inicio = stoi(data_inicio.get_valor().substr(3, 2));
        int ano_data_inicio = stoi(data_inicio.get_valor().substr(6, 2));
        int dia_data_termino = stoi(data_termino.get_valor().substr(0, 2));
        int mes_data_termino = stoi(data_termino.get_valor().substr(3, 2));
        int ano_data_termino = stoi(data_termino.get_valor().substr(6, 2));
        if (ano_data_termino < ano_data_inicio)
        {
            flag = false;
        }
        else if (ano_data_termino == ano_data_inicio)
        {
            if (mes_data_termino < mes_data_inicio && ano_data_termino == ano_data_inicio)
            {
                flag = false;
            }
            else if (mes_data_termino == mes_data_inicio)
            {
                if (dia_data_termino < dia_data_inicio)
                {
                    flag = false;
                }
            }
        }
        if (! flag)
            {
                cout << "Data de termino nao pode ser anterior a data de inicio." << endl;
                continue;
            }
        return data_termino;
    }
}

Data CntrAprInput::get_data_atividade(Data data_inicio, Data data_termino)
{
    Data data_atividade; string data_atividade_string;
    limpa_buffer();
    while (true)
    {
        cout << "Data da atividade: ";
        cin >> data_atividade_string;
        if (cin.fail())
        {
            limpa_buffer();
            cout << "A data deve ser uma string sem espacos." << endl;
            continue;
        }
        try
        {
            data_atividade.set_valor(data_atividade_string);
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
            continue;
        }

        bool flag = true;
        int dia_data_inicio = stoi(data_inicio.get_valor().substr(0, 2));
        int mes_data_inicio = stoi(data_inicio.get_valor().substr(3, 2));
        int ano_data_inicio = stoi(data_inicio.get_valor().substr(6, 2));

        int dia_data_atividade = stoi(data_atividade.get_valor().substr(0, 2));
        int mes_data_atividade = stoi(data_atividade.get_valor().substr(3, 2));
        int ano_data_atividade = stoi(data_atividade.get_valor().substr(6, 2));

        int dia_data_termino = stoi(data_termino.get_valor().substr(0, 2));
        int mes_data_termino = stoi(data_termino.get_valor().substr(3, 2));
        int ano_data_termino = stoi(data_termino.get_valor().substr(6, 2));

        //Verificando se data_inicio <= data_atividade
        if (ano_data_atividade < ano_data_inicio)
        {
            flag = false;
        }
        else if (ano_data_atividade == ano_data_inicio)
        {
            if (mes_data_atividade < mes_data_inicio)
            {
                flag = false;
            }
            else if (mes_data_atividade == mes_data_inicio)
            {
                if (dia_data_atividade < dia_data_inicio)
                {
                    flag = false;
                }
            }
        }
        if (! flag)
            {
                cout << "Data da atividade nao pode ser anterior a data de inicio do destino." << endl;
                //continue;
            }

        //Verificando se data_atividade <= data_termino
        if (ano_data_termino < ano_data_atividade)
        {
            flag = false;
        }
        else if (ano_data_termino == ano_data_atividade)
        {
            if (mes_data_termino < mes_data_atividade)
            {
                flag = false;
            }
            else if (mes_data_termino == mes_data_atividade)
            {
                if (dia_data_termino < dia_data_atividade)
                {
                    flag = false;
                }
            }
        }
        if (! flag)
            {
                cout << "Data da atividade nao pode ser posterior a data de termino do destino." << endl;
                //continue;
            }
		if (! flag)
		{
			cout << "Trago informacoes para te auxiliar, viajante:" << endl;
			cout << "A data de inicio do destino eh " << data_inicio.get_valor() << endl;
			cout << "A data de termino do destino eh " << data_termino.get_valor() << endl;
			continue;
		}
        return data_atividade;
    }
}


void CntrAprInicial::executar()
{
    Conta* conta_ptr = nullptr;
    CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    int user_input;

    while (true)
    {
		separa_telas();
        cout << "Essa eh a tela inicial. Selecione uma das opcoes abaixo:" << endl;
        cout << "1. Criar conta" << endl;
        cout << "2. Login" << endl;
        cout << "-1. Sair" << endl;

        user_input = cntrAprInput->get_user_input();

        switch(user_input)
        {
        case 1:
            this->cntrAprCRUDConta->create(conta_ptr);
            break;
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
	separa_telas();
    ContainerContas* container_contas = ContainerContas::get_instancia();
    CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Codigo codigo; 
    Senha senha;
	bool autenticado; 

    cout << "Tela de autenticacao" << endl;
    codigo = cntrAprInput->get_codigo();
    senha = cntrAprInput->get_senha();
    
    conta_ptr = new Conta();
    conta_ptr->set_codigo(codigo);
    conta_ptr->set_senha(senha);

	autenticado = container_contas->fetch(conta_ptr);

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
	separa_telas();
    CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Codigo codigo; 
    Senha senha; 
    bool ja_existe;

	cout << "Tela de criacao de conta" << endl;
    codigo = cntrAprInput->get_codigo();
    senha = cntrAprInput->get_senha();

    ja_existe = !(this->cntrSerCUDConta->create(conta_ptr, codigo, senha));

    if (ja_existe)
    {
        cout << "Esse codigo ja esta em uso" << endl;
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
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	int user_input;
    Codigo viagem_codigo;
    Viagem* viagem_ptr = nullptr;

    while (true)
    {
		separa_telas();
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
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar conta" << endl;
        cout << "2. Deletar conta" << endl;
        cout << "3. Criar viagem" << endl;
        cout << "4. Escolher Viagem" << endl;
        cout << "-1. Voltar" << endl;
        user_input = cntrAprInput->get_user_input();

        switch(user_input)
        {
        case 1:
            update(conta_ptr);
            break;
        case 2:
            if(destroy(conta_ptr)) return;
            else break;
        case 3:
            this->cntrAprCRUDViagem->create(conta_ptr);
            break;
        case 4:
            cout << "Qual viagem deseja acessar?" << endl;
            viagem_codigo = cntrAprInput->get_codigo();

            viagem_ptr = conta_ptr->get_viagem_ptr(viagem_codigo);
            if (viagem_ptr == nullptr)
            {
                cout << "Viagem nao encontrada." << endl;
                break;
            }
            else this->cntrAprCRUDViagem->read(conta_ptr, viagem_ptr);
            break;
        case -1:
            conta_ptr = nullptr;
            return;
		default:
			cout << "Opcao invalida" << endl;
        }
    }
}

void CntrAprCRUDConta::update(Conta* conta_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Senha senha; 

    cout << "Tela de atualizacao de conta" << endl;
    cout << "Atualizando conta " << conta_ptr->get_codigo().get_valor() << endl;
    senha = cntrAprInput->get_senha();
    this->cntrSerCUDConta->update(conta_ptr, senha);
    cout << "Conta atualizada com sucesso" << endl;
}

bool CntrAprCRUDConta::destroy(Conta* conta_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    int user_input;

    cout << "Tela de delecao de conta" << endl;
	if (!conta_ptr->is_viagem_ptr_empty())
		{
			cout << "A conta nao pode ser deleta, pois ha viagens associadas a ela" << endl;
			return false;
		}
    cout << "Deletando conta " << conta_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa conta?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;

    user_input = cntrAprInput->get_user_input();
    switch (user_input)
    {
    case 1:
        this->cntrSerCUDConta->destroy(conta_ptr);
        cout << "Conta deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
	default:
		cout << "Opcao invalida" << endl;
		return false;
    }
}



void CntrAprCRUDViagem::create(Conta* conta_ptr)
{   
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Codigo codigo; 
    Nome nome; 
    Avaliacao avaliacao; 
	bool resultado;

    cout << "Tela de criacao de viagem" << endl;
    cout << "Criando viagem para a conta " << conta_ptr->get_codigo().get_valor() << endl;
    codigo = cntrAprInput->get_codigo();
	nome = cntrAprInput->get_nome();
	avaliacao = cntrAprInput->get_avaliacao();

    resultado = this->cntrSerCUDViagem->create(conta_ptr, codigo, nome, avaliacao);
    if (resultado)
        cout << "Viagem criada com sucesso" << endl;
    else
        cout << "Esse codigo ja esta em uso" << endl;
}


void CntrAprCRUDViagem::read(Conta* conta_ptr, Viagem* viagem_ptr)
{
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    int user_input;
	Codigo destino_codigo; 
    Destino* destino_ptr = nullptr;

    while (true)
    {
		separa_telas();
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

        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar viagem" << endl;
        cout << "2. Deletar viagem" << endl;
        cout << "3. Criar destino" << endl;
        cout << "4. Escolher destino" << endl;
        cout << "-1. Voltar" << endl;
        user_input = cntrAprInput->get_user_input();

        
        switch(user_input)
        {
        case 1:
            update(conta_ptr,viagem_ptr);
            break;
        case 2:
            if(destroy(conta_ptr,viagem_ptr)) return;
            else break;
        case 3:
            this->cntrAprCRUDDestino->create(viagem_ptr);
            break;
        case 4:
            cout << "Qual destino deseja acessar?" << endl;
            
            destino_codigo = cntrAprInput->get_codigo();
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
		default:
			cout << "Opcao invalida" << endl;
        }
    }
}

void CntrAprCRUDViagem::update(Conta* conta_ptr, Viagem* viagem_ptr)
{   
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	Nome nome; 
    Avaliacao avaliacao;

    cout << "Tela de atualizacao de viagem" << endl;
    cout << "Atualizando viagem da conta " << conta_ptr->get_codigo().get_valor() << endl;

    nome = cntrAprInput->get_nome();
	avaliacao = cntrAprInput->get_avaliacao();

    this->cntrSerCUDViagem->update(viagem_ptr, nome, avaliacao);
    cout << "Viagem atualizada com sucesso !" << endl;
}

bool CntrAprCRUDViagem::destroy(Conta* conta_ptr, Viagem* viagem_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	int user_input;

    cout << "Tela de delecao de viagem" << endl;
	if (!viagem_ptr->is_destino_ptr_empty())
	{
		cout << "A viagem nao pode ser deletada, pois ha destinos associados a ela." << endl;
		return false;
	}
    cout << "Deletando viagem da conta " << conta_ptr->get_codigo().get_valor() << endl;
    cout << "Nome da viagem: " << viagem_ptr->get_nome().get_valor() << endl;
    cout << "Codigo da viagem: " << viagem_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa viagem?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    
    user_input = cntrAprInput->get_user_input();
    switch (user_input)
    {
    case 1:
        this->cntrSerCUDViagem->destroy(conta_ptr, viagem_ptr);
        cout << "Viagem deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
	default:
		cout << "Opcao invalida" << endl;
		return false;
    }
}


void CntrAprCRUDDestino::create(Viagem* viagem_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	Codigo codigo; 
    Nome nome; 
    Data data_inicio; 
    Data data_termino; 
    Avaliacao avaliacao;
	bool resultado;

    cout << "Tela de criacao de destino" << endl;
    cout << "Criando destino para a viagem " << viagem_ptr->get_nome().get_valor() << "(codigo " << viagem_ptr->get_codigo().get_valor() << ")" << endl;
    
	codigo = cntrAprInput->get_codigo();
	nome = cntrAprInput->get_nome();
	data_inicio = cntrAprInput->get_data_inicio();
	data_termino = cntrAprInput->get_data_termino(data_inicio);
	avaliacao = cntrAprInput->get_avaliacao();

	resultado = this->cntrSerCUDDestino->create(viagem_ptr, codigo, nome, data_inicio, data_termino, avaliacao);
    if (resultado)
        cout << "Destino criado com sucesso" << endl;
    else
        cout << "Esse codigo ja esta em uso" << endl;
}

void CntrAprCRUDDestino::read(Viagem* viagem_ptr, Destino* destino_ptr)
{
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    int user_input;
	Codigo codigo; 
    Hospedagem* hospedagem_ptr = nullptr;
    Atividade* atividade_ptr = nullptr;


    while (true)
    {
		separa_telas();
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
		cout << endl;
        if (destino_ptr->is_atividade_ptr_empty())
            cout << "Ainda nao ha nenhuma atividade associada a esse destino" << endl;
        else
            {
                cout << "Atividades associadas a esse destino:" << endl;
                for (Atividade* atividade_ptr : destino_ptr->get_atividades_ptr())
                {
                    cout << atividade_ptr->get_nome().get_valor() << "(codigo " <<  atividade_ptr->get_codigo().get_valor() << ")" << endl;
                }
            }
		cout << endl;

        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar Destino" << endl;
        cout << "2. Deletar Destino" << endl;
        cout << "3. Criar Hospedagem" << endl;
        cout << "4. Criar Atividade" << endl;
        cout << "5. Escolher Hospedagem" << endl;
        cout << "6. Escolher Atividade" << endl;
        cout << "-1. Voltar" << endl;
        user_input = cntrAprInput->get_user_input();

        switch(user_input)
        {
        case 1:
            update(viagem_ptr, destino_ptr);
            break;
        case 2:
            if(destroy(viagem_ptr,destino_ptr)) return;
            else break;
        case 3:
            this->cntrAprCRUDHospedagem->create(destino_ptr);
            break;
        case 4:
            this->cntrAprCRUDAtividade->create(destino_ptr);
            break;
        case 5:
            cout << "Qual hospedagem deseja acessar?" << endl;
            codigo = cntrAprInput->get_codigo();
            hospedagem_ptr = destino_ptr->get_hospedagem_ptr(codigo);
            if (hospedagem_ptr == nullptr)
            {
                cout << "Hospedagem nao encontrada" << endl;
                break;
            }
            else this->cntrAprCRUDHospedagem->read(destino_ptr, hospedagem_ptr);
            break;

        case 6:
            cout << "Qual atividade desja acessar? " << endl;
            codigo = cntrAprInput->get_codigo();
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
		default:
			cout << "Opcao invalida" << endl;
        }
    }
}

void CntrAprCRUDDestino::update(Viagem* viagem_ptr, Destino* destino_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Nome nome; 
    Data data_inicio;
    Data data_termino; 
    Avaliacao avaliacao; 

    cout << "Tela de atualizacao de destino" << endl;
    cout << "Atualizando destino da viagem " << viagem_ptr->get_nome().get_valor() << endl;

    nome = cntrAprInput->get_nome();
	data_inicio = cntrAprInput->get_data_inicio();
	data_termino = cntrAprInput->get_data_termino(data_inicio);
	avaliacao = cntrAprInput->get_avaliacao();

    this->cntrSerCUDDestino->update(destino_ptr, nome, data_inicio, data_termino, avaliacao);
    cout << "Destino atualizado com sucesso" << endl;
}

bool CntrAprCRUDDestino::destroy(Viagem* viagem_ptr, Destino* destino_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	int user_input;

    cout << "Tela de delecao de destino" << endl;
	if (!(destino_ptr->is_hospedagem_ptr_empty() && destino_ptr->is_atividade_ptr_empty()))
	{
		cout << "Destino nao pode ser deletado, pois ha hospedagens e/ou atividades associadas a ele.";
		return false;
	}
    cout << "Deletando destino da viagem " << viagem_ptr->get_nome().get_valor() << "(codigo" << viagem_ptr->get_codigo().get_valor() << endl;
    cout << "Nome do destino: " << destino_ptr->get_nome().get_valor() << endl;
    cout << "Codigo do destino: " << destino_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar esse destino?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    
	user_input = cntrAprInput->get_user_input();
    switch (user_input)
    {
    case 1:
        this->cntrSerCUDDestino->destroy(viagem_ptr, destino_ptr);
        cout << "Destino deletado com sucesso" << endl;
        return true;
    case 2:
        return false;
	default:
		cout << "Opcao invalida" << endl;
		return false;
    }
}



void CntrAprCRUDHospedagem::create(Destino* destino_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Codigo codigo; 
    Nome nome; 
    Dinheiro diaria; 
    Avaliacao avaliacao;
	bool resultado;

    cout << "Tela de criacao de hospedagem" << endl;

    if (!destino_ptr->is_hospedagem_ptr_empty())
    {
        cout << "Deve haver somente uma hospedagem associada a cada destino" << endl;
        cout << "Ja ha uma hospedagem associada a esse destino" << endl;
        cout << "Saindo ..." << endl;
        return;
    }

    cout << "Criando hospedagem para o destino " << destino_ptr->get_nome().get_valor() << "(codigo " << destino_ptr->get_codigo().get_valor() << ")" << endl;
    
	codigo = cntrAprInput->get_codigo();
	nome = cntrAprInput->get_nome();
	diaria = cntrAprInput->get_diaria();
	avaliacao = cntrAprInput->get_avaliacao();

    resultado = this->cntrSerCUDHospedagem->create(destino_ptr, codigo, nome, diaria, avaliacao);
    if (resultado)
        cout << "Hospedagem criada com sucesso" << endl;
    else
        cout << "Esse codigo ja esta em uso" << endl;
}

void CntrAprCRUDHospedagem::read(Destino* destino_ptr, Hospedagem* hospedagem_ptr)
{
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	int user_input;

    while (true)
    {
		separa_telas();
        cout << "Tela de leitura de hospedagem" << endl;
        cout << "Detalhes da hospedagem " << hospedagem_ptr->get_codigo().get_valor() << ":" << endl;
        cout << "Nome da hospedagem: " << hospedagem_ptr->get_nome().get_valor() << endl;
        cout << "Diaria da hospedagem: " << hospedagem_ptr->get_diaria().get_valor() << endl;
        cout << "Avaliacao da hospedagem: " << hospedagem_ptr->get_avaliacao().get_valor() << endl;
        cout << endl;

        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar hospedagem" << endl;
        cout << "2. Deletar hospedagem" << endl;
        cout << "-1. Voltar" << endl;
        user_input = cntrAprInput->get_user_input();

        switch(user_input)
        {
        case 1:
            update(destino_ptr, hospedagem_ptr);
            break;
        case 2:
            if(destroy(destino_ptr,hospedagem_ptr)) return;
            else break;
        case -1:
            return;
		default:
			cout << "Opcao invalida" << endl;
        }
    }
}

void CntrAprCRUDHospedagem::update(Destino* destino_ptr, Hospedagem* hospedagem_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	Nome nome; 
    Dinheiro diaria; 
    Avaliacao avaliacao; 

    cout << "Tela de atualizacao de hospedagem" << endl;
    cout << "Atualizando hospedagem do destino " << destino_ptr->get_nome().get_valor() << endl;
    
	nome = cntrAprInput->get_nome();
	diaria = cntrAprInput->get_diaria();
	avaliacao = cntrAprInput->get_avaliacao();
    this->cntrSerCUDHospedagem->update(hospedagem_ptr, nome, diaria, avaliacao);
    cout << "Hospedagem atualizada com sucesso" << endl;
}


bool CntrAprCRUDHospedagem::destroy(Destino* destino_ptr, Hospedagem* hospedagem_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
	int user_input;

    cout << "Tela de delecao de hospedagem" << endl;
    cout << "Deletando hospedagem do destino " << destino_ptr->get_nome().get_valor() << "(codigo" << destino_ptr->get_codigo().get_valor() << endl;
    cout << "Nome da hospedagem: " << hospedagem_ptr->get_nome().get_valor() << endl;
    cout << "Codigo da hospedagem: " << hospedagem_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa hospedagem?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;
    
    user_input = cntrAprInput->get_user_input();
    switch (user_input)
    {
    case 1:
        this->cntrSerCUDHospedagem->destroy(destino_ptr, hospedagem_ptr);
        cout << "Hospedagem deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
	default:
		cout << "Opcao invalida" << endl;
		return false;
    }
}

void CntrAprCRUDAtividade::create(Destino* destino_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Codigo codigo; 
    Nome nome; 
    Data data; 
    Horario horario; 
    Duracao duracao; 
    Dinheiro preco; 
    Avaliacao avaliacao;
	bool resultado; 

    cout << "Tela de criacao de atividade" << endl;
    cout << "Criando atividade para o destino " << destino_ptr->get_nome().get_valor() << "(codigo " << destino_ptr->get_codigo().get_valor() << ")" << endl;
	codigo = cntrAprInput->get_codigo();
	nome = cntrAprInput->get_nome();
	data = cntrAprInput->get_data_atividade(destino_ptr->get_data_inicio(),destino_ptr->get_data_termino());
	horario = cntrAprInput->get_horario();
	duracao = cntrAprInput->get_duracao();
	preco = cntrAprInput->get_preco();
	avaliacao = cntrAprInput->get_avaliacao();
    
    resultado = this->cntrSerCUDAtividade->create(destino_ptr, codigo, nome, data, horario, duracao, preco, avaliacao);
    if (resultado)
        cout << "Atividade criada com sucesso" << endl;
    else
        cout << "Esse codigo ja esta em uso" << endl;
}

void CntrAprCRUDAtividade::read(Destino* destino_ptr, Atividade* atividade_ptr)
{   
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    int user_input;
	
	while(true)
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

        cout << "Escolha uma opcao:" << endl;
        cout << "1. Atualizar atividade" << endl;
        cout << "2. Deletar atividade" << endl;
        cout << "-1. Voltar" << endl;
        user_input = cntrAprInput->get_user_input();

        switch(user_input)
        {
        case 1:
            update(destino_ptr, atividade_ptr);
            break;
        case 2:
            if(destroy(destino_ptr,atividade_ptr)) return;
            else break;
        case -1:
            return;
		default:
			cout << "Opcao invalida" << endl;
        }
    }
}


void CntrAprCRUDAtividade::update(Destino* destino_ptr, Atividade* atividade_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    Nome nome; 
    Data data; 
    Horario horario; 
    Duracao duracao; 
    Dinheiro preco; 
    Avaliacao avaliacao; 

    cout << "Tela de atualizacao de atividade" << endl;
    cout << "Atualizando atividade do destino " << destino_ptr->get_nome().get_valor() << endl;

	nome = cntrAprInput->get_nome();
	data = cntrAprInput->get_data_atividade(destino_ptr->get_data_inicio(),destino_ptr->get_data_termino());
	horario = cntrAprInput->get_horario();
	duracao = cntrAprInput->get_duracao();
	preco = cntrAprInput->get_preco();
	avaliacao = cntrAprInput->get_avaliacao();
    
    this->cntrSerCUDAtividade->update(atividade_ptr, nome, data, horario, duracao, preco, avaliacao);
    cout << "Atividade atualizada com sucesso" << endl;
}


bool CntrAprCRUDAtividade::destroy(Destino* destino_ptr, Atividade* atividade_ptr)
{
	separa_telas();
	CntrAprInput* cntrAprInput = CntrAprInput::get_instancia();
    int user_input;

    cout << "Tela de delecao de atividade" << endl;
    cout << "Deletando atividade do destino " << destino_ptr->get_nome().get_valor() << "(codigo" << destino_ptr->get_codigo().get_valor() << endl;
    cout << "Nome da atividade: " << atividade_ptr->get_nome().get_valor() << endl;
    cout << "Codigo da atividade: " << atividade_ptr->get_codigo().get_valor() << endl;
    cout << "Deseja realmente deletar essa atividade?" << endl;
    cout << "1. Sim" << endl;
    cout << "2. Nao" << endl;

	user_input = cntrAprInput->get_user_input();
    switch (user_input)
    {
    case 1:
        this->cntrSerCUDAtividade->destroy(destino_ptr, atividade_ptr);
        cout << "Atividade deletada com sucesso" << endl;
        return true;
    case 2:
        return false;
	default:
		cout << "Opcao invalida" << endl;
		return false;
    }
}
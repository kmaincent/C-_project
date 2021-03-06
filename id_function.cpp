#include "include.h"

void is_a_parameter(std::string& param)
{
    if (param=="")
    {
        cout << "Cette fonction necessite un second parametre. Veuillez le specifier : " << endl;
        cin >> param ;
        cin.ignore();
    }
}

int id_function(mediatheque& media, utilisateur user, std::string str, std::string param)
{
    list_function temp[]={BYE, ADD, LOAD, SAVE, SEARCH, CLEAR, LIST, SHOW, DELETE, RESET, CONCHITA, RESERV, BORROW, RETURN, RELOAD, ERROR};
    list_function _function = ERROR;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    string tmp ="";
    for (int i=0; i<15; i++)
    {
        if(str==list_function_str[i])
        {
            _function=temp[i];
            break;
        }
    }
    switch (_function)
    {
    case BYE :
        cout<<"Au revoir, merci d'avoir utilise notre logiciel"<<endl;
        media.save_state(user);
        return 0;
        break;
    case CONCHITA :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        cout << "Si vous utilisez cette fonction la recherche courante sera perdue!" << endl;
        cout << "Souhaitez-vous poursuivre cette opération? y/n" << endl;
        do{
            cin >> tmp;
            if (tmp=="y")
            {
                media.conchita();
                media.clear();
                media.list();
            }
            else if (tmp=="n")
                ;
            else
                cout << "Commande incorrecte." << endl;
        }while(tmp!="y" && tmp!="n");
        break;
    case ADD :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        transform(param.begin(), param.end(), param.begin(), ::toupper);
        media.add(param);
        break;
    case LOAD :
        is_a_parameter(param);
        media.reset();
        media.load(param);
        break;
    case SAVE :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autoriser a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        media.save(param);
        break;
    case SEARCH :
        is_a_parameter(param);
        media.search(param);
        break;
    case CLEAR :
        media.clear();
        break;
    case LIST :
        media.list();
        break;
    case SHOW :
        is_a_parameter(param);
        media.gestion(param,1);
        break;
    case BORROW :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        media.gestion(param,2);
        break;
    case RETURN :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        media.gestion(param,3);
        break;
    case RESERV :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        media.gestion(param,4);
        break;
    case DELETE :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        media.gestion(param,5);
        media.resetID();
        break;
    case RESET :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        media.reset();
        break;
   case RELOAD:
	media.reload();	
	break;
    case ERROR:
    default :
        cout<<"Mauvaise commande, veuillez reessayer."<<endl;
        break;

    }
    return 1;
}

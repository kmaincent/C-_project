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
    list_function temp[]={BYE, ADD, LOAD, SAVE, SEARCH, CLEAR, LIST, SHOW, DELETE, RESET, ERROR};
    list_function _function = ERROR;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    for (int i=0; i<10; i++)
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
        return 0;
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
        media.load(param);
        break;
    case SAVE :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
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
        media.show(param);
        break;
    case DELETE :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        is_a_parameter(param);
        media.delet(param);
        break;
    case RESET :
        if(!user.getAdmin())
        {
            cout<<"Vous n'etes pas autorise a utiliser cette commande."<<endl;
            break;
        }
        media.reset();
        break;
    case ERROR:
    default :
        cout<<"Mauvaise commande, veuillez reessayer."<<endl;
        break;

    }
    return 1;
}

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

int id_function(mediatheque& media, std::string str, std::string param)
{
    list_function temp[]={BYE, ADD, LOAD, SAVE, SEARCH, CLEAR, LIST, SHOW, DELETE, RESET, ERROR};
    list_function _function = ERROR;

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
        cout<<"Au revoir, merci d'avoir utilisé notre logiciel"<<endl;
        return 0;
        break;
    case ADD :
        is_a_parameter(param);
        media.add(param);
        break;
    case LOAD :
        is_a_parameter(param);
        media.load(param);
        break;
    case SAVE :
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
        is_a_parameter(param);
        media.delet(param);
        break;
    case RESET :
        media.reset();
        break;
    case ERROR:
    default :
        cout<<"Mauvaise commande, veuillez réessayer."<<endl;
        break;

    }
    return 1;
}

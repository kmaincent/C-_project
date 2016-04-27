#include "include.h"

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
        cout << "Yes : " << param << endl;
        media.add(param);
        break;
    case LOAD :
        media.load(param);
        break;
    case SAVE :
        media.save(param);
        break;
    case SEARCH :
        media.search(param);
        break;
    case CLEAR :
        media.clear();
        break;
    case LIST :
        media.list();
        break;
    case SHOW :
        media.show(param);
        break;
    case DELETE :
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

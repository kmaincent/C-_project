#include "include.h"


mediatheque::mediatheque():
    nb_ressource(0), nb_livre(0), nb_revue(0), nb_cd(0), nb_vhs(0), nb_dvd(0), nb_docnum(0)
{
}

mediatheque::~mediatheque()
{
    for (unsigned int i(0); i<base_donnees.size(); i++)
    {
        delete base_donnees[i];
        base_donnees[i]=0;
    }
}

void mediatheque::add(std::string param)
{

}

void mediatheque::save(std::string file_name)
{
    string type;
    ofstream infile;
    infile.open(file_name.c_str());
    if (infile.fail())
    {
        cout<<"Probleme d'ouverture de fichier"<<endl;
    }
    for (unsigned int i(0); i<base_donnees.size(); i++)
    {
        base_donnees[i]->save(infile);
    }
    infile.close();
}

int mediatheque::load(const std::string file_name)
{
    string type;
    ifstream infile;
    infile.open(file_name.c_str());
    if (infile.fail())
    {
        cout<<"plus de ficher"<<endl;
        return false;
    }
    getline(infile, type);
    while(type.size()!=0)
    {

        switch (enum_string_type(type))
        {
        case CD:
            base_donnees.push_back(new cd());
            break;
        case DVD:
            base_donnees.push_back(new dvd());
            break;
        case LIVRE:
            base_donnees.push_back(new livre());
            break;
        case REVUE:
            base_donnees.push_back(new revue());
            break;
        case VHS:
            base_donnees.push_back(new vhs());
            break;
        case RESSOURCE_NUM:
            base_donnees.push_back(new ressource_num());
            break;
        default:
            cout<<"Ce type de ressource n'existe pas"<<endl;
            break;

        }
        base_donnees[nb_ressource]->setType(enum_string_type(type));
        base_donnees[nb_ressource]->load(infile);
        nb_ressource++;
        getline(infile, type);
    }
    return 1;
}

void mediatheque::search(std::string param)
{
    if (base_recherche.size()==0)
        base_recherche.insert(base_recherche.begin(), nb_ressource,true);
    for (unsigned int i=0; i<base_donnees.size(); i++)
    {
        base_recherche[i]=base_donnees[i]->search(param);
    }
}

void mediatheque::show(std::string param)
{
    int _id = atoi(param.c_str());
    if (_id<nb_ressource or _id > 0 )
        base_donnees[_id-1]->affiche();
    else
        cout<<"Pas de ressource à cet ID"<<endl;
}

void mediatheque::delet(std::string param)
{
    int _id = atoi(param.c_str());
    if (_id<nb_ressource or _id > 0)
        base_donnees.erase(base_donnees.begin() + _id -1);
    else
        cout<<"Pas de ressource à cet ID"<<endl;

}

void mediatheque::clear()
{
    //for (int i=0; i<base_recherche.size(); i++)
    //    base_recherche=0;
    base_recherche.clear();
}

void mediatheque::list()
{
    if (base_recherche.size()==0)
        base_recherche.insert(base_recherche.begin(), nb_ressource,1);

    for (unsigned int i=0; i<base_recherche.size(); i++)
    {  if(base_recherche[i]==1)
            base_donnees[i]->affiche();
    }

}

void mediatheque::reset()
{

}

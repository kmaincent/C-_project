#include "include.h"




mediatheque::mediatheque():
    nb_ressource(0), nb_livre(0), nb_revue(0), nb_cd(0), nb_vhs(0), nb_dvd(0), nb_docnum(0)
{
}

mediatheque::~mediatheque()
{
    for (unsigned int i(0); i<base_donnees.size(); i++)
    {
        delete base_donnees[i]; // Pourquoi mettre à 0 alors qu'on vient de le supprimer?
        base_donnees[i]=0; //On libère la i-ème case mémoire allouée puis On met le pointeur à 0 pour éviter les soucis
    }
}

void mediatheque::add(std::string param)
{
    switch (enum_string_type(param))
    {
    case CD:
        base_donnees.push_back(new cd());
        base_donnees[nb_ressource]->setId(nb_ressource);
        nb_cd ++;
        break;
    case DVD:
        base_donnees.push_back(new dvd());
        base_donnees[nb_ressource]->setId(nb_ressource);
        nb_dvd ++;
        break;
    case LIVRE:
        base_donnees.push_back(new livre());
        base_donnees[nb_ressource]->setId(nb_ressource);
        nb_livre ++;
        break;
    case REVUE:
        base_donnees.push_back(new revue());
        base_donnees[nb_ressource]->setId(nb_ressource);
        nb_revue ++;
        break;
    case VHS:
        base_donnees.push_back(new vhs());
        base_donnees[nb_ressource]->setId(nb_ressource);
        nb_vhs ++;
        break;
    case RESSOURCE_NUM:
        base_donnees.push_back(new ressource_num());
        base_donnees[nb_ressource]->setId(nb_ressource);
        nb_docnum ++;
        break;
    default:
        cout<<"Ce type de ressource n'existe pas"<<endl;
        return;
        break;

    }
    base_donnees[nb_ressource]->setType(enum_string_type(param));
    base_donnees[nb_ressource]->load(cin);
    base_recherche.push_back(1);
    nb_ressource++;
}



void mediatheque::save(std::string file_name) const
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
        cout<<"Ce fichier n'existe pas."<<endl;
        return 0;
    }
    getline(infile, type);
    while(type.size()!=0)
    {

        switch (enum_string_type(type))
        {
        case CD:
            base_donnees.push_back(new cd());
            base_donnees[nb_ressource]->setId(nb_ressource);
            nb_cd ++;
            break;
        case DVD:
            base_donnees.push_back(new dvd());
            base_donnees[nb_ressource]->setId(nb_ressource);
            nb_dvd ++;
            break;
        case LIVRE:
            base_donnees.push_back(new livre());
            base_donnees[nb_ressource]->setId(nb_ressource);
            nb_livre ++;
            break;
        case REVUE:
            base_donnees.push_back(new revue());
            base_donnees[nb_ressource]->setId(nb_ressource);
            nb_revue ++;
            break;
        case VHS:
            base_donnees.push_back(new vhs());
            base_donnees[nb_ressource]->setId(nb_ressource);
            nb_vhs ++;
            break;
        case RESSOURCE_NUM:
            base_donnees.push_back(new ressource_num());
            base_donnees[nb_ressource]->setId(nb_ressource);
            nb_docnum ++;
            break;
        default:
            cout<<"Ce type de ressource n'existe pas"<<endl;
            return 1;
            break;

        }
        std::cout.setstate(std::ios_base::failbit);
        base_donnees[nb_ressource]->setType(enum_string_type(type));
        base_donnees[nb_ressource]->load(infile);
        base_recherche.push_back(1);
        nb_ressource++;
        type="";
        getline(infile, type);
        std::cout.clear();
    }
    return 1;
}

void mediatheque::search(std::string param)
{
    if (base_recherche.size()!=nb_ressource)
        base_recherche.insert(base_recherche.begin(), nb_ressource,true);
    for (unsigned int i=0; i<base_donnees.size(); i++)
    {
        base_recherche[i]=base_donnees[i]->search(param);
    }
}

void mediatheque::show(std::string param) const
{
    int _id = atoi(param.c_str());
    if (_id<=nb_ressource and _id > 0 )
        base_donnees[_id-1]->show();
    else
        cout<<"Pas de ressource à cet ID"<<nb_ressource<<endl;
}

void mediatheque::delet(std::string param)
{
    int _id = atoi(param.c_str());
    if (_id<nb_ressource and _id > 0)
    {
        switch (base_donnees[_id]->getType())
        {
        case CD:
            nb_cd --;
            break;
        case DVD:
            nb_dvd --;
            break;
        case LIVRE:
            nb_livre --;
            break;
        case REVUE:
            nb_revue --;
            break;
        case VHS:
            nb_vhs --;
            break;
        case RESSOURCE_NUM:
            nb_docnum --;
            break;
        default:
            break;
        }
        base_donnees.erase(base_donnees.begin() + _id -1);
        base_recherche.erase(base_recherche.begin() + _id -1);
    }
    else
        cout<<"Pas de ressource à cet ID"<<nb_ressource<<endl;

}

void mediatheque::clear()
{
    for (int i=0; i<base_recherche.size(); i++)
        base_recherche[i]=0;
}

void mediatheque::list()
{
    //    if (base_recherche.size()!=nb_ressource)
    //        base_recherche.insert(base_recherche.begin(), nb_ressource,true);
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|ID    |TYPE           |AUTEUR             |TITRE                             |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;// 81 caractères - 5 pour les barres verticales
    for (unsigned int i=0; i<base_recherche.size(); i++)
    {  if(base_recherche[i]==1)
        {
            string str1, str2, str3, str4;
            char buffer[6];
            str1 = miseenforme(itoa(base_donnees[i]->getId(), buffer, 10),6); // 6 caractères pour l'id
            str2 = miseenforme(enum_string_type(base_donnees[i]->getType()),15); // 15 caractères pour le type
            str3 = miseenforme(base_donnees[i]->getAuteur(),19); // 19 caractères pour l'auteur
            str4 = miseenforme(base_donnees[i]->getTitre(),34); // 34 caractères pour l'id
            cout << "|" << str1 << "|" << str2 << "|" << str3 << "|" << str4 << "|" << endl;
            //base_donnees[i]->show();
        }
    }
    cout << "-------------------------------------------------------------------------------" << endl;
}

void mediatheque::reset()
{
    nb_ressource=0;
    nb_livre=0;
    nb_revue=0;
    nb_cd=0;
    nb_vhs=0;
    nb_dvd=0;
    nb_docnum=0;
    for (unsigned int i(0); i<base_donnees.size(); i++)
    {
        delete base_donnees[i]; // Pourquoi mettre à 0 alors qu'on vient de le supprimer?
        base_donnees[i]=0; //On libère la i-ème case mémoire allouée puis On met le pointeur à 0 pour éviter les soucis
    }
}

string mediatheque::miseenforme(string modif, int taille)
{
    string buffer= "                                        ";
    buffer = modif + buffer; // on concatène avec une chaîne vide de taille notre taille maximale (ici 40)
    buffer = buffer.substr(0,taille);
    return buffer; // On retourne une troncature du buffer à la taille souhaitée
}

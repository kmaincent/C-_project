#include "include.h"




mediatheque::mediatheque():
    nb_ressource(0), nb_livre(0), nb_revue(0), nb_cd(0), nb_vhs(0), nb_dvd(0), nb_docnum(0), nom_media("")
{
}

mediatheque::~mediatheque()
{
    for (unsigned int i(0); i<base_donnees.size(); i++)
    {
        delete base_donnees[i]; // Pourquoi mettre à 0 alors qu'on vient de le supprimer?
        base_donnees[i]=0; //On libère la i-ème case mémoire allouée puis On met le pointeur à 0 pour éviter les soucis
    }
	//cout<<"destruction"<<endl;
}

string mediatheque::getNom_media() const
{
    return nom_media;
}

void mediatheque::setNom_media(const string &value)
{
    nom_media = value;
}

void mediatheque::add(std::string param)
{
    switch (enum_string_type(param))
    {
    case CD:
        base_donnees.push_back(new cd());
        base_donnees[nb_ressource]->setId(getNextId(CD));
        nb_cd ++;
        break;
    case DVD:
        base_donnees.push_back(new dvd());
        base_donnees[nb_ressource]->setId(getNextId(DVD));
        nb_dvd ++;
        break;
    case LIVRE:
        base_donnees.push_back(new livre());
        base_donnees[nb_ressource]->setId(getNextId(LIVRE));
        nb_livre ++;
        break;
    case REVUE:
        base_donnees.push_back(new revue());
        base_donnees[nb_ressource]->setId(getNextId(REVUE));
        nb_revue ++;
        break;
    case VHS:
        base_donnees.push_back(new vhs());
        base_donnees[nb_ressource]->setId(getNextId(VHS));
        nb_vhs ++;
        break;
    case RESSOURCE_NUM:
        base_donnees.push_back(new ressource_num());
        base_donnees[nb_ressource]->setId(getNextId(RESSOURCE_NUM));
        nb_docnum ++;
        break;
    default:
        cout<<"Ce type de ressource n'existe pas"<<endl;
        return;
        break;

    }
    base_donnees[nb_ressource]->setType(enum_string_type(param));
    base_donnees[nb_ressource]->setEtat_actuel(DISPONIBLE);
    base_donnees[nb_ressource]->load(cin);
    base_recherche.push_back(1);
    nb_ressource++;
}



void mediatheque::save(std::string file_name)
{
    string type;
    ofstream infile;
    infile.open(file_name.c_str());
    if (infile.fail())
    {
        cout<<"Probleme d'ouverture de fichier"<<endl;
        return;
    }
    for (unsigned int i(0); i<base_donnees.size(); i++)
    {
        base_donnees[i]->save(infile);
    }
    nom_media=file_name;
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
    nom_media=file_name;
    getline(infile, type);
    while(type.size()!=0)
    {

        switch (enum_string_type(type))
        {
        case CD:
            base_donnees.push_back(new cd());
            base_donnees[nb_ressource]->setId(getNextId(CD));
            nb_cd ++;
            break;
        case DVD:
            base_donnees.push_back(new dvd());
            base_donnees[nb_ressource]->setId(getNextId(DVD));
            nb_dvd ++;
            break;
        case LIVRE:
            base_donnees.push_back(new livre());
            base_donnees[nb_ressource]->setId(getNextId(LIVRE));
            nb_livre ++;
            break;
        case REVUE:
            base_donnees.push_back(new revue());
            base_donnees[nb_ressource]->setId(getNextId(REVUE));
            nb_revue ++;
            break;
        case VHS:
            base_donnees.push_back(new vhs());
            base_donnees[nb_ressource]->setId(getNextId(VHS));
            nb_vhs ++;
            break;
        case RESSOURCE_NUM:
            base_donnees.push_back(new ressource_num());
            base_donnees[nb_ressource]->setId(getNextId(RESSOURCE_NUM));
            nb_docnum ++;
            break;
        default:
            cout<<"Ce type de ressource n'existe pas"<<endl;
            return 1;
            break;

        }
        std::cout.setstate(std::ios_base::failbit);
        base_donnees[nb_ressource]->setType(enum_string_type(type));
        //base_donnees[nb_ressource]->setEtat_actuel(DISPONIBLE); //géré dans le load de ressource a priori
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
    if ((signed)base_recherche.size()!=nb_ressource)
        base_recherche.insert(base_recherche.begin(), nb_ressource,true);
    for (unsigned int i=0; i<base_donnees.size(); i++)
    {
        base_recherche[i]=base_donnees[i]->search(param);
    }
}

int mediatheque::gestion(std::string param, int mode) //mode 1 pour show 2 pour borrow 3 pour returne 4 pour reserve 5 pour delete
{
    int _id = atoi(param.c_str());
    for (int i=0; i < nb_ressource; i++)
    {
        if (base_donnees[i]->getId()==_id)
        {
            switch (mode)
            {
            case 1:
                base_donnees[i]->show();
                break;
            case 2:
                if (base_donnees[i]->getEtat_actuel()==RESERVE)
                    cout << "Impossible car ce livre est deja reserve." << endl;
                else
                    base_donnees[i]->setEtat_actuel(EMPRUNTE);
                break;
            case 3:
                base_donnees[i]->setEtat_actuel(DISPONIBLE);
                break;
            case 4:
                if (base_donnees[i]->getEtat_actuel()==EMPRUNTE)
                    cout << "Impossible car ce livre est deja emprunte." << endl;
                else
                    base_donnees[i]->setEtat_actuel(RESERVE);
                break;
            case 5:
                switch (base_donnees[i]->getType())
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
                base_donnees.erase(base_donnees.begin() + i);
                base_recherche.erase(base_recherche.begin() + i);
                nb_ressource --;
                break;
            default:
                cout << "Mode de fonctionnement inconnu."<< endl;
                break;
            }
            return 0;
        }
    }
    cout<<"Pas de ressource a cet ID."<<endl;
    return 0;
}


void mediatheque::clear()
{
    for (int i=0; i<(signed)base_recherche.size(); i++)
        base_recherche[i]=true;
}

void mediatheque::list()
{  
	//    if (base_recherche.size()!=nb_ressource)
    //        base_recherche.insert(base_recherche.begin(), nb_ressource,true);
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|ID    |TYPE           |AUTEUR             |TITRE                             |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;// 81 caractères - 5 pour les barres verticales
	if (nb_ressource == 0)
		return ; 
    for (unsigned int i=0; i<base_recherche.size(); i++)
    {  if(base_recherche[i]==1)
        {
            string str1, str2, str3, str4;
            //char buffer[6];
            ostringstream tampon;
            tampon << base_donnees[i]->getId();
            str1 = miseenforme(tampon.str(),6); // 6 caractères pour l'id
            str2 = miseenforme(enum_string_type(base_donnees[i]->getType()),15); // 15 caractères pour le type
            str3 = miseenforme(base_donnees[i]->getAuteur(),19); // 19 caractères pour l'auteur
            str4 = miseenforme(base_donnees[i]->getTitre(),34); // 34 caractères pour l'id
            cout << "|" << str1 << "|" << str2 << "|" << str3 << "|" << str4 << "|" << endl;
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
    nom_media="";
//    for (unsigned int i(0); i<base_donnees.size(); i++)
//    {
//        delete base_donnees[i]; // Pourquoi mettre à 0 alors qu'on vient de le supprimer?
//        base_donnees[i]=0; //On libère la i-ème case mémoire allouée puis On met le pointeur à 0 pour éviter les soucis
//    }
    //~base_recherche();
	base_donnees.erase(base_donnees.begin(), base_donnees.end());
	base_recherche.erase(base_recherche.begin(), base_recherche.end());
}


string mediatheque::miseenforme(string modif, int taille)
{
    string buffer= "                                        ";
    buffer = modif + buffer; // on concatène avec une chaîne vide de taille notre taille maximale (ici 40)
    buffer = buffer.substr(0,taille);
    return buffer; // On retourne une troncature du buffer à la taille souhaitée
}

void mediatheque::load_state(utilisateur user)
{
    string tampon;
    ifstream infile;
    infile.open(user.getNom().c_str());
    if (infile.fail())
        return;
    tampon="";
    getline(infile, tampon);
    if (tampon=="")
        return;
    load(tampon);
    tampon="";
    getline(infile, tampon);
    base_recherche.resize(base_donnees.size(),true);
    for(unsigned i(0) ; i < base_recherche.size() ; i++) {

        if (tampon[i] == '0')
            base_recherche[i] = false;
        else if(tampon[i] == '1')
            base_recherche[i] = true;

    }

}

void mediatheque::save_state(utilisateur user) const
{
    string tampon;
    ofstream infile;
    infile.open(user.getNom().c_str());
    if (infile.fail())
        return;
    if (nom_media=="")
	return;
    infile<<nom_media<<endl;
    for(unsigned i(0) ; i < base_recherche.size() ; i++) {

        if (base_recherche[i])
            infile<<1;
        else if(!base_recherche[i])
            infile<<0;

    }
    infile.close();

}

void mediatheque::conchita() //Reeordonne les medias selon leur identifiants
{
    bool stay (true);
    for (int i=0; i<(nb_ressource +1); i++)
    {
        if (stay == true)
        {
            stay= false;
            for (int j=0; j<nb_ressource-1; j++)
            {
                if(base_donnees[j]->getId()>base_donnees[j+1]->getId())
                {
                    stay=true;
                    std::swap(base_donnees[j],base_donnees[j+1]);
                    // base_donnees[j].swap(base_donnees[j+1]);S
                }
            }
        }
        else
            break;
    }
}

int mediatheque::getNextId (type_ressource type)
{
    int nextId (0);
    switch (type)
    {
    case CD:
        nextId=ID_CD + nb_cd;
        break;
    case DVD:
        nextId=ID_DVD + nb_dvd;
        break;
    case LIVRE:
        nextId=ID_LIVRE + nb_livre;
        break;
    case REVUE:
        nextId=ID_REVUE + nb_revue;
        break;
    case VHS:
        nextId=ID_VHS + nb_vhs;
        break;
    case RESSOURCE_NUM:
        nextId=ID_RESSOURCE_NUM + nb_docnum;
        break;
    default:
        break;
    }
    return nextId;
}

void mediatheque::reload()
{
	if (nom_media=="")	
		return;
	reset();
	load(nom_media);
}

void mediatheque::resetID()
{
    int nbcd (0);
    int nbdvd (0);
    int nblivre(0);
    int nbrevue (0);
    int nbvhs (0);
    int nbresnum (0);
    for (int i=0; i<nb_ressource; i++)
    {
        switch (base_donnees[i]->getType())
        {
        case CD:
            base_donnees[i]->setId(ID_CD + nbcd);
            nbcd ++;
            break;
        case DVD:
            base_donnees[i]->setId(ID_DVD + nbdvd);
            nbdvd++;
            break;
        case LIVRE:
            base_donnees[i]->setId(ID_LIVRE + nblivre);
            nblivre++;
            break;
        case REVUE:
            base_donnees[i]->setId(ID_REVUE + nbrevue);
            nbrevue++;
            break;
        case VHS:
            base_donnees[i]->setId(ID_VHS + nbvhs);
            nbvhs++;
            break;
        case RESSOURCE_NUM:
            base_donnees[i]->setId(ID_RESSOURCE_NUM + nbresnum);
            nbresnum++;
            break;
        default:
            break;
        }
    }
}

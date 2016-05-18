#include "include.h"


string ressource::getTitre() const
{
    return titre;
}

void ressource::setTitre(const string &value)
{
    titre = value;
}

string ressource::getAuteur() const
{
    return auteur;
}

void ressource::setAuteur(const string &value)
{
    auteur = value;
}

type_ressource ressource::getType() const
{
    return type;
}

void ressource::setType(const type_ressource &value)
{
    type = value;
}
int ressource::getId() const
{
    return id;
}

void ressource::setId(int value)
{
    id = value;
}

etat ressource::getEtat_actuel() const
{
    return etat_actuel;
}

void ressource::setEtat_actuel(const etat &value)
{
    etat_actuel = value;
}

ressource::ressource()
{

}

ressource::ressource(type_ressource _type, int _id, std::string _titre, std::string _auteur, etat etate):
    id(_id),titre(_titre),auteur(_auteur), type(_type), etat_actuel(etate)
{
}

void ressource::save(std::ofstream &infile) const
{
    infile<<enum_string_type(type)<<endl
         <<titre<<endl
        <<auteur<<endl
        <<enum_string_etat(etat_actuel)<<endl;
}

void ressource::load(std::istream &file)
{
    string tampon;
    cout << "Quel est le titre de cette oeuvre?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setTitre(tampon);
    cout << "Qui est l'auteur de cette oeuvre?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setAuteur(tampon);
    //do{
    if (file!=cin)
    {
    getline(file, tampon);
    //}while(tampon.size()==0);
    setEtat_actuel(enum_string_etat(tampon));
    }
}

void ressource::show() const
{
    cout<<"Type: " << enum_string_type(type)<<endl
       <<"Titre: "<<titre<<endl
       <<"Auteur: " << auteur << endl
       << "Etat: "<< enum_string_etat(etat_actuel) << endl;

}

bool ressource::search(std::string str) const
{
    if (titre.find(str)!=string::npos)
        return true;
    if (auteur.find(str)!=string::npos)
        return true;

    return false;

}

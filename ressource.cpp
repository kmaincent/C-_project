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
ressource::ressource()
{

}

ressource::ressource(type_ressource _type, int _id, std::string _titre, std::string _auteur):
    id(_id),titre(_titre),auteur(_auteur), type(_type)
{
}

void ressource::save(std::ofstream &infile) const
{
    infile<<enum_string_type(type)<<endl
         <<titre<<endl
        <<auteur<<endl;
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
}

void ressource::affiche() const
{
    cout<<"Article N°"<<id<<" : "<<titre<<endl
       <<"Ecrit par : "<<auteur<<endl
      <<enum_string_type(type);
}

bool ressource::search(std::string str) const
{
    if (titre.find(str)!=string::npos)
        return true;
    if (auteur.find(str)!=string::npos)
        return true;

    return false;

}

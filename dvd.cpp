#include "include.h"


int dvd::getNb_chap() const
{
    return nb_chap;
}

void dvd::setNb_chap(int value)
{
    nb_chap = value;
}

dvd::dvd()
{

}

dvd::~dvd()
{

}

dvd::dvd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_chap, etat _etat) :
    vhs(_type, _id, _titre, _auteur, _duree, _maison_prod, _etat), //vhs
    nb_chap(_nb_chap)
{
}

void dvd::show() const
{
    vhs::show();
    cout << "Nombre de chapitres: " << nb_chap << endl;
}

void dvd::save(std::ofstream &infile) const
{
    vhs::save(infile);
    infile<<nb_chap<<endl;
}

void dvd::load(std::istream &file)
{
    string tampon;
    vhs::load(file);
    cout << "Combien y a-t-il de chapitres dans ce DVD?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setNb_chap(atoi(tampon.c_str()));
}

bool dvd::search(std::string str) const
{
    if (vhs::search(str))
        return true;

    return false;

}

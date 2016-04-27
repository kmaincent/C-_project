#include "include.h"


int cd::getNb_pistes() const
{
    return nb_pistes;
}

void cd::setNb_pistes(int value)
{
    nb_pistes = value;
}
cd::cd()
{

}

cd::cd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_pistes) :
    vhs(_type, _id, _titre, _auteur, _duree, _maison_prod), //vhs
    nb_pistes(_nb_pistes) //cd
{
}

void cd::affiche() const
{
    vhs::affiche();
    cout<<"Il y a "<<nb_pistes<<" pistes."<<endl;
}

int cd::save(std::ofstream &infile) const
{
    vhs::save(infile);
    infile<<nb_pistes<<endl;
}

void cd::load(std::ifstream &file)
{
    string tampon;
    vhs::load(file);
    getline( file, tampon);
    setNb_pistes(atoi(tampon.c_str()));
}

bool cd::search(std::string str)
{
    if (vhs::search(str))
        return true;

    return false;

}

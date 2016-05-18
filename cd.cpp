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

cd::~cd()
{

}

cd::cd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_pistes, etat _etat) :
    vhs(_type, _id, _titre, _auteur, _duree, _maison_prod, _etat), //vhs
    nb_pistes(_nb_pistes) //cd
{
}

void cd::show() const
{
    vhs::show();
    cout << "Nombre de pistes: " << nb_pistes << endl;
}

void cd::save(std::ofstream &infile) const
{
    vhs::save(infile);
    infile<<nb_pistes<<endl;
}

void cd::load(std::istream &file)
{
    string tampon;
    vhs::load(file);
    cout << "Combien y a-t-il de pistes sur ce CD?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setNb_pistes(atoi(tampon.c_str()));
}

bool cd::search(std::string str) const
{
    if (vhs::search(str))
        return true;

    return false;

}

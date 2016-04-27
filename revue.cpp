#include "include.h"


string revue::getEditeur() const
{
    return editeur;
}

void revue::setEditeur(const string &value)
{
    editeur = value;
}

int revue::getNb_article() const
{
    return nb_article;
}

void revue::setNb_article(int value)
{
    nb_article = value;
}

string revue::getNom_article() const
{
    return nom_article;
}

void revue::setNom_article(const string &value)
{
    nom_article = value;
}
revue::revue()
{
}

revue::revue(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _annee_publi, int _nb_page, std::string _collection, std::string _resume, std::string _editeur, int _nb_article, std::string _nom_article) :
    livre( _type, _id, _titre, _auteur, _annee_publi, _nb_page, _collection, _resume), //livre
    editeur(_editeur), nb_article(_nb_article), nom_article(_nom_article) //revue
{	
}


void revue::save(std::ofstream &infile) const
{
    livre::save(infile);
    infile<<editeur<<endl<<nb_article<<endl<<nom_article<<endl;
    /*for(int i=0;i<nb_article;i++)
    {
        infile<<article[i]<<endl;
    }*/
}

void revue::affiche() const
{
    livre::affiche();
    cout<<"L'editeur est : "<<editeur<<endl
       <<"Il y à "<<nb_article<<"articles"<<endl
      <<nom_article<<endl;
    /*for(int i=0;i<nb_article;i++)
    {
        cout<<"Article "<<i<<" : "<<article[i]<<endl;
    }*/
}



void revue::load(std::ifstream &file)
{
    string tampon;
    livre::load(file);
    getline( file, tampon);
    setEditeur(tampon);
    getline( file, tampon);
    setNb_article(atoi(tampon.c_str()));
    getline( file, tampon);
    setNom_article(tampon);
}

bool revue::search(std::string str)
{
    if (livre::search(str))
        return true;
    if (editeur.find(str)!=string::npos)
        return true;
    if (nom_article.find(str)!=string::npos)
        return true;

    return false;

}

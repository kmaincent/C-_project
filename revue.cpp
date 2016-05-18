#include "include.h"

// Compléter LOAD pour gérer le nombre d'articles le remplissage des titres etc ...

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

revue::revue(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _annee_publi, int _nb_page, std::string _collection, std::string _resume, std::string _editeur, int _nb_article, std::string _nom_article, etat _etat) :
    livre( _type, _id, _titre, _auteur, _annee_publi, _nb_page, _collection, _resume, _etat), //livre
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

void revue::show() const
{
    livre::show();
    cout<<"Editeur: "<<editeur<<endl
       <<"Nombre d'articles: "<<nb_article <<endl
      <<"Article: " << nom_article<<endl;
    /*for(int i=0;i<nb_article;i++)
    {
        cout<<"Article "<<i<<" : "<<article[i]<<endl;
    }*/
}



void revue::load(std::istream &file)
{
    string tampon;
    livre::load(file);
    cout << "Quel est l'editeur de cette revue?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setEditeur(tampon);
    cout << "Combien d'articles cette revue comporte-t-elle?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setNb_article(atoi(tampon.c_str()));
    cout << "Quel est le nom de l'article?" << endl;
    do{
    getline( file, tampon);
    }while(tampon.size()==0);
    setNom_article(tampon);
}

bool revue::search(std::string str) const
{
    if (livre::search(str))
        return true;
    if (editeur.find(str)!=string::npos)
        return true;
    if (nom_article.find(str)!=string::npos)
        return true;

    return false;

}

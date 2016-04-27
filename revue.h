#ifndef REVUE_H
#define REVUE_H

class revue : public livre
{
private :
    string editeur;
    int nb_article;
    string nom_article;//A tester pas sur que ca marche

public :
    revue();
    revue(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _annee_publi, int _nb_page, std::string _collection, std::string _resume, std::string _editeur, int _nb_article, std::string _nom_article);
    void affiche() const;
    void save(std::ofstream &infile) const;
    void load(std::ifstream &file);
    bool search(std::string str);



    string getEditeur() const;
    void setEditeur(const string &value);
    int getNb_article() const;
    void setNb_article(int value);
    string getNom_article() const;
    void setNom_article(const string &value);
};

#endif

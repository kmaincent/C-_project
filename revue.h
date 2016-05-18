#ifndef REVUE_H
#define REVUE_H

class revue : public livre
{
private :
    string editeur;
    int nb_article;
    std::vector <string> nom_article;//A tester pas sur que ca marche

public :
    revue();
    virtual ~revue();
    //revue(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _annee_publi, int _nb_page, std::string _collection, std::string _resume, std::string _editeur, int _nb_article, std::string _nom_article, etat _etat);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual bool search(std::string str) const;
    virtual void load(std::istream &file);

    string getEditeur() const;
    void setEditeur(const string &value);
    int getNb_article() const;
    void setNb_article(int value);
//    string getNom_article() const;
//    void setNom_article(const string &value);
};

#endif

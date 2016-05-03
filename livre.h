#ifndef LIVRE_H
#define LIVRE_H

class livre : public ressource
{
protected:
    int annee_publication, nb_pages;
    std::string collection, resume;

public:
    livre();
    livre(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _annee_publi, int _nb_page, std::string _collection, std::string _resume);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual void load(std::istream &file);
    virtual bool search(std::string str);

    std::string getResume() const;
    void setResume(const std::string &value);
    std::string getCollection() const;
    void setCollection(const std::string &value);
    int getAnnee_publication() const;
    void setAnnee_publication(int value);
    int getNb_pages() const;
    void setNb_pages(int value);
};

#endif

#ifndef VHS_H
#define VHS_H


class vhs : public ressource
{
protected :
    int duree;
    std::string maison_prod;
public:
    vhs();
    vhs(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, etat _etat);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual bool search(std::string str) const;
    virtual void load(std::istream &file);

    std::string getMaison_prod() const;
    void setMaison_prod(const std::string &value);
    int getDuree() const;
    void setDuree(int value);
};

#endif // VHS_H

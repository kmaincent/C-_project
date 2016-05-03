#ifndef CD_H
#define CD_H


class cd : public vhs
{
private:
    int nb_pistes;

public:
    cd();
    cd(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _duree, std::string _maison_prod, int _nb_pistes);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual bool search(std::string str) const;
    virtual void load(std::istream &file);


    int getNb_pistes() const;
    void setNb_pistes(int value);
};

#endif // CD_H

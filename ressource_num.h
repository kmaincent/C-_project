#ifndef RESSOURCE_NUM_H
#define RESSOURCE_NUM_H


class ressource_num: public ressource
{
private:
    int taille;
    std::string URL, format;
public:
    ressource_num();
    ressource_num(type_ressource _type, int _id, std::string _titre, std::string _auteur, int _taille, std::string _format, std::string _URL, etat _etat);
    virtual void show() const;
    virtual void save(std::ofstream &infile) const;
    virtual bool search(std::string str) const;
    virtual void load(std::istream &file);

    int getTaille() const;
    void setTaille(int value);
    std::string getFormat() const;
    void setFormat(const std::string &value);
    std::string getURL() const;
    void setURL(const std::string &value);
};

#endif // RESSOURCE_NUM_H

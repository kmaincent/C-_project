#include "include.h"


utilisateur::utilisateur()
{
}

utilisateur::utilisateur(string _nom):nom(_nom), admin(false)
{
}

bool utilisateur::getAdmin() const
{
    return admin;
}


bool utilisateur::is_admin(string pass)
{
	if (pass=="ADMIN")
		admin=true;
    return admin;
}


string utilisateur::getNom() const
{
    return nom;
}

void utilisateur::setNom(const string &value)
{
    nom = value;
}



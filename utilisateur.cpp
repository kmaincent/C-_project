#include "include.h"

utilisateur::utilisateur(string _nom):nom(_nom), admin(false)
{
}

void utilisateur::is_admin(string pass)
{
	if (pass=="ADMIN")
		admin=true;
}

string utilisateur::nom_user() const
{
	return nom;
}

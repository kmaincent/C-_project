#include "include.h" 

type_ressource enum_string_type(std::string str_type)
{
    type_ressource temp[]={LIVRE, REVUE, CD, VHS, DVD, RESSOURCE_NUM};
    for (int i=0; i<6; i++)
    {
        if (str_type==type_string[i])
            return temp[i];
    }
    return ERROR_RES;
}

std::string enum_string_type (type_ressource enum_type)
{
    type_ressource temp[]={LIVRE, REVUE, CD, VHS, DVD, RESSOURCE_NUM};
    for (int i=0; i<6;i++)
    {
        if (temp[i]==enum_type)
            return type_string[i];
    }
    return "";
}

etat enum_string_etat(std::string str_type)
{
    etat temp[]={DISPONIBLE, RESERVE, EMPRUNTE};
    for (int i=0; i<3; i++)
    {
        if (str_type==etat_string[i])
            return temp[i];
    }
    return ERROR_ET;
}

std::string enum_string_etat (etat enum_etat)
{
    etat temp[]={DISPONIBLE, RESERVE, EMPRUNTE};
    for (int i=0; i<6;i++)
    {
        if (temp[i]==enum_etat)
            return etat_string[i];
    }
    return "";
}

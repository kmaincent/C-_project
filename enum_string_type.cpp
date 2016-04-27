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


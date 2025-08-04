#ifndef AREA_TYPE
#define AREA_TYPE

#include <iostream>

enum class AreaType{
    VENTAS,
    MARKETING,
    ATENCION_AL_PUBLICO,
    ADMINISTRACION
};

std::string areaName(AreaType areaType){
    std::string areaName = "";
    switch (areaType)
    {
    case AreaType::VENTAS:
        areaName = "Ventas";
        break;
    case AreaType::MARKETING:
        areaName = "Marketing";
        break;
    case AreaType::ATENCION_AL_PUBLICO:
        areaName = "Atención al público";
        break;
    case AreaType::ADMINISTRACION:
        areaName = "Administración";
        break;
    default:
        areaName = "Ventas";
        break;
    }
    return areaName;
}

#endif
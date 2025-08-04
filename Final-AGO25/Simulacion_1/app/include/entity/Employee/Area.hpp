#ifndef AREA_HPP
#define AREA_HPP

#include <iostream>

enum class AreaType{
    VENTAS,
    MARKETING,
    ATENCION_AL_PUBLICO,
    ADMINISTRACION
};

std::string areaName(AreaType areaType);

#endif
#include <iostream>
#include "../../include/enums.hpp"

using namespace std;

namespace enums
{
    //convert int to Career enum
    Career intToCareer(const int careerInt) {

        Career career = AcompanamientoTerapeutico;

        if (careerInt == 1) return AcompanamientoTerapeutico;
        if (careerInt == 2) return AnalisisDeSistemas;
        if (careerInt == 3) return GestionAmbiental;
        if (careerInt == 4) return Turismo;

        return career;
    }

    //convert int to CareerYear enum
    CareerYear intToCareerYear(const int careerYearInt) {
        CareerYear careerYear = primero;

        if (careerYearInt == 1) careerYear=primero;
        if (careerYearInt == 2) careerYear=segundo;
        if (careerYearInt == 3) careerYear=tercero;

        return careerYear;
    }

    //convert Career enum to integer
    int careerToInt(const Career career) {
        switch (career) {
            case AcompanamientoTerapeutico: return 1;
            case AnalisisDeSistemas: return 2;
            case GestionAmbiental: return 3;
            case Turismo: return 4;
            default: return 0;
        }
    }

    //convert CareerYear enum to integer
    int careerYearToInt(const CareerYear careerYear) {
        switch (careerYear) {
            case primero: return 1;
            case segundo: return 2;
            case tercero: return 3;
            default: return 0;
        }
    }

    //convert career to string value
    string careerToString(Career career) {
        switch (career) {
            case AcompanamientoTerapeutico: return "Acompanamiento Terapeutico";
            case AnalisisDeSistemas: return "Analisis de Sistemas";
            case GestionAmbiental: return "Gestion Ambiental";
            case Turismo: return "Turismo";
            default: return "Desconocido";
        }
    }

    //convert careerYear to string value
    string careerYearToString(CareerYear year) {
        switch (year) {
            case primero: return "Primero";
            case segundo: return "Segundo";
            case tercero: return "Tercero";
            default: return "Desconocido";
        }
    }
} // namespace enums



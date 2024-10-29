#if !defined(ENUMS_HPP)
#define ENUMS_HPP

    #include <iostream>

    namespace enums
    {
        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( structures and types )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

        //ENUM for careers and careersYears
        enum Career {
            AcompanamientoTerapeutico,
            AnalisisDeSistemas,
            GestionAmbiental,
            Turismo
        };

        enum CareerYear {
            primero,
            segundo,
            tercero
        };

        //■■■■■■■■■■■■■■■■■■■■■■■■■■■■■( interfaces declaration )■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

        //convert string to Career enum
        Career intToCareer(const int careerInt);

        //convert string to CareerYear enum
        CareerYear intToCareerYear(const int careerYearInt);

        //convert Career enum to integer
        int careerToInt(const Career career);

        //convert CareerYear enum to integer
        int careerYearToInt(const CareerYear careerYear);

        //convert career to string value
        std::string careerToString(Career career);

        //convert careerYear to string value
        std::string careerYearToString(CareerYear year);

    } // namespace enums

#endif // ENUMS_HPP

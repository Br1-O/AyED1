#include <iostream>
#include "./include/entity/Branch/Branch.hpp"
#include "./include/repository/Repository.hpp"
#include "./include/entity/Notificator/Notificator.hpp"
#include "./include/service/EmployeeBranchService.hpp"

int main() {

    Branch* branch1 = new Branch("1", "Pinamar");
    Branch* branch2 = new Branch("2", "Miramar");
    Branch* branch3 = new Branch("3", "Mar del Plata");

    Repository* EBRepository = new Repository();
    EBRepository->insertBranch(branch1);
    EBRepository->insertBranch(branch2);
    EBRepository->insertBranch(branch3);

    Notificator* cmdNotificator = new Notificator();

    EmployeeBranchService* EBService = new EmployeeBranchService(EBRepository, cmdNotificator);

    std::cout << "Por favor, ingrese 3 empleados: \n" << std::endl;

    for (size_t i = 0; i < 3; i++)
    {
        EBService->addEmployee();
    }

    EBService->showAllBranches();
    EBService->showAllEmployees();
    EBService->showEmployeesByBranchCode();

    EBService->sendMessageToOne();
    EBService->sendMessageToBranch();
    EBService->sendMessageToAll();
    EBService->sendMessageToAll();

    delete branch1;
    delete branch2;
    delete branch3;

    return 0;
}
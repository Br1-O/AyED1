#include "../../include/Client.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

//id
int Client::getId(){
    return this->id;
};

//name
std::string Client::getName(){
    return this->name;
};

//last name
std::string Client::getLastName(){
    return this->lastName;
};

//phone
std::string Client::getPhone(){
    return this->phone;
};

//address
std::string Client::getAddress(){
    return this->address;
};

//■■■■■■■■■ setters ■■■■■■■■■//

//id
void Client::setId(int id){
    this->id = id;
};

//name
void Client::setName(std::string name){
    this->name = name;
};

//last name
void Client::setLastName(std::string lastName){
    this->lastName = lastName;
};

//phone
void Client::setPhone(std::string phone){
    this->phone = phone;
};

//address
void Client::setAddress(std::string address){
    this->address = address;
};

//■■■■■■■■■ constructor ■■■■■■■■■//

Client::Client(){};

Client::Client(            
int id,
std::string name,
std::string lastName,
std::string phone,
std::string address)
{
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->phone = phone;
    this->address = address;
};

//■■■■■■■■■ destructor ■■■■■■■■■//

Client::~Client(){};


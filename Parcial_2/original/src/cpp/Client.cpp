#include "../../include/Client.hpp"

//■■■■■■■■■ getters ■■■■■■■■■//

//id
int Client::getId() const {
    return id;
}

//name
std::string Client::getName() const {
    return name;
}

//last name
std::string Client::getLastName() const {
    return lastName;
}

//phone
std::string Client::getPhone() const {
    return phone;
}

//address
std::string Client::getAddress() const {
    return address;
}

//■■■■■■■■■ setters ■■■■■■■■■//

//id
void Client::setId(int id) {
    this->id = id;
}

//name
void Client::setName(const std::string& name) {
    this->name = name;
}

//last name
void Client::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

//phone
void Client::setPhone(const std::string& phone) {
    this->phone = phone;
}

//address
void Client::setAddress(const std::string& address) {
    this->address = address;
}

//■■■■■■■■■ constructor ■■■■■■■■■//

Client::Client() : id(0) {}

Client::Client(int id, const std::string& name, const std::string& lastName, const std::string& phone, const std::string& address)
    : id(id), name(name), lastName(lastName), phone(phone), address(address) {}

//■■■■■■■■■ destructor ■■■■■■■■■//

Client::~Client() {}

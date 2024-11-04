#if !defined(CLIENT_HPP)
#define CLIENT_HPP

#include <iostream>
#include <string>

class Client
{
private:
    int id;
    std::string name;
    std::string lastName;
    std::string phone;
    std::string address;

public:
    //■■■■■■■■■ getters ■■■■■■■■■//

    // id
    int getId() const;

    //name
    std::string getName() const;

    //last name
    std::string getLastName() const;

    //phone
    std::string getPhone() const;

    //address
    std::string getAddress() const;

    //■■■■■■■■■ setters ■■■■■■■■■//

    //id
    void setId(int id);

    //name
    void setName(const std::string& name);

    //last name
    void setLastName(const std::string& lastName);

    //phone
    void setPhone(const std::string& phone);

    //address
    void setAddress(const std::string& address);

    //■■■■■■■■■ constructors ■■■■■■■■■//

    Client();

    Client(int id, const std::string& name, const std::string& lastName,
           const std::string& phone, const std::string& address);

    //■■■■■■■■■ destructor ■■■■■■■■■//

    ~Client();
};

#endif // CLIENT_HPP
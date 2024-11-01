#if !defined(CLIENT_HPP)
#define CLIENT_HPP

    #include <iostream>

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

            //id
            int getId();

            //name
            std::string getName();
            
            //last name
            std::string getLastName();

            //phone
            std::string getPhone();

            //address
            std::string getAddress();

            //■■■■■■■■■ setters ■■■■■■■■■//

            //id
            void setId(int id);

            //name
            void setName(std::string name);
            
            //last name
            void setLastName(std::string lastName);

            //phone
            void setPhone(std::string phone);

            //address
            void setAddress(std::string address);

            //■■■■■■■■■ constructor ■■■■■■■■■//

            Client();

            Client(            
            int id,
            std::string name,
            std::string lastName,
            std::string phone,
            std::string address);

            //■■■■■■■■■ destructor ■■■■■■■■■//

            ~Client();
    };

#endif // CLIENT_HPP
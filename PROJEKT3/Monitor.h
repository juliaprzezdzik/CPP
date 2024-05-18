#pragma once 
#include <iostream>
#include <string>
#include <vector>

class Base{
        std::string name;
    public:
        Base(std::string name = "empty");
        virtual void make(std::string name);
        virtual void remove();
        virtual void edit();
        virtual ~Base();
};

class Folder: virtual public Base{
        std::vector<Base> W;
    public:
        Folder();
        void make(std::string name) override;
        void remove() override;
        void edit() override;
        ~Folder();
};

class Subfolder:public Folder{
    public:
        Subfolder();
        void make(std::string name) override;
        void remove() override;
        void edit() override;
        ~Subfolder();

};

class File final: public Subfolder{
    public:
        File();
        void make(std::string name) override;
        void remove() override;
        void edit() override;
        ~File();
};


#include<iostream>
#include<vector>
#include <fstream>

class Message
{
protected:
    std::string message;

public:
    Message(const std::string& m) : message(m) { }

    std::string messages()
    {
        return message;
    }
};


class Command
{
public:
    virtual void execute() = 0;
};


class message_to_the_console : public Command
{
private:
    Message& mess;

public:

    message_to_the_console(Message& m) : mess(m) { }
    void execute()
    {
        std::cout << mess.messages() << std::endl;
    }
};


class message_to_the_file : public Command
{
public:
    Message& mess;
    std::string file_name;
    std::ofstream out;// поток для записи
public:
    message_to_the_file(Message& m, std::string file_name_) : mess(m), file_name(file_name_) 
    { out.open(file_name, std::ios::app); }
    void execute()
    {
        //std::ofstream out;          // поток для записи
        //out.open(file_name);      // открываем файл для записи
        
        if (out.is_open())
        {
           
            //out << mess.messages() << std::endl;
            out << "Hello World!" << std::endl;
        }
    }
    ~message_to_the_file() { out.close(); }
};


class RemoteControl
{
private:
    std::vector<Command*> commands;
public:
    void addCommand(Command* cmd)
    {
        commands.push_back(cmd);
    }
    void pressButton(int slot)
    {
        if (slot >= 0 && slot < commands.size())
        {
            commands[slot]->execute();
        }
    }
};

int main()
{
    Message tv("TV");
    Message lights("Lights");

    message_to_the_console TV_on_console(tv);
    message_to_the_file TV_on_file(tv, "in.txt");
    message_to_the_console Lights_on_console(lights);
    message_to_the_file Lights_on_file(lights, "in.txt");

    RemoteControl remote;

    remote.addCommand(&TV_on_console);
    remote.addCommand(&TV_on_file);
    remote.addCommand(&Lights_on_console);
    remote.addCommand(&Lights_on_file);

    remote.pressButton(0);
    remote.pressButton(1);
    remote.pressButton(2);
    remote.pressButton(3);


    return 0;
}
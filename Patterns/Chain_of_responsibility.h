//����������� � C++ �� ��� �� �����, ��� ��� ���������� ����� ���� ��������, ��������, ��������� ������.
//�������� ���������� �������� : ������� ������������ ����� ���������� �� ������� ������������ ��� ��������, 
//����� ������� ������������ �������.�������� ���� ������� ���������� ������������ �����.

#include "Library.h"

//��������� ����������� ��������� ����� ���������� ������� ������������. �� �� ��������� ����� ��� ���������� �������.
 
class Handler
{
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual string Handle(std::string request) = 0;
};
//��������� ������� �� ��������� ����� ���� ����������� ������ �������� ������ �����������.
 
class AbstractHandler : public Handler
{    
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr)
    {
    }
    Handler* SetNext(Handler* handler) override 
    {
        this->next_handler_ = handler;
        // ������� ����������� ������ �������� ������� ����������� ������� ��������,
        // ��� ���: $monkey->setNext($squirrel)->setNext($dog);
        return handler;
    }
    string Handle(string request) override
    {
        if (this->next_handler_)
        {
            return this->next_handler_->Handle(request);
        }

       // return {};
    }
};
// ��� ���������� ����������� ���� ������������ ������, ���� �������� ��� ���������� ����������� � �������.
 
class MonkeyHandler : public AbstractHandler 
{
public:
    string Handle(std::string request) override
    {
        if (request == "Banana")
        {
            return "Monkey: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class SquirrelHandler : public AbstractHandler
{
public:
    string Handle(std::string request) override
    {
        if (request == "Nut")
        {
            return "Squirrel: I'll eat the " + request + ".\n";
        }
        else 
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class DogHandler : public AbstractHandler
{
public:
    string Handle(std::string request) override
    {
        if (request == "MeatBall") 
        {
            return "Dog: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

 //������ ���������� ��� ������������ ��� ������ � ������������ ������������. �
 // ����������� ������� ������� ���� ����������, ��� ���� ���������� �������� ������ �������.
 
void ClientCode(Handler& handler) 
{
    vector<std::string> food = { "Nut", "Banana", "Cup of coffee" };
    for (const std::string& f : food) 
    {
        cout << "Client: Who wants a " << f << "?\n";
        const string result = handler.Handle(f);
        if (!result.empty())
        {            
            cout << "  " << result;
        }
        else
        {
            cout << "  " << f << " was left untouched.\n";
        }
    }
}
 //������ ����� ����������� ���� ������� ���� �������.
 

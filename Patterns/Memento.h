// �� C++ ���� ����� ��������� � ������� ������������.

#include "Library.h"

class Memento
{
private:
    int state; // ���������
    friend class Originator; // �������� ������ ����� - ��������� class Originator
    Memento(const int s) : state(s) {}
    void setState(const int s)
    {
        state = s;
    }
    int getState() {
        return state; // ��� �������� ���������
    }
};

class Originator // �C���������, ������� ���������� ������ �X���������.
{
public:
    void setState(const int s) // ���������� ��������� �� ������� ������
    {
        state = s;
        cout << "Set state to " << s << "\n";
    }
    int getState()
    {
        return state;
    }
    void setMemento(Memento* const m)
    {
        state = m->getState();
    }
    Memento* createMemento()
    {
        return new Memento(state);
    }

private:
    int state; // ��������� ��������� �������� � ����� ����������
};

class CareTaker // "���������" �������� �� ����������� ������, �� �� ����� � ���� ������
{
public:
    CareTaker(Originator* const o) : originator(o) {}
    ~CareTaker()
    {
        for (unsigned int i = 0; i < history.size(); i++)
        {
            delete history.at(i);
        }
        history.clear();
    }
    void save()   // c�������� ������� ��������� ������ ������
    {
        cout << "Save state" << "\n";
        history.push_back(originator->createMemento());
    }
    void undo()  // ������������ � �������� ���������
    {
        if (history.empty())
        {
            cout << "Unable to undo state." << "\n";
            return;
        }
        Memento* m = history.back();
        originator->setMemento(m);
        cout << "Undo state" << "\n";
        history.pop_back();
        delete m;
    }

private:
    Originator* originator;
    vector<Memento*> history;
};


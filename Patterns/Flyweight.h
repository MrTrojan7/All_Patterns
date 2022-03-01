#include "Library.h"

struct SharedState
{
    string brand_;
    string model_;
    string color_;

    SharedState(const string& brand, const string& model, const string& color)
        : brand_(brand), model_(model), color_(color)
    {
    }

    friend ostream& operator<<(ostream& os, const SharedState& ss)
    {
        return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
    }
};

struct UniqueState
{
    string owner_;
    string plates_;

    UniqueState(const string& owner, const string& plates) : owner_(owner), plates_(plates)
    {
    }

    friend ostream& operator<<(ostream& os, const UniqueState& us)
    {
        return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
    }
};

class Flyweight
{
private:
    SharedState* shared_state_;

public:
    Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state))
    {
    }

    Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_))
    {
    }

    ~Flyweight()
    {
        delete shared_state_;
    }

    SharedState* shared_state() const
    {
        return shared_state_;
    }

    void Operation(const UniqueState& unique_state) const
    {
        cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
    }
};

class FlyweightFactory
{   
private:
    unordered_map<std::string, Flyweight> flyweights_;
  
    string GetKey(const SharedState& ss) const
    {
        return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
    }

public:
    FlyweightFactory(initializer_list<SharedState> share_states)
    {
        for (const SharedState& ss : share_states)
        {
            this->flyweights_.insert(make_pair<string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
        }
    }
    
    Flyweight GetFlyweight(const SharedState& shared_state)
    {
        string key = this->GetKey(shared_state);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
            this->flyweights_.insert(make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            cout << "FlyweightFactory: Reusing existing flyweight.\n";
        }
        return this->flyweights_.at(key);
    }

    void ListFlyweights() const
    {
        size_t count = this->flyweights_.size();
        cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
        for (pair<string, Flyweight> pair : this->flyweights_)
        {
            cout << pair.first << "\n";
        }
    }
};

void AddCarToPoliceDatabase(FlyweightFactory& ff, const string& plates, const string& owner,
    const string& brand, const string& model, const string& color)
{
    cout << "\nClient: Adding a car to database.\n";
    const Flyweight& flyweight = ff.GetFlyweight({ brand, model, color });    
    flyweight.Operation({ owner, plates });
}


#include <iostream>
using namespace std;


class AbstractEntity{
    public:
        virtual ~AbstractEntity() {}
        string getName(); 
};

string AbstractEntity::getName() {
    string s = typeid(*this).name();
    for (int i = 2; i < s.size(); i++) s[i-2] = s[i];
    s[s.size() - 2] = ' ';
    s[s.size() - 1] = ' ';
    return s;
}

class AccountEntity: public AbstractEntity {
    public:
        AccountEntity() {};
        ~AccountEntity() {};
};

class RoleEntity: public AbstractEntity {
    public:
        RoleEntity() {};
        ~RoleEntity() {};
};

class IRepository {
    public:
        virtual void Save(AbstractEntity& e) = 0;
        virtual ~IRepository() {};
};

class AccountRepository {
    public:
        void Save(AbstractEntity& e) {
            cout << "AccountRepo saving " << e.getName() << "\n";
        }
        ~AccountRepository() {};
};

class RoleRepository {
    public:
        void Save(AbstractEntity& e) {
            cout << "RoleRepo saving " << e.getName() << "\n";
        }
        ~RoleRepository() {};
};

int main() {
    AccountEntity acc;
    RoleEntity role;

    AccountRepository accountRepo;
    RoleRepository roleRepo;

    accountRepo.Save(acc);
    roleRepo.Save(role);

    return 0;
}
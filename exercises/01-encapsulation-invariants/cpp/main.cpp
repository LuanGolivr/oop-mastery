#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>

#include <stdexcept>


class InvalidStateError : public std::logic_error {
    using std::logic_error::logic_error;
};

class InsufficientFundsError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

enum class Status{
    PENDING,
    ACTIVE,
    FROZEN,
    CLOSED
};

class DigitalEscrowAccount {
    private:
        int id;
        Status status;
        int64_t balance;

    public:
        explicit DigitalEscrowAccount(int id): id(id), status(Status::PENDING), balance(0){}

        DigitalEscrowAccount(const DigitalEscrowAccount&) = delete;
        DigitalEscrowAccount& operator=(const DigitalEscrowAccount&) = delete;

        void deposit(int64_t amount){
            if(status != Status::PENDING && status != Status::ACTIVE){
                throw InvalidStateError("Deposit only allowed in PENDING or ACTIVE accounts");
            }

            if(!(amount > 0))
                throw std::invalid_argument("Amount must be > 0");

            if(status == Status::PENDING)status = Status::ACTIVE;
            
            balance += amount;
        }

        void releaseFunds(int64_t amount){
            if(status != Status::ACTIVE)
                throw InvalidStateError("Release only allowed in ACTIVE accounts");

            if(!(amount > 0))
                throw std::invalid_argument("Amount must be > 0");

            if(amount > balance)
                throw InsufficientFundsError("Amount exceeds balance");

            balance -= amount;
        }

        void close(){
            if(status != Status::ACTIVE && status != Status::FROZEN)
                throw InvalidStateError("Close only allowed from ACTIVE or FROZEN accounts");

            if(balance != 0)
                throw InvalidStateError("Balance must be zero");

            status = Status::CLOSED;
        }

        void freeze(){
            if(status != Status::ACTIVE)
                throw InvalidStateError("Freeze only allowed in ACTIVE accounts");

            status = Status::FROZEN;
        }

        void unfreeze(){
            if(status != Status::FROZEN)
                throw InvalidStateError("Unfreeze only allowed in FROZEN accounts");

            status = Status::ACTIVE;
        }

        int64_t getBalance() const{
            return balance;
        }

        Status getStatus() const{
            return status;
        }

        int getId() const{
            return id;
        }

        
};

int main(){
    return 0;
}
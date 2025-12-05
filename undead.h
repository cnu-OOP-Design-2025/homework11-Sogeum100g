
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "character.h"
using namespace std;

class Undead {
public:
    virtual string name() const = 0;
    virtual int power() const = 0;
    virtual int agility() const = 0;
    virtual int endurance() const = 0;
    virtual ~Undead() {}
};

class Zombie : public Undead {
public:
    string name() const override { return "Zombie"; }
    int power() const override { return 15; }
    int agility() const override { return 5; }
    int endurance() const override { return 20; }
};

class Skeleton : public Undead {
public:
    string name() const override { return "Skeleton"; }
    int power() const override { return 10; }
    int agility() const override { return 15; }
    int endurance() const override { return 10; }
};

class Lich : public Undead {
public:
    string name() const override { return "Lich"; }
    int power() const override { return 25; }
    int agility() const override { return 12; }
    int endurance() const override { return 18; }
};

// Adapter: Undead → Character
class UndeadAdapter : public Character {
    shared_ptr<Undead> undead;
public:
    UndeadAdapter(shared_ptr<Undead> u) : undead(u) { 
        /* TODO */
        /*
        Undead 객체를 내부 포인터로 저장합니다.
        Character의 description과 type을 Undead의 이름에 따라 설정합니다.
        Character의 type은 character.h에 정의된 CharacterType을 참조하세요.
        */
        this->description = u->name();
        
        if (description == "Zombie")
            this->type = CharacterType::Zombie;
        else if (description == "Skeleton")
            this->type = CharacterType::Skeleton;
        else if (description == "Lich")
            this->type = CharacterType::Lich;

    }
    int getAttack() const override { /* TODO */ 
    
        return undead->power();
    }
    int getSpeed() const override { /* TODO */ 
        
        return undead->agility();

    }
    int getDefense() const override { /* TODO */ 

        return undead->endurance();
    }
};

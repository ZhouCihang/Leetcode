#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car
{
    string maker;
    int price;
};

struct Citizen
{
    char name[32];
    int deposite;
    Car *car;
};

void buy(Citizen *owner)
{
    Car *car = (Car *)malloc(sizeof(Car));
    car->maker = "Chevrolet";
    car->price = 10;

    owner->car = car;
    owner->deposite -= car->price;
}

void discard(Citizen *owner)
{
    free(owner->car);
    owner->car = NULL;
}

void sell(Citizen *owner, Citizen *other)
{
    Car* car = owner->car;
    car->price *= 0.5;
    other->deposite -= car->price;
    other->car = car;
    
    owner->deposite += car->price;
    owner->car = nullptr;
}

int main()
{
    Citizen a = {"xiaopiqiu", 100, nullptr};
    buy(&a);
    //discard(&a);
    Citizen b = {"fiona", 1000, nullptr};
    sell(&a, &b);
    return 0;
}
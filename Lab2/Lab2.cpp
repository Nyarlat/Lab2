#include <iostream>
#include <conio.h>
#include <stdio.h>

class  Bird {
private:
    int wing = 2;
public:
    int stamina;
    int speed;
    Bird() {
        printf("Bird()\n");
        stamina = 10;
        speed = 5;
    }
    Bird(int stamina, int speed) {
        printf("Bird(int stamina, int speed)\n");
        this->stamina = stamina;
        this->speed = speed;
    }
    Bird(const Bird& b) {
        printf("Bird(const Bird& b)\n");
        stamina = b.stamina;
        speed = b.speed;
    }
    virtual ~Bird() {
        printf("%d,%d\n",stamina, speed);
        printf("~Bird()\n");
        printf("\n");
    }
    void fly() {
        stamina -= 5;
        speed += 5;
    }
    void run();
};

void Bird::run() {
    stamina -= 3;
    speed += 2;
}



class Goose : public Bird {
protected:
    int skin;
public:
    Goose() :Bird() {
        printf("Goose()\n");
        skin = 0;
    }
    Goose(int stamina, int speed, int skin) :Bird(stamina, speed) {
        printf("Goose(int stamina, int speed, int skin)\n");
        this->skin = skin;

    }

    Goose(const Goose& g) {
        printf("Goose(const Goose& g)\n");
        stamina = g.stamina;
        speed = g.speed;
        skin = g.skin;
    }

    ~Goose() {
        sound();
        printf("%d,%d,%d\n", stamina, speed, skin);
        printf("~Goose()\n");
        printf("\n");
    }
    void change_z(int new_skin) {
        skin = new_skin;
    }

    void sound() {
        printf("Honk!");
        printf("Honk!\n");
    }
};


class Gaggle {
protected:
    Goose* g1;
    Goose* g2;
    Goose* g3;

public:
    Gaggle() {
        printf("Gaggle()\n");
        g1 = new Goose;
        g2 = new Goose;
        g3 = new Goose;
    }
    Gaggle(int stamina1, int speed1, int skin1, int stamina2, int speed2, int skin2, int stamina3, int speed3, int skin3) {
        printf("Gaggle(int stamina, int speed, int skin)\n");
        g1 = new Goose(stamina1, speed1, skin1);
        g2 = new Goose(stamina2, speed2, skin2);
        g3 = new Goose(stamina3, speed3, skin3);
    }
    Gaggle(const Gaggle& ga) {
        printf("Gaggle(const Gaggle& ga)\n");
        g1 = new Goose(*(ga.g1));
        g2 = new Goose(*(ga.g2));
        g3 = new Goose(*(ga.g3));
    }
    ~Gaggle() {
        delete g1;
        delete g2;
        delete g3;
        printf("~Gaggle()\n");
    }
    void migration(){
        g1->fly();
        g2->fly();
        g3->fly();
    }
};


int main() {
    {
        Bird p;
        Bird p2(15, 20);
        Bird p3(p2);
        printf("\n");
    }

    Bird* b1 = new Bird;
    Bird* b2 = new Bird(12, 20);
    b2->fly();
    b2->run();

    Bird* b3 = new Bird(*b2);
    printf("\n");

    delete b1;
    delete b2;
    delete b3;

    Goose* g1 = new Goose(10, 11, 1);
    g1->fly();
    delete g1;

    Bird* g2 = new Goose(1, 2, 2);
    g2->speed = 22;
    delete g2;

    Gaggle* ga1 = new Gaggle;
    Gaggle* ga2 = new Gaggle(*ga1);

    delete ga1;
    delete ga2;


    _getch();
    return 0;

}
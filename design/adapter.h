class enemyAttacker;
class adapterTest {
private:
    static void game(enemyAttacker*);
public:
    static void test();
};

class enemyAttacker {
public:
    virtual void fireWeapon() = 0;
    virtual void driveForward() = 0;
    virtual void assignDriver(std::string) = 0;
};

class enemyTank: public enemyAttacker {
public:
    virtual void fireWeapon();
    virtual void driveForward();
    virtual void assignDriver(std::string);
};

class enemyRobot {
public:
    void smashWithHand();
    void walkForward();
    void reactToHuman(std::string);
};

class plane {
public:
    virtual void fireWeapon() = 0;
    virtual void takeOff() = 0;
    virtual void moveForward() = 0;
    virtual void landing() = 0;
    virtual void assignDriver(std::string) = 0;
};

class jet: public plane {
public:
    virtual void fireWeapon();
    virtual void takeOff();
    virtual void moveForward();
    virtual void landing();
    virtual void assignDriver(std::string);
};

class helicopter: public plane {
public:
    virtual void fireWeapon();
    virtual void takeOff();
    virtual void moveForward();
    virtual void landing();
    virtual void assignDriver(std::string);
};

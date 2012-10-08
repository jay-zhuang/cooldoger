class commandTest {
public:
    static void test();
};

class electronicDevice {
public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void volumeUp() = 0;
    virtual void volumeDown() = 0;
};

class tv : public electronicDevice {
private:
    int volume;
public:
    void on();
    void off();
    void volumeUp();
    void volumeDown();
};

class radio : public electronicDevice {
private:
    int volume;
public:
    void on();
    void off();
    void volumeUp();
    void volumeDown();
};

class command {
public:
    virtual void execute() = 0;
};

class turnOn : public command {
private:
    electronicDevice *device;
public:
    turnOn(electronicDevice*);
    virtual void execute();
};

template<class Receiver>
class simpleCommand : public command {
public:
    typedef void (Receiver::* Action)();
    simpleCommand(Receiver* r, Action a) : _receiver(r), _action(a) {
    }
    virtual void execute();
private:
    Action _action;
    Receiver* _receiver;
};

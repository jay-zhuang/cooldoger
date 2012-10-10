class bridgeTest {
public:
    static void test();
};

class entertainmentDevice {
public:
    entertainmentDevice() : volumeLevel(0) {}
    int volumeLevel;

    virtual void buttonTwoPressed();
    virtual void buttonEightPressed();
    virtual void buttonFourPressed() = 0;
    virtual void buttonSixPressed() = 0;
};

class remoteButton {
private:
    entertainmentDevice& device;
    remoteButton();
public:
    remoteButton(entertainmentDevice& d) : device(d) {}
    virtual void buttonTwoPress() = 0;
    virtual void buttonFourPress() = 0;
    virtual void buttonFivePress() = 0;
    virtual void buttonSixPress() = 0;
    virtual void buttonEightPress() = 0;
};

class tvRemote : public remoteButton {
public:
    tvRemote(entertainmentDevice& d): remoteButton(d) {};
    virtual void buttonTwoPress();
    virtual void buttonFourPress();
    virtual void buttonFivePress();
    virtual void buttonSixPress();
    virtual void buttonEightPress();
};

class dvdRemote : public remoteButton {
public:
    virtual void buttonTwoPress();
    virtual void buttonFourPress();
    virtual void buttonFivePress();
    virtual void buttonSixPress();
    virtual void buttonEightPress();
};

class TV : public entertainmentDevice {
public:
    TV() : channel(0) {}
    int channel;
    virtual void buttonFourPressed();
    virtual void buttonSixPressed();
};

class DVD : public entertainmentDevice {
public:
    int chapter;
    DVD() : chapter(0) {}
    virtual void buttonFourPressed();
    virtual void buttonSixPressed();
};

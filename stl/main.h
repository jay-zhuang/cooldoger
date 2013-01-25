class ccTest {
public:
    virtual void test() = 0;
};

class basicTest : public ccTest {
public:
    virtual void test();
};
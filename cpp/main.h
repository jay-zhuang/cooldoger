class ccTest {
public:
    virtual void test() = 0;
};

class threadTest : public ccTest {
public:
    virtual void test();
};

class missingNumber {
protected:
    std::vector<int> a;
    virtual void init(int);
    void shuffle();
public:
    friend std::ostream& operator<<(std::ostream&, const missingNumber&);
};

class oddNumber: public missingNumber {
protected:
};

class missingNumberTest {
public:
    static void test();
};

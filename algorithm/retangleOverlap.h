struct retangle {
    std::pair<int, int>a;
    std::pair<int, int>b;
};

class retangleOverlap{
public:
    static bool isOverlap(struct retangle&, struct retangle&);
    static void test();
};

class ccTest2 {
public:
    static void bridgeTest();
};

class sharp {
private:
    virtual void doDraw() = 0;
public:
    void draw();
};

class rectangle : public sharp {
public:
    rectangle();
    ~rectangle();
private:
    void doDraw();
};

class triangle : public sharp {
public:
    triangle();
    ~triangle();
private:
    void doDraw();
};

class table {
public:
    void tableDraw();
    table();
    ~table();
};

class tableBridgeClass : public sharp, public table {
public:
    tableBridgeClass();
    ~tableBridgeClass();
private:
    void doDraw();
};

class tableBridgeObject : public sharp {
private:
    std::shared_ptr<table> t_p;
    void doDraw();
public:
    tableBridgeObject(std::shared_ptr<table>);
    ~tableBridgeObject();
};

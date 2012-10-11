class compositeTest {
public:
    void static test();
};

class songComponent {
public:
    virtual std::string getSongName();
    virtual int getReleaseYear();
    virtual void displaySongInfor() = 0;
};

class song : public songComponent {
private:
    std::string songName;
    int releaseYear;
public:
    song(std::string name="", int year=1980);
    virtual std::string getSongName();
    virtual int getReleaseYear();
    virtual void displaySongInfor();
};

class songGroup : public songComponent {
private:
    std::string groupName;
    std::string groupDescription;
    std::list<songComponent*> child;
public:
    songGroup(std::string name="", std::string desp="");
    virtual void add(songComponent&);
    virtual void remove(songComponent&);
    virtual void displaySongInfor();
};

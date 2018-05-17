#ifndef RESOURCES_H_
#define RESOURCES_H_

//#define BLACK_PIG 0
//#define PINK_PIG 1

enum PlayerType
{
    BLACK_PIG = 0,
    PINK_PIG
};

class Resources
{
public:
    void setType(PlayerType type);
    ~Resources();
    const char* normal;
    const char* hurted;
};

#endif // RESOURCES_H_

#ifndef RESOURCES_H_
#define RESOURCES_H_

#define BLACK_PIG 0
#define PINK_PIG 1

class Resources
{
public:
    Resources(int type);
    ~Resources();
    const char* normal;
    const char* hurted;
};

#endif // RESOURCES_H_

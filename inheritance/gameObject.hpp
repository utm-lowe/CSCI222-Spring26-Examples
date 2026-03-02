#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <string>

class GameObject 
{
public:
    // constructors
    GameObject();
    GameObject(int x, int y, int w, int h, std::string category);

    // destructors
    virtual ~GameObject();

    // getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getCategory() const;

    // setters
    void setX(int x);
    void setY(int y);
    void setWidth(int w);
    void setHeight(int h);
    void setCategory(std::string category);

    // collision detection
    bool isColliding(const GameObject& other) const;

    // collision response
    virtual void onCollision(const GameObject& other);
private:
    int x, y;
    int w, h;
    std::string category;
};

#endif
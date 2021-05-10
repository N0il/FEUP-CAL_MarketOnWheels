#ifndef SRC_TRUCK_H
#define SRC_TRUCK_H

#include <queue>
#include <vector>
#include <Order.h>
#include "../Position/Position.h"

typedef enum {created, assigned, delivering, completed} state_t;

class Truck {
private:
    unsigned int id;
    static unsigned int id_aux;
    state_t state; //TODO created
    unsigned int capacity;
    unsigned int load;
    std::queue<Order*> orders;
    std::queue<Position*> path;
public:
    Truck(unsigned int capacity);
    Truck(unsigned int capacity, std::queue<Order*> orders);
    unsigned int getId() const;
    unsigned int getCapacity() const;
    unsigned int getLoad() const;
    void setLoad(unsigned int load);
    void addOrder(Order* order);
    void popOrder();
    void removeOrder(Order* order);
    void setPath(std::queue<Position*>& path);
    std::queue<Position*> getPath() const;
    void addPositionToPath(Position* position);
    void removePositionFromPath();
    friend std::ostream& operator<<(std::ostream& os, const Truck& truck);
    friend std::istream& operator>>(std::istream& is, Truck& truck);
    state_t getState();
    void setState(state_t state);
    std::string returnStateString(int state);
};

#endif //SRC_TRUCK_H
